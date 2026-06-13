# Project Template

Use this template for roadmap projects. A project is complete only when its
acceptance criteria and current phase gate pass.

## Project Name

`project-name-here`

**Category:** Core lab, core project, portfolio project, track project, optional
specialization, or delivery project.

**Prerequisites:** Earlier projects and concept-brief sections that must already be
understood.

**Difficulty:** 1/5

**Estimated time:** 2-4 hours

**Tooling stage:** State the build, test, analysis, or delivery skill added.

## Concept Check

Before implementation, answer three to five prerequisite questions without notes.
Link to the relevant section of `concept-briefs.md`.

## Learning Outcomes

After completing this project, the learner can:

- explain outcome 1;
- implement outcome 2;
- diagnose outcome 3.

## Goal

Describe observable behavior and why the project exists.

## Non-Goals

- State features or techniques intentionally excluded.
- Keep the project focused on its learning outcomes.

## Requirements

- [ ] Requirement 1
- [ ] Requirement 2
- [ ] Requirement 3

## Acceptance Criteria

- [ ] Minimum behavior is demonstrated with documented commands.
- [ ] Invalid input and relevant failure paths have defined behavior.
- [ ] Automated tests cover the core logic required by the current phase.
- [ ] The current phase warning, formatter, analyzer, and sanitizer expectations pass.
- [ ] Ownership, lifetime, and error policy are documented, or marked not
      applicable with a reason.

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

Early core labs may use one source file. Do not create public include directories
or library targets before the roadmap introduces the translation and CMake model.

## Build

Single-config generator:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Multi-config generator:

```bash
cmake -S . -B build-multi
cmake --build build-multi --config Debug
```

All CMake targets request C++23 without vendor extensions:

```cmake
target_compile_features(app PRIVATE cxx_std_23)
set_target_properties(app PROPERTIES CXX_EXTENSIONS OFF)
```

Do not rely only on global `CMAKE_CXX_STANDARD` after target-based CMake is taught.
Do not pass `CMAKE_BUILD_TYPE` to a multi-config generator.

## Run

Single-config Unix-like example:

```bash
./build/app
```

Multi-config output commonly includes the configuration directory, for example:

```bat
build-multi\Debug\app.exe
```

Document the actual target path produced by the selected generator. Prefer CTest for
portable automated execution instead of hard-coding executable paths in scripts.

## Tests

Single-config:

```bash
ctest --test-dir build --output-on-failure
```

Multi-config:

```bash
ctest --test-dir build-multi -C Debug --output-on-failure
```

Record which are expected at the current stage:

- smoke tests;
- unit tests;
- integration tests;
- compile-fail tests;
- sanitizer runs;
- property or fuzz tests;
- concurrency stress tests;
- clean-consumer package tests.

## Quality Gate

- [ ] Warnings are enabled and understood.
- [ ] C++23 mode is requested and vendor language extensions are disabled unless a
      documented platform-specific target requires them.
- [ ] The repository formatter configuration has been applied.
- [ ] The relevant debugger, sanitizer, analyzer, or profiler was used.
- [ ] Public interfaces document invalid inputs and errors.
- [ ] `git diff` was reviewed and generated files are not tracked.

## Evidence

Record commands, representative output, defect reproduction, diagnosis, and fix.

## Notes

Write what was learned and which assumptions changed.

## What I Would Improve

List concrete technical improvements, not only additional features.
