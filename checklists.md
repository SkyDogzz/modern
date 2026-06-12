# Modern C++ Learning Checklists

## Baseline Project Checklist

- [ ] I can explain each project learning outcome without reading the code.
- [ ] The project builds as C++23.
- [ ] I compiled with warnings and investigated every warning.
- [ ] I tested normal, boundary, invalid-input, and failure cases.
- [ ] I separated pure logic from I/O where practical.
- [ ] I documented ownership, lifetime, and error behavior.
- [ ] I used standard-library facilities instead of unnecessary custom machinery.
- [ ] I wrote a short README with build, run, and test commands.
- [ ] I can reproduce and explain at least one bug I fixed.

## Baseline Commands

Direct compiler invocations use:

```bash
c++ -std=c++23 -Wall -Wextra -Wpedantic -g source.cpp -o app
```

Optional stricter diagnostics:

```bash
-Wconversion -Wshadow
```

Use `-Werror` only for code and compiler versions controlled by the project. Do
not make third-party warnings or cross-compiler differences fatal by default.

## Sanitizers

AddressSanitizer and UndefinedBehaviorSanitizer:

```bash
-fsanitize=address,undefined -fno-omit-frame-pointer -g
```

ThreadSanitizer for concurrency projects, in a separate build:

```bash
-fsanitize=thread -fno-omit-frame-pointer -g
```

Do not combine ThreadSanitizer with AddressSanitizer in the same executable.

## Phase Gates

### End of Phase 1

- [ ] I can compile, debug, and test a small multi-file C++23 program.
- [ ] I understand initialization, control flow, functions, structs, references, and const.
- [ ] I can explain declarations, definitions, namespaces, linkage, and the ODR.
- [ ] I can create CMake executable and test targets.

### End of Phase 2

- [ ] I can reason about storage duration, object lifetime, and ownership.
- [ ] I use RAII and the Rule of Zero by default.
- [ ] I can explain copy, move, value categories, copy elision, and `noexcept`.
- [ ] I can choose among exceptions, `std::optional`, and `std::expected`.

### End of Phase 3

- [ ] I select containers using complexity and invalidation guarantees.
- [ ] I can use iterators, lambdas, algorithms, ranges, and views safely.
- [ ] I can design testable filesystem, formatting, and chrono code.

### End of Phase 4

- [ ] I can design regular value types and constrained templates.
- [ ] I can compare composition, inheritance, variants, and type erasure.
- [ ] I understand the template compilation model and customization points.

### End of Phase 5

- [ ] I can identify data races, deadlocks, unsafe cancellation, and invalid memory ordering.
- [ ] I can use `std::jthread`, mutexes, condition variables, and atomics deliberately.
- [ ] I profile before optimizing and can justify allocator or PMR use with evidence.
- [ ] I understand that modules and coroutines are optional, toolchain-sensitive facilities.

### End of Phase 6

- [ ] I can test, fuzz, analyze, package, document, and release a C++ project.
- [ ] I can maintain a CI matrix and reproducible CMake presets.
- [ ] I can define and enforce a capstone scope through milestones and non-goals.

## Good Habits

- Prefer initialization over assignment after construction.
- Prefer values and the Rule of Zero.
- Prefer `std::vector` and `std::string` over owning raw arrays.
- Use `std::span` and `std::string_view` only when their non-owning lifetime is safe.
- Prefer RAII over manual cleanup.
- Prefer `std::unique_ptr` for exclusive dynamic ownership.
- Use `std::shared_ptr` only when ownership is genuinely shared.
- Prefer `const` and narrow interfaces where they improve reasoning.
- Prefer algorithms and ranges when they make intent clearer.
- Prefer composition until runtime substitutability justifies inheritance.
- Avoid raw `new`, raw `delete`, and unjustified casts.
- Measure before optimizing.

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
10. What could be removed or simplified?
