# Phase 4 - Generic Programming and Design

This phase teaches C++ abstraction mechanisms and the tradeoffs between them.
Inheritance is not presented as the default form of reuse.

Focus on:

- regular value types and operator overloading;
- composition, variants, inheritance, and runtime polymorphism;
- function and class templates;
- the template compilation model;
- constexpr evaluation, concepts, and constraints;
- customization protocols, advanced templates, and type erasure.

## 26. Vector2 Value Type

**Prerequisites:** Phases 1-3.

**Difficulty:** 3/5

**Estimated time:** 6-9 hours

**CMake stage:** Build and test a small reusable library target.

### Learning Outcomes

- Design a regular value type with predictable copy and comparison behavior.
- Choose member versus non-member operator overloads.
- Preserve mathematical and API invariants.

### Goal

Implement vector addition, subtraction, scalar multiplication, equality, output,
length, normalization, and dot product.

### Requirements

- Use symmetric non-member operators where implicit conversion symmetry matters.
- Define zero-vector normalization behavior.
- Do not use exact equality as an approximate floating-point comparison.
- Add a custom formatter or stream output operator.
- Mark non-mutating operations const.

### Acceptance Criteria

- [ ] Algebraic properties are tested within appropriate tolerance.
- [ ] Invalid normalization behavior is explicit.
- [ ] Operators do not produce surprising hidden mutation.

### Stretch Goal

Generalize dimensions after completing the basic template project.

---

## 27. Shape Design Comparison

**Prerequisites:** Project 26 and Phase 2 ownership.

**Difficulty:** 4/5

**Estimated time:** 10-14 hours

**CMake stage:** Build separate implementations behind one test contract.

### Learning Outcomes

- Compare composition, `std::variant`, and virtual polymorphism.
- Use abstract interfaces and virtual destructors safely.
- Recognize when closed and open sets of alternatives favor different designs.

### Goal

Implement area, perimeter, and rendering for circles, rectangles, and triangles
using two designs:

1. value types stored in `std::variant`;
2. polymorphic objects stored in `std::unique_ptr<Shape>`.

### Requirements

- Keep common rendering policy separate from geometric data where practical.
- Give the polymorphic base a virtual destructor.
- Avoid shared ownership.
- Add one operation and one new shape to each design, then compare the edits required.
- Document why composition is the baseline recommendation for reuse.

### Acceptance Criteria

- [ ] Both designs satisfy the same behavioral tests.
- [ ] No derived object is deleted through a non-virtual base destructor.
- [ ] The design report identifies open/closed operation and type tradeoffs.

### Stretch Goal

Add a component-based renderer that contains a shape value instead of inheriting.

---

## 28. Generic Stack

**Prerequisites:** Projects 26-27.

**Difficulty:** 3.5/5

**Estimated time:** 7-10 hours

**CMake stage:** Use an `INTERFACE` target for a header-only template library.

### Learning Outcomes

- Write function and class templates.
- Explain template instantiation and why definitions are usually visible in headers.
- State type requirements before formalizing them as concepts.

### Goal

Implement `Stack<int>`, `Stack<std::string>`, and `Stack<Player>`.

### Requirements

- Support push, emplace, pop, top, empty, and size.
- Define empty-pop behavior with `std::expected`, `std::optional`, or a documented precondition.
- Support const and non-const access.
- Test move-only element types.
- Explain any forwarding reference used by `emplace`.

### Acceptance Criteria

- [ ] The stack works with copyable and move-only types.
- [ ] Template definitions do not create linker errors.
- [ ] Empty access behavior is explicit and tested.

### Stretch Goal

Expose iterator support by delegating to the underlying container.

---

## 29. Compile-Time Math and Validation

**Prerequisites:** Project 28.

**Difficulty:** 3.5/5

**Estimated time:** 6-8 hours

**CMake stage:** Add compile-time tests through `static_assert`.

### Learning Outcomes

- Use `constexpr`, `consteval`, and `static_assert`.
- Distinguish a function that can run at compile time from one that must.
- Avoid compile-time work without a practical reason.

### Goal

Implement checked power, greatest common divisor, primality, and lookup-table generation.

### Requirements

- Validate important results with `static_assert`.
- Use an iterative implementation where recursion adds no teaching value.
- Reject invalid compile-time inputs clearly.
- Include one runtime call to a `constexpr` function.

### Acceptance Criteria

- [ ] Compile-time and runtime behavior are both demonstrated.
- [ ] Failure diagnostics identify the violated requirement.
- [ ] The README explains why recursive Fibonacci is not a useful benchmark.

### Stretch Goal

Create a compile-time validated fixed-size unit-conversion table.

---

## 30. Constrained Generic Algorithms

**Prerequisites:** Projects 28-29 and Phase 3 ranges.

**Difficulty:** 4/5

**Estimated time:** 8-11 hours

**CMake stage:** Add compile-fail examples outside the normal passing test suite.

### Learning Outcomes

- Use standard concepts, `requires` clauses, and constrained overloads.
- Express range, value, and operation requirements.
- Compare unconstrained and constrained diagnostics.

### Goal

Implement average, maximum value, and print-all algorithms for suitable ranges.

### Requirements

- Build constraints from standard concepts such as ranges and arithmetic requirements.
- Avoid a vague custom "container-like" concept.
- Define behavior for empty ranges.
- Ensure invalid calls fail during overload resolution with useful diagnostics.

### Acceptance Criteria

- [ ] Valid contiguous and non-contiguous ranges are tested.
- [ ] Invalid element types are demonstrated in compile-fail examples.
- [ ] Constraints express actual implementation needs, not incidental properties.

### Stretch Goal

Provide a projection parameter similar to standard ranges algorithms.

---

## 31. Serialization Customization Library

**Prerequisites:** Projects 28-30 and Project 17 error handling.

**Difficulty:** 4.5/5

**Estimated time:** 12-16 hours

**CMake stage:** Separate public customization API from format implementation.

### Learning Outcomes

- Use variadic templates, type traits, `if constexpr`, and constrained overloads.
- Design an explicit customization protocol without assuming language reflection.
- Preserve useful parse and serialization errors.

### Goal

Serialize primitive values, strings, ranges, and explicitly opted-in structs to
a readable text format.

### Requirements

- Require user types to provide a named customization function or descriptor.
- Do not claim arbitrary struct serialization.
- Support escaped strings and nested sequences.
- Return `std::expected` for deserialization failures.
- Use forwarding references only when value category preservation is required.

### Acceptance Criteria

- [ ] Unsupported types fail with a readable compile-time diagnostic.
- [ ] Round-trip tests cover all supported categories.
- [ ] Malformed input reports location and cause.
- [ ] The customization boundary is documented as public API.

### Stretch Goal

Add version tags and backward-compatible field defaults.

---

## 32. Type-Erased Command System

**Prerequisites:** Projects 20 and 27-31.

**Difficulty:** 4.5/5

**Estimated time:** 10-14 hours

**CMake stage:** Expose the command abstraction as a library API.

### Learning Outcomes

- Compare inheritance, templates, variants, and type erasure.
- Build a value-semantics wrapper around heterogeneous behavior.
- Identify API-boundary and allocation tradeoffs.

### Goal

Store and execute heterogeneous commands through one `Command` value type.

### Requirements

- Implement an inheritance version first.
- Implement a type-erased value wrapper second.
- Define copyability, movability, and empty-state behavior.
- Add commands dynamically at runtime.
- Do not call the project a plugin system unless it loads external modules.

### Acceptance Criteria

- [ ] Both implementations satisfy the same command tests.
- [ ] Ownership and allocation behavior are documented.
- [ ] The report identifies when a simple callable or variant is sufficient.

### Stretch Goal

Add a separately scoped dynamic-library experiment and document its ABI and
platform constraints.
