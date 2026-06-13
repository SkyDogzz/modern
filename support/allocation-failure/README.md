# Allocation-Failure Injection

`allocation_failpoint.hpp` supplies a deterministic teaching allocator. It avoids a
process-wide replacement of `operator new`, which would make unrelated library
allocations fail unpredictably.

Call `fail_after(0)` to fail the next allocation through
`roadmap::testing::allocate`. Call `disable()` during cleanup. Production code should
use normal standard-library owners and allocators.
