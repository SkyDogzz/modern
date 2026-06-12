# Project Template

Use this template for every roadmap project. A project is complete only when its
acceptance criteria and quality gate pass.

## Project Name

`project-name-here`

**Prerequisites:** List earlier projects or concepts that must already be understood.

**Difficulty:** 1/5

**Estimated time:** 2-4 hours

**CMake stage:** State the build-system skill added or practiced.

## Learning Outcomes

After completing this project, the learner can:

- explain outcome 1;
- implement outcome 2;
- diagnose outcome 3.

## Goal

Describe the observable behavior of the program and why this project exists.

## Non-Goals

- State features or techniques intentionally excluded from this project.
- Keep the project focused on its learning outcomes.

## Requirements

- [ ] Requirement 1
- [ ] Requirement 2
- [ ] Requirement 3

## Acceptance Criteria

- [ ] The minimum behavior is demonstrated with documented example commands.
- [ ] Invalid input and failure paths have defined behavior.
- [ ] Automated tests cover the core logic where the current phase requires tests.
- [ ] The project builds with the phase warning and sanitizer configuration.
- [ ] The README explains the design, ownership model, and error policy.

## Stretch Goals

- [ ] Stretch goal 1
- [ ] Stretch goal 2

## Suggested File Structure

Use only as much structure as the current phase needs:

```txt
project/
|-- CMakeLists.txt
|-- README.md
|-- include/
|-- src/
`-- tests/
```

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

All targets must request C++23 through CMake:

```cmake
target_compile_features(app PRIVATE cxx_std_23)
```

Do not rely only on a global `CMAKE_CXX_STANDARD` setting once the roadmap
introduces target-based CMake.

## Run

```bash
./build/app
```

## Tests

```bash
ctest --test-dir build --output-on-failure
```

Record which of these are currently expected:

- smoke tests;
- unit tests;
- integration tests;
- sanitizer runs;
- fuzz or property tests;
- concurrency tests.

## Quality Gate

- [ ] Warnings are enabled and understood.
- [ ] Formatting has been applied.
- [ ] The debugger or a sanitizer was used for at least one diagnosed defect.
- [ ] No ownership or lifetime rule is left implicit.
- [ ] Public interfaces document errors and invalid inputs.

## Notes

Write what you learned and which assumptions changed.

## Mistakes Encountered

Record bugs, misunderstandings, diagnostic evidence, and fixes.

## What I Would Improve

List concrete technical improvements, not only additional features.
