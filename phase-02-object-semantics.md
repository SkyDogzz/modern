# Phase 2 - Object Semantics, Lifetime, and Ownership

This phase develops the object model required for safe modern C++. Its manual
resource-management projects are teaching labs; production code should prefer
standard-library owners and the Rule of Zero.

Focus on:

- storage duration, scope, and object lifetime;
- classes, invariants, constructors, destructors, and const member functions;
- RAII and explicit ownership;
- copy and move semantics, value categories, copy elision, and `noexcept`;
- the Rule of Zero, Rule of Three, and Rule of Five;
- `std::optional`, `std::expected`, exceptions, and exception guarantees.

## 11. Lifetime and Storage Visualizer

**Prerequisites:** Phase 1.

**Difficulty:** 3/5

**Estimated time:** 5-7 hours

**CMake stage:** Add sanitizer presets and keep unsafe demonstrations in isolated tests.

### Learning Outcomes

- Distinguish scope, storage duration, and lifetime.
- Identify automatic, static, thread, and dynamic storage duration.
- Detect dangling pointers, references, iterators, and views.

### Goal

Build small experiments whose constructors and destructors log object creation,
movement, and destruction.

### Requirements

- Demonstrate automatic, static, thread-local, and dynamic storage.
- Observe nested-scope destruction order and temporary lifetime.
- Demonstrate safe lifetime extension of a temporary.
- Put intentional dangling examples behind disabled tests or separate executables.
- Diagnose invalid access with AddressSanitizer or UndefinedBehaviorSanitizer.

### Acceptance Criteria

- [ ] The normal test suite contains no executed undefined behavior.
- [ ] Each experiment predicts destruction order before it is run.
- [ ] The learner can distinguish a dangling pointer from a memory leak.

### Stretch Goal

Add a `std::string_view` example that becomes invalid and explain why.

---

## 12. Bank Account Simulator

**Prerequisites:** Project 11 and Phase 1 structs, functions, and const.

**Difficulty:** 3/5

**Estimated time:** 6-9 hours

**CMake stage:** Build model and application targets; test the model without terminal I/O.

### Learning Outcomes

- Design a class that protects invariants through encapsulation.
- Use constructors, member initializer lists, and const member functions.
- Distinguish a passive aggregate `struct` from an invariant-protecting `class`.

### Goal

Implement accounts and transactions without permitting an invalid balance or
invalid monetary operation.

### Requirements

- Store money as integer minor units, not binary floating point.
- Validate construction, deposits, withdrawals, and transfers.
- Expose read-only state through const member functions.
- Keep transaction history in a separate value-type struct.
- Mark important ignored results `[[nodiscard]]`.

### Acceptance Criteria

- [ ] Tests prove that failed operations preserve account invariants.
- [ ] No public data member can bypass validation.
- [ ] Const account references can inspect but not mutate state.

### Stretch Goal

Add multiple currencies without silently mixing their values.

---

## 13. RAII File Wrapper

**Prerequisites:** Projects 11-12.

**Difficulty:** 3.5/5

**Estimated time:** 6-8 hours

**CMake stage:** Add platform guards only if a native file handle is used.

### Learning Outcomes

- Tie resource acquisition and release to object lifetime.
- Design an exclusive owner and explicitly delete copying.
- Explain basic, strong, and no-throw exception guarantees.

### Goal

Wrap a file resource that is valid after successful construction and always
released during destruction.

### Requirements

- Acquire the resource in a constructor or named factory.
- Release it in the destructor.
- Delete copy construction and copy assignment.
- Define failure behavior using an exception or `std::expected`.
- Ensure cleanup still occurs during stack unwinding.

### Acceptance Criteria

- [ ] Tests cover missing files, successful writes, and cleanup after failure.
- [ ] The wrapper cannot be accidentally copied.
- [ ] The documented error policy matches the public API.

### Stretch Goal

Add move operations and compare the result with the next project.

---

## 14. Dynamic String Copy Lab

**Prerequisites:** Projects 11-13.

**Difficulty:** 4/5

**Estimated time:** 8-12 hours

**CMake stage:** Run copy tests under AddressSanitizer and leak detection.

### Learning Outcomes

- Implement deep copy and the Rule of Three.
- Recognize self-assignment and partial-construction hazards.
- Provide the strong exception guarantee for copy assignment.

### Goal

Build a deliberately small owning character buffer to understand mechanics that
`std::string` normally handles.

### Requirements

- Implement construction from text, destruction, copy construction, and copy assignment.
- Maintain a null-terminated buffer and size invariant.
- Use copy-and-swap or an equivalent strongly exception-safe assignment.
- Test empty, copied, assigned, and self-assigned objects.
- State explicitly that this is a learning type, not a replacement for `std::string`.

### Acceptance Criteria

- [ ] Copies own independent buffers.
- [ ] Sanitizers report no leaks or invalid accesses.
- [ ] Failed allocation cannot leave the target object corrupted.

### Stretch Goal

Expose a safe `std::string_view` observer whose lifetime constraints are documented.

---

## 15. Movable Buffer and Rule of Zero Refactor

**Prerequisites:** Project 14.

**Difficulty:** 4/5

**Estimated time:** 8-12 hours

**CMake stage:** Add tests that exercise relocation inside `std::vector`.

### Learning Outcomes

- Distinguish lvalues, xvalues, prvalues, and rvalue references.
- Implement move construction and move assignment with valid moved-from states.
- Explain copy elision, `std::move`, and why move operations are often `noexcept`.
- Prefer the Rule of Zero after understanding manual ownership.

### Goal

First add move support to an owning buffer, then refactor a client type to use
`std::vector<std::byte>` and require no custom special member functions.

### Requirements

- Instrument copy and move operations.
- Mark move operations `noexcept` only when the implementation guarantees it.
- Compare vector relocation with and without a `noexcept` move constructor.
- Demonstrate guaranteed copy elision without trying to force a move.
- Build a Rule-of-Zero version using a standard owner.

### Acceptance Criteria

- [ ] Moved-from objects remain valid and destructible.
- [ ] `std::move` is explained as a cast, not a move operation by itself.
- [ ] The final client type has no unnecessary destructor, copy, or move definitions.

### Stretch Goal

Add `std::span<const std::byte>` as a non-owning read-only view.

---

## 16. Dungeon Ownership Graph

**Prerequisites:** Projects 11-15.

**Difficulty:** 4/5

**Estimated time:** 8-10 hours

**CMake stage:** Add ownership-focused tests and sanitizer runs.

### Learning Outcomes

- Choose between values, IDs, `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`.
- Separate ownership edges from non-owning navigation edges.
- Explain why shared ownership is not a default graph representation.

### Goal

Model rooms, exits, and player navigation without ownership cycles.

### Requirements

- Implement the baseline with one owning collection and stable room IDs.
- Implement a second version using `std::unique_ptr` ownership and non-owning links.
- Use `std::shared_ptr`/`std::weak_ptr` only as a comparison.
- Document invalidation behavior when rooms are removed.

### Acceptance Criteria

- [ ] Every edge is classified as owning or non-owning.
- [ ] Removing a room cannot leave silently usable dangling links.
- [ ] The design report explains why the chosen baseline is simpler than shared ownership.

### Stretch Goal

Serialize the graph while preserving stable IDs.

---

## 17. Config Parser and Error Policy

**Prerequisites:** Projects 11-16.

**Difficulty:** 4/5

**Estimated time:** 10-14 hours

**CMake stage:** Separate parser, filesystem adapter, CLI, and test targets.

### Learning Outcomes

- Model absence with `std::optional` and recoverable failure with `std::expected`.
- Use exceptions for failures that cannot be handled locally.
- State and test an exception guarantee.
- Parse and validate typed configuration values.

### Goal

Parse:

```txt
username=nyx
volume=80
fullscreen=true
```

into validated typed values.

### Requirements

- Return `std::expected<Config, ParseErrors>` from the primary parser.
- Use `std::optional` only for genuinely optional values.
- Store typed values with `std::variant` where appropriate.
- Report line numbers and multiple malformed entries.
- Keep file reading separate from text parsing.
- Implement a small exception-based adapter and compare policies.

### Acceptance Criteria

- [ ] Valid, missing, malformed, duplicate, and out-of-range values are tested.
- [ ] Parse failure does not produce a partially usable `Config`.
- [ ] The README explains when `optional`, `expected`, and exceptions are appropriate.
- [ ] The parser is fuzz-ready because it accepts an in-memory text input.

### Stretch Goal

Use the parser to configure the Interactive Todo List persistence format.
