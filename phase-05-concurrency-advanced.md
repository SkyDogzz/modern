# Phase 5 - Concurrency, Performance, and Advanced Facilities

Concurrency and measurement fundamentals are required. PMR, modules, coroutines,
`std::mdspan`, and weak memory ordering are optional specializations and do not
block Phase 6.

Read Concept Briefs 18-21 before and during this phase.

Focus on:

- thread lifecycle, ownership, data races, and deterministic shutdown;
- mutex-protected invariants and deadlock prevention;
- condition variables, queues, cooperative cancellation, and task results;
- atomics and the C++ memory model;
- ThreadSanitizer and reproducible stress tests;
- profiling before optimization;
- optional memory-resource and modern-facility experiments.

## 44. Thread Lifecycle and Data-Race Lab

**Category:** Core lab

**Prerequisites:** Phases 1-4 and [Concept Brief 18](concept-briefs.md#18-threads-races-and-locks).

**Difficulty:** 4/5

**Estimated time:** 7-10 hours

**Tooling stage:** Add a separate TSan preset where supported.

### Learning Outcomes

- Start work with `std::thread` and give every thread a scope-bound joining owner.
- Pass values and references to threads deliberately.
- Define conflicting evaluations and every condition required for a data race.
- Diagnose one data race with TSan.

### Goal

Run deterministic worker tasks, then isolate and repair one shared-counter race.

### Requirements

- Use `std::jthread` or a scope-bound join guard so every started thread is joined
  during normal and exceptional exits.
- Keep direct `std::thread::join` mechanics in a small no-throw experiment.
- Demonstrate safe value transfer and one explicitly lifetime-bounded reference transfer.
- Keep an intentionally racy counter in a separate TSan executable.
- Fix the race first with a mutex.
- Explain why detaching would break the ownership model.
- Test cleanup when an operation throws after a worker starts.

### Acceptance Criteria

- [ ] No joinable `std::thread` reaches its destructor on any tested exit path.
- [ ] An exception-path test demonstrates deterministic joining during unwinding.
- [ ] The passing suite is race-free under TSan where supported.
- [ ] The learner identifies overlapping conflicting evaluations, potential
      concurrency, the non-atomic-access requirement, and missing happens-before.
- [ ] The learner explains why relaxed atomic operations are not themselves a data
      race on the atomic object.

### Stretch Goal

Compare a scope-bound RAII join guard with `std::jthread` cancellation and
destruction behavior.

---

## 45. Mutex Invariants and Deadlock Lab

**Category:** Core lab

**Prerequisites:** Project 44 and [Concept Brief 18](concept-briefs.md#18-threads-races-and-locks).

**Difficulty:** 4/5

**Estimated time:** 7-10 hours

**Tooling stage:** Add deterministic lock-order tests and a separately labeled stress test.

### Learning Outcomes

- Protect an invariant with mutexes and RAII lock types.
- Minimize critical sections without exposing unprotected state.
- Prevent deadlock through one-lock design, lock ordering, or `scoped_lock`.

### Goal

Implement thread-safe account transfers and repair an isolated deadlock example.

### Requirements

- Protect account and transfer invariants, not individual statements.
- Use RAII locks on every exit path.
- Demonstrate a two-lock deadlock only in an isolated, timeout-controlled executable.
- Fix it using `scoped_lock` or a documented global order.
- Never call unknown user code while holding a mutex.

### Acceptance Criteria

- [ ] Total balance remains invariant under stress.
- [ ] The passing implementation has no circular wait.
- [ ] Lock scope and ownership are documented.

### Stretch Goal

Use `std::call_once` for one shared initialization, then compare coarse- and
fine-grained locking with measurement, not intuition.

---

## 46. Blocking Queue

**Category:** Core project

**Prerequisites:** Projects 44-45 and
[Concept Brief 19](concept-briefs.md#19-condition-variables-cancellation-and-task-results).

**Difficulty:** 4.5/5

**Estimated time:** 10-15 hours

**Tooling stage:** Add multi-producer/multi-consumer stress tests and long-test labels.

### Learning Outcomes

- Wait efficiently with `condition_variable`.
- Use predicate waits to handle spurious wakeups.
- Define queue closure so blocked operations can terminate.

### Goal

Implement a bounded queue used by multiple producers and consumers.

### Requirements

- Support blocking push and pop with predicate waits.
- Define full, empty, closed, and drained states.
- Make close idempotent and wake every waiter.
- Return typed status instead of using sentinel data values.
- Keep element construction/move exception-safe.

### Acceptance Criteria

- [ ] Stress tests preserve each accepted item exactly once.
- [ ] Closure wakes blocked producers and consumers.
- [ ] No wait occurs without a predicate.
- [ ] TSan is clean in supported environments.

### Stretch Goal

Add non-blocking `try_push` and `try_pop`.

---

## 47. Cancellable Worker

**Category:** Core project

**Prerequisites:** Projects 44-46 and [Concept Brief 19](concept-briefs.md#19-condition-variables-cancellation-and-task-results).

**Difficulty:** 4/5

**Estimated time:** 8-12 hours

**Tooling stage:** Test repeated start, stop, and destruction under TSan.

### Learning Outcomes

- Own a thread with `std::jthread`.
- Use stop tokens for cooperative cancellation.
- Integrate cancellation with blocking work and queue closure.

### Goal

Run a background worker that processes queued tasks and stops promptly.

### Requirements

- Use `jthread`, not a detached thread.
- Observe stop requests inside repeated and blocking work.
- Coordinate stop requests with queue closure.
- Make destruction wait safely.
- Define what happens to queued and in-progress work during shutdown.

### Acceptance Criteria

- [ ] Repeated start/stop tests terminate reliably.
- [ ] No worker accesses owner state after destruction.
- [ ] Cancellation cannot strand a waiting thread.

### Stretch Goal

Add a shutdown deadline and distinguish requested, graceful, and timed-out outcomes.

---

## 48. Task Results with Futures and Promises

**Category:** Core lab

**Prerequisites:** Projects 44-47 and [Concept Brief 19](concept-briefs.md#19-condition-variables-cancellation-and-task-results).

**Difficulty:** 4/5

**Estimated time:** 6-9 hours

**Tooling stage:** Add result, exception, timeout, and broken-promise tests.

### Learning Outcomes

- Transport a value or exception through `future` and `promise`.
- Compare explicit thread/promise work with `async`.
- Separate task results from shared mutable publication.

### Goal

Run several independent calculations and collect their results deterministically.

### Requirements

- Publish one successful value and one exception through promises.
- Handle a broken promise.
- Use `wait_for` without busy-waiting.
- If using `async`, specify and explain the launch policy.
- Do not use a future as a substitute for queue cancellation.

### Acceptance Criteria

- [ ] Values and exceptions reach the waiting caller.
- [ ] Every future is consumed or deliberately abandoned.
- [ ] The report explains shared state internal to a future versus application shared state.

### Stretch Goal

Build small focused examples with `latch`, `barrier`, or `counting_semaphore`; these
facilities are survey material, not a mandatory phase-gate item.

---

## 49. Parallel File Hasher

**Category:** Portfolio project

**Prerequisites:** Projects 31 and 44-48.

**Difficulty:** 4.5/5

**Estimated time:** 14-22 hours

**Tooling stage:** Link `Threads::Threads`, run TSan, and benchmark Release builds.

### Learning Outcomes

- Split independent work across a bounded worker set.
- Minimize shared state and publish deterministic results.
- Cancel safely after traversal or hashing errors.

### Goal

Traverse a directory, hash regular files concurrently, and print deterministic results.

### Requirements

- Use a fixed number of `jthread` workers and the Project 46 queue.
- Avoid one-thread-per-file.
- Choose and document the hash algorithm.
- If using a teaching non-cryptographic hash, label it unsuitable for security or
  integrity guarantees; a cryptographic implementation may be a pinned dependency.
- Define behavior for unreadable, disappearing, or changing files.
- Sort output independently from completion order.
- Compare single-thread and multi-thread modes on the same workload.

### Acceptance Criteria

- [ ] Each accepted file yields one result or one documented error.
- [ ] Cancellation cannot strand workers.
- [ ] Representative stress runs are TSan-clean.
- [ ] Performance claims include workload, hardware, build, and repetitions.

### Stretch Goal

Add incremental cancellation from a signal-safe outer adapter.

---

## 50. Atomics and Memory Model Lab

**Category:** Core lab

**Prerequisites:** Projects 44-49 and [Concept Brief 20](concept-briefs.md#20-atomics-and-the-memory-model).

**Difficulty:** 5/5

**Estimated time:** 10-15 hours

**Tooling stage:** Keep racy examples separate from passing tests.

### Learning Outcomes

- Distinguish atomicity, visibility, ordering, and compound invariants.
- Use atomic scalar state where appropriate.
- Explain sequential consistency and happens-before.

### Goal

Compare unsafe, mutex-protected, and atomic counters, then build a progress monitor.

### Requirements

- Demonstrate the race only in an isolated TSan executable.
- Fix the counter with both a mutex and an atomic.
- Use default sequential consistency in the baseline.
- Keep compound state under a mutex.
- Document any optional weaker order with a happens-before diagram and argument.
- Do not implement a lock-free queue.

### Acceptance Criteria

- [ ] Correct versions produce repeatable totals under stress.
- [ ] The learner explains why several atomic fields do not form one atomic invariant.
- [ ] Passing tests are not presented as proof of memory-order correctness.

### Stretch Goal

Implement a release/acquire publication flag only after writing the proof.

---

## 51. Profiling Before Optimization

**Category:** Core project

**Prerequisites:** Phases 1-4 and [Concept Brief 21](concept-briefs.md#21-measurement-profiling-and-pmr).

**Difficulty:** 4/5

**Estimated time:** 9-14 hours

**Tooling stage:** Add Release and RelWithDebInfo presets plus a benchmark target.

### Learning Outcomes

- Distinguish timing, benchmarking, and profiling.
- Establish a reproducible baseline and account for noise.
- Optimize the measured bottleneck while preserving behavior.

### Goal

Profile a deliberately slow text-processing workload and improve one verified hotspot.

### Requirements

- Record workload, hardware, compiler, flags, build, warmup, and repetitions.
- Use an available profiler.
- Capture allocation evidence where possible.
- Make one algorithmic improvement before a micro-optimization.
- Use branch-likelihood attributes only with profile evidence.
- Keep correctness tests unchanged before and after.

### Acceptance Criteria

- [ ] Before/after results are reproducible within documented noise.
- [ ] The optimized version preserves behavior.
- [ ] The report separates profiler evidence from speculation.

### Stretch Goal

Generate a flame graph or equivalent visual profile.

---

## 52. Profiled PMR Text Processor

**Category:** Optional specialization

**Prerequisites:** Project 51 and [Concept Brief 21](concept-briefs.md#21-measurement-profiling-and-pmr).

**Difficulty:** 5/5

**Estimated time:** 10-16 hours

**Tooling stage:** Benchmark standard and PMR implementations together.

### Learning Outcomes

- Use allocator-aware containers and `pmr::memory_resource`.
- Match resource lifetime to every dependent object.
- Decide whether arena allocation solves a measured problem.

### Goal

Parse many short-lived tokens with standard containers, then compare a PMR version.

### Requirements

- Verify and profile the normal-container version first.
- Use PMR strings and vectors with one explicit resource.
- Ensure every PMR object dies before its resource.
- Report time, allocation count, memory use, and complexity.
- Remove PMR if evidence does not justify it.

### Acceptance Criteria

- [ ] Both versions produce identical results.
- [ ] Resource lifetime is documented and sanitizer-clean.
- [ ] Added complexity is retained only with evidence.

### Stretch Goal

Compare monotonic and pool resources for different lifetimes.

---

## 53. Optional Modern Feature Tracks

**Category:** Optional specialization

**Prerequisites:** Phase 4. No track is required before Phase 6.

**Difficulty:** 4.5-5/5

**Estimated time:** 8-16 hours per selected track

**Tooling stage:** Document toolchain support in dedicated presets.

### Learning Outcomes

- Evaluate one modern facility in a naturally matched problem.
- Use feature-test macros and document portability.
- Compare with a conventional fallback.

### Goal

Optionally complete any number of independent tracks. Completing zero tracks does
not block the roadmap.

### Requirements

- Select zero or more tracks according to interest and toolchain support.
- Record compiler, standard-library, CMake, and operating-system constraints.
- Keep unsupported facilities from breaking unrelated projects.
- Compare each selected facility with a conventional implementation.

### Track A: Lazy Generator

- Use `std::generator` where available to yield numbers or file lines.
- Compare with an iterator/range implementation.
- Keep custom promise types as a stretch goal.

### Track B: Modular Vector Library

- Convert Vector2 to a C++ module with documented toolchain-specific CMake support.
- Keep a header fallback.
- Compare build and distribution ergonomics.

### Track C: `std::mdspan` Matrix View

- Apply `mdspan` to a matrix or image problem.
- Demonstrate extents, layouts, and non-owning lifetime.
- Keep it out of unrelated CLI code.

### Acceptance Criteria

- [ ] The selected facility fits the selected problem.
- [ ] Unsupported toolchains fail clearly or use a fallback.
- [ ] Support detection does not rely only on compiler versions.
- [ ] Standard guarantees and implementation limitations are distinguished.

### Stretch Goal

Complete a second track and compare portability cost.
