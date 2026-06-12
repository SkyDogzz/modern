# Phase 1 - Foundations and Workflow

This phase builds the language and tooling foundation needed for later C++.
Projects must be completed in order.

Focus on:

- compiling and debugging C++23;
- initialization, types, expressions, and control flow;
- functions, scope, references, pointers, and const;
- strings, `std::array`, vectors, structs, and enums;
- declarations, definitions, namespaces, linkage, and the ODR;
- introductory testing and target-based CMake.

## 1. Hello C++23

**Prerequisites:** A C++23-capable compiler and a terminal.

**Difficulty:** 1/5

**Estimated time:** 1-2 hours

**CMake stage:** Build one executable target after compiling once by hand.

### Learning Outcomes

- Compile, run, and intentionally break a one-file C++23 program.
- Read a compiler diagnostic and inspect execution in a debugger.
- Add a smoke test that checks the program's exit status.

### Goal

Create a program that prints a greeting, returns success, and can be built both
with a direct compiler command and CMake.

### Requirements

- Compile with `-std=c++23 -Wall -Wextra -Wpedantic -g`.
- Set a breakpoint on `main` in GDB or LLDB and step over one statement.
- Add one `assert`-based check or CTest smoke test.
- Create an executable target using `target_compile_features(app PRIVATE cxx_std_23)`.

### Acceptance Criteria

- [ ] A clean checkout can be configured, built, run, and tested using documented commands.
- [ ] The README includes one compiler error and explains how it was corrected.
- [ ] No IDE-only build steps are required.

### Stretch Goal

Add `CMakePresets.json` with a Debug preset.

---

## 2. Character Stat Sheet

**Prerequisites:** Project 1.

**Difficulty:** 1/5

**Estimated time:** 2-3 hours

**CMake stage:** Reuse the executable target and warning configuration.

### Learning Outcomes

- Declare and initialize fundamental types and `std::string`.
- Distinguish initialization from later assignment.
- Use `const`, local scope, standard input, and formatted output.

### Goal

Read a character name and print a stat sheet containing health, mana, strength,
agility, and an alive/dead flag.

### Requirements

- Use brace initialization.
- Use appropriate integer, floating-point, Boolean, character, and string values.
- Make values `const` when they do not change.
- Demonstrate a nested local scope without leaking names outside it.
- Reject an empty name.

### Acceptance Criteria

- [ ] The program handles valid and empty input deliberately.
- [ ] Every variable is initialized.
- [ ] The learner can explain each variable's type and scope.

### Stretch Goal

Add a scoped `enum class CharacterClass` and print a selected class.

---

## 3. Unit Converter

**Prerequisites:** Projects 1-2.

**Difficulty:** 1.5/5

**Estimated time:** 3-4 hours

**CMake stage:** Extract conversion logic into a small library target.

### Learning Outcomes

- Use arithmetic expressions, precedence, and functions.
- Distinguish implicit conversion, explicit conversion, and narrowing.
- Use `auto` only when the deduced type remains clear.
- Separate pure calculations from input/output.

### Goal

Build an interactive converter for distance, temperature, and mass.

### Requirements

- Implement each conversion as a pure function.
- Use `double` where fractional results are expected.
- Demonstrate one safe `static_cast` and one rejected narrowing conversion.
- Test representative and boundary values without reading from standard input.

### Acceptance Criteria

- [ ] Conversion functions have automated tests.
- [ ] Invalid categories and units have defined behavior.
- [ ] Floating-point comparisons use a documented tolerance.

### Stretch Goal

Represent conversion categories and units with scoped enums.

---

## 4. Expression Calculator

**Prerequisites:** Projects 1-3.

**Difficulty:** 2/5

**Estimated time:** 3-5 hours

**CMake stage:** Add a dedicated test executable and register it with CTest.

### Learning Outcomes

- Use `if`, `else`, `switch`, comparison, and logical operators.
- Explain integer division, remainder, and floating-point division.
- Validate user input and define failure behavior.

### Goal

Evaluate two operands and one operator from an interactive prompt.

### Requirements

- Support `+`, `-`, `*`, `/`, `%`, `<`, `>`, and `==`.
- Reject remainder operations on floating-point operands.
- Detect division by zero.
- Keep evaluation logic independent from terminal I/O.

### Acceptance Criteria

- [ ] Every operator has normal and invalid-case tests.
- [ ] Stream input failure does not cause an infinite loop.
- [ ] The debugger is used to inspect at least one failing case.

### Stretch Goal

Repeat calculations until the user chooses to quit.

---

## 5. Number Guessing Game

**Prerequisites:** Projects 1-4.

**Difficulty:** 2/5

**Estimated time:** 3-4 hours

**CMake stage:** Add reusable project warning and sanitizer options.

### Learning Outcomes

- Use `while`, `for`, `break`, and `continue`.
- Generate random numbers with `<random>`.
- Model loop invariants and termination conditions.

### Goal

Let the user guess a generated number and report whether each guess is too high
or too low.

### Requirements

- Use a modern random engine and distribution, not `std::rand`.
- Count attempts and reject out-of-range input.
- Add easy, normal, and hard ranges.
- Test the comparison logic separately from randomness and input.

### Acceptance Criteria

- [ ] The game always has a reachable termination condition.
- [ ] Invalid input is cleared and reported.
- [ ] The core comparison function is deterministic and tested.

### Stretch Goal

Accept a seed for reproducible debugging sessions.

---

## 6. Dice Roller

**Prerequisites:** Projects 1-5.

**Difficulty:** 2.5/5

**Estimated time:** 4-6 hours

**CMake stage:** Keep parsing and rolling in separate library targets or source units.

### Learning Outcomes

- Design functions with parameters, return values, and overloads.
- Use a `struct` and `enum class` to model data.
- Apply pass-by-value, `const&`, and local scope deliberately.

### Goal

Roll dice from a simple count-and-sides request such as `3 6` or `1 20`.

### Requirements

- Define a `DiceRequest` struct.
- Validate positive count and sides.
- Return individual rolls and a total.
- Overload one helper only where the overload improves the API.
- Do not parse full expressions such as `2d8+1d6+3` in the baseline project.

### Acceptance Criteria

- [ ] Invalid dice requests are tested.
- [ ] No function relies on unexplained global mutable state.
- [ ] The learner can justify each value or reference parameter.

### Stretch Goal

Parse a single term such as `4d10+2`, or build a fixed-size d6 histogram with
`std::array`.

---

## 7. Inventory Editor

**Prerequisites:** Projects 1-6.

**Difficulty:** 2.5/5

**Estimated time:** 5-7 hours

**CMake stage:** Build a reusable inventory library plus app and test targets.

### Learning Outcomes

- Store records in `std::vector` and text in `std::string`.
- Use indexes, range-based loops, references, pointers, and `nullptr`.
- Explain when vector growth invalidates references and pointers.

### Goal

Manage an in-memory inventory with add, remove, rename, upgrade, find, and list
operations.

### Requirements

- Model an item with a `struct`.
- Provide const and mutable search operations.
- Return a pointer only as a non-owning result and document its validity.
- Validate indexes before access.
- Add tests that trigger vector insertion and removal.

### Acceptance Criteria

- [ ] No pointer or reference is retained across an operation that can invalidate it.
- [ ] Search failure is represented explicitly.
- [ ] Const functions do not mutate the inventory.

### Stretch Goal

Replace the pointer-returning search API with an index-based result and compare
the lifetime tradeoffs.

---

## 8. Interactive Todo List

**Prerequisites:** Projects 1-7.

**Difficulty:** 2.5/5

**Estimated time:** 5-8 hours

**CMake stage:** Add integration tests that drive the command-processing layer.

### Learning Outcomes

- Combine strings, vectors, loops, structs, and functions in one program.
- Separate command processing from storage and terminal I/O.
- Maintain state during a single process.

### Goal

Run one interactive session:

```txt
todo> add Learn RAII
todo> list
todo> done 1
todo> remove 1
todo> quit
```

### Requirements

- Store tasks in memory for the duration of the process.
- Give each task stable text and completion state.
- Validate user-visible task numbers.
- Keep persistence out of the baseline project.

### Acceptance Criteria

- [ ] The documented interface does not imply state survives separate process invocations.
- [ ] Command parsing and task operations have automated tests.
- [ ] Empty, unknown, and malformed commands have defined responses.

### Stretch Goal

Add save/load persistence, then support separate invocations such as
`./todo add` and `./todo list`.

---

## 9. Command-Line Greeter

**Prerequisites:** Projects 1-8.

**Difficulty:** 2/5

**Estimated time:** 3-5 hours

**CMake stage:** Add CTest cases with different command-line arguments.

### Learning Outcomes

- Interpret `main(int argc, char** argv)`.
- Parse positional arguments and simple options.
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

- Reject unknown options and missing option values.
- Convert the repeat count safely and validate its range.
- Keep parsed options in a struct.
- Return a non-zero exit status on invalid invocation.

### Acceptance Criteria

- [ ] Success and failure exit statuses are tested.
- [ ] `--help` documents every supported form.
- [ ] Parsing does not read past `argv`.

### Stretch Goal

Allow options before or after the name without duplicating parsing logic.

---

## 10. Multi-File Build and Test Lab

**Prerequisites:** Projects 1-9.

**Difficulty:** 3/5

**Estimated time:** 6-8 hours

**CMake stage:** Use target-based include paths, compile features, libraries, and tests.

### Learning Outcomes

- Distinguish declarations, definitions, translation units, and linkage.
- Use namespaces, include guards, and internal linkage correctly.
- Explain the One Definition Rule and basic storage-duration categories.
- Debug and test a multi-file C++23 program.

### Goal

Refactor an earlier project into:

```txt
include/roadmap/model.hpp
include/roadmap/operations.hpp
src/operations.cpp
src/main.cpp
tests/operations_tests.cpp
```

### Requirements

- Place public names in a project namespace.
- Demonstrate and fix one linker error.
- Demonstrate and fix one ODR violation.
- Identify automatic, static, and dynamic storage in the project.
- Build library, app, and test targets with CMake.
- Run AddressSanitizer and UndefinedBehaviorSanitizer in a separate preset.

### Acceptance Criteria

- [ ] Headers are self-contained and do not contain accidental definitions.
- [ ] Target usage requirements are `PUBLIC`, `PRIVATE`, or `INTERFACE` for a stated reason.
- [ ] All tests pass from a clean build directory.
- [ ] The learner can explain compilation and linking without invoking CMake terminology.

### Stretch Goal

Add installable headers locally, without yet creating a distributable package.
