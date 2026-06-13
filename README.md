# Modern C++23 Project Roadmap

A prerequisite-driven path from first compilation to standard-library breadth,
advanced language work, and independently building, testing, packaging, releasing,
and maintaining modern C++ software.

This repository provides three explicit routes: **professional foundations**,
**standard-library breadth**, and **advanced language and delivery**. "Mostly full
standard library" means core mastery or working familiarity across the documented
facility inventory, with survey or reference-only treatment for specialized areas.
It does not mean memorizing every declaration or mastering every platform API.

See [curriculum-routes.md](curriculum-routes.md) for completion claims, prerequisites,
time ranges, and coverage tiers. Use the concept briefs, a current C++ reference,
compiler documentation, code review, and sustained practice together.

The authoritative standard-library mapping is
[stdlib-facility-inventory.md](stdlib-facility-inventory.md). Compiler and library
capabilities are recorded using [toolchain-support.md](toolchain-support.md).

## AI Disclosure and Learning Policy

All README files and roadmap documentation in this repository were created using
artificial intelligence (AI).

Advice: do not use AI to implement, complete, debug, or test the projects in
this curriculum. Write the project code and tests yourself, investigate failures
yourself, and be able to explain every result. Learning to design tests, identify
edge cases, and understand failures is as important as learning to code.

## Curriculum Structure

1. Language Foundations and Workflow
2. Classes, Lifetime, Ownership, and Errors
3. Standard Library and Data Processing
4. Generic Programming and Design
5. Concurrency, Performance, and Advanced Facilities
6. Delivery and Maintenance

Routes:

- **Professional Foundations:** baseline Projects 1-51.
- **Standard-Library Breadth:** Phase 3 plus the required facility inventory and
  breadth labs.
- **Advanced Language and Delivery:** Phases 4-6 plus the mandatory C++20-to-C++23
  delta work.

Optional specializations never become mandatory merely because they appear in a
phase document.

Phase documents:

- [Phase 1 - Language Foundations and Workflow](phase-01-foundations.md)
- [Phase 2 - Classes, Lifetime, Ownership, and Errors](phase-02-object-semantics.md)
- [Phase 3 - Standard Library and Data Processing](phase-03-standard-library-fluency.md)
- [Phase 4 - Generic Programming and Design](phase-04-generic-programming.md)
- [Phase 5 - Concurrency, Performance, and Advanced Facilities](phase-05-concurrency-advanced.md)
- [Phase 6 - Delivery and Maintenance](phase-06-professional-delivery.md)

Use [concept-briefs.md](concept-briefs.md) before each project,
[project-template.md](project-template.md) for project records, and
[checklists.md](checklists.md) for phase gates. Route entry and completion are defined
only in [curriculum-routes.md](curriculum-routes.md).

## Project Categories

- **Core lab:** small, focused prerequisite work. Complete it, but keep it small.
- **Core project:** integrated work required for progression.
- **Portfolio project:** a core project worth polishing for external review.
- **Track project:** required breadth work where only one sibling project needs
  portfolio-level depth.
- **Optional specialization:** advanced work that does not block later phases.
- **Delivery project:** verification, release, capstone, or maintenance work.

Every core lab and core project is required. Optional specializations are never
part of a mandatory phase gate.

## Learning Method

For every project:

1. Read the linked concept brief and complete its review questions.
2. Explain the prerequisite rules before writing code.
3. Implement only the baseline requirements.
4. Pass every acceptance criterion and the current phase quality gate.
5. Record one defect, the evidence used to diagnose it, and the correction.
6. Attempt stretch goals only after the baseline is explainable and tested.

A project applies knowledge; it must not be the learner's first unexplained
encounter with that knowledge.

## Required Toolchain

- A compiler and standard library with usable C++23 support
- CMake 3.25 or newer
- GDB, LLDB, or an equivalent debugger
- Git
- A formatter such as `clang-format`
- AddressSanitizer and UndefinedBehaviorSanitizer where supported
- ThreadSanitizer for concurrency projects where supported
- A maintained unit-test framework by Project 14

Direct compiler examples use the command for the selected profile.

GCC or Clang:

```bash
c++ -std=c++23 -Wall -Wextra -Wpedantic -g source.cpp -o app
```

MSVC developer shell:

```bat
cl /std:c++latest /permissive- /W4 /EHsc /Zi source.cpp
```

CMake targets request C++23 explicitly and disable vendor language extensions:

```cmake
target_compile_features(app PRIVATE cxx_std_23)
set_target_properties(app PROPERTIES CXX_EXTENSIONS OFF)
```

Single-config and multi-config generators use different configuration commands and
output layouts. Use the matching commands in
[project-template.md](project-template.md). Library support varies by compiler and
standard-library version; follow [toolchain-support.md](toolchain-support.md) rather
than inferring support from language mode.

## Testing and Tooling Progression

1. Project 1 uses a direct compiler command without test infrastructure.
2. Projects 2-5 add CTest smoke checks and a supplied minimal assertion pattern.
3. Projects 6-13 use focused test executables while language structure remains the
   primary objective.
4. Project 14 adopts one maintained test framework or a documented repository
   harness.
5. Phases 2-4 add fixtures, compile-fail tests, sanitizers, formatting, static
   analysis, and basic CI incrementally.
6. Phases 5-6 add stress tests, TSan, benchmarks, fuzzing, coverage, packaging,
   release verification, and maintenance tests.

## Repository Layout

```txt
modern-cpp-roadmap/
|-- README.md
|-- curriculum-routes.md
|-- stdlib-facility-inventory.md
|-- toolchain-support.md
|-- concept-briefs.md
|-- checklists.md
|-- main-quest.md
|-- project-template.md
|-- phase-01-foundations.md
|-- phase-02-object-semantics.md
|-- phase-03-standard-library-fluency.md
|-- phase-04-generic-programming.md
|-- phase-05-concurrency-advanced.md
|-- phase-06-professional-delivery.md
|-- projects/
|   |-- 01-compile-run-diagnostics/
|   `-- ...
`-- playground/
```

Start with one source file. Add source libraries, public include directories,
install rules, and packaging only when the relevant project introduces them.

## Full Project Order

### Phase 1 - Language Foundations and Workflow

1. Compile, Run, and Read Diagnostics - core lab
2. Debugger, CMake, and Smoke-Test Orientation - core lab
3. Character Stat Sheet - core lab
4. Integer and Conversion Lab - core lab
5. Unit Converter - core project
6. Expression Calculator - core project
7. Number Guessing Game - core lab
8. Dice Roller and Basic Containers - core project
9. References, Pointers, and Views Lab - core lab
10. Inventory Editor - core project
11. Interactive Todo List - portfolio project
12. Command-Line Greeter - core project
13. Compilation and Linking Lab - core lab
14. Target-Based CMake and Test Lab - portfolio project

### Phase 2 - Classes, Lifetime, Ownership, and Errors

15. Class and Special-Member Mechanics - core lab
16. Lifetime and Storage Visualizer - core lab
17. Bank Account Simulator - portfolio project
18. Error-Handling Policy Lab - core lab
19. RAII File Wrapper - portfolio project
20. Raw Allocation Mechanics - core lab
21. Dynamic String Copy Lab - core lab
22. Movable Buffer and Rule of Zero Refactor - core project
23. Dungeon Ownership Graph - core project
24. Config Parser and Error Policy - portfolio project

### Phase 3 - Standard Library and Data Processing

25. Contact Book and Container Selection - portfolio project
26. Playlist Iterator Lab - core lab
27. Event Dispatcher and Callable Objects - core project
28. Student Grade Analyzer - portfolio project
29. Range, View, and Sentinel Lab - core lab
30. Data Processing with Ranges - portfolio project
31. Directory Analyzer - track project
32. C++23 Table Printer - track project
33. Testable Pomodoro Timer - track project

### Phase 4 - Generic Programming and Design

34. Vector2 Regular Value Type - portfolio project
35. Runtime Polymorphism Safety Lab - core lab
36. Shape Design Comparison - portfolio project
37. Generic Stack - portfolio project
38. Template Mechanics Lab - core lab
39. Compile-Time Math and Validation - core project
40. Constrained Generic Algorithms - core project
41. Traits, Variadics, and Customization Lab - core lab
42. Serialization Customization Library - optional specialization
43. Type-Erased Command System - optional specialization

### Phase 5 - Concurrency, Performance, and Advanced Facilities

44. Thread Lifecycle and Data-Race Lab - core lab
45. Mutex Invariants and Deadlock Lab - core lab
46. Blocking Queue - core project
47. Cancellable Worker - core project
48. Task Results with Futures and Promises - core lab
49. Parallel File Hasher - portfolio project
50. Atomics and Memory Model Lab - core lab
51. Profiling Before Optimization - core project
52. Profiled PMR Text Processor - optional specialization
53. Optional Modern Feature Tracks - optional specialization

### Phase 6 - Delivery and Maintenance

54. Quality Engineering Pass - delivery project
55. Package and Release One Project - delivery project
56. Milestone-Driven Capstone - delivery project
57. Maintenance and Patch Release - delivery project

## Effort Model

- **Micro-lab:** 1-3 hours.
- **Core lab:** 3-8 hours.
- **Core or track project:** 6-16 hours.
- **Portfolio project:** 12-24 hours including documentation and review.
- **Delivery project:** 16 hours or more.

Estimates are comparative. Beginner completion data should be used to revise them.
Stop at a phase gate when prerequisite concepts cannot be explained.

Current and target route totals:

- **Professional Foundations:** 329-483 hours for Projects 1-51.
- **Standard-Library Breadth:** 156-236 hours after Phase 2, or 286-426 hours from
  the beginning.
- **Advanced Language and Delivery:** 257-405 hours after Phase 3, including the
  reserved C++20-to-C++23 delta work.

Calendar examples at 6, 10, and 15 hours per week are maintained in
[curriculum-routes.md](curriculum-routes.md). Optional specializations are excluded
from these totals.

## Portfolio Route

The authoritative portfolio route is defined in [main-quest.md](main-quest.md).
README does not duplicate that list.

## Optional Specializations

Modules, custom coroutine promise types, `std::mdspan`, PMR specialization,
manual type erasure, serialization frameworks, and weak memory ordering are not
required to write professional C++. Treat them as focused advanced study after
ownership, library, testing, build, and concurrency fundamentals are reliable.
