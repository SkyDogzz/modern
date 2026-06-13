# Current Curriculum Audit

Audit date: 2026-06-13

## Scope

This audit reviewed the current documentation-only repository as:

- a prerequisite-driven C++ learning curriculum;
- a roadmap toward C++23;
- a roadmap intended to teach most of the C++ standard library;
- an executable project specification with build, test, and assessment guidance.

The review covered all 11 current Markdown files, 3,922 lines, and Projects 1-57.
The pre-existing deletion of `curriculum-audit.md` was treated as intentional and
was not reverted.

## Executive Verdict

The repository is a strong roadmap for modern C++ professional foundations. It is
particularly good at ownership, lifetime, error policies, concurrency shutdown,
testing discipline, packaging, release work, and maintenance.

It does not currently meet the intended goal of teaching mostly the full standard
library. Its documented scope explicitly stops at professional foundations:
`README.md:6`. Large standard-library areas are absent or receive only survey-level
coverage.

The roadmap is also not executable exactly as written because it refers to supplied
resources and directories that are not present.

## Prioritized Findings

### Critical: Standard-Library Coverage Does Not Match the Intended Goal

Phase 3 covers selected containers, algorithms, ranges, callables, filesystem,
formatting, and chrono: `phase-03-standard-library-fluency.md:8`.

This is a useful practical subset, but not mostly full standard-library coverage.
Major missing or shallow areas include:

- general utilities such as `pair`, `tuple`, `any`, `bitset`, and broader
  `<functional>` facilities;
- systematic stream I/O, stream state, file streams, string streams, span streams,
  stream buffers, and synchronized output;
- numeric algorithms, mathematical functions, complex numbers, bit operations,
  numeric constants, ratios, and floating-point facilities;
- regular expressions and localization;
- diagnostics and runtime support such as `source_location`, `stacktrace`, RTTI,
  exception utilities, and termination behavior;
- several container families and advanced container operations;
- iterator adaptors and iterator utilities;
- broad algorithm families and execution policies;
- significant C++23 library additions.

See `stdlib-coverage-audit.md` for the detailed matrix.

### Critical: The Curriculum Is Not Self-Contained

The documented repository layout contains `projects/` and `playground/`, but neither
directory exists: `README.md:109`.

The curriculum also requires resources that are not present:

- a supplied minimal assertion pattern: `README.md:99`;
- supplied starter code: `main-quest.md:10`;
- allocator-failure injection: `phase-02-object-semantics.md:272`;
- supplied type-erasure structural guidance:
  `phase-04-generic-programming.md:442`;
- a supplied package skeleton: `phase-06-professional-delivery.md:92`.

A learner cannot follow these requirements reproducibly without inventing missing
infrastructure.

### High: C++23 Mode Is Not a C++23 Curriculum

The build requests C++23, but there is no structured C++20-to-C++23 language and
library delta.

C++23 range additions are only a stretch goal:
`phase-03-standard-library-fluency.md:273`. Modules, generators, and `mdspan` are
optional tracks grouped under concurrency and performance:
`phase-05-concurrency-advanced.md:407`.

A dedicated delta section should cover representative C++20 and C++23 changes,
feature-test macros, implementation support, fallbacks, and the difference between
language and library features.

### High: The Required Route Is Large and Strictly Serial

The mandatory project estimates total approximately 429-651 hours. This excludes
reading, environment setup, failed attempts, remediation, review, and optional
specializations.

At ten hours per week, the stated work alone represents roughly 43-65 weeks. Adding
broad standard-library coverage without reducing existing work would make the route
unnecessarily difficult to finish.

The roadmap should publish separate routes:

1. professional core;
2. standard-library breadth;
3. advanced specialization and delivery.

Experienced learners should be able to use diagnostic tests to skip competencies
they can already demonstrate.

### High: Assessment Is Mostly Self-Attested

The project requirements and acceptance criteria are generally clear, but completion
depends heavily on checkboxes and statements such as "I can explain":
`project-template.md:50` and `checklists.md:104`.

Missing assessment support includes:

- scoring dimensions and pass thresholds;
- expected evidence for subjective criteria;
- answer guidance for review questions;
- reviewer instructions;
- independent transfer tasks;
- reference behavior for exercises;
- rules for partial completion and remediation.

Each phase should end with at least one unseen implementation or diagnosis exercise.

### High: The Data-Race Definition Is Incomplete

`concept-briefs.md:476` defines a data race as concurrent access to the same memory,
with at least one write and no synchronization ordering. It omits that the conflicting
operations are potentially concurrent and at least one is non-atomic.

This matters because relaxed atomic operations may be unordered without constituting
a data race. The current wording conflicts with the later atomic guidance at
`concept-briefs.md:517`.

### Medium: Manual Allocation Receives Disproportionate Mandatory Time

Projects 20-22 require approximately 24-34 hours for raw allocation, a custom dynamic
string, and movable-buffer mechanics:

- `phase-02-object-semantics.md:233`;
- `phase-02-object-semantics.md:276`;
- `phase-02-object-semantics.md:319`.

This material is useful, but it should be compressed into one scaffolded
diagnosis-copy-move-Rule-of-Zero sequence. The recovered time should be assigned to
standard-library breadth.

### Medium: Retention and Transfer Are Not Scheduled

The learning loop includes concept review, implementation, tests, and defect
recording: `README.md:56`. Phase gates provide large terminal reviews:
`checklists.md:102`.

There is no explicit spaced retrieval or cumulative practice. Add closed-book review
after approximately 2, 6, and 15 projects, plus recurring tasks that modify or debug
older projects.

### Medium: Some Prerequisites Are Broader Than Necessary

Several projects require entire prior phases instead of named competencies. Examples
include Vector2 requiring Phases 1-3 and introductory threading requiring Phases 1-4:

- `phase-04-generic-programming.md:22`;
- `phase-05-concurrency-advanced.md:23`.

Replace phase-sized prerequisites with a competency dependency graph and diagnostic
checks.

### Medium: The Range-View Ownership Criterion Is Inaccurate

`phase-03-standard-library-fluency.md:219` requires every view to name the storage
that owns its elements. This assumes views always refer to external element storage.

Some views can own their underlying range or generated values. The criterion should
instead require the learner to identify:

- whether the view owns or references its underlying state;
- where yielded elements or values come from;
- what invalidates iteration;
- whether a returned view can outlive its dependencies.

### Medium: Initial Thread Ownership Is Not Exception-Safe

Project 44 requires joining threads on all normal paths:
`phase-05-concurrency-advanced.md:43`. An exception can still destroy a joinable
`std::thread` and call `std::terminate`.

RAII joining or `std::jthread` should be baseline behavior. Manual joining can remain
as an isolated mechanics exercise.

### Medium: Callback Lifetime Cannot Be Enforced as Specified

Project 27 says the dispatcher must prevent callbacks from silently retaining
short-lived reference captures: `phase-03-standard-library-fluency.md:128`.

A dispatcher storing an arbitrary `std::function` cannot inspect a lambda's captures.
The project needs an enforceable contract, such as:

- requiring callbacks to own captured state;
- using weak ownership with explicit expiration behavior;
- binding subscription lifetime to an owner;
- documenting reference captures as a caller precondition.

### Medium: File Finalization Errors Are Not Addressed

The RAII file project correctly requires a non-throwing destructor:
`phase-02-object-semantics.md:216`. However, operations such as `fclose` may report
buffered-write or finalization failures.

Where output integrity matters, require an explicit `close()` or `finish()` operation
that reports errors. The destructor should remain a no-throw fallback cleanup path.

### Medium: Build Instructions Are Unix and Single-Config Oriented

The direct compiler flags, `CMAKE_BUILD_TYPE`, and `./build/app` examples assume a
GCC/Clang-like Unix environment:

- `README.md:81`;
- `project-template.md:83`;
- `project-template.md:98`.

Visual Studio and Xcode use multi-config generators and configuration-specific output
paths. Also, `cxx_std_23` alone does not require disabling compiler extensions.

The CMake baseline should set target or project extension policy deliberately and
document both single-config and multi-config commands.

### Medium: Feature Support Is Not Measurable

The roadmap permits "usable C++23 support" and fallbacks, but supplies no required
feature inventory or compiler/library matrix: `README.md:72`.

A learner can therefore complete the route while silently skipping many C++23
facilities. Record:

- compiler and standard-library versions;
- required feature-test macros;
- supported, unavailable, and fallback facilities;
- minimum features required for each curriculum route.

### Medium: Technical Claims Lack Source Traceability

The AI disclosure is clear, and learners are told to consult a current reference:
`README.md:8`. However, the curriculum provides no standard clauses, reference links,
compiler support pages, or dated compatibility matrix.

Every concept brief should include a small "Further reference" section using stable
primary or well-maintained reference sources.

### Low: Floating Equality Is Mislabeled

`phase-01-foundations.md:265` describes floating equality as "exact input equality."
The operation compares parsed floating-point values, not input text. Distinct text
such as `0.1` and `0.10` will normally produce equal values.

Use "exact equality of the represented floating-point values" and distinguish this
from textual equality and tolerance-based numerical comparison.

### Low: The Portfolio Route Is Too Large

The main quest names 16 portfolio artifacts: `main-quest.md:100`.

Maintain four to six evolving projects across phases and treat most remaining work as
small labs. Revisiting the same code provides stronger evidence of maintenance and
transfer than producing many isolated repositories.

## Strengths

- Prerequisite ordering is explicit.
- Ownership, lifetime, RAII, and Rule-of-Zero guidance are strong.
- Error handling compares preconditions, `optional`, `expected`, exceptions, and
  `error_code`.
- Undefined behavior demonstrations are isolated from normal tests.
- Concurrency projects emphasize shutdown, cancellation, invariants, and TSan.
- Performance work requires measurement before optimization.
- Delivery includes installation, package consumption, release artifacts, and patch
  maintenance.
- Project numbering 1-57 is consistent.
- Local Markdown links and explicit anchors resolve.
- The roadmap avoids claiming that projects alone create exhaustive mastery.

## Verification Performed

- Inventoried repository files and Markdown line counts.
- Reviewed all phase documents, concept briefs, checklists, main quest, README, and
  project template.
- Verified Projects 1-57 are sequential and consistently categorized.
- Checked local Markdown links and anchors.
- Inventoried named standard-library facilities and searched for missing major areas.
- Calculated mandatory and optional estimated effort.
- Confirmed the repository has no project source tree, root CMake project, presets,
  CI configuration, or test suite.
- Preserved the pre-existing deletion of `curriculum-audit.md`.

