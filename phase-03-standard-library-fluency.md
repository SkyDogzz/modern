# Phase 3 - Standard Library and Data Processing

This phase teaches deliberate selection and composition of standard-library tools.
The goal is fluency and defensible tradeoffs, not memorization.

Read Concept Briefs 11-14 before and during this phase.

Focus on:

- sequence and associative containers;
- complexity, layout, iterator categories, sentinels, and invalidation;
- lambdas, function objects, callbacks, and lifetime;
- algorithms, projections, ranges, views, and materialization;
- filesystem, formatting, printing, and chrono;
- testable adapters around operating-system effects.

## 25. Contact Book and Container Selection

**Category:** Portfolio project

**Prerequisites:** Phases 1-2 and [Concept Brief 11](concept-briefs.md#11-containers-iterators-and-algorithms).

**Difficulty:** 3/5

**Estimated time:** 8-12 hours

**Tooling stage:** Build a reusable contact library and thin CLI.

### Learning Outcomes

- Select containers from required operations and invalidation rules.
- Compare vector, ordered-map, unordered-map, and set use cases.
- Distinguish average from worst-case complexity and simple timing from benchmarking.

### Goal

Manage contacts with names, email addresses, phone numbers, and unique tags.

### Requirements

- Write an operation table before choosing containers.
- Implement a vector baseline.
- Add one indexed implementation using `unordered_map`.
- Use `set` only for uniqueness and `map` for one genuinely ordered report.
- Use structured bindings where they improve readability.
- Collect simple Release-build lookup timings but make no rigorous performance claim.
- Document iterator and reference invalidation for each selected container.

### Acceptance Criteria

- [ ] Duplicate identity and missing-contact behavior are explicit.
- [ ] Every container has a workload-based reason.
- [ ] Timing observations are labeled exploratory, not a benchmark conclusion.

### Stretch Goal

Evaluate `std::flat_map` when the standard library supports it.

---

## 26. Playlist Iterator Lab

**Category:** Core lab

**Prerequisites:** Project 25 and [Concept Brief 11](concept-briefs.md#11-containers-iterators-and-algorithms).

**Difficulty:** 3/5

**Estimated time:** 6-8 hours

**Tooling stage:** Add focused invalidation tests.

### Learning Outcomes

- Use iterator operations and identify iterator categories.
- Recognize invalidation after insertion, erasure, and reallocation.
- Compare contiguous and node-based mutation without assuming one is superior.

### Goal

Implement next, previous, insert, remove-current, and shuffle behavior.

### Requirements

- Build a vector version first.
- Name the iterator category required by each operation.
- Never use an iterator after an invalidating operation.
- Rebuild the mutation experiment with `list`.
- Define empty, first, last, and removal-of-current behavior.

### Acceptance Criteria

- [ ] Boundary and invalidation states are tested.
- [ ] The learner states the relevant invalidation rules.
- [ ] The list version is not called faster without workload evidence.

### Stretch Goal

Add a deque comparison focused only on its invalidation rules.

---

## 27. Event Dispatcher and Callable Objects

**Category:** Core project

**Prerequisites:** Projects 25-26, Phase 2 lifetime rules, and
[Concept Brief 12](concept-briefs.md#12-lambdas-callables-and-callback-lifetime).

**Difficulty:** 4/5

**Estimated time:** 10-14 hours

**Tooling stage:** Test the dispatcher as a library without CLI dependencies.

### Learning Outcomes

- Write lambdas with value, reference, and explicit captures.
- Compare function pointers, function objects, generic callables, and `std::function`.
- Define callback ownership, reentrancy, and mutation-during-dispatch policy.

### Goal

Register, remove, and invoke callbacks for named events.

### Requirements

- Return a subscription token from registration.
- Choose and document immediate, deferred, or forbidden mutation during dispatch.
- Prevent callbacks from silently retaining short-lived reference captures.
- Use `std::function` deliberately and document possible allocation/indirection.
- Never invoke unknown callback code while an internal mutex is held; the baseline
  itself remains single-threaded.

### Acceptance Criteria

- [ ] Callback order and reentrancy behavior are defined.
- [ ] Unsubscription and attempted mutation during dispatch are tested.
- [ ] A test demonstrates and fixes one capture-lifetime defect.

### Stretch Goal

Make subscription lifetime RAII-based.

---

## 28. Student Grade Analyzer

**Category:** Portfolio project

**Prerequisites:** Projects 25-27.

**Difficulty:** 3/5

**Estimated time:** 8-11 hours

**Tooling stage:** Add table-driven algorithm tests.

### Learning Outcomes

- Use sorting, search, counting, transformation, and numeric algorithms.
- Write valid predicates, comparators, and projections.
- Prefer algorithms when they state intent more clearly than loops.

### Goal

Compute averages, ranking, failures, highest grades, grouped results, and top ten.

### Requirements

- Keep input order unchanged unless mutation is explicit.
- Define tie and empty-input behavior.
- Use stable sorting where equal grades preserve original order.
- Use a projection or projected comparison for one record field.
- Parse CSV only in an adapter outside analysis logic.

### Acceptance Criteria

- [ ] Empty, singleton, tied, invalid, and boundary grades are tested.
- [ ] Every comparator satisfies strict weak ordering.
- [ ] Integer and floating average semantics are explicit.

### Stretch Goal

Use a standard container adaptor for one naturally stack-, queue-, or priority-based task.

---

## 29. Range, View, and Sentinel Lab

**Category:** Core lab

**Prerequisites:** Projects 25-28 and [Concept Brief 13](concept-briefs.md#13-ranges-and-views).

**Difficulty:** 3.5/5

**Estimated time:** 6-9 hours

**Tooling stage:** Keep dangling demonstrations isolated under sanitizers.

### Learning Outcomes

- Explain ranges, iterators, sentinels, views, and borrowed ranges.
- Compose lazy adaptors without confusing a view with an owner.
- Decide when to materialize.

### Goal

Build small pipelines over owned arrays, vectors, strings, and temporary ranges.

### Requirements

- Implement one iterator/sentinel loop.
- Build filter and transform views over a persistent owner.
- Materialize one pipeline into a vector.
- Demonstrate a safe borrowed-range case without claiming universal lifetime.
- Keep one dangling-view example disabled or isolated.

### Acceptance Criteria

- [ ] Every view names the storage that owns its elements.
- [ ] Returned results do not refer to destroyed temporaries.
- [ ] The learner explains exactly what borrowed-range status guarantees.

### Stretch Goal

Write a small view-returning function with a documented lifetime contract.

---

## 30. Data Processing with Ranges

**Category:** Portfolio project

**Prerequisites:** Project 29.

**Difficulty:** 3.5/5

**Estimated time:** 8-12 hours

**Tooling stage:** Compile classic-algorithm and ranges implementations in one suite.

### Learning Outcomes

- Compose range algorithms and lazy views.
- Preserve source data by materializing before mutation.
- Compare classic and ranges interfaces on the same behavior.

### Goal

Process users containing name, score, and active state.

### Requirements

Use this order:

1. filter active records;
2. materialize selected records into an owning container;
3. sort or partially select by score;
4. take the top ten;
5. transform selected records into names.

- Implement classic-algorithm and ranges versions.
- Keep the original user collection unchanged.
- Use a projection where supported and clearer.

### Acceptance Criteria

- [ ] Both implementations return equivalent results.
- [ ] The source collection remains unchanged.
- [ ] Tests cover fewer than ten, exactly ten, ties, and no active users.

### Stretch Goal

Use applicable C++23 range additions behind feature-test macros.

---

## 31. Directory Analyzer

**Category:** Track project

**Prerequisites:** Project 30, Project 24 error policy, and
[Concept Brief 14](concept-briefs.md#14-filesystem-formatting-and-chrono).

**Difficulty:** 3.5/5

**Estimated time:** 7-11 hours

**Tooling stage:** Separate traversal from report generation.

### Learning Outcomes

- Use `filesystem::path`, directory iteration, and temporary directories.
- Handle errors with exceptions or `error_code`.
- Define recursion, permission, and symlink policy.

### Goal

Report largest files, empty files, duplicate names, and files grouped by extension.

### Requirements

- Accept a path argument and preserve path values as paths.
- State whether traversal is recursive.
- Define missing-path, permission, changing-file, and symlink behavior.
- Keep traversal results independent from presentation.
- Do not delete files in the baseline.

### Acceptance Criteria

- [ ] Tests use RAII-managed temporary directories.
- [ ] Errors identify path and operation.
- [ ] Symlink cycles cannot cause unbounded traversal.

### Stretch Goal

Add a dry-run cleanup plan with explicit confirmation separated from analysis.

---

## 32. C++23 Table Printer

**Category:** Track project

**Prerequisites:** Project 30 and [Concept Brief 14](concept-briefs.md#14-filesystem-formatting-and-chrono).

**Difficulty:** 3/5

**Estimated time:** 6-9 hours

**Tooling stage:** Add compile-time feature checks for library support.

### Learning Outcomes

- Use `std::format` and `std::print` where available.
- Control alignment, width, and precision.
- Distinguish byte length from terminal display width.

### Goal

Render aligned text, numeric, and Markdown tables.

### Requirements

- Auto-size ASCII columns from cell text.
- Align text and numeric values differently.
- Keep rendering separate from output destination.
- Provide a documented fallback when `std::print` is unavailable.
- Declare complex Unicode terminal width out of scope.

### Acceptance Criteria

- [ ] Empty tables, long cells, negative values, and precision are tested.
- [ ] Fallback output is content-equivalent.
- [ ] Feature detection uses feature-test macros or compile checks, not version guesses.

### Stretch Goal

Add a custom formatter for the Phase 4 `Vector2` type after Project 34.

---

## 33. Testable Pomodoro Timer

**Category:** Track project

**Prerequisites:** Project 30 and [Concept Brief 14](concept-briefs.md#14-filesystem-formatting-and-chrono).

**Difficulty:** 3.5/5

**Estimated time:** 7-10 hours

**Tooling stage:** Add fake-clock unit tests and one real-time integration test.

### Learning Outcomes

- Use durations, time points, monotonic clocks, and sleeping.
- Separate elapsed time from wall-clock timestamps.
- Inject time dependencies for fast tests.

### Goal

Run work, short-break, and long-break cycles and record session history.

### Requirements

- Use `steady_clock` for elapsed intervals.
- Use a wall clock only for recorded timestamps.
- Inject clock and sleep behavior through a small explicit interface.
- Support accelerated or fake time in unit tests.

### Acceptance Criteria

- [ ] Unit tests perform no real multi-minute sleeps.
- [ ] Four-cycle long-break behavior is tested.
- [ ] Wall-clock changes cannot corrupt elapsed-time calculations.

### Stretch Goal

Persist history and analyze it with the Project 30 ranges pipeline.
