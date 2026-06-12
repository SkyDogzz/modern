# Phase 3 - Standard Library Fluency

This phase teaches deliberate selection and composition of standard-library tools. The goal
is fluency and sound tradeoffs, not memorization or premature claims of mastery.

Focus on:

- sequence and associative containers;
- complexity and iterator invalidation;
- lambdas, function objects, and callbacks;
- algorithms, ranges, views, and view lifetime;
- filesystem, formatting, printing, and chrono;
- testable adapters around operating-system effects.

## 18. Contact Book

**Prerequisites:** Phases 1-2.

**Difficulty:** 3/5

**Estimated time:** 7-10 hours

**CMake stage:** Build a reusable contact library and a thin CLI target.

### Learning Outcomes

- Select containers using lookup, insertion, ordering, and memory tradeoffs.
- Use `std::vector`, `std::map`, `std::unordered_map`, and `std::set`.
- Explain average versus worst-case complexity.

### Goal

Manage contacts with names, email addresses, phone numbers, and tags.

### Requirements

- Implement the first version using `std::vector`.
- Add an indexed version using `std::unordered_map`.
- Use a set only where uniqueness is required.
- Use structured bindings when they make map iteration clearer.
- Measure lookup with a release build and enough data to be meaningful.
- Document iterator and reference invalidation for each chosen container.

### Acceptance Criteria

- [ ] Duplicate identities and missing contacts have defined behavior.
- [ ] Container choices are justified with operations and complexity.
- [ ] Benchmark conclusions distinguish measured facts from assumptions.

### Stretch Goal

Evaluate `std::flat_map` when the selected standard library implements it.

---

## 19. Playlist Iterator Lab

**Prerequisites:** Project 18.

**Difficulty:** 3/5

**Estimated time:** 6-8 hours

**CMake stage:** Add focused invalidation tests.

### Learning Outcomes

- Use iterators, ranges, and range-based loops.
- Recognize invalidation after insertion, erasure, and reallocation.
- Compare contiguous and node-based containers.

### Goal

Implement next, previous, insert, remove-current, and shuffle behavior.

### Requirements

- Build a `std::vector` version first.
- Never dereference an iterator after an operation that invalidates it.
- Rebuild the experiment with `std::list` and compare costs.
- Define behavior for empty playlists and removal of the current item.

### Acceptance Criteria

- [ ] Tests cover first, last, empty, insertion, and erasure states.
- [ ] The learner can state the relevant invalidation rules.
- [ ] The list version is not declared superior without workload evidence.

### Stretch Goal

Add a `std::deque` version and compare its invalidation rules.

---

## 20. Event Dispatcher and Callable Objects

**Prerequisites:** Projects 18-19 and Phase 2 lifetime rules.

**Difficulty:** 3.5/5

**Estimated time:** 8-11 hours

**CMake stage:** Test the dispatcher as a library without CLI dependencies.

### Learning Outcomes

- Write lambdas with value, reference, and explicit captures.
- Compare function pointers, function objects, generic callables, and `std::function`.
- Reason about callback ownership and captured-object lifetime.

### Goal

Register, remove, and invoke multiple callbacks for named events.

### Requirements

- Return a subscription token from registration.
- Define removal during dispatch.
- Prevent callbacks from silently capturing short-lived references.
- Use `std::function` deliberately and document its type-erasure cost.

### Acceptance Criteria

- [ ] Multiple callbacks execute in a defined order.
- [ ] Unsubscription and mutation during dispatch are tested.
- [ ] At least one test demonstrates and then fixes a capture-lifetime defect.

### Stretch Goal

Add event priorities without invalidating active iteration.

---

## 21. Student Grade Analyzer

**Prerequisites:** Projects 18-20.

**Difficulty:** 3/5

**Estimated time:** 7-9 hours

**CMake stage:** Add table-driven algorithm tests.

### Learning Outcomes

- Use `sort`, `find_if`, `count_if`, `transform`, and numeric algorithms.
- Write predicates and comparators with lambdas.
- Prefer algorithms when they express intent more clearly than manual loops.

### Goal

Compute averages, ranking, failed students, highest grades, and the top ten.

### Requirements

- Keep input order unchanged unless mutation is explicitly intended.
- Define tie handling and empty-input behavior.
- Use a stable sort when equal grades must preserve original order.
- Parse CSV only in an adapter outside the analysis logic.

### Acceptance Criteria

- [ ] Empty, singleton, tied, and invalid-grade cases are tested.
- [ ] Comparator requirements are satisfied.
- [ ] Each algorithm use is clearer than the equivalent manual loop.

### Stretch Goal

Add grouped statistics by course using associative containers.

---

## 22. Data Processing with Ranges

**Prerequisites:** Project 21.

**Difficulty:** 3.5/5

**Estimated time:** 7-10 hours

**CMake stage:** Compile classic-algorithm and ranges implementations in the same test suite.

### Learning Outcomes

- Compose range algorithms and lazy views.
- Distinguish views from owning containers.
- Avoid dangling views and reason about borrowed ranges.

### Goal

Process users containing name, score, and active state.

### Requirements

Perform operations in a data-preserving order:

1. filter active user records;
2. sort or partially select records by score;
3. take the top ten records;
4. transform the selected records into names.

- Implement classic-algorithm and ranges versions.
- Do not transform records into names before score-based ordering.
- Materialize a container where an owning result is required.

### Acceptance Criteria

- [ ] Both implementations return equivalent results.
- [ ] No returned view refers to a destroyed temporary.
- [ ] Tests cover fewer than ten, exactly ten, ties, and no active users.

### Stretch Goal

Use applicable C++23 range additions when the toolchain supports them and guard
them with feature-test macros.

---

## 23. Directory Analyzer

**Prerequisites:** Projects 18-22 and Project 17 error-policy work.

**Difficulty:** 3.5/5

**Estimated time:** 8-12 hours

**CMake stage:** Separate filesystem traversal from report generation.

### Learning Outcomes

- Use `std::filesystem::path` and directory iteration.
- Handle filesystem errors with exceptions or `std::error_code`.
- Treat destructive operations as a separate, explicit capability.

### Goal

Report largest files, empty files, duplicate names, and files grouped by extension.

### Requirements

- Accept a path argument.
- Define behavior for permissions, missing paths, and symlinks.
- Keep traversal results independent from presentation.
- Do not delete files in the baseline project.

### Acceptance Criteria

- [ ] Tests use temporary directories and clean them through RAII.
- [ ] Symlink and permission policy is documented.
- [ ] Errors identify the affected path and operation.

### Stretch Goal

Add a dry-run cleanup plan, then require explicit confirmation before deletion.

---

## 24. C++23 Table Printer

**Prerequisites:** Projects 18-23.

**Difficulty:** 3/5

**Estimated time:** 6-8 hours

**CMake stage:** Add compile-time feature checks for library support.

### Learning Outcomes

- Use `std::format` and `std::print` where available.
- Control alignment, width, and numeric precision.
- Define scope limits for terminal and Unicode behavior.

### Goal

Render aligned text, numeric, and Markdown tables.

### Requirements

- Auto-size columns from provided cell text.
- Align text and numbers differently.
- Keep rendering separate from output destination.
- Provide a documented fallback when `std::print` is unavailable.
- Treat terminal display width for complex Unicode as out of scope unless implemented deliberately.

### Acceptance Criteria

- [ ] Empty tables, long cells, negative values, and precision are tested.
- [ ] The fallback produces equivalent content.
- [ ] Feature detection does not rely on compiler version guesses alone.

### Stretch Goal

Add a custom formatter for one project value type.

---

## 25. Testable Pomodoro Timer

**Prerequisites:** Projects 18-24.

**Difficulty:** 3.5/5

**Estimated time:** 7-10 hours

**CMake stage:** Add unit tests with a fake clock and one real-time integration test.

### Learning Outcomes

- Use clocks, durations, time points, and sleeping.
- Select a monotonic clock for elapsed-time measurement.
- Isolate time dependencies so logic can be tested without waiting.

### Goal

Run work, short-break, and long-break cycles while recording session history.

### Requirements

- Use `std::chrono::steady_clock` for elapsed intervals.
- Inject clock/sleep behavior into scheduling logic.
- Support accelerated or fake time in tests.
- Write session timestamps separately from elapsed-time calculations.

### Acceptance Criteria

- [ ] Unit tests complete without real multi-minute sleeps.
- [ ] Four-cycle long-break behavior is tested.
- [ ] Wall-clock changes cannot corrupt elapsed-time calculations.

### Stretch Goal

Persist session history and analyze it using the ranges pipeline.
