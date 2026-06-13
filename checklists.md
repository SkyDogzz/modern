# Modern C++ Learning Checklists

Use the checklist for the current phase. `Not applicable` is valid only with a
short reason; early projects are not required to pretend they have complex
ownership, packaging, or concurrency concerns.

## Baseline Project Checklist

- [ ] I can explain each learning outcome without reading the code.
- [ ] The project builds as C++23 from documented commands.
- [ ] I investigated every compiler warning.
- [ ] I tested normal, boundary, invalid-input, and relevant failure cases.
- [ ] I separated pure logic from I/O where practical.
- [ ] I documented ownership, lifetime, and error behavior when they are relevant.
- [ ] I used standard-library facilities instead of unnecessary custom machinery.
- [ ] I recorded at least one defect, diagnostic observation, and fix.
- [ ] I reviewed the diff before committing focused changes to Git.

## Baseline Direct-Compiler Commands

GCC or Clang:

```bash
c++ -std=c++23 -Wall -Wextra -Wpedantic -g source.cpp -o app
```

MSVC developer shell:

```bat
cl /std:c++latest /permissive- /W4 /EHsc /Zi source.cpp
```

Optional stricter GCC or Clang diagnostics:

```bash
-Wconversion -Wshadow
```

Use `-Werror` only for controlled code and compiler versions. Do not make
third-party warnings or cross-compiler differences fatal by default.

After CMake is introduced, verify whether the selected generator is single-config or
multi-config and use the matching commands from `project-template.md`.

## Sanitizers

AddressSanitizer and UndefinedBehaviorSanitizer:

```bash
-fsanitize=address,undefined -fno-omit-frame-pointer -g
```

ThreadSanitizer, in a separate build:

```bash
-fsanitize=thread -fno-omit-frame-pointer -g
```

Do not combine ThreadSanitizer with AddressSanitizer in one executable.
Intentionally undefined or racy demonstrations belong in isolated executables and
never in the normal passing test suite.

## Phase Project Gates

### Phase 1 Projects

- [ ] Every variable is initialized and conversions are deliberate.
- [ ] User input and exit status have defined failure behavior.
- [ ] References, pointers, spans, and string views are documented as non-owning.
- [ ] Tests use the current staged harness instead of inventing new infrastructure.
- [ ] Generated build files are ignored by Git.

### Phase 2 Projects

- [ ] Class invariants cannot be bypassed through the public interface.
- [ ] Special-member behavior is intentional: defaulted, deleted, or implemented.
- [ ] Every resource has one documented owner and an RAII release path.
- [ ] Error type and exception guarantee match the public API.
- [ ] ASan/UBSan pass for normal tests.

### Phase 3 Projects

- [ ] Container choice is justified by operations, complexity, and invalidation.
- [ ] Iterator, view, callback, and filesystem lifetimes are safe.
- [ ] Algorithms satisfy comparator, projection, and empty-input requirements.
- [ ] Operating-system effects are behind testable adapters.
- [ ] Formatting and static-analysis configuration are applied consistently.

### Phase 4 Projects

- [ ] Value types have unsurprising copy, move, comparison, and operator behavior.
- [ ] Runtime polymorphism uses virtual destruction and `override` correctly.
- [ ] Template constraints express actual implementation requirements.
- [ ] Compile-fail examples are separate from the passing test suite.
- [ ] Advanced machinery is justified against a simpler value, callable, or variant.

### Phase 5 Projects

- [ ] Every thread has an owner and deterministic shutdown path.
- [ ] Shared invariants have explicit synchronization.
- [ ] Stress tests terminate and TSan runs separately where supported.
- [ ] Memory-order claims include a written happens-before argument.
- [ ] Performance claims identify workload, hardware, build, repetitions, and noise.

### Phase 6 Projects

- [ ] CI runs documented compiler, test, sanitizer, and analysis jobs.
- [ ] Dependencies and tool versions are constrained reproducibly.
- [ ] Installed-package behavior is verified from a clean external consumer.
- [ ] Versioning, compatibility, license, changelog, and artifacts are defined.
- [ ] Post-release fixes include reproduction, regression test, review, and release notes.

## Phase Gates

### End of Phase 1

- [ ] I can compile, debug, test, and commit a small multi-file C++23 program.
- [ ] I understand initialization, integer behavior, control flow, functions,
      structs, enums, arrays, vectors, references, pointers, views, and const.
- [ ] I can explain declarations, definitions, preprocessing, translation units,
      linkage, namespaces, and the ODR.
- [ ] I can create target-based CMake library, executable, and test targets.

### End of Phase 2

- [ ] I can reason about scope, storage duration, object lifetime, and ownership.
- [ ] I use RAII and the Rule of Zero by default.
- [ ] I can explain special-member generation, copy, move, value categories,
      copy elision, and `noexcept`.
- [ ] I can choose among preconditions, exceptions, `optional`, `expected`, and
      `error_code`.

### End of Phase 3

- [ ] I select containers using operation, complexity, layout, and invalidation needs.
- [ ] I can use iterators, sentinels, lambdas, algorithms, ranges, and views safely.
- [ ] I can design testable filesystem, formatting, and chrono adapters.
- [ ] I completed all three system-library breadth tracks and can identify the
      portfolio-depth track.

### Standard-Library Breadth Route Gate

- [ ] Every Core and Working row in `stdlib-facility-inventory.md` links to evidence.
- [ ] I completed B1-B9 and Surveys S1-S5.
- [ ] I passed the unseen B10 facility-selection assessment.
- [ ] My feature record distinguishes native, fallback, survey, and unsupported
      facilities.
- [ ] I can retrieve complexity, invalidation, precondition, and guarantee facts from
      a current reference.

### End of Phase 4

- [ ] I can design regular value types and constrained templates.
- [ ] I can compare composition, inheritance, variants, callables, and type erasure.
- [ ] I understand template deduction, forwarding, traits, variadics, folds,
      compilation, and named customization protocols.
- [ ] I know that manual serialization frameworks and type erasure are optional
      specializations.

### End of Phase 5

- [ ] I can identify data races, deadlocks, unsafe cancellation, and invalid ordering.
- [ ] I can use threads, `jthread`, mutexes, condition variables, futures, and
      atomics deliberately.
- [ ] I profile before optimizing and distinguish measurement from speculation.
- [ ] I know that PMR, modules, coroutines, `mdspan`, and weak ordering are optional.

### End of Phase 6

- [ ] I can test, fuzz, analyze, package, document, release, and maintain a project.
- [ ] I can maintain a CI matrix and reproducible CMake presets.
- [ ] I can review a change for source, binary, behavior, and dependency compatibility.
- [ ] I can scope a capstone through milestones and complete a post-release patch.

## Good Habits

- Prefer initialization over assignment after construction.
- Prefer values and the Rule of Zero.
- Prefer `std::vector`, `std::array`, and `std::string` over owning raw arrays.
- Use `std::span` and `std::string_view` only when non-owning lifetime is safe.
- Prefer RAII over manual cleanup.
- Prefer `std::unique_ptr` for exclusive dynamic ownership.
- Use `std::shared_ptr` only when ownership is genuinely shared.
- Prefer const and narrow interfaces where they improve reasoning.
- Prefer algorithms and ranges when they make intent clearer.
- Prefer composition until runtime substitutability justifies inheritance.
- Avoid raw `new`, raw `delete`, and unjustified casts in production code.
- Measure before optimizing.
- Keep commits focused and reviewable.

## Review Questions

1. What are this project's invariants?
2. Who owns every resource and view?
3. What is each object's storage duration and lifetime?
4. Can any reference, pointer, iterator, view, or callback dangle?
5. What is the error policy and exception guarantee?
6. What happens on invalid, partial, or hostile input?
7. Which tests prove the important behavior?
8. Which debugger, sanitizer, analyzer, or profiler evidence supports the result?
9. What are the time and space complexity tradeoffs?
10. What API, ABI, behavior, or dependency compatibility could this change affect?
11. What could be removed or simplified?
