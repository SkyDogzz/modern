# Phase 4 - Generic Programming and Design

This phase teaches C++ abstraction mechanisms and the tradeoffs between them.
Inheritance is not presented as the default form of reuse. Projects 42-43 are
optional specializations.

Read Concept Briefs 15-17 before and during this phase.

Focus on:

- regular value types, comparison, and operator overloading;
- safe runtime polymorphism, composition, variants, and inheritance;
- function and class templates, deduction, forwarding, and dependent names;
- constant evaluation, concepts, and constraints;
- traits, variadics, folds, and named customization protocols;
- optional serialization and manual type-erasure implementations.

## 34. Vector2 Regular Value Type

**Category:** Core project

**Prerequisites:** Competencies O1-O3 and L1-L2 from
[diagnostic-placement.md](diagnostic-placement.md), plus
[Concept Brief 15](concept-briefs.md#15-regular-types-operators-and-polymorphism).

**Difficulty:** 3/5

**Estimated time:** 5-7 hours

**Tooling stage:** Build and test a reusable value-type library.

### Learning Outcomes

- Design a regular value type with predictable copy and comparison behavior.
- Choose member versus non-member operators.
- Distinguish exact structural equality from approximate numeric comparison.

### Goal

Implement vector addition, subtraction, scalar multiplication, equality, output,
length, normalization, dot product, and an approximate-equality operation.

### Requirements

- Use symmetric non-member operators where operand symmetry matters.
- Default exact equality only if member-wise equality matches the value model.
- Provide a named approximate comparison with documented tolerance semantics.
- Define and enforce a finite-component invariant for the baseline type.
- Define zero-vector and non-finite normalization behavior.
- Add stream output or a formatter, depending on Project 32 completion.
- Add a small integral `GridPoint` example using defaulted `==` and `<=>`; explain
  why floating-point ordering can be partial.

### Acceptance Criteria

- [ ] Algebraic properties are tested within appropriate tolerances.
- [ ] Operators do not hide mutation.
- [ ] NaN and infinity policy is explicit.

### Stretch Goal

Generalize dimensions after completing the template-mechanics projects.

---

## 35. Runtime Polymorphism Safety Lab

**Category:** Core lab

**Prerequisites:** Project 34 and [Concept Brief 15](concept-briefs.md#15-regular-types-operators-and-polymorphism).

**Difficulty:** 3.5/5

**Estimated time:** 3-5 hours

**Tooling stage:** Add polymorphic destruction and slicing tests.

### Learning Outcomes

- Define and implement a minimal abstract interface.
- Use virtual destruction, `override`, and deliberate `final`.
- Recognize object slicing and avoid downcast-driven design.

### Goal

Implement two tiny renderable value implementations behind an owning base pointer.

### Requirements

- Give the base a virtual destructor.
- Mark every overriding function `override`.
- Demonstrate slicing in a disabled or isolated example and replace it with
  reference/pointer polymorphism.
- Avoid `dynamic_cast` in the baseline by designing the required virtual operation.
- Store implementations in `unique_ptr<Base>`.

### Acceptance Criteria

- [ ] Destruction through the base is correct under sanitizers.
- [ ] No derived object is passed by base value.
- [ ] The learner explains when `final` is a design statement rather than a default.

### Stretch Goal

Compare the same two behaviors using `std::variant`.

---

## 36. Shape Design Comparison

**Category:** Core project

**Prerequisites:** Projects 34-35 and Phase 2 ownership.

**Difficulty:** 4/5

**Estimated time:** 7-10 hours

**Tooling stage:** Build separate designs behind one behavioral test contract.

### Learning Outcomes

- Compare composition, variants, and virtual polymorphism.
- Recognize open and closed sets of types and operations.
- Measure edit cost rather than declaring one abstraction universally superior.

### Goal

Implement area, perimeter, and rendering for circles, rectangles, and triangles
using:

1. value types stored in `variant`;
2. polymorphic objects stored in `unique_ptr<Shape>`;
3. one composition-oriented renderer boundary.

### Requirements

- Keep rendering policy separate from geometry where practical.
- Reuse Project 35 virtual-safety rules.
- Add one operation and one shape to each design.
- Record files and interfaces changed for each extension.
- Avoid shared ownership.

### Acceptance Criteria

- [ ] All designs satisfy the same behavior tests.
- [ ] The report identifies open-type and open-operation tradeoffs.
- [ ] Composition remains the default recommendation for reuse.

### Stretch Goal

Benchmark only after profiling identifies dispatch as relevant.

---

## 37. Generic Stack

**Category:** Core project

**Prerequisites:** Projects 34-36 and [Concept Brief 16](concept-briefs.md#16-templates-deduction-and-forwarding).

**Difficulty:** 3.5/5

**Estimated time:** 6-8 hours

**Tooling stage:** Use an `INTERFACE` target for a header-only template library.

### Learning Outcomes

- Write function and class templates.
- Explain template instantiation and visible definitions.
- State informal type requirements before formal concepts.

### Goal

Implement `Stack<int>`, `Stack<std::string>`, and `Stack<Player>`.

### Requirements

- Support `push(const T&)`, `push(T&&)`, pop, top, empty, and size.
- Define empty behavior with `expected`, `optional`, or a documented precondition.
- Support const and non-const access.
- Test a move-only element type.
- Compare the learning type with standard `std::stack`.
- Defer variadic perfect-forwarding `emplace` until Project 38.

### Acceptance Criteria

- [ ] Copyable and move-only types work.
- [ ] Template definitions create no linker failures.
- [ ] Empty access is explicit and tested.
- [ ] The README states when `std::stack` is the production choice.

### Stretch Goal

Expose iterators only if the abstraction should cease behaving like a stack.

---

## 38. Template Mechanics Lab

**Category:** Core lab

**Prerequisites:** Project 37 and [Concept Brief 16](concept-briefs.md#16-templates-deduction-and-forwarding).

**Difficulty:** 4/5

**Estimated time:** 5-7 hours

**Tooling stage:** Add isolated compile-fail examples.

### Learning Outcomes

- Explain deduction, overload resolution, explicit specialization, and dependent names.
- Use forwarding references and `std::forward` only when preserving value category.
- Use a type trait and fold expression in focused code.

### Goal

Build small independent template experiments before combining these techniques in
a library.

### Requirements

- Compare deduced and explicit template arguments.
- Add `emplace` to Generic Stack with a constrained variadic constructor call.
- Use `typename` or `template` on one genuine dependent name.
- Demonstrate `decltype` and one justified `decltype(auto)` return, then show where
  plain `auto` intentionally drops reference or cv-qualification.
- Implement one trait-based compile-time branch and one fold expression.
- Demonstrate a narrow explicit specialization, then prefer an overload where clearer.
- Keep invalid instantiations in compile-fail tests.

### Acceptance Criteria

- [ ] Every use of forwarding preserves a caller value category for a stated reason.
- [ ] Diagnostics identify the failed requirement.
- [ ] The learner can explain why overloads are often preferable to specialization.

### Stretch Goal

Inspect compiler-generated template instantiations with an available tool.

---

## 39. Compile-Time Math and Validation

**Category:** Core project

**Prerequisites:** Project 38 and [Concept Brief 17](concept-briefs.md#17-constant-evaluation).

**Difficulty:** 3.5/5

**Estimated time:** 6-9 hours

**Tooling stage:** Add compile-time tests with `static_assert`.

### Learning Outcomes

- Use `constexpr`, `consteval`, and `static_assert`.
- Distinguish code that may run at compile time from code that must.
- Detect invalid input and overflow in constant evaluation.

### Goal

Implement checked power, greatest common divisor, primality, and lookup-table generation.

### Requirements

- Validate representative results with `static_assert`.
- Use iterative implementations where recursion adds no value.
- Reject invalid and overflowing compile-time inputs clearly.
- Include runtime calls to `constexpr` functions.
- Justify why each compile-time operation is useful.

### Acceptance Criteria

- [ ] Compile-time and runtime behavior are both demonstrated.
- [ ] Failure diagnostics identify the violated condition.
- [ ] Recursive Fibonacci is not used as a meaningful benchmark.

### Stretch Goal

Create a compile-time validated fixed-size conversion table.

---

## 40. Constrained Generic Algorithms

**Category:** Core project

**Prerequisites:** Projects 38-39 and Phase 3 ranges.

**Difficulty:** 4/5

**Estimated time:** 9-13 hours

**Tooling stage:** Keep compile-fail examples outside normal tests.

### Learning Outcomes

- Use standard concepts, requires clauses, and constrained overloads.
- Express range, value, operation, and projection requirements.
- Compare constrained and unconstrained diagnostics.

### Goal

Implement average, maximum value, and print-all algorithms for suitable ranges.

### Requirements

- Build from standard range and arithmetic concepts.
- Avoid vague "container-like" concepts.
- Define empty behavior and result types.
- Avoid accidental integer truncation in average.
- Accept a projection where it improves reuse.
- Ensure invalid calls fail during overload resolution.

### Acceptance Criteria

- [ ] Contiguous and non-contiguous valid ranges are tested.
- [ ] Invalid element and projection types appear in compile-fail tests.
- [ ] Constraints express only implementation needs.

### Stretch Goal

Return a richer statistics value from one pass over an input range.

---

## 41. Traits, Variadics, and Customization Lab

**Category:** Core lab

**Prerequisites:** Projects 38-40.

**Difficulty:** 4/5

**Estimated time:** 5-7 hours

**Tooling stage:** Test public customization behavior and compile-time failures.

### Learning Outcomes

- Combine traits, parameter packs, folds, and `if constexpr`.
- Design a named opt-in customization function.
- Compare customization with inheritance, variant visitation, and `std::function`.

### Goal

Build a small `describe(value)` facility for primitive values and explicitly
opted-in user types.

### Requirements

- Provide built-in overloads for a small closed set of primitives.
- Let user types opt in through a named `describe_fields` or `tag_invoke`-style function.
- Use a fold expression to combine field descriptions.
- Reject unsupported types with a readable constrained diagnostic.
- Do not claim language reflection or arbitrary struct support.
- Compare this compile-time protocol with the runtime erasure in `std::function`.

### Acceptance Criteria

- [ ] Opt-in and unsupported behavior are tested.
- [ ] The public customization boundary is documented.
- [ ] The simplest overload or variant solution is preferred where sufficient.

### Stretch Goal

Add version metadata without implementing deserialization.

---

## 42. Serialization Customization Library

**Category:** Optional specialization

**Prerequisites:** Projects 24 and 38-41.

**Difficulty:** 5/5

**Estimated time:** 14-22 hours

**Tooling stage:** Separate public customization API from format implementation.

### Learning Outcomes

- Apply advanced templates to a concrete opt-in protocol.
- Preserve useful parse and serialization errors.
- Control format scope and compatibility explicitly.

### Goal

Serialize primitive values, escaped strings, ranges, and explicitly opted-in
structs to a small documented text format.

### Requirements

- Reuse Project 41's named customization protocol.
- Support escaped strings and nested sequences.
- Return `expected` from deserialization.
- Use forwarding only where category preservation is required.
- Define format grammar, limits, and unsupported cases.

### Acceptance Criteria

- [ ] Unsupported types fail with readable diagnostics.
- [ ] Round-trip tests cover every supported category.
- [ ] Malformed input reports location and cause.
- [ ] No claim of arbitrary reflection is made.

### Stretch Goal

Add version tags and backward-compatible defaults.

---

## 43. Type-Erased Command System

**Category:** Optional specialization

**Prerequisites:** Projects 27, 35-41.

**Difficulty:** 5/5

**Estimated time:** 14-20 hours

**Tooling stage:** Expose the command abstraction as a documented library API.

### Learning Outcomes

- Compare inheritance, templates, variants, callables, and manual type erasure.
- Build a value-semantics wrapper around heterogeneous behavior.
- Identify allocation, copy, and ABI tradeoffs.

### Goal

Store and execute heterogeneous commands through one `Command` value type.

### Requirements

- Implement an inheritance version first.
- Implement a manually type-erased value wrapper from the
  [supplied structural guidance](projects/43-type-erased-command-system/README.md).
- Define copyability, movability, and empty state.
- Add commands dynamically at runtime.
- Compare with `std::function` and variant alternatives.
- Do not call it a plugin system without external module loading.

### Acceptance Criteria

- [ ] Both implementations satisfy one test contract.
- [ ] Ownership and allocation behavior are documented.
- [ ] The report identifies when a simple callable or variant is sufficient.

### Stretch Goal

Run a separately scoped dynamic-library experiment and document ABI constraints.

---

## Phase 4 Transfer Gate

Complete revision M4, submit the phase evidence, and pass the
[Phase 4 unseen generic-design exercise](assessment-and-retention.md#phase-4-transfer)
at 12/15 or better. Optional Projects 42-43 cannot substitute for this gate.
