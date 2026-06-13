#pragma once

#include <algorithm>
#include <cstddef>

namespace roadmap::ownership_lab {

// Intentionally broken: diagnose ownership, copy, assignment, and cleanup defects.
class BrokenBuffer {
public:
    explicit BrokenBuffer(std::size_t size)
        : data_{new int[size]}, size_{size} {
        std::fill_n(data_, size_, 0);
    }

    [[nodiscard]] auto data() noexcept -> int* {
        return data_;
    }

    [[nodiscard]] auto data() const noexcept -> const int* {
        return data_;
    }

    [[nodiscard]] auto size() const noexcept -> std::size_t {
        return size_;
    }

private:
    int* data_;
    std::size_t size_;
};

}
