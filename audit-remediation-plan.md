# Audit Remediation Plan

This backlog orders changes by dependency and impact. It is designed to expand
standard-library coverage without simply adding hundreds of hours to the existing
route.

## Task 1: Define Curriculum Claims and Routes

Priority: P0

- Keep the existing professional-foundations route.
- Add a standard-library breadth route.
- Add an advanced language and delivery route.
- State which route is required before each phase or project.
- Define "mostly full standard library" using the tier model in
  `stdlib-coverage-audit.md`.
- Publish expected hours and weekly calendar examples for each route.

Completion evidence:

- README contains unambiguous scope claims.
- Every required topic belongs to exactly one route and coverage tier.
- Optional topics cannot be mistaken for required mastery.

## Task 2: Add a Facility Coverage Inventory

Priority: P0

- Create a checklist organized by standard-library area.
- Record facility, header, standard version, coverage tier, project, and assessment.
- Add a C++20/C++23 delta column.
- Record feature-test macros and fallback requirements.
- Define the minimum supported compiler and standard-library combinations.

Completion evidence:

- Every core and working-familiarity facility maps to an exercise.
- No phase gate can pass with an unrecorded unsupported feature.

## Task 3: Supply the Missing Curriculum Infrastructure

Priority: P0

- Add `projects/` and `playground/`.
- Supply the minimal assertion helper used by early projects.
- Add starter and broken-code fixtures.
- Add compile-fail test infrastructure.
- Add sanitizer presets.
- Add allocator-failure injection for the ownership lab.
- Add the type-erasure structural scaffold.
- Add a reusable package skeleton.
- Add single-config and multi-config build instructions.
- Add one pinned CI example.

Completion evidence:

- Every occurrence of "supplied" links to an existing file.
- A clean checkout can start Project 1 and the first scaffolded project.
- The root documentation does not advertise absent paths.

## Task 4: Correct Technical Specifications

Priority: P0

- Correct the data-race definition in `concept-briefs.md`.
- Correct floating-value equality wording in Phase 1.
- Replace the range-view storage-owner criterion.
- Make Project 44 thread ownership exception-safe.
- Replace the unenforceable callback-capture requirement with a lifetime contract.
- Add explicit close/finalization error handling to the RAII file project.
- Disable C++ compiler extensions deliberately where portability is intended.

Completion evidence:

- Updated wording agrees across briefs, projects, and phase gates.
- Each changed rule has a testable acceptance criterion.

## Task 5: Rebalance Existing Mandatory Work

Priority: P1

- Merge Projects 20-22 into one scaffolded ownership mechanics sequence.
- Convert more core labs from greenfield implementations into diagnosis and repair.
- Reduce the portfolio from 16 artifacts to 4-6 evolving projects.
- Replace phase-wide prerequisites with competency prerequisites.
- Allow diagnostic skip tests for existing skills.

Target:

- Recover at least 50-80 hours before adding standard-library breadth.

Completion evidence:

- Revised mandatory estimate is published.
- Removed hours are assigned explicitly to library breadth or retention.

## Task 6: Expand Standard-Library Breadth

Priority: P1

Add focused required labs for:

1. vocabulary and general utilities;
2. complete container families and adaptors;
3. iterator adaptors and algorithm families;
4. numerics, math, random, and bit utilities;
5. streams, formatting, files, and buffers;
6. chrono calendars/time zones and filesystem breadth;
7. concurrency coordination, atomic wait/ref, and execution policies;
8. C++23 library additions.

Add survey modules for:

- regex;
- localization;
- C compatibility;
- diagnostics and runtime support;
- allocators and PMR.

Completion evidence:

- Every area rated Absent or Thin in `stdlib-coverage-audit.md` is intentionally
  upgraded or marked survey/reference-only with a reason.

## Task 7: Add a C++20-to-C++23 Delta Phase

Priority: P1

- Separate language features from library features.
- Teach feature-test macros and implementation detection.
- Cover representative C++20 prerequisites, including concepts, ranges, coroutines,
  modules, formatting, chrono expansion, and synchronization primitives.
- Cover representative C++23 language changes.
- Cover representative C++23 library additions.
- Keep implementation-sensitive projects optional, but make conceptual comparison
  and feature detection mandatory.

Completion evidence:

- The learner can explain which standard introduced each selected facility.
- The learner can compile a feature inventory and document fallbacks.

## Task 8: Add Objective Assessment and Retention

Priority: P1

- Add scoring rubrics and pass thresholds.
- Add expected evidence to subjective acceptance criteria.
- Add review-question answer guidance.
- Add one unseen transfer exercise per phase.
- Schedule closed-book retrieval after approximately 2, 6, and 15 projects.
- Require modifications to older projects in later phases.
- Add remediation rules for failed gates.

Completion evidence:

- Two reviewers can reach similar pass/fail decisions.
- Phase completion requires more than self-attestation.

## Task 9: Add References and Compatibility Records

Priority: P2

- Add stable references to every concept brief.
- Prefer standard drafts, official compiler documentation, and maintained library
  references.
- Record the date and supported versions for compatibility statements.
- Add a support table for GCC/libstdc++, Clang/libc++, and MSVC where practical.
- Distinguish standard requirements from implementation limitations.

Completion evidence:

- Every compatibility workaround has a source and review date.
- Learners can verify exact signatures and guarantees without relying on AI text.

## Recommended Implementation Order

1. Tasks 1-4 establish truthful scope and correct specifications.
2. Task 5 creates capacity for the broader goal.
3. Tasks 6-7 add the missing C++ and standard-library breadth.
4. Task 8 makes completion measurable and improves retention.
5. Task 9 improves long-term maintenance and traceability.

