# Diagnostic Placement and Competency Prerequisites

The roadmap is prerequisite-driven, not attendance-driven. A learner may replace a
core lab with diagnostic evidence when they already possess the competency. Core
projects, breadth assessments, portfolio milestones, and delivery projects are not
skippable, but an existing artifact may be upgraded instead of rebuilt.

## Competency Codes

| Code | Competency | Minimum evidence |
|---|---|---|
| F1 | Compile, run, read diagnostics, and use a debugger | Repair one compile defect and one runtime defect |
| F2 | Initialization, conversions, control flow, functions, records | Pass a closed-book implementation task |
| F3 | References, pointers, views, invalidation, and CLI text | Diagnose two lifetime or bounds defects |
| F4 | Translation units, target CMake, tests, Git | Build and test a clean multi-file target |
| O1 | Classes, invariants, storage duration, lifetime | Explain and repair an invariant/lifetime defect |
| O2 | RAII, ownership, and error policies | Implement one fallible resource owner |
| O3 | Copy, move, value categories, Rule of Zero | Diagnose copy/move behavior and refactor to Rule of Zero |
| L1 | Containers, iterators, invalidation, callables | Complete a selection and invalidation task |
| L2 | Algorithms, ranges, views, materialization | Implement equivalent classic/ranges pipelines |
| L3 | Filesystem, formatting, chrono adapters | Test one injected system-facing adapter |
| G1 | Regular values, polymorphism, composition | Compare two designs against one behavior contract |
| G2 | Templates, constraints, constant evaluation | Pass one implementation and one compile-fail task |
| C1 | Thread ownership and synchronization readiness | Explain RAII cleanup and callback lifetime |

## Placement Rules

1. Take the diagnostic without notes or AI assistance.
2. Record commands, output, reasoning, and reviewer result.
3. Score the diagnostic with the
   [project rubric](assessment-and-retention.md#project-rubric). It passes at 12/15
   or better only when Behavior, Verification, and Reasoning are each at least 2 and
   every diagnostic criterion passes.
4. Failed evidence sends the learner to the corresponding lab; partial credit does
   not remove prerequisites.
5. A skipped lab is recorded as `diagnostic-equivalent`, not marked as implemented.
6. Reattempt after remediation uses a different fixture.
7. Phase transfer assessments and final route gates cannot be skipped.

## Phase Entry

| Phase | Required competencies |
|---|---|
| 1 | Toolchain smoke check |
| 2 | F1-F4 |
| 3 | F1-F4 and O1-O3 |
| 4 | O1-O3 and L1-L2 |
| 5 | O1-O3, L1-L2, G1-G2, and C1 |
| 6 | All prior phase gates plus one reusable tested library |

## Project-Level Use

A project prerequisite should name competency codes and only the specific earlier
artifact it extends. "Complete all prior phases" is not sufficient unless the
project genuinely integrates every prior phase gate.

## Default Diagnostic and Repair Labs

These labs should start from a small provided defect, earlier learner artifact, or
compile-fail fixture rather than a greenfield repository:

| Projects | Default task |
|---|---|
| 15-16 | Predict and repair special-member, initialization-order, and lifetime defects |
| 18 | Adapt one operation across error policies and diagnose guarantee violations |
| 20 | Repair the provided raw owner, then refactor to Rule of Zero |
| 26 and 29 | Diagnose iterator invalidation and dangling-view cases |
| 35 | Repair slicing and polymorphic-destruction defects |
| 38 and 41 | Repair template diagnostics and unsupported customization calls |
| 44-45 | Repair a thread ownership race and an isolated deadlock |
| 48 and 50 | Diagnose broken-promise, atomicity, and ordering mistakes |

The learner writes the final tests and explanation. Starting from a defect changes
the exercise shape, not the pass standard.
