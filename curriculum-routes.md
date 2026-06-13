# Curriculum Routes

The roadmap has three routes with different completion claims. They share projects,
but each topic has one primary route owner so required and optional work remain
unambiguous.

## Coverage Terms

"Mostly full standard library" does not mean memorizing every declaration or
completing every specialization. It means:

- **Core mastery:** select, use, test, and explain the facility without
  step-by-step guidance.
- **Working familiarity:** complete a focused exercise, explain the facility's
  purpose and hazards, and use a reference for exact APIs.
- **Survey:** identify when the area applies, its major limitations, and the next
  reference to consult.
- **Reference only:** recognize specialized, obsolete, or implementation-sensitive
  facilities without requiring implementation practice.

The Standard-Library Breadth route is complete only when every inventory item marked
Core mastery or Working familiarity has assessment evidence. A Survey item requires
the named comparison or review exercise. Reference-only items never block completion.
The authoritative mapping is
[stdlib-facility-inventory.md](stdlib-facility-inventory.md).

## Route A: Professional Foundations

**Purpose:** independently build, test, debug, and maintain modern C++ programs with
sound ownership, error handling, generic design, concurrency, and measurement habits.

**Required work:** the baseline requirements through Project 51, excluding retired
identifiers 21-22. Project 52 is optional and identifier 53 is retired. Phase 6 is
part of Route C.

**Current project estimate:** 272-402 hours.

**Completion claim:** professional C++ foundations through C++23 mode. This route does
not claim broad standard-library coverage or mastery of every C++20/C++23 addition.

### Rebalanced Time Budget

The previous baseline estimate was 329-483 hours. Combining the former Projects
20-22, using diagnosis-first core labs, and reducing portfolio duplication lowers the
baseline to 272-402 hours, recovering 57-81 hours.

The recovered budget is assigned deliberately:

- 40-60 hours to required standard-library breadth labs;
- 17-21 hours to retrieval practice, transfer assessments, and remediation.

This allocation is part of the route design; the removed portfolio polishing work is
not silently replaced with additional greenfield projects.

## Route B: Standard-Library Breadth

**Purpose:** gain core mastery or working familiarity across most major standard
library areas while learning to retrieve exact signatures and guarantees from current
references.

**Prerequisites:** Phase 1 and Phase 2 competencies. A learner may begin the breadth
route after passing the Phase 2 transfer assessment.

**Required work:**

1. Projects 25-33;
2. every Core mastery and Working familiarity item in the facility inventory;
3. B1-B10 in [standard-library-breadth.md](standard-library-breadth.md);
4. the final facility-selection and documentation-navigation assessment.

**Target estimate:** 148-225 hours after Phase 2, including the existing Phase 3
estimate of 58-85 hours. The complete route from a new learner therefore targets
254-383 hours.

**Completion claim:** mostly full standard-library breadth at the documented tiers,
not memorization of every overload, locale facet, C compatibility declaration, or
specialized numerical facility.

Toolchain evidence follows [toolchain-support.md](toolchain-support.md); unavailable
facilities cannot be silently counted as complete.

## Route C: Advanced Language and Delivery

**Purpose:** study advanced abstraction and selected modern language facilities, then
verify, package, release, and maintain software.

**Prerequisites:** Phase 3 competencies. Individual advanced projects list narrower
competency prerequisites where possible.

**Required work:**

1. Projects 34-51;
2. D1-D4 in [cpp20-23-delta.md](cpp20-23-delta.md);
3. Projects 54-57.

Projects 42, 43, 52, and D5-D7 remain optional unless explicitly selected as a
specialization. Project identifier 53 is retired.

**Target estimate:** 232-367 hours after Phase 3, including 24-40 hours reserved for
the mandatory language/library delta work.

**Completion claim:** advanced language foundations plus demonstrated verification,
packaging, release, and maintenance practice. It does not claim expertise in every
platform, ABI, coroutine implementation, or module toolchain.

## Phase Entry Map

| Phase | Required route context | Entry evidence |
|---|---|---|
| 1. Language Foundations | Route A | Toolchain can compile one C++23 source file |
| 2. Object Semantics | Route A | Phase 1 gate or diagnostic equivalent |
| 3. Standard Library | Routes A and B | Phase 2 gate or transfer assessment |
| 4. Generic Programming | Routes A and C | Object lifetime, error policy, containers, and ranges diagnostics |
| 5. Concurrency and Performance | Routes A and C | Ownership, callable lifetime, testing, and RAII diagnostics |
| 6. Delivery and Maintenance | Route C | Phase 5 and D1-D4 gates plus one reusable tested library |

Optional specializations never satisfy missing entry evidence and never block the
next required phase.

## Topic Ownership

| Topic family | Primary route |
|---|---|
| Syntax, object lifetime, ownership, errors, build, tests | Professional Foundations |
| Standard containers, algorithms, ranges, text, I/O, numerics, time, filesystem | Standard-Library Breadth |
| Templates, advanced abstraction, concurrency, performance | Advanced Language and Delivery |
| C++20/C++23 language and library delta | Advanced Language and Delivery |
| Packaging, releases, compatibility, maintenance | Advanced Language and Delivery |

Projects may use earlier topics, but their assessment belongs to the primary route.
This prevents an incidental mention from being counted as coverage.

## Calendar Examples

These calendars use the current or target estimates and exclude optional
specializations:

| Route | 6 hours/week | 10 hours/week | 15 hours/week |
|---|---:|---:|---:|
| Professional Foundations | 46-67 weeks | 28-41 weeks | 19-27 weeks |
| Standard-Library Breadth from beginner | 43-64 weeks | 26-39 weeks | 17-26 weeks |
| Advanced Language and Delivery after Phase 3 | 39-62 weeks | 24-37 weeks | 16-25 weeks |

These are planning ranges, not promises. Record actual completion time and revise the
estimates from learner evidence.
