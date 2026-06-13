#pragma once

#include <cstddef>
#include <limits>
#include <memory>
#include <new>
#include <optional>

namespace roadmap::testing {

class AllocationFailpoint {
public:
    static void fail_after(std::size_t successful_allocations) {
        countdown_ = successful_allocations;
    }

    static void disable() noexcept {
        countdown_.reset();
    }

    [[nodiscard]] static bool should_fail() noexcept {
        if (!countdown_.has_value()) {
            return false;
        }

        if (*countdown_ == 0) {
            countdown_.reset();
            return true;
        }

        --*countdown_;
        return false;
    }

private:
    inline static thread_local std::optional<std::size_t> countdown_{};
};

template <class T>
[[nodiscard]] auto allocate(std::size_t count) -> T* {
    if (count > std::numeric_limits<std::size_t>::max() / sizeof(T)) {
        throw std::bad_array_new_length{};
    }
    if (AllocationFailpoint::should_fail()) {
        throw std::bad_alloc{};
    }
    return std::allocator<T>{}.allocate(count);
}

template <class T>
void deallocate(T* pointer, std::size_t count) noexcept {
    std::allocator<T>{}.deallocate(pointer, count);
}

}  // namespace roadmap::testing
