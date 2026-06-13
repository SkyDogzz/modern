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

Core labs may also be replaced by passing evidence from
[diagnostic-placement.md](diagnostic-placement.md). Required projects and transfer
gates remain mandatory. Scoring, retention checkpoints, older-project revisions,
and transfer exercises are defined in
[assessment-and-retention.md](assessment-and-retention.md).

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

Complete Projects 15-20 and 23-24 in order. Project 20 is the combined ownership
mechanics sequence; identifiers 21-22 are retired and retained only to avoid
renumbering later projects.

**Route entry:** Professional Foundations. Pass the Phase 1 project gate and unseen
transfer exercise. Diagnostics may replace eligible labs, not the transfer.

Build seriously:

- Project 17: Bank Account Simulator

Use Project 19 as a reusable component and evolve Project 11 with Project 24 rather
than creating separate portfolio repositories. Projects 15-16, 18-20, and 23-24 may
remain focused labs or compact milestones. Class mechanics, lifetime, raw allocation
mechanics, copy/move behavior, Rule of Zero, ownership graphs, and error policy are
not optional knowledge.

## Phase 3 - Standard Library Route

Complete Projects 25-30 in order.

**Route entry:** Professional Foundations and Standard-Library Breadth. Pass the
Phase 2 project gate and unseen transfer exercise. Route B completion additionally
requires the facility inventory and breadth labs; Projects 25-33 alone do not
establish mostly full standard-library coverage.

Then complete the baseline requirements for all three breadth tracks:

- Project 31: Directory Analyzer
- Project 32: C++23 Table Printer
- Project 33: Testable Pomodoro Timer

Choose one of Projects 31-33 for portfolio-level depth. Keep the other two as
small, tested adapters. This satisfies the phase gate for filesystem, formatting,
and chrono without requiring three large repositories.

Build Project 25 as the portfolio seed. Treat Projects 28 and 30 as tested
extensions of the same data-processing track where practical.

Route B then requires B1-B10 from
[standard-library-breadth.md](standard-library-breadth.md). Surveys S1-S5 are
embedded in those labs. Passing Projects 25-33 without this work completes the
Professional Foundations use of the library, not the mostly-full breadth claim.

## Phase 4 - Abstraction Route

Complete Projects 34-41 in order.

**Route entry:** Professional Foundations and Advanced Language and Delivery.
Pass the Phase 3 project gate and unseen transfer exercise.

Keep Projects 34-41 as reusable libraries, design comparisons, or focused labs.
Select Project 34 or 37 for the package-and-release evolution track instead of
creating three separate portfolio repositories.

Projects 42 and 43 are optional specializations:

- Project 42: Serialization Customization Library
- Project 43: Type-Erased Command System

The core route teaches traits, variadics, customization protocols, and the design
tradeoffs of type erasure without requiring a beginner to implement a framework.

## Phase 5 - Concurrency and Performance Route

Complete Projects 44-51 in order.

**Route entry:** Professional Foundations and Advanced Language and Delivery.
Pass the Phase 4 project gate and unseen transfer exercise.

Project 49, Parallel File Hasher, is the portfolio project. Project 52 is an optional
specialization:

- Project 52: Profiled PMR Text Processor

Project identifier 53 is retired. Modules, coroutine generators, and `mdspan` moved
to D5-D7 in [cpp20-23-delta.md](cpp20-23-delta.md).

D1-D4 are mandatory for the Advanced Language and Delivery route. PMR and D5-D7 are
not part of the mandatory Phase 5 gate.

## Phase 6 - Delivery and Maintenance Route

Complete all four:

**Route entry:** Advanced Language and Delivery. Pass the Phase 5 unseen transfer
and D1-D4 gates, and provide one reusable tested library suitable for packaging.

- Project 54: Quality Engineering Pass
- Project 55: Package and Release One Project
- Project 56: Milestone-Driven Capstone
- Project 57: Maintenance and Patch Release

These are not cleanup tasks. They demonstrate that earlier code can be verified,
consumed, maintained, upgraded, and released.

## Main Quest Portfolio

A completed portfolio contains six evolving tracks:

1. **Todo and configuration:** Project 11 evolved through Project 24 and the quality
   pass.
2. **Build and package:** Project 14 evolved into one installed and released library
   using Project 34 or 37.
3. **Domain and concurrency:** Project 17 evolved through the transfer and locking
   exercises.
4. **Standard-library data tool:** Project 25 evolved through Projects 28-33.
5. **Concurrent file tool:** Project 31 evolved into Project 49.
6. **Released capstone:** Projects 56-57, including the maintenance patch.

Each track must pass the relevant phase gate. Revisions M2-M6 deliberately evolve
these artifacts instead of producing replacements. Intermediate labs remain
evidence in the learning log rather than becoming separate portfolio repositories.
