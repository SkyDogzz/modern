# Minimal Test Harness

Projects 2-13 may copy or include `minitest.hpp`. It deliberately supplies only:

- `ROADMAP_TEST_CASE("name")`;
- `ROADMAP_REQUIRE(expression)`;
- `roadmap::test::run_all()`.

Example:

```cpp
#include "minitest.hpp"

ROADMAP_TEST_CASE("addition") {
    ROADMAP_REQUIRE(2 + 2 == 4);
}

int main() {
    return roadmap::test::run_all();
}
```

The harness is not a production test framework. Project 14 requires adopting a
maintained framework or documenting why a repository harness remains appropriate.
