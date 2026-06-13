# Curriculum Support Files

These files provide infrastructure explicitly referenced by the roadmap. They are
scaffolds and test utilities, not completed project solutions.

- `minitest/`: dependency-free assertion harness for Projects 2-13.
- `compile-fail/`: instructions and CMake helper for expected compiler failures.
- `allocation-failure/`: deterministic allocation failure injection.
- `package-skeleton/`: installable CMake library skeleton for Project 55.
- `toolchain-profile.cpp`: compile-time guard for the pinned GCC/libstdc++ and
  Clang/libc++ CI baseline profiles.
- `tests/`: smoke tests that verify the support utilities themselves.

From the repository root:

```bash
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
```

Sanitizer support checks:

```bash
cmake --preset asan-ubsan
cmake --build --preset asan-ubsan
ctest --preset asan-ubsan
```

Use `tsan` separately. Do not combine ThreadSanitizer with AddressSanitizer.
