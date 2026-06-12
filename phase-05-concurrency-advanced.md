# Phase 5 - Concurrency and Advanced Facilities

Concurrency fundamentals are required in this phase. Coroutines, modules, `std::mdspan`, and
allocator specialization are advanced or toolchain-sensitive topics and must
not block progress to professional project work.

Focus on:

- `std::jthread`, cooperative cancellation, and thread ownership;
- mutexes, condition variables, deadlock prevention, and task queues;
- atomics and the C++ memory model;
- ThreadSanitizer and reproducible concurrency tests;
- profiling before optimization;
- allocators and polymorphic memory resources;
- optional, focused modules and coroutine labs.

## 33. Cancellable Worker

**Prerequisites:** Phases 1-4.

**Difficulty:** 4/5

**Estimated time:** 8-10 hours

**CMake stage:** Add a separate ThreadSanitizer preset where supported.

### Learning Outcomes

- Own a thread with `std::jthread`.
- Use stop tokens for cooperative cancellation.
- Avoid detached threads and unsafe shutdown.

### Goal

Run a background worker that processes periodic tasks and stops promptly when
requested.

### Requirements

- Use `std::jthread`, not a detached `std::thread`.
- Observe a stop token inside blocking or repeated work.
- Make destruction wait for the worker safely.
- Define what happens to unfinished work during shutdown.

### Acceptance Criteria

- [ ] Repeated start/stop tests terminate reliably.
- [ ] No worker accesses state after its owner is destroyed.
- [ ] ThreadSanitizer reports no data race in supported environments.

### Stretch Goal

Add a timeout and report whether shutdown was graceful.

---

## 34. Blocking Queue and Deadlock Lab

**Prerequisites:** Project 33.

**Difficulty:** 4.5/5

**Estimated time:** 10-14 hours

**CMake stage:** Add stress tests and a long-running test label.

### Learning Outcomes

- Protect invariants with mutexes and RAII lock types.
- Wait efficiently with `std::condition_variable`.
- Prevent deadlock through lock ordering and `std::scoped_lock`.

### Goal

Implement a bounded blocking queue used by multiple producers and consumers.

### Requirements

- Support blocking push and pop.
- Use predicates to handle spurious wakeups.
- Provide close/cancel behavior so waiting threads can exit.
- Create an isolated deadlock demonstration, then fix it with consistent locking.
- Never call unknown user code while holding the queue mutex.

### Acceptance Criteria

- [ ] Multiple-producer and multiple-consumer stress tests preserve every item exactly once.
- [ ] Closing wakes all waiting operations.
- [ ] Lock ownership is exception-safe.
- [ ] The fixed design has no circular wait.

### Stretch Goal

Add a non-blocking `try_push` and `try_pop`.

---

## 35. Parallel File Hasher

**Prerequisites:** Projects 23, 33, and 34.

**Difficulty:** 4.5/5

**Estimated time:** 12-18 hours

**CMake stage:** Link thread support through `Threads::Threads` and test with TSan.

### Learning Outcomes

- Split independent work across a bounded worker set.
- Minimize shared state and synchronize result publication.
- Cancel safely after errors.

### Goal

Traverse a directory, hash regular files concurrently, and print deterministic results.

### Requirements

- Use a fixed number of `std::jthread` workers.
- Feed work through the blocking queue.
- Avoid one-thread-per-file.
- Define behavior for unreadable or changing files.
- Sort output independently from completion order.
- Compare single-thread and multi-thread execution with the same workload.

### Acceptance Criteria

- [ ] Every accepted file produces exactly one result or one documented error.
- [ ] Cancellation cannot strand waiting workers.
- [ ] ThreadSanitizer is clean on a representative stress run.
- [ ] Performance claims include workload, hardware, build type, and repeated measurements.

### Stretch Goal

Add incremental cancellation from a signal-safe outer adapter.

---

## 36. Atomics and Memory Model Lab

**Prerequisites:** Projects 33-35.

**Difficulty:** 5/5

**Estimated time:** 10-14 hours

**CMake stage:** Keep intentionally racy demonstrations separate from passing tests.

### Learning Outcomes

- Distinguish atomicity, visibility, ordering, and higher-level invariants.
- Use `std::atomic` for appropriate scalar state.
- Explain sequential consistency and why weaker ordering requires proof.

### Goal

Compare an unsafe counter, a mutex-protected counter, and an atomic counter, then
build a stop/progress monitor.

### Requirements

- Demonstrate the data race in an isolated TSan example.
- Fix the counter with both a mutex and `std::atomic`.
- Use default sequentially consistent ordering first.
- Document any weaker memory order with a happens-before argument.
- Do not attempt a lock-free queue as the baseline project.

### Acceptance Criteria

- [ ] The racy example is never part of the normal passing test run.
- [ ] Correct versions produce repeatable totals under stress.
- [ ] The learner can explain why multiple atomic fields do not create one atomic invariant.

### Stretch Goal

Implement a small publish/subscribe flag using release/acquire and justify it.

---

## 37. Profiling Before Optimization

**Prerequisites:** Phases 1-4 and a release-capable build.

**Difficulty:** 4/5

**Estimated time:** 8-12 hours

**CMake stage:** Add Release and RelWithDebInfo presets plus a benchmark target.

### Learning Outcomes

- Distinguish benchmarking from profiling.
- Establish a reproducible baseline before changing code.
- Use a profiler to find time or allocation hotspots.

### Goal

Profile a deliberately slow text-processing workload and optimize only the
measured bottleneck.

### Requirements

- Record workload, hardware, compiler, flags, and repeated timings.
- Use an available profiler such as `perf`, Instruments, Visual Studio Profiler, or equivalent.
- Capture allocation evidence where tooling permits.
- Make one algorithmic optimization before a low-level micro-optimization.
- Use `[[likely]]` or `[[unlikely]]` only if profile evidence justifies it.

### Acceptance Criteria

- [ ] Before-and-after measurements are reproducible.
- [ ] Correctness tests pass before and after optimization.
- [ ] The report separates profiler evidence from speculation.

### Stretch Goal

Generate a flame graph or equivalent visual profile.

---

## 38. Profiled PMR Text Processor

**Prerequisites:** Project 37.

**Difficulty:** 5/5

**Estimated time:** 10-15 hours

**CMake stage:** Benchmark standard and PMR implementations in one executable.

### Learning Outcomes

- Use allocator-aware containers and `std::pmr::memory_resource`.
- Match resource lifetime to all containers that use it.
- Decide whether arena allocation solves a measured problem.

### Goal

Parse many short-lived tokens using standard containers, then compare a PMR
implementation backed by `std::pmr::monotonic_buffer_resource`.

### Requirements

- Build and verify the normal-container version first.
- Profile allocation behavior before introducing PMR.
- Use `std::pmr::string` and `std::pmr::vector` with one explicit resource.
- Ensure no PMR object outlives its memory resource.
- Report time, allocation count, memory use, and complexity tradeoffs.

### Acceptance Criteria

- [ ] Standard and PMR versions produce identical results.
- [ ] The resource lifetime is documented and tested.
- [ ] PMR is retained only if measurements justify the added complexity.

### Stretch Goal

Compare monotonic and pool resources for different object lifetimes.

---

## 39. Optional Modern Feature Tracks

**Prerequisites:** Projects 26-32. Complete at least one track; none is required
before Phase 6.

**Difficulty:** 4.5-5/5

**Estimated time:** 8-14 hours per track

**CMake stage:** Document compiler and standard-library support in dedicated presets.

### Learning Outcomes

- Evaluate a modern facility in a focused problem rather than a feature dump.
- Use feature-test macros and document portability constraints.
- Provide a conventional fallback when practical.

### Goal

Complete one self-contained experiment whose problem naturally benefits from a
specific modern facility.

### Requirements

- Select exactly one baseline track.
- Record compiler, standard-library, CMake, and operating-system constraints.
- Keep unsupported facilities from breaking unrelated roadmap projects.
- Compare the selected facility with a conventional implementation.

### Track A: Lazy Generator

- Use `std::generator` when available to yield numbers or file lines lazily.
- Compare it with an iterator/range implementation.
- Implement a custom promise type only as an advanced stretch goal.

### Track B: Modular Vector Library

- Convert the Vector2 library to a C++ module.
- Build imports through documented toolchain-specific CMake support.
- Keep a header-based fallback and compare build ergonomics.

### Track C: `std::mdspan` Matrix View

- Apply `std::mdspan` to a matrix or image-processing problem.
- Demonstrate extents, layouts, and non-owning lifetime.
- Do not include `mdspan` in unrelated CLI code.

### Acceptance Criteria

- [ ] The selected track solves a problem naturally matched to the facility.
- [ ] Unsupported toolchains fail clearly or use a documented fallback.
- [ ] Feature support is detected with feature-test macros where available.
- [ ] The README distinguishes standard guarantees from implementation limitations.

### Stretch Goal

Complete a second track and compare its portability cost.
