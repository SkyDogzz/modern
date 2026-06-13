# Phase 1 - Language Foundations and Workflow

This phase teaches language fundamentals and introduces tools in controlled
increments. Projects must be completed in order unless a core lab is replaced by
approved diagnostic evidence.

Read Concept Briefs 1-6 before and during this phase.

Focus on:

- translation, diagnostics, debugging, Git, and staged testing;
- initialization, types, integer behavior, expressions, and conversions;
- control flow, functions, scope, references, pointers, and const;
- strings, scoped enums, arrays, vectors, structs, spans, and string views;
- command-line input, declarations, definitions, linkage, and the ODR;
- target-based CMake only after the compile and link model is understood.

## 1. Compile, Run, and Read Diagnostics

**Category:** Core lab

**Prerequisites:** A C++23 compiler and [Concept Brief 1](concept-briefs.md#1-translation-and-execution).

**Difficulty:** 1/5

**Estimated time:** 1-2 hours

**Tooling stage:** Direct compiler command only.

### Learning Outcomes

- Explain source, compilation, linking, execution, and exit status at a basic level.
- Compile, run, and intentionally break a one-file program.
- Read the first relevant compiler diagnostic.

### Goal

Print a greeting and return success without relying on an IDE build button.

### Requirements

- Compile with `-std=c++23 -Wall -Wextra -Wpedantic -g`.
- Produce and fix one syntax error and one type error.
- Return zero on success and a chosen non-zero status on an intentional failure path.
- Document the exact build and run commands.

### Acceptance Criteria

- [ ] A clean shell can build and run the program.
- [ ] The learner distinguishes a compiler diagnostic from runtime output.
- [ ] No CMake, debugger, or unit-test framework is required yet.

### Stretch Goal

Inspect the generated object file and executable names without interpreting their
binary contents.

---

## 2. Debugger, CMake, and Smoke-Test Orientation

**Category:** Core lab

**Prerequisites:** Project 1 and [Concept Brief 6](concept-briefs.md#6-tests-debugging-cmake-and-git).

**Difficulty:** 1.5/5

**Estimated time:** 2-3 hours

**Tooling stage:** One executable target, one CTest smoke test, and Git initialization.

### Learning Outcomes

- Step through `main` and inspect one value in a debugger.
- Configure and build one CMake executable target.
- Distinguish a smoke test from a unit test.
- Create a focused Git commit and ignore generated build output.

### Goal

Put Project 1 under a minimal, reproducible build and smoke-test workflow.

### Requirements

- Set a breakpoint on `main` and step over one statement.
- Create one executable target with `target_compile_features`.
- Register a CTest that checks exit success.
- Add a `.gitignore` for build directories.
- Review `git diff` before committing.

### Acceptance Criteria

- [ ] Configure, build, test, and run commands are documented.
- [ ] The smoke test is not described as proof of program correctness.
- [ ] Generated files are not tracked.

### Stretch Goal

Add a Debug `CMakePresets.json` preset.

---

## 3. Character Stat Sheet

**Category:** Core lab

**Prerequisites:** Projects 1-2 and [Concept Brief 2](concept-briefs.md#2-initialization-types-and-integer-behavior).

**Difficulty:** 1/5

**Estimated time:** 2-3 hours

**Tooling stage:** Reuse the single executable and smoke-test workflow.

### Learning Outcomes

- Declare and initialize fundamental values and `std::string`.
- Distinguish initialization from assignment.
- Use const, block scope, a struct, and a scoped enum.

### Goal

Read a character name and print a stat sheet with class, health, mana, strength,
agility, and alive state.

### Requirements

- Use brace initialization and initialize every object.
- Define `enum class CharacterClass` and a `Character` struct.
- Make values const when they do not change.
- Demonstrate a nested block without leaking names outside it.
- Reject an empty name.

### Acceptance Criteria

- [ ] Valid and empty input have deliberate behavior.
- [ ] Every field's type and valid range can be explained.
- [ ] No integer code substitutes for the scoped enum.

### Stretch Goal

Write a function that converts every enum value to display text.

---

## 4. Integer and Conversion Lab

**Category:** Core lab

**Prerequisites:** Project 3 and [Concept Brief 2](concept-briefs.md#2-initialization-types-and-integer-behavior).

**Difficulty:** 2/5

**Estimated time:** 3-5 hours

**Tooling stage:** Add a small assertion-based test executable using the
[supplied minimal harness](support/minitest/README.md).

### Learning Outcomes

- Explain narrowing, signed and unsigned ranges, integer division, and overflow.
- Validate before an explicit conversion.
- Parse an integer with `std::from_chars`.
- Recognize undefined behavior without putting it in the normal test suite.

### Goal

Build a set of focused experiments that classify safe, rejected, lossy, and
undefined arithmetic operations.

### Requirements

- Demonstrate a brace-initialization narrowing rejection as a compile-fail example.
- Compare signed and unsigned values only after a deliberate range decision.
- Check addition or multiplication before it can overflow.
- Parse valid, partial, out-of-range, and invalid text with `from_chars`.
- Keep an intentional signed-overflow UBSan demonstration in a separate executable.

### Acceptance Criteria

- [ ] Normal tests execute no undefined behavior.
- [ ] `from_chars` checks both its error code and final pointer.
- [ ] The learner explains why a cast alone does not make a conversion safe.

### Stretch Goal

Implement a checked integer-add function returning a small result struct containing
either a value or a status enum.

---

## 5. Unit Converter

**Category:** Core project

**Prerequisites:** Projects 1-4 and [Concept Brief 3](concept-briefs.md#3-control-flow-functions-and-scope).

**Difficulty:** 1.5/5

**Estimated time:** 3-5 hours

**Tooling stage:** One application source plus a focused calculation test executable.

### Learning Outcomes

- Use arithmetic expressions, precedence, and pure functions.
- Choose integer or floating-point types from the domain.
- Separate calculations from terminal input/output.

### Goal

Build an interactive converter for distance, temperature, and mass.

### Requirements

- Implement each conversion as a pure function.
- Use `double` where fractional values are expected.
- Use scoped enums for categories and units.
- Test representative, negative where meaningful, and boundary values.
- Document the tolerance used for floating-point comparisons.

### Acceptance Criteria

- [ ] Invalid categories and units have defined behavior.
- [ ] Calculation tests do not read standard input.
- [ ] Every explicit conversion has a stated range argument.

### Stretch Goal

Add a table-driven conversion test.

---

## 6. Expression Calculator

**Category:** Core project

**Prerequisites:** Projects 1-5.

**Difficulty:** 2/5

**Estimated time:** 4-6 hours

**Tooling stage:** Register a dedicated logic test executable with CTest.

### Learning Outcomes

- Use `if`, `switch`, comparisons, and logical operators.
- Distinguish integer and floating-point operation domains.
- Define input and arithmetic failure behavior.

### Goal

Evaluate two operands and an operator in either integer mode or floating-point mode.

### Requirements

- Support `+`, `-`, `*`, `/`, `<`, `>`, and `==` in both modes.
- Support `%` only in integer mode.
- Detect zero divisors and checked integer overflow where applicable.
- Keep parsing, evaluation, and terminal I/O separate.
- Use a scoped operation enum rather than dispatching on raw characters internally.

### Acceptance Criteria

- [ ] Every operation has normal and invalid-case tests.
- [ ] Floating `==` is described as exact equality of the represented parsed values,
      not equality of the input text or an approximate numerical comparison.
- [ ] Stream failure cannot create an infinite loop.

### Stretch Goal

Repeat calculations until the user chooses to quit.

---

## 7. Number Guessing Game

**Category:** Core lab

**Prerequisites:** Projects 1-6.

**Difficulty:** 2/5

**Estimated time:** 3-4 hours

**Tooling stage:** Add reusable warning and sanitizer options for local targets.

### Learning Outcomes

- Use `while`, `for`, `break`, and `continue`.
- Generate values with a random engine and distribution.
- State a loop invariant and termination argument.

### Goal

Let the user guess a generated number and report whether each guess is high or low.

### Requirements

- Use `<random>`, not `std::rand`.
- Count attempts and reject out-of-range input.
- Add easy, normal, and hard ranges.
- Test comparison logic separately from randomness and input.

### Acceptance Criteria

- [ ] The game has a reachable termination condition.
- [ ] Invalid input is cleared and reported.
- [ ] Deterministic core tests do not depend on random output.

### Stretch Goal

Accept a seed for reproducible debugging.

---

## 8. Dice Roller and Basic Containers

**Category:** Core project

**Prerequisites:** Projects 1-7 and [Concept Brief 4](concept-briefs.md#4-records-enums-and-basic-containers).

**Difficulty:** 2.5/5

**Estimated time:** 5-7 hours

**Tooling stage:** Keep one target; separate logic with functions, not source libraries.

### Learning Outcomes

- Use `std::vector`, `std::array`, structs, and scoped enums.
- Design functions with values, `const&`, and mutable references deliberately.
- Explain fixed-size versus dynamic contiguous storage.

### Goal

Roll requests such as three six-sided dice and report individual rolls, a total,
and a fixed-size d6 histogram.

### Requirements

- Define a validated `DiceRequest` struct.
- Return individual rolls in a vector.
- Build a d6 histogram with `std::array`.
- Overload one helper only if the overload improves the interface.
- Keep full dice-expression parsing out of scope.

### Acceptance Criteria

- [ ] Invalid count and side values are tested.
- [ ] No unexplained global mutable random state exists.
- [ ] Each parameter-passing choice can be justified.

### Stretch Goal

Parse one term such as `4d10+2`.

---

## 9. References, Pointers, and Views Lab

**Category:** Core lab

**Prerequisites:** Project 8 and [Concept Brief 5](concept-briefs.md#5-references-pointers-views-and-c-strings).

**Difficulty:** 2.5/5

**Estimated time:** 4-6 hours

**Tooling stage:** Run invalid lifetime demonstrations only in isolated sanitizer targets.

### Learning Outcomes

- Distinguish references, pointers, ownership, and absence.
- Use `std::span` and `std::string_view` as non-owning views.
- Predict invalidation after vector or string mutation.

### Goal

Observe one owned object through references, pointers, spans, and string views,
then document every observer's validity.

### Requirements

- Show a reference observer and a nullable pointer observer.
- Pass an array and vector through `span<const int>`.
- Pass owned text through `string_view`.
- Trigger vector reallocation and string mutation without dereferencing stale observers.
- Keep one intentionally dangling example disabled or isolated under ASan.

### Acceptance Criteria

- [ ] Every observer names its owner and validity period.
- [ ] No normal test dereferences an invalid observer.
- [ ] The learner explains why a non-null pointer can still dangle.

### Stretch Goal

Compare an owning string return with a string-view return and document when each is valid.

---

## 10. Inventory Editor

**Category:** Core project

**Prerequisites:** Projects 1-9.

**Difficulty:** 2.5/5

**Estimated time:** 5-8 hours

**Tooling stage:** Focused model tests; still no public library target.

### Learning Outcomes

- Apply vector mutation and invalidation rules.
- Provide const and mutable search interfaces.
- Represent search failure explicitly.

### Goal

Manage an in-memory inventory with add, remove, rename, upgrade, find, and list.

### Requirements

- Model an item with a struct and stable numeric ID.
- Implement an index-returning search first.
- Add pointer-returning const and mutable searches only as a comparison.
- Validate user-visible positions and IDs before access.
- Test insertion, erasure, and reallocation.

### Acceptance Criteria

- [ ] No observer is retained across an invalidating operation.
- [ ] Search failure cannot be mistaken for a valid item.
- [ ] Const access cannot mutate inventory state.

### Stretch Goal

Compare stable IDs with vector indexes after erasure.

---

## 11. Interactive Todo List

**Category:** Portfolio project

**Prerequisites:** Projects 1-10.

**Difficulty:** 3/5

**Estimated time:** 8-12 hours

**Tooling stage:** Add integration tests around command processing.

### Learning Outcomes

- Combine text, containers, control flow, records, and functions.
- Separate command parsing, storage, and terminal I/O.
- Maintain documented in-process state.

### Goal

Run an interactive session:

```txt
todo> add Learn RAII
todo> list
todo> done 1
todo> remove 1
todo> quit
```

### Requirements

- Store tasks only for the process duration.
- Give each task a stable ID, text, and completion state.
- Keep persistence out of the baseline.
- Define empty, malformed, and unknown-command responses.

### Acceptance Criteria

- [ ] The interface does not imply cross-process persistence.
- [ ] Parsing and task operations have automated tests.
- [ ] The README documents invariants and command failures.

### Stretch Goal

Revisit persistence after Project 24 rather than implementing an ad hoc format now.

---

## 12. Command-Line Greeter

**Category:** Core project

**Prerequisites:** Projects 1-11 and [Concept Brief 5](concept-briefs.md#5-references-pointers-views-and-c-strings).

**Difficulty:** 2.5/5

**Estimated time:** 4-6 hours

**Tooling stage:** Add CTest cases with command-line arguments and expected statuses.

### Learning Outcomes

- Explain `main(int argc, char** argv)` and null-terminated argument strings.
- Convert arguments to safe views and parse numbers with `from_chars`.
- Produce useful help, usage, and error messages.

### Goal

Support:

```bash
./greeter Thomas
./greeter --shout Thomas
./greeter --repeat 3 Thomas
./greeter --help
```

### Requirements

- Reject unknown options and missing values.
- Never read beyond `argc`.
- Convert arguments promptly to `string_view`.
- Parse and range-check repeat count with `from_chars`.
- Store parsed options in a struct and return non-zero on invalid invocation.

### Acceptance Criteria

- [ ] Success, help, and failure statuses are tested.
- [ ] Partial numeric input such as `3x` is rejected.
- [ ] The learner explains who owns every argument string.

### Stretch Goal

Allow options before or after the name without duplicated parsing logic.

---

## 13. Compilation and Linking Lab

**Category:** Core lab

**Prerequisites:** Projects 1-12 and [Concept Brief 1](concept-briefs.md#1-translation-and-execution).

**Difficulty:** 3/5

**Estimated time:** 5-7 hours

**Tooling stage:** Build several source files with direct compiler commands first.

### Learning Outcomes

- Distinguish declarations, definitions, translation units, and linkage.
- Explain preprocessing, headers, namespaces, include guards, and the ODR.
- Diagnose compile-time and link-time failures separately.

### Goal

Split an earlier project's model and operations across self-contained headers and
source files before introducing multi-target CMake.

### Requirements

- Place public names in a project namespace.
- Demonstrate and fix one missing-definition linker error.
- Demonstrate and fix one ODR violation in isolated broken examples.
- Use include guards or `#pragma once` consistently.
- Explain that include guards and feature-test macros use preprocessing, and avoid
  function-like macros where functions, constants, or templates suffice.
- Identify automatic, static, thread-local, and dynamic storage examples without
  requiring dynamic allocation.

### Acceptance Criteria

- [ ] Headers compile when included alone.
- [ ] Headers contain no accidental non-inline definitions.
- [ ] The learner explains the failure without CMake terminology.

### Stretch Goal

Use an unnamed namespace for one source-file-only helper and explain internal linkage.

---

## 14. Target-Based CMake and Test Lab

**Category:** Portfolio project

**Prerequisites:** Projects 1-13 and [Concept Brief 6](concept-briefs.md#6-tests-debugging-cmake-and-git).

**Difficulty:** 3/5

**Estimated time:** 7-10 hours

**Tooling stage:** Library, application, maintained test framework, formatter, and sanitizer presets.

### Learning Outcomes

- Model a library, application, and tests as CMake targets.
- Choose `PUBLIC`, `PRIVATE`, and `INTERFACE` usage requirements deliberately.
- Adopt one maintained test framework or a documented repository harness.
- Apply formatter and sanitizer configurations reproducibly.

### Goal

Put the Project 13 multi-file program under a clean target-based build and test workflow.

### Requirements

- Build library, application, and test targets.
- Request C++23 per target, disable vendor language extensions, and use target-based
  include paths.
- Add Debug and ASan/UBSan presets.
- Configure one repository formatter.
- Fetch, vendor, or locate the test framework through a documented pinned strategy.
- Add a basic CI job that configures, builds, and tests one supported compiler.

### Acceptance Criteria

- [ ] A clean checkout configures, builds, tests, and formats from documented commands.
- [ ] The documentation distinguishes single-config and multi-config configure,
      build, test, and executable paths.
- [ ] Target usage requirements have stated reasons.
- [ ] All tests pass from a clean build directory.
- [ ] Dependency acquisition is reproducible.

### Stretch Goal

Install headers and the library to a local prefix without yet exporting a package.

---

## Phase 1 Transfer Gate

Complete R2 and R6, submit the phase evidence, and pass the
[Phase 1 unseen converter diagnosis](assessment-and-retention.md#phase-1-transfer)
at 12/15 or better. Project checkboxes without the scored transfer do not unlock
Phase 2.
