# Phase 2 - Classes, Lifetime, Ownership, and Errors

This phase develops the object model required for safe modern C++. Manual resource
management appears only in isolated teaching labs; production code should prefer
standard-library owners and the Rule of Zero.

Read Concept Briefs 7-10 before and during this phase.

Focus on:

- classes, invariants, constructors, destructors, and special-member generation;
- scope, storage duration, object lifetime, and non-owning views;
- exceptions, `std::optional`, `std::expected`, `std::error_code`, and guarantees;
- RAII and explicit ownership;
- copy and move semantics, value categories, copy elision, and `noexcept`;
- values, stable IDs, and deliberate smart-pointer selection.

## 15. Class and Special-Member Mechanics

**Category:** Core lab

**Prerequisites:** Competencies F2-F4 from
[diagnostic-placement.md](diagnostic-placement.md) and
[Concept Brief 7](concept-briefs.md#7-classes-invariants-and-special-members).

**Difficulty:** 3/5

**Estimated time:** 3-4 hours

**Tooling stage:** Use the Phase 1 test framework and formatter.

### Learning Outcomes

- Define a class with an invariant, constructor, and const observers.
- Predict member initialization and destruction order.
- Explain compiler generation, suppression, `=default`, and `=delete`.

### Goal

Build a small bounded counter and an instrumented `Trace` type used by later labs.

### Requirements

- Keep the bounded counter's value inside a documented range.
- Initialize members in declaration-aware order.
- Add const observers and controlled mutating operations.
- Demonstrate defaulted copy behavior and one deliberately deleted operation.
- Record which special members the compiler generates in each experiment.

### Acceptance Criteria

- [ ] Public operations cannot bypass the invariant.
- [ ] Construction and destruction order predictions match observed output.
- [ ] The learner explains why declaring a destructor can affect move generation.

### Stretch Goal

Use type traits to inspect copy and move capabilities; consult the facility inventory
for the required trait scope.

---

## 16. Lifetime and Storage Visualizer

**Category:** Core lab

**Prerequisites:** Project 15 and [Concept Brief 8](concept-briefs.md#8-storage-duration-and-lifetime).

**Difficulty:** 3/5

**Estimated time:** 3-5 hours

**Tooling stage:** Add isolated sanitizer executables for invalid examples.

### Learning Outcomes

- Distinguish scope, storage duration, and lifetime.
- Identify automatic, static, thread-local, and dynamic storage.
- Detect dangling pointers, references, iterators, spans, and string views.

### Goal

Use the Project 15 `Trace` type to predict and observe object creation and destruction.

### Requirements

- Demonstrate all four storage-duration categories.
- Observe nested-block destruction order and temporary lifetime.
- Demonstrate one valid reference lifetime extension.
- Compare it with a string view that does not extend lifetime.
- Keep every dangling access disabled or in a separate ASan/UBSan executable.

### Acceptance Criteria

- [ ] The normal suite executes no undefined behavior.
- [ ] Each experiment includes a prediction before output.
- [ ] Leaks and dangling observers are explained as different defects.

### Stretch Goal

Observe thread-local construction and destruction in one short-lived `std::jthread`
using the [supplied example](projects/16-lifetime-storage-visualizer/README.md);
concurrency is not yet the learning objective.

---

## 17. Bank Account Simulator

**Category:** Portfolio project

**Prerequisites:** Projects 15-16.

**Difficulty:** 3/5

**Estimated time:** 7-10 hours

**Tooling stage:** Build model, app, and test targets; test without terminal I/O.

### Learning Outcomes

- Protect invariants through encapsulation.
- Use constructors, initializer lists, and const member functions.
- Distinguish a passive record from an invariant-protecting class.

### Goal

Implement accounts and transactions without permitting an invalid monetary state.

### Requirements

- Store money as integer minor units and include an explicit currency value.
- Restrict the baseline to one currency per account and reject mixed transfers.
- Validate deposits, withdrawals, and transfers.
- Return a simple status enum from operations; Project 18 will compare richer policies.
- Keep transaction history in a separate value-type struct.
- Mark important ignored results `[[nodiscard]]`.

### Acceptance Criteria

- [ ] Failed operations preserve account invariants.
- [ ] No public data member bypasses validation.
- [ ] Const account references inspect but cannot mutate state.

### Stretch Goal

Introduce a strongly typed `Money` value without permitting implicit currency mixing.

---

## 18. Error-Handling Policy Lab

**Category:** Core lab

**Prerequisites:** Projects 15-17 and [Concept Brief 9](concept-briefs.md#9-errors-exceptions-and-guarantees).

**Difficulty:** 3.5/5

**Estimated time:** 4-6 hours

**Tooling stage:** Add table-driven failure tests.

### Learning Outcomes

- Use preconditions, `optional`, `expected`, exceptions, and `error_code`.
- Explain `throw`, stack unwinding, `try`, `catch`, and destructor rules.
- State no-throw, strong, and basic exception guarantees.

### Goal

Implement the same small lookup/load operation with several error policies and
compare the resulting interfaces.

### Requirements

- Use `optional` for expected absence without diagnostic detail.
- Use `expected` for a typed recoverable failure.
- Implement one throwing adapter and catch only where recovery is meaningful.
- Implement one non-throwing filesystem or system-style operation with `error_code`.
- Demonstrate stack unwinding with an RAII tracer.
- Ensure destructors do not propagate exceptions.

### Acceptance Criteria

- [ ] Each policy has a stated caller responsibility.
- [ ] Tests cover success, absence, malformed input, and thrown failure.
- [ ] Exception guarantees refer to observable state.

### Stretch Goal

Refactor Bank Account operation statuses into a typed `expected` error.

---

## 19. RAII File Wrapper

**Category:** Core project

**Prerequisites:** Projects 15-18 and [Concept Brief 10](concept-briefs.md#10-raii-copy-move-and-ownership).

**Difficulty:** 3.5/5

**Estimated time:** 5-7 hours

**Tooling stage:** Add platform guards only if a native handle is used.

### Learning Outcomes

- Tie resource acquisition and release to object lifetime.
- Design an exclusive owner and delete copying explicitly.
- Apply stack unwinding and exception guarantees to resource cleanup.

### Goal

Wrap either a C `FILE*` or a platform-neutral temporary-file abstraction. State the
selected resource model explicitly.

### Requirements

- Acquire in a constructor or named factory.
- Release in a non-throwing destructor.
- Provide an explicit idempotent `close()` or `finish()` operation that reports
  finalization failure; the destructor performs only no-throw fallback cleanup.
- Delete copy construction and copy assignment.
- Return `expected` from a factory or throw from construction; document the choice.
- Prove cleanup after a later operation fails.
- Inject or fake one close failure so it can be tested portably.

### Acceptance Criteria

- [ ] Missing file, successful use, and cleanup-after-failure are tested.
- [ ] Explicit close success and failure are tested without relying on a destructor
      to report the error.
- [ ] Operations after a successful or failed close follow a documented state policy.
- [ ] The wrapper cannot be copied accidentally.
- [ ] Public failure behavior matches the implementation.

### Stretch Goal

Add move operations after writing their post-move invariant.

---

## 20. Ownership Mechanics Diagnosis and Rule-of-Zero Refactor

**Category:** Core lab

**Prerequisites:** Competencies O1-O2 from
[diagnostic-placement.md](diagnostic-placement.md) and Projects 15-19.

**Difficulty:** 4/5

**Estimated time:** 8-12 hours

**Tooling stage:** Diagnose the
[provided broken owner](projects/20-ownership-mechanics/README.md) under ASan/UBSan,
allocation-failure injection, and relocation tests.

### Learning Outcomes

- Distinguish allocation, construction, destruction, and deallocation.
- Diagnose leak, double-delete, shallow-copy, use-after-free, and
  partial-construction hazards.
- Implement deep copy, strong copy assignment, and exception-safe moves.
- Explain value categories, copy elision, `std::move`, and conditional `noexcept`.
- Prefer the Rule of Zero after understanding the manual mechanics.

### Goal

Repair one deliberately broken buffer, add copy and move behavior, observe container
relocation, and replace the manual owner in the final client with
`std::vector<std::byte>`.

### Requirements

- Use `new[]` and `delete[]` only inside this sequence.
- Track pointer, size, and initialized-element invariants.
- Keep defect demonstrations in isolated sanitizer executables.
- Implement destruction, deep copy, and strongly safe copy assignment.
- Use copy-and-swap or an equivalent strongly safe assignment.
- Use the [allocation failpoint](support/allocation-failure/README.md) for failure
  tests.
- Instrument copy and move operations.
- Mark moves `noexcept` only when guaranteed.
- Compare vector relocation with throwing and non-throwing move declarations.
- Demonstrate guaranteed copy elision without forcing a move.
- Finish with a client type that defines no unnecessary special members.
- Expose read-only bytes through `span<const std::byte>`.

### Acceptance Criteria

- [ ] Normal tests leak no memory and execute no invalid access.
- [ ] Copies own independent buffers and failed allocation preserves the target.
- [ ] Moved-from objects remain valid and destructible.
- [ ] `std::move` is explained as a cast.
- [ ] The final production-style type follows the Rule of Zero.

### Stretch Goal

Compare the teaching buffer with `std::unique_ptr<T[]>` and explain why `vector`
still provides the better default sequence abstraction.

---

## 23. Dungeon Ownership Graph

**Category:** Core project

**Prerequisites:** Project 20 and competency O3.

**Difficulty:** 4/5

**Estimated time:** 8-12 hours

**Tooling stage:** Add ownership and invalidation tests under sanitizers.

### Learning Outcomes

- Choose among values, stable IDs, `unique_ptr`, `shared_ptr`, and `weak_ptr`.
- Separate owning edges from navigation edges.
- Define removal and stale-link behavior.

### Goal

Model rooms, exits, and player navigation without ownership cycles.

### Requirements

- Implement the baseline with one owning collection and stable room IDs.
- Define whether removed IDs become invalid, tombstoned, or reusable.
- Implement a comparison version with `unique_ptr` owners and non-owning links.
- Use `shared_ptr`/`weak_ptr` only in a small comparison.
- Detect stale navigation rather than exposing a silently dangling link.

### Acceptance Criteria

- [ ] Every edge is classified as owning or non-owning.
- [ ] Removing a room has explicit observable behavior.
- [ ] The report explains why shared ownership is not the default.

### Stretch Goal

Serialize stable IDs without serializing memory addresses.

---

## 24. Config Parser and Error Policy

**Category:** Core project

**Prerequisites:** Projects 15-20 and 23, plus competencies F3 and O1-O3.

**Difficulty:** 4/5

**Estimated time:** 12-18 hours

**Tooling stage:** Separate parser, file adapter, CLI, and tests; add `clang-tidy`
or an equivalent analyzer and a basic multi-compiler CI job.

### Learning Outcomes

- Parse typed values from non-owning text input.
- Model optional values, recoverable errors, and exception adapters.
- Use `std::variant` and visitation for a closed set of configuration values.
- State and test a strong parse-result guarantee.

### Goal

Parse:

```txt
username=nyx
volume=80
fullscreen=true
```

into a validated configuration.

### Requirements

- Return `std::expected<Config, ParseErrors>` from the primary parser.
- Use `optional` only for genuinely optional settings.
- Parse numeric text with `from_chars`.
- Store heterogeneous typed values with `variant` where it improves the model.
- Report line numbers and multiple malformed entries.
- Keep file reading separate from in-memory parsing.
- Add one exception-based adapter and one `error_code` filesystem adapter.

### Acceptance Criteria

- [ ] Valid, missing, malformed, duplicate, partial, and out-of-range values are tested.
- [ ] Failure never exposes a partially usable `Config`.
- [ ] The README compares preconditions, optional, expected, exceptions, and error codes.
- [ ] The in-memory parser is suitable for later fuzzing.
- [ ] Formatter, analyzer, sanitizer, and CI checks pass.

### Stretch Goal

Add versioned persistence to the Todo List through this parser rather than ad hoc text handling.

---

## Phase 2 Transfer Gate

Complete R15 and revision M2, submit the phase evidence, and pass the
[Phase 2 unseen lifetime/error diagnosis](assessment-and-retention.md#phase-2-transfer)
at 12/15 or better. A failed transfer follows the documented remediation and uses a
new variant.
