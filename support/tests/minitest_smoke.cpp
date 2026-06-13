#include "minitest.hpp"

ROADMAP_TEST_CASE("minimal test harness executes cases") {
    ROADMAP_REQUIRE(2 + 2 == 4);
}

ROADMAP_TEST_CASE("minimal test harness accepts Boolean expressions") {
    const bool ready{true};
    ROADMAP_REQUIRE(ready);
}

int main() {
    return roadmap::test::run_all();
}
