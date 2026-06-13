# Compile-Fail Tests

Compile-fail tests prove that an invalid program is rejected. They are separate from
normal passing targets.

From the root project, `add_compile_fail_test(name source)` invokes the selected
compiler in C++23 mode and passes only when compilation fails. The sample narrowing
test is registered as `support.compile-fail.narrowing`.

Do not match complete diagnostic text across compilers. When wording matters, match
only a stable project-authored `static_assert` fragment.
