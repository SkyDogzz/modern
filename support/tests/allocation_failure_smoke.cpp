#include "allocation_failpoint.hpp"
#include "minitest.hpp"

#include <memory>
#include <new>

ROADMAP_TEST_CASE("failpoint rejects the selected allocation") {
    roadmap::testing::AllocationFailpoint::fail_after(0);

    bool threw{false};
    try {
        auto* value = roadmap::testing::allocate<int>(1);
        roadmap::testing::deallocate(value, 1);
    } catch (const std::bad_alloc&) {
        threw = true;
    }

    ROADMAP_REQUIRE(threw);
}

ROADMAP_TEST_CASE("disabled failpoint permits allocation") {
    roadmap::testing::AllocationFailpoint::disable();
    auto* value = roadmap::testing::allocate<int>(1);
    std::construct_at(value, 42);
    ROADMAP_REQUIRE(*value == 42);
    std::destroy_at(value);
    roadmap::testing::deallocate(value, 1);
}

int main() {
    return roadmap::test::run_all();
}
