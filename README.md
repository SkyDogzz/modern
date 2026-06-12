# Modern C++23 Project Roadmap

A prerequisite-driven, project-based path from first compilation to packaging
and releasing modern C++ software.

## Curriculum Structure

1. Foundations and Workflow
2. Object Semantics, Lifetime, and Ownership
3. Standard Library Fluency
4. Generic Programming and Design
5. Concurrency and Advanced Facilities
6. Professional Delivery

Phase documents:

- [Phase 1 - Foundations and Workflow](phase-01-foundations.md)
- [Phase 2 - Object Semantics, Lifetime, and Ownership](phase-02-object-semantics.md)
- [Phase 3 - Standard Library Fluency](phase-03-standard-library-fluency.md)
- [Phase 4 - Generic Programming and Design](phase-04-generic-programming.md)
- [Phase 5 - Concurrency and Advanced Facilities](phase-05-concurrency-advanced.md)
- [Phase 6 - Professional Delivery](phase-06-professional-delivery.md)

The roadmap develops:

- language fundamentals and the C++ object model;
- ownership, lifetime, RAII, and value semantics;
- containers, algorithms, ranges, and modern error handling;
- templates, concepts, polymorphism, and type erasure;
- concurrency, profiling, and advanced facilities;
- testing, debugging, CMake, packaging, CI, and releases.

This repository is a curriculum roadmap, not a language reference. Use a current
C++ reference and compiler documentation when studying each project's concepts.

## Required Toolchain

- A compiler with usable C++23 language and library support
- CMake 3.25 or newer
- GDB, LLDB, or an equivalent debugger
- Git
- AddressSanitizer and UndefinedBehaviorSanitizer where supported
- ThreadSanitizer for concurrency projects where supported

Direct compiler examples use:

```bash
c++ -std=c++23 -Wall -Wextra -Wpedantic -g source.cpp -o app
```

CMake targets request C++23 explicitly:

```cmake
target_compile_features(app PRIVATE cxx_std_23)
```

Library support varies by compiler and standard-library version. Optional
features in Project 39 require feature detection and documented fallbacks.

## How to Use the Roadmap

For every project:

1. Read its prerequisites and learning outcomes.
2. Implement only the baseline requirements.
3. Pass every acceptance criterion.
4. Run the phase's warning, test, debugger, and sanitizer quality gate.
5. Record bugs, evidence, tradeoffs, and remaining questions.
6. Attempt stretch goals only after the baseline is explainable and tested.

Use [project-template.md](project-template.md) for project documentation and
[checklists.md](checklists.md) for phase gates.

## Repository Layout

```txt
modern-cpp-roadmap/
|-- README.md
|-- projects/
|   |-- 01-hello-cpp23/
|   |-- 02-character-stat-sheet/
|   `-- ...
|-- notes/
|   |-- phase-01-foundations.md
|   |-- phase-02-object-semantics.md
|   `-- ...
`-- playground/
```

Start with one source file. Add libraries, include directories, tests, presets,
installation, and packaging only when the relevant roadmap stage introduces them.

## Full Project Order

### Phase 1 - Foundations and Workflow

1. Hello C++23
2. Character Stat Sheet
3. Unit Converter
4. Expression Calculator
5. Number Guessing Game
6. Dice Roller
7. Inventory Editor
8. Interactive Todo List
9. Command-Line Greeter
10. Multi-File Build and Test Lab

### Phase 2 - Object Semantics, Lifetime, and Ownership

11. Lifetime and Storage Visualizer
12. Bank Account Simulator
13. RAII File Wrapper
14. Dynamic String Copy Lab
15. Movable Buffer and Rule of Zero Refactor
16. Dungeon Ownership Graph
17. Config Parser and Error Policy

### Phase 3 - Standard Library Fluency

18. Contact Book
19. Playlist Iterator Lab
20. Event Dispatcher and Callable Objects
21. Student Grade Analyzer
22. Data Processing with Ranges
23. Directory Analyzer
24. C++23 Table Printer
25. Testable Pomodoro Timer

### Phase 4 - Generic Programming and Design

26. Vector2 Value Type
27. Shape Design Comparison
28. Generic Stack
29. Compile-Time Math and Validation
30. Constrained Generic Algorithms
31. Serialization Customization Library
32. Type-Erased Command System

### Phase 5 - Concurrency and Advanced Facilities

33. Cancellable Worker
34. Blocking Queue and Deadlock Lab
35. Parallel File Hasher
36. Atomics and Memory Model Lab
37. Profiling Before Optimization
38. Profiled PMR Text Processor
39. Optional Modern Feature Tracks

### Phase 6 - Professional Delivery

40. Quality Engineering Pass
41. Package and Release One Project
42. Milestone-Driven Capstone

## Effort Model

Not every project should become a large repository:

- **Lab:** focused experiment, usually 1-6 hours.
- **Project:** tested component or application, usually 6-16 hours.
- **Delivery project:** packaging, CI, or capstone work, usually 16 hours or more.

Difficulty and time estimates are comparative, not guarantees. Stop at a phase
gate when you cannot explain the prerequisite concepts.

## Serious Project Recommendations

Build these as portfolio-quality checkpoints:

1. Interactive Todo List
2. Bank Account Simulator
3. RAII File Wrapper
4. Config Parser and Error Policy
5. Contact Book
6. Student Grade Analyzer
7. Data Processing with Ranges
8. Vector2 Value Type
9. Shape Design Comparison
10. Generic Stack
11. Parallel File Hasher
12. Package and Release One Project
13. Milestone-Driven Capstone

The remaining projects can be smaller labs, but their acceptance criteria still apply.

## Optional Topics

Modules, custom coroutine promise types, `std::mdspan`, PMR specialization, and
weak memory ordering are not required to write professional C++. Treat them as
focused advanced study after the core ownership, library, testing, and build
skills are reliable.
