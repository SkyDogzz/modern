# Professional Foundations Quest

This is Route A from [curriculum-routes.md](curriculum-routes.md). It defines the
professional-foundations project order. The Standard-Library Breadth and Advanced
Language and Delivery routes have additional completion evidence and must not be
inferred from this file.

This quest limits portfolio-level effort, not prerequisite knowledge. Complete core
labs with the smallest implementation that proves the concept; invest substantial
design and documentation effort only in the named portfolio projects.

Optional specializations never block the next phase.

Core labs may use the [supplied starter and broken-code fixtures](projects/README.md)
and be completed as diagnosis, repair, compile-fail, or code-reading exercises when
the phase specification permits. They do not each require a standalone repository
or greenfield implementation.

## Phase 1 - Required Foundations

Complete Projects 1-14 in order.

**Route entry:** Professional Foundations. No earlier phase is required; compile one
C++23 source file before Project 1.

Build seriously:

- Project 11: Interactive Todo List
- Project 14: Target-Based CMake and Test Lab

Keep the remaining projects focused. This sequence supplies diagnostics, types,
integer behavior, conversions, control flow, functions, enums, arrays, vectors,
references, pointers, views, invalidation, CLI parsing, the translation model,
Git habits, a test framework, and target-based CMake.

## Phase 2 - Required Object Model

Complete Projects 15-24 in order.

**Route entry:** Professional Foundations. Pass the Phase 1 gate or its diagnostic
equivalent.

Build seriously:

- Project 17: Bank Account Simulator
- Project 19: RAII File Wrapper
- Project 24: Config Parser and Error Policy

Projects 15-16 and 18-23 may remain focused labs or compact projects. Class
mechanics, lifetime, raw allocation mechanics, copy/move behavior, Rule of Zero,
ownership graphs, and error policy are not optional knowledge.

## Phase 3 - Standard Library Route

Complete Projects 25-30 in order.

**Route entry:** Professional Foundations and Standard-Library Breadth. Pass the
Phase 2 gate or its transfer assessment. Route B completion additionally requires
the facility inventory and breadth labs; Projects 25-33 alone do not establish
mostly full standard-library coverage.

Then complete the baseline requirements for all three breadth tracks:

- Project 31: Directory Analyzer
- Project 32: C++23 Table Printer
- Project 33: Testable Pomodoro Timer

Choose one of Projects 31-33 for portfolio-level depth. Keep the other two as
small, tested adapters. This satisfies the phase gate for filesystem, formatting,
and chrono without requiring three large repositories.

Build Projects 25, 28, and 30 seriously.

## Phase 4 - Abstraction Route

Complete Projects 34-41 in order.

**Route entry:** Professional Foundations and Advanced Language and Delivery.
Demonstrate object lifetime, error policy, container, iterator, and range
competencies.

Build seriously:

- Project 34: Vector2 Regular Value Type
- Project 36: Shape Design Comparison
- Project 37: Generic Stack

Projects 42 and 43 are optional specializations:

- Project 42: Serialization Customization Library
- Project 43: Type-Erased Command System

The core route teaches traits, variadics, customization protocols, and the design
tradeoffs of type erasure without requiring a beginner to implement a framework.

## Phase 5 - Concurrency and Performance Route

Complete Projects 44-51 in order.

**Route entry:** Professional Foundations and Advanced Language and Delivery.
Demonstrate RAII, callable lifetime, testing, and deterministic cleanup.

Project 49, Parallel File Hasher, is the portfolio project. Projects 52 and 53 are
optional specializations:

- Project 52: Profiled PMR Text Processor
- Project 53: Optional Modern Feature Tracks

PMR, modules, coroutines, and `mdspan` are not part of the mandatory Phase 5 gate.

## Phase 6 - Delivery and Maintenance Route

Complete all four:

**Route entry:** Advanced Language and Delivery. Pass the Phase 5 gate and provide
one reusable tested library suitable for packaging.

- Project 54: Quality Engineering Pass
- Project 55: Package and Release One Project
- Project 56: Milestone-Driven Capstone
- Project 57: Maintenance and Patch Release

These are not cleanup tasks. They demonstrate that earlier code can be verified,
consumed, maintained, upgraded, and released.

## Main Quest Portfolio

A completed portfolio should contain:

1. Interactive Todo List
2. Target-Based CMake and Test Lab
3. Bank Account Simulator
4. RAII File Wrapper
5. Config Parser and Error Policy
6. Contact Book and Container Selection
7. Student Grade Analyzer
8. Data Processing with Ranges
9. One system-library track project
10. Vector2 Regular Value Type
11. Shape Design Comparison
12. Generic Stack
13. Parallel File Hasher
14. Released Library
15. Capstone
16. Maintenance and Patch Release

Every portfolio project must pass the relevant phase gate in `checklists.md`.
