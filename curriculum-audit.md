# C++23 Curriculum Audit - Pre-Remediation Snapshot

> Historical note: this audit describes the curriculum before the remediation
> that introduced 57 prerequisite-correct projects, concept briefs, explicit
> project categories, aligned phase gates, independent breadth tracks, and a
> maintenance release. Project numbers and findings below refer to the earlier
> 42-project sequence. Use `README.md` and the phase files as the current
> curriculum specification.

## Remediation Status

The current curriculum resolves the audit's actionable findings:

- compact prerequisite teaching now exists in `concept-briefs.md`;
- Project 1 tooling was split and testing now progresses in explicit stages;
- integer behavior, views, C strings, `from_chars`, special-member rules,
  exception syntax, range vocabulary, template mechanics, and thread basics have
  dedicated prerequisite work;
- compile/link concepts precede multi-target CMake and library extraction;
- filesystem, formatting, and chrono are independent breadth tracks with aligned gates;
- runtime-polymorphism safety precedes comparative design;
- serialization, manual type erasure, PMR, modules, coroutines, and `mdspan` are
  unambiguously optional;
- phase gates, Main Quest, README, and project numbering use one 57-project sequence;
- capstone scope was narrowed and the unsupported POSIX option was removed;
- Git, CI, review, compatibility, dependency upgrades, and a patch release are
  now assessed professional skills.

## Global Summary

The repository is a strong **project roadmap**, but it is not yet a complete
from-scratch curriculum. Its best qualities are explicit prerequisites, observable
acceptance criteria, repeated quality gates, modern ownership guidance, and a
credible path from small programs to release engineering. Its main weakness is
that projects often name a concept and immediately require competent use without
providing a preceding lesson or smaller exercise that builds the required mental
model.

Overall assessment:

- **As a roadmap used with a good textbook, reference, and mentor:** strong, about
  8/10.
- **As a standalone path for a serious beginner:** incomplete, about 5/10.
- **As preparation for autonomous junior-level C++ work:** plausible after the
  proposed corrections.
- **As preparation for a broadly "professional" level:** a good foundation, but
  42 projects cannot substitute for sustained maintenance work, code review,
  collaboration, dependency upgrades, and production debugging.

The curriculum covers nearly every requested headline topic. The problem is not
primarily topic absence; it is granularity, prerequisite accuracy, and abrupt
difficulty increases.

The phase filenames listed in the audit request are an older naming scheme. The
repository currently uses `phase-01-foundations.md`,
`phase-02-object-semantics.md`, `phase-03-standard-library-fluency.md`,
`phase-04-generic-programming.md`, `phase-05-concurrency-advanced.md`, and
`phase-06-professional-delivery.md`. This audit evaluates the files actually
present in the repository.

## Strengths

1. Ownership, lifetime, RAII, value semantics, and the Rule of Zero are central
   rather than appended as advanced cleanup.
2. Projects separate pure logic from I/O and require invalid-input and failure-path
   behavior.
3. Tests, warnings, debugging, sanitizers, CMake, profiling, CI, packaging, and
   documentation are integrated throughout the route.
4. The curriculum correctly treats inheritance as one design choice and compares
   it with composition, variants, and type erasure.
5. Manual memory management is explicitly framed as a learning exercise, not a
   production recommendation.
6. C++23 facilities such as `std::expected`, `std::print`, and optional
   `std::generator`/`std::mdspan` tracks are used in projects with a purpose.
7. Concurrency work emphasizes cancellation, bounded work, deadlock avoidance,
   deterministic output, TSan, and measurement.
8. The capstone options include explicit non-goals, milestones, hardening, and a
   release step. This is substantially better than an unbounded "build an engine"
   assignment.

## Major Issues

### 1. The repository cannot by itself teach C++ from scratch

**Current problem:** [README.md](README.md) explicitly calls the repository a
roadmap rather than a language reference, but the project is presented as a path
from first compilation to professional work.

**Why it is a problem:** a true beginner needs explanations, worked examples,
knowledge checks, common-error notes, and reading assignments before being asked
to use concepts such as vector invalidation, exception guarantees, forwarding
references, borrowed ranges, or happens-before relationships.

**Change:** add a short lesson block before each project or link each learning
outcome to an authoritative reading section and a five-to-ten-minute concept
check.

**Benefit:** projects become application and assessment rather than the learner's
first unexplained encounter with the concept.

### 2. Project 1 overloads the beginner with unrelated tools

**Current problem:** Project 1 combines manual compilation, compiler diagnostics,
debugger stepping, `assert` or CTest, CMake targets, documentation, and potentially
presets in one one-to-two-hour exercise.

**Why it is a problem:** beginners cannot distinguish language errors, build
configuration errors, linker errors, test failures, and debugger behavior when
all are introduced at once.

**Change:** split it into:

1. **1A Compile and Run:** source file, `main`, output, exit status, one compiler
   error.
2. **1B Tooling Orientation:** debugger, minimal CMake target, and one CTest smoke
   test.

**Benefit:** lower initial cognitive load without postponing professional habits.

### 3. Several declared prerequisites are false or contradictory

- Project 3 creates a library target before Project 10 teaches declarations,
  definitions, translation units, and linking.
- Project 6 returns individual rolls, which practically requires a container,
  before Project 7 claims to introduce `std::vector`.
- Project 11 logs constructors and destructors before Project 12 introduces
  classes, constructors, and destructors.
- Project 13 permits `std::expected` and requires exception guarantees before
  Project 17 teaches error-policy selection.
- Project 14 assumes raw allocation, C-string invariants, and allocation-failure
  reasoning that have not been introduced.
- Project 22 requires borrowed-range reasoning without a preceding explanation of
  iterator/sentinel, view, range, and borrowed-range vocabulary.
- `main-quest.md` says choose one of Projects 23-25, but Project 24 requires 23 and
  Project 25 requires 24.
- Project 39 says both "complete at least one track" and "none is required before
  Phase 6."

**Change:** correct the local prerequisite lines and add the missing bridge labs
listed in the recommended order below.

**Benefit:** learners stop failing projects because of hidden knowledge rather
than the stated learning objective.

### 4. The testing progression is backwards

**Current problem:** automated tests are required from Project 1, but a maintained
test framework or documented harness is not selected until Project 40.

**Why it is a problem:** learners may repeatedly invent fragile ad hoc test
programs, misuse `assert`, or spend more effort on infrastructure than behavior.

**Change:** define three explicit stages:

1. Projects 1-3: CTest smoke tests and a tiny supplied assertion helper.
2. Projects 4-10: introduce one maintained unit-test framework or a repository
   test harness.
3. Later phases: fixtures, properties, fuzzing, concurrency tests, and coverage.

**Benefit:** testing complexity grows with program complexity.

### 5. The difficulty curve has four abrupt jumps

1. Project 10 combines the compile model, ODR, linkage, target usage requirements,
   sanitizers, and multi-target CMake.
2. Projects 14-15 move from ordinary RAII to exception-safe manual ownership and
   value-category mechanics.
3. Projects 31-32 jump from constrained algorithms to variadics, traits,
   customization protocols, parsing, and manual type erasure.
4. Project 33 begins concurrency with `std::jthread`, stop tokens, blocking work,
   destruction ordering, and TSan rather than basic thread lifecycle.

**Change:** add focused bridge labs and split Projects 10, 14-15, 31-32, and 33-34
as described below.

**Benefit:** difficulty increases because one new abstraction is added at a time.

### 6. Main Quest and phase gates are not fully aligned

**Current problem:**

- Main Quest permits choosing only one of filesystem, formatting, and chrono, but
  the Phase 3 gate requires competence in all three.
- Main Quest permits choosing either Project 31 or 32, but the Phase 4 gate
  requires both customization-point and type-erasure/design knowledge.
- Project 38 is optional, but the Phase 5 gate requires allocator/PMR justification.

**Change:** mark gate items as **core** or **track-specific**, or require small labs
for every facility while allowing only one portfolio-scale project.

**Benefit:** completion claims become auditable and consistent.

### 7. The route is modern, but not a systematic C++23 language survey

**Current problem:** the curriculum covers selected C++23 library facilities but
omits or barely treats several core language/library foundations. It should not
imply that completing the projects means comprehensive knowledge of C++23.

**Change:** describe the outcome as "professional foundations in modern C++23"
and add a final language-feature survey covering omitted but relevant facilities.

**Benefit:** expectations remain accurate while preserving the project-first
approach.

## Minor Issues

1. Phase 1 claims `std::array` coverage, but it appears only as a stretch goal.
2. Scoped enums are also stretch-only even though later projects rely heavily on
   typed domain modeling.
3. Some time estimates are optimistic for beginners, especially Projects 10, 14,
   15, 17, 31, 32, 34, 35, 40, and 41.
4. Project 18 lists `std::map` as a learning outcome but does not require a map
   implementation.
5. Project 22's pipeline can accidentally mutate the original collection when
   sorting through a filtered view; materialization must occur before ordering.
6. Project 24 and 25 have unnecessary prerequisites unrelated to their objectives.
7. Project 26's operator-overloading coverage omits defaulted comparisons and
   three-way comparison.
8. Project 35 does not define whether "hash" means a teaching checksum,
   non-cryptographic hash, or cryptographic digest.
9. Project 40 introduces test-framework dependency selection before Project 41
   formally introduces dependency management.
10. The sample repository layout in README places phase files under `notes/`,
    while the actual files are at repository root.
11. The baseline checklist asks every Phase 1 project to document ownership,
    lifetime, and error behavior before those models are taught.
12. "Formatting has been applied" is ambiguous without naming a formatter and
    configuration.

## File-by-File Analysis

### README.md

**Good:** clear phase structure, honest warning that the roadmap is not a
reference, sensible toolchain baseline, and strong project-order overview.

**Problems:** the advertised repository layout does not match the repository;
"from first compilation" is credible but "learn from scratch" requires teaching
material; the full order makes optional/specialization projects look mandatory;
and it does not explain which C++23 library features may need compatibility
fallbacks at each project.

**Change:** add "required core / required lab / optional track" labels to the
project list, fix the layout, and add a per-phase study-resource section.

### main-quest.md

**Good:** distinguishes portfolio investment from prerequisite labs and prevents
learners from turning every exercise into a large repository.

**Problems:** Projects 23-25 are not actually alternatives under their current
prerequisites; the Phase 3/4/5 choices do not satisfy all checklist gates; and
"lower volume" still means roughly 35 required implementations.

**Change:** make Projects 23-25 independent, split phase gates into core and
track-specific items, and offer a genuinely reduced route with concept checks or
code-reading labs replacing some full implementations.

### checklists.md

**Good:** excellent ownership, invalidation, error-policy, test, tooling, and
complexity review questions.

**Problems:** one baseline checklist is applied too early and assumes later
knowledge; optional PMR/modules/coroutines are mixed into mandatory phase gates;
and no check covers version-control practice, code review, dependency updates, or
reproducibility beyond CMake presets.

**Change:** create phase-specific project checklists and add Git history, review,
dependency, and reproducibility checks in Phase 6.

### project-template.md

**Good:** strong learning outcomes, non-goals, acceptance criteria, quality gate,
and retrospective sections.

**Problems:** it duplicates checklist material and requires ownership/error-policy
documentation even when not meaningful for a first program.

**Change:** allow explicit `Not applicable yet` fields and reference the current
phase gate rather than copying every generic requirement.

### phase-01-foundations.md

**Good:** practical sequence from expressions to control flow, functions, records,
containers, CLI parsing, and multi-file builds.

**Problems:** toolchain load is too front-heavy; libraries/source units precede
the compile model; vector, pointers, invalidation, and `argv` C strings arrive
without smaller conceptual labs; arrays/enums are not core; and integer behavior,
signedness, overflow, C strings, and non-owning string views are absent.

**Change:** add small type/conversion and reference/pointer labs, make enums and
`std::array` core, delay library targets until the compile-model lesson, and split
Project 10.

### phase-02-object-semantics.md

**Good:** this is the conceptual center of the curriculum and correctly prioritizes
lifetime, RAII, copy/move semantics, ownership, and error policy.

**Problems:** Project 11 precedes the class mechanics it uses; Project 13 teaches
error mechanisms before the error-policy project; Project 14 has hidden raw-memory
prerequisites; and Projects 14-15 are a severe jump.

**Change:** teach basic class construction first, add explicit exception syntax
and special-member-generation lessons, then use a smaller owning-buffer lab before
the full copy/move experiment.

### phase-03-standard-library-fluency.md

**Good:** strong container-selection, iterator-invalidation, lambda, algorithm,
range-lifetime, filesystem, formatting, and chrono objectives.

**Problems:** Project 18 introduces too many containers plus benchmarking at once;
Project 20 is more advanced than its rating; Project 22's required order is
semantically unsafe unless records are materialized; and Projects 23-25 conflict
with Main Quest.

**Change:** split container survey from benchmark work, explicitly teach range
vocabulary, fix Project 22's pipeline, and make Projects 23-25 independent tracks.

### phase-04-generic-programming.md

**Good:** value types precede templates; concepts follow unconstrained templates;
inheritance is compared rather than promoted; customization and type erasure are
treated as design tradeoffs.

**Problems:** inheritance basics are first taught inside a complex comparative
project; forwarding references appear in the first class-template project;
Projects 31-32 are specialization-level work; and three-way comparison, template
deduction, specialization, and dependent-name basics are not explicit.

**Change:** add small inheritance and template-mechanics labs, make `emplace`
forwarding a later exercise, and mark Projects 31-32 as advanced tracks rather
than ordinary core progression.

### phase-05-concurrency-advanced.md

**Good:** emphasizes structured thread ownership, cancellation, mutex invariants,
condition-variable predicates, deadlock avoidance, memory-model discipline, TSan,
and evidence-based optimization.

**Problems:** it lacks a basic thread lifecycle/data-race lab; the blocking queue
introduces too many synchronization ideas at once; profiling and PMR are not
concurrency topics; futures/tasks are absent; and Project 39 is internally
contradictory.

**Change:** rename the phase to **Concurrency, Performance, and Advanced
Facilities**, add a thread-basics lab, split mutex and condition-variable work,
add a small `future`/`promise` or task-result lab, and make PMR/Project 39 clearly
optional.

### phase-06-professional-delivery.md

**Good:** unusually strong treatment of risk-based testing, fuzzing, static
analysis, install/export rules, consumer testing, CI matrices, versioning,
licensing, releases, and capstone scope.

**Problems:** too many quality practices are deferred to one large pass; Project
41 may exceed 24 hours for a beginner; Option B has crash-recovery complexity,
Option C depends on an unprovided POSIX curriculum, and Option D's persistence plus
incremental update is large for the stated capstone budget.

**Change:** introduce formatting/static analysis/CI incrementally in earlier
phases; provide packaging scaffolds; add a POSIX prerequisite track or remove
Option C; and narrow Options B and D.

## Phase-by-Phase Analysis

### Phase 01 - Foundations and Workflow

- **Coherence:** mostly logical language progression, but build/test tooling is
  interleaved before learners understand the compile model.
- **Difficulty:** 1/5 to 3.5/5; Project 10 is the spike.
- **Well-placed concepts:** variables, expressions, functions, control flow,
  structs, basic containers, input validation, CLI behavior.
- **Missing concepts:** integer model, overflow/UB, signed/unsigned comparisons,
  arrays as core, enums as core, C strings, header basics, `string_view`, a clear
  testing-harness progression.
- **Concepts to move:** library targets and multi-source organization should move
  to the Project 10 sequence.
- **Suggestions:** split tooling onboarding and compile/link/CMake work; insert a
  reference/pointer micro-lab before vector invalidation.

### Phase 02 - Object Semantics, Lifetime, and Ownership

- **Coherence:** excellent target concepts, imperfect local order.
- **Difficulty:** 3/5 to 4.5/5; Projects 14-15 are steep.
- **Well-placed concepts:** invariants, RAII, copy/move, Rule of Zero, smart
  pointers, optional/expected/exceptions.
- **Missing concepts:** implicit special-member generation/suppression,
  `=default`, exception syntax, destructor exception rules, raw-allocation
  prerequisites, non-owning `span`/`string_view` as core.
- **Concepts to move:** introduce class mechanics before lifetime instrumentation;
  teach error mechanisms before requiring exception guarantees in the RAII wrapper.
- **Suggestions:** use a provided `Trace` type for lifetime experiments, then have
  the learner implement classes; split manual copy and move work into smaller labs.

### Phase 03 - Standard Library Fluency

- **Coherence:** good high-level order from containers to iterators, callables,
  algorithms, ranges, and system-library adapters.
- **Difficulty:** 3/5 to 4/5; Event Dispatcher is underrated.
- **Well-placed concepts:** container tradeoffs, invalidation, lambdas,
  algorithms, ranges, filesystem, format/print, chrono.
- **Missing concepts:** iterator categories, sentinels, projections, borrowed
  ranges explained explicitly, standard container adaptors, `from_chars`,
  `error_code` category/value basics.
- **Concepts to move:** profiling of container lookup should follow the dedicated
  profiling lesson or use simple timing with strict caveats.
- **Suggestions:** add a range-model micro-lab and make Projects 23-25 parallel,
  independent choices.

### Phase 04 - Generic Programming and Design

- **Coherence:** strong through Project 30, then specialization-level topics.
- **Difficulty:** 3/5 to 5/5; Projects 31-32 are the spike.
- **Well-placed concepts:** regular value types, operator overloading, design
  comparison, templates, constant evaluation, concepts.
- **Missing concepts:** `<=>`, defaulted comparisons, template argument deduction,
  specialization overview, dependent names, fold expressions, forwarding mechanics.
- **Concepts to move:** forwarding-heavy `emplace` and manual type erasure should
  follow dedicated mechanics labs.
- **Suggestions:** keep Projects 31-32 as optional advanced branches; require a
  smaller traits/variadics exercise first.

### Phase 05 - Concurrency and Advanced Facilities

- **Coherence:** the concurrency subsequence is sound after a missing introduction;
  performance/PMR/feature tracks are separate concerns.
- **Difficulty:** 4/5 to 5/5 throughout.
- **Well-placed concepts:** `jthread`, cancellation, mutexes, condition variables,
  atomics after lock-based synchronization, TSan, profiling before PMR.
- **Missing concepts:** basic `thread` join semantics, data-race vocabulary before
  cancellation, futures/promises/task results, `call_once`, and optional
  latch/barrier/semaphore survey.
- **Concepts to move:** profiling can be introduced after Phase 3; PMR and modern
  facility tracks should be explicitly optional.
- **Suggestions:** add a deterministic two-thread lab and a task-result lab before
  the blocking queue.

### Phase 06 - Professional Delivery

- **Coherence:** good delivery progression from verification to package to product.
- **Difficulty:** 4/5 to 5/5, with workload rather than language as the main jump.
- **Well-placed concepts:** fuzzing, static analysis, coverage caveats,
  install/export/consume, dependency strategy, CI, documentation, release policy.
- **Missing concepts:** Git workflow, code review, issue/decision records,
  dependency-update practice, ABI/API compatibility, reproducible artifact
  provenance, maintenance after release.
- **Concepts to move:** formatter, static analyzer, and basic CI should begin
  earlier and be consolidated here.
- **Suggestions:** add a post-release maintenance milestone that fixes a bug,
  upgrades a dependency, and preserves compatibility.

## C++23 Concept Coverage

| Area | Status | Audit |
|---|---|---|
| Basic syntax | Partial | Applied immediately, but no explicit lexical/preprocessor/header teaching sequence. |
| Types, variables, expressions | Good | Add integer representation, signedness, overflow, and UB. |
| Functions | Good | Pure functions, parameters, overloads, and separation from I/O are well staged. |
| Scope, lifetime, storage duration | Strong | Core theme; reorder class mechanics before Project 11. |
| References and pointers | Partial | Introduced early through a complex invalidation project; add a micro-lab. |
| Const-correctness | Strong | Repeated in functions, searches, classes, and APIs. |
| RAII | Strong | Central and applied to files, locks, temporary directories, and processes. |
| Classes and structs | Good | Clear aggregate/invariant distinction; class basics need to precede instrumentation. |
| Encapsulation | Strong | Bank Account project has clear invariants and tests. |
| Constructors/destructors | Good | Covered, but local order is wrong. |
| Copy/move semantics | Strong | Deep copy, move, elision, `noexcept`, and Rule of Zero are explicit. |
| Operator overloading | Good | Add `<=>`, defaulted comparisons, and conversion-operator cautions. |
| Templates | Good | Function/class templates and compilation model covered; mechanics need one bridge lab. |
| Concepts | Strong | Correctly follows unconstrained templates and uses actual implementation requirements. |
| Lambdas | Strong | Capture lifetime and callback ownership make this better than syntax-only coverage. |
| Exceptions | Partial | Policy and guarantees are strong; basic `try`/`throw`/`catch` mechanics are implicit. |
| STL containers | Strong | Broad selection and tradeoffs; Project 18 is overloaded. |
| Iterators | Good | Usage and invalidation covered; categories/sentinels are not explicit. |
| Algorithms | Strong | Includes comparator correctness, stable sorting, numeric algorithms, and tests. |
| Ranges | Good | Views and dangling are covered; range vocabulary and Project 22 ordering need repair. |
| Smart pointers | Strong | Ownership choice and cycle avoidance are handled carefully. |
| Polymorphism | Good | Virtual interface plus value alternatives; add slicing/`override` basics. |
| Inheritance vs composition | Strong | One of the curriculum's best design comparisons. |
| Modern error handling | Strong | `optional`, `expected`, exceptions, `error_code`, and guarantees are compared. |
| Filesystem | Strong | Error, permission, symlink, temporary-directory, and destructive-operation policy covered. |
| Chrono | Strong | Correct clock selection and fake time are emphasized. |
| Formatting | Good | `format`, `print`, fallback, feature detection, and Unicode scope are present. |
| Modules | Appropriate optional coverage | Correctly treated as toolchain-sensitive, not a core blocker. |
| Coroutines | Appropriate optional coverage | `std::generator` first; custom promise types remain advanced. |
| Threads, atomics, mutexes | Strong but abrupt | Add basic thread and task-result labs. |
| Build systems/CMake | Strong | Possibly too prominent early; excellent target/install/export progression later. |
| Testing | Strong goals, weak staging | Framework/harness decision is delayed until Phase 6. |
| Debugging | Good | Present from Project 1; add core-dump/postmortem or stacktrace survey later. |
| Profiling | Strong | Evidence requirements are excellent. |
| Sanitizers | Strong | ASan/UBSan/TSan separation and isolated UB/race demos are correct. |
| Documentation | Good | README/API/release docs covered; decision records and maintenance docs are missing. |
| Packaging/project structure | Strong | Install/export/consumer/package/release flow is unusually complete. |
| Professional practices | Good foundation | Missing collaboration, review, maintenance, and dependency-upgrade workflow. |

## Missing or Insufficiently Covered C++23 Concepts

| Concept | Add in | Why it matters |
|---|---|---|
| Integer ranges, signed/unsigned behavior, overflow, and UB | Phase 1, before Calculator | Prevents common correctness and security defects and makes warnings understandable. |
| `std::array` and scoped enums as core | Phase 1, before Dice Roller | Both are claimed or repeatedly useful but currently stretch-only. |
| C strings and `argv` conversion | Phase 1, before Project 9 | `char** argv` otherwise introduces an unexplained representation. |
| `std::string_view` and `std::span` | Late Phase 1/early Phase 2 | Non-owning interfaces are fundamental to modern API and lifetime reasoning. |
| Raw allocation prerequisites and array ownership | Phase 2, before Project 14 | The manual string lab otherwise assumes the mechanics it is meant to teach. |
| Implicit special-member rules, `=default`, `=delete` | Phase 2, before copy/move labs | Learners must know what the compiler generates and suppresses. |
| Exception syntax and destructor rules | Phase 2, before Project 13 | Guarantees and stack unwinding are not understandable without the mechanism. |
| `std::from_chars` | Phase 1 CLI or Phase 2 parser | Provides explicit, locale-independent numeric parsing and error handling. |
| Iterator categories, sentinels, range/view vocabulary | Phase 3, before Project 22 | Required to understand algorithm constraints and dangling/borrowed behavior. |
| Standard container adaptors | Phase 3 | Prevents the custom Generic Stack from being mistaken for the normal production choice. |
| `override`, `final`, slicing, and downcast avoidance | Phase 4, before Project 27 | These are minimum safe runtime-polymorphism knowledge. |
| Three-way/defaulted comparison | Phase 4, Project 26 | Important modern operator and regular-type machinery. |
| Template deduction, specialization, dependent names, folds | Phase 4 bridge lab | Needed before variadic customization code and readable diagnostics. |
| Basic thread lifecycle and data-race model | Phase 5, before Project 33 | Cancellation is not an appropriate first concurrency abstraction. |
| Futures/promises or task-result transport | Phase 5 | Workers need a principled way to return values and failures. |
| Git workflow and review | Phases 1 and 6 | Git is listed as required but never taught or assessed. |
| Static formatting/analyzer setup | Phase 2 or 3 | These should become routine before the final quality pass. |
| ABI/API compatibility and dependency upgrades | Phase 6 | Releasing is incomplete without maintaining consumers over change. |
| Post-release maintenance project | Phase 6 | Professional work is mostly changing existing software safely, not greenfield creation. |

Not required as core topics: custom coroutine promise types, lock-free containers,
weak atomics beyond a justified lab, advanced allocators, modules, and `mdspan`.
The curriculum is correct to keep these optional.

## Misplaced Concepts

1. **Library targets in Projects 3 and 6:** move to the compile/link/CMake unit
   around Project 10. Earlier projects can use one executable plus a test source
   supplied by the curriculum.
2. **Constructor/destructor instrumentation in Project 11:** move after basic
   class construction, or provide the instrumentation type.
3. **Exception guarantees in Project 13:** place after a short exception and
   error-model lesson.
4. **Forwarding references in Project 28:** move to a dedicated forwarding lab or
   the advanced template track.
5. **Borrowed ranges in Project 22:** introduce through a focused range-lifetime
   lab first.
6. **Benchmarking in Project 18:** use simple measurements only; rigorous
   benchmarking belongs with Project 37.
7. **Profiling in Phase 5:** introduce a smaller profiling pass after algorithms;
   keep advanced optimization work in Phase 5.
8. **PMR as phase-gate knowledge:** make it a specialization track.
9. **Advanced verification only in Project 40:** distribute formatting, CI,
   static analysis, and framework adoption across earlier phases.

## Redundancy

### Useful Pedagogical Repetition

- Lifetime appears in pointers, views, callbacks, smart pointers, filesystem test
  resources, PMR, and concurrency. This is appropriate spiral reinforcement.
- Error policy recurs in parsing, filesystem, threads, and public APIs. This is
  domain-specific reuse, not duplication.
- Container invalidation recurs in Projects 7, 18, 19, and 22. The repetition is
  useful if each project explicitly names the new invalidation context.
- Testing, sanitizers, and CMake are revisited with increasing depth. This is
  appropriate professional habit formation.

### Actual Redundancy or Overhead

- The template, baseline checklist, phase gates, and every project repeat similar
  quality requirements. Keep the project-specific criteria and reference one
  shared phase gate.
- Projects 18 and 19 both spend substantial effort comparing containers and
  invalidation. Project 18 should focus on operation-driven container selection;
  Project 19 should focus only on iterator state and mutation.
- README's serious-project list and Main Quest portfolio list duplicate policy.
  Keep the authoritative list in Main Quest and link to it from README.
- Requiring a new CMake technique in almost every early project risks turning
  language exercises into build-system exercises. Group CMake milestones at
  deliberate checkpoints.

## Project-by-Project Analysis

| Project | Objective / prerequisite / level audit | Required change |
|---|---|---|
| 1. Hello C++23 | Objective is clear, but six tooling concerns are too much for 1/5. | Split compile/run from debugger/CMake/CTest. |
| 2. Character Stat Sheet | Clear and level-appropriate; some types are included artificially. | Make enum core and ask learners to justify each type rather than merely use every type. |
| 3. Unit Converter | Good functions/conversions project; library target precedes compile-model knowledge. | Keep one executable initially; move library extraction to Project 10. |
| 4. Expression Calculator | Clear, but mixed `%` and floating operands create an unstated type-model problem. | Specify integer and floating modes or defer `%`; define parser/result types explicitly. |
| 5. Number Guessing Game | Clear, well-scoped loop/RNG project with deterministic core testing. | Provide a short engine/distribution lesson and keep seeding mechanics explicit. |
| 6. Dice Roller | Good modeling/function objective; returned rolls need a container not yet introduced. | Introduce `vector` here or move project after the vector lesson; delay source-unit split. |
| 7. Inventory Editor | Valuable but combines vector CRUD, pointer APIs, const overloads, and invalidation. | Precede it with a reference/pointer micro-lab; consider returning an index first, pointer second. |
| 8. Interactive Todo List | Strong Phase 1 integration project with a clear non-goal. | Keep persistence out of Phase 1 baseline; link the stretch goal to Phase 2/3 revisit. |
| 9. Command-Line Greeter | Clear CLI exercise; `char**` and C-string boundaries are hidden prerequisites. | Teach `argc`/`argv`, null termination, conversion to `string_view`, and numeric parsing first. |
| 10. Multi-File Build/Test Lab | Excellent objectives, but compile model, ODR, CMake visibility, storage, and sanitizers form a spike. | Split into compile/link lab and target-based CMake/quality lab. |
| 11. Lifetime/Storage Visualizer | Essential objective; uses classes and special members before they are taught. | Supply a `Trace` class or move after Project 12; keep thread-local as a small survey. |
| 12. Bank Account Simulator | Clear, appropriate, and one of the strongest projects. | Teach constructor failure policy and avoid implying integer money alone solves currency modeling. |
| 13. RAII File Wrapper | Clear RAII objective; failure policy and exception guarantees arrive early. | Add exception/error lesson first and specify whether wrapping `FILE*`, descriptor, or another resource. |
| 14. Dynamic String Copy Lab | Pedagogically valid manual lab, but raw allocation and C-string mechanics are unstated. | Add a smaller allocation lab, provide invariants, and rate it at least 4.5/5 for beginners. |
| 15. Movable Buffer/Rule of Zero | Strong and correctly ends at Rule of Zero. | Split value categories/copy elision from implementing move operations if learners struggle. |
| 16. Dungeon Ownership Graph | Clear ownership-comparison project at the right conceptual point. | Specify stable-ID invalidation/tombstone policy; keep shared ownership comparison small. |
| 17. Config Parser/Error Policy | Strong capstone for Phase 2, but parsing and `variant` add considerable scope. | Teach `from_chars`, `string_view`, variant visitation, and exception syntax immediately before it. |
| 18. Contact Book | Objective is good; four containers plus benchmarking is overloaded and `map` is not required. | Require operation tables first, compare two implementations, and move rigorous benchmarking later. |
| 19. Playlist Iterator Lab | Clear and level-appropriate; list comparison is useful when evidence-based. | Focus on iterator state/invalidation and avoid duplicating Project 18's broad container survey. |
| 20. Event Dispatcher | Excellent lifetime/callable project, but mutation during dispatch and type erasure make it 4/5. | Define reentrancy and mutation semantics precisely; consider subscription RAII as a later extension. |
| 21. Student Grade Analyzer | Clear, well-prepared algorithm project. | Add projection use as a bridge to ranges and retain comparator-law checks. |
| 22. Data Processing with Ranges | Objective is strong, but sorting a filtered view can mutate the source unexpectedly. | Filter, materialize active records, sort/select, then transform; teach range vocabulary first. |
| 23. Directory Analyzer | Clear, practical, and properly depends on error-policy work. | Keep independent from Projects 24-25 and specify recursion/symlink traversal policy. |
| 24. C++23 Table Printer | Clear focused formatting project; Project 23 is not a prerequisite. | Require only core Phase 3 work; define byte length versus display width explicitly. |
| 25. Testable Pomodoro Timer | Excellent chrono/testability objective; Projects 23-24 are not prerequisites. | Require only core Phase 3 work; define the fake-clock interface without advanced template demands. |
| 26. Vector2 Value Type | Strong regular-type/operator project. | Add defaulted comparison/`<=>` discussion and distinguish exact structural equality from approximate tests. |
| 27. Shape Design Comparison | High-value design comparison, but too much for a first inheritance encounter. | Add a small virtual-interface lab covering `override`, virtual destruction, slicing, and ownership. |
| 28. Generic Stack | Good first class-template project; move-only support is useful, forwarding `emplace` is premature. | Implement `push(const T&)`/`push(T&&)` first; make perfect-forwarding `emplace` a later step. |
| 29. Compile-Time Math | Clear and appropriately warns against pointless compile-time work. | Include compile-time diagnostic quality and overflow constraints. |
| 30. Constrained Algorithms | Clear and well-sequenced after templates/ranges. | Specify result types and integer-average semantics; add projections as core or bridge work. |
| 31. Serialization Customization | Objective is clear but combines too many advanced topics and parser complexity. | Add traits/variadics/folds/customization micro-labs; make this an advanced branch. |
| 32. Type-Erased Command System | Excellent advanced comparison, not core beginner-to-junior material. | Mark optional specialization; provide a scaffold for the erased model/vtable mechanics. |
| 33. Cancellable Worker | Clear modern objective, but inappropriate as the first threading project. | Add thread creation/join, shared-state race, and synchronization basics first. |
| 34. Blocking Queue/Deadlock | Valuable, but bounded queues, CVs, cancellation, deadlock, and callbacks are a large bundle. | Split mutex/deadlock lab from condition-variable queue implementation. |
| 35. Parallel File Hasher | Strong integration project with good performance evidence requirements. | Define the hash algorithm/dependency and separate I/O throughput from CPU parallelism claims. |
| 36. Atomics/Memory Model | Well-scoped for an advanced lab and correctly rejects a lock-free queue baseline. | Keep sequential consistency core and release/acquire optional; add happens-before diagrams. |
| 37. Profiling Before Optimization | Excellent professional project. | Introduce a smaller profiling exercise earlier; include benchmark warmup/noise cautions. |
| 38. Profiled PMR Text Processor | Clear evidence-driven specialization project. | Label optional everywhere and remove PMR from the mandatory phase gate. |
| 39. Optional Feature Tracks | Tracks are sensible and appropriately focused. | Replace "complete at least one" with unambiguously optional wording and independent completion badges. |
| 40. Quality Engineering Pass | Strong goals, but too many new tools are introduced at once. | Adopt test framework, formatter, analyzer, and basic CI earlier; use this project for integration and risk strategy. |
| 41. Package and Release | Excellent professional delivery project, likely underestimated. | Supply CMake package skeletons and split first release from package-manager recipe work. |
| 42. Capstone | Milestones/non-goals are strong; option scope is uneven. | Keep A; narrow B recovery guarantees and D incremental persistence; add a real POSIX prerequisite track for C. |

## Recommended Learning Order

The six-phase model can remain, but the internal order should be corrected as
follows.

### Phase 1 - Language Foundations and Basic Workflow

1. Compile/run and diagnostics.
2. Variables, initialization, expressions, conversions, integer behavior, and UB.
3. Branching and loops.
4. Functions, parameters, overloads, scope, and const.
5. Structs, scoped enums, `string`, `array`, then `vector`.
6. References and pointers in a focused non-owning-access lab.
7. Container mutation and invalidation.
8. CLI parsing, C strings, `string_view`, and `from_chars`.
9. Integrated Todo project.
10. Compile/link model, headers, namespaces, ODR, then target-based CMake/tests.

### Phase 2 - Classes, Lifetime, Ownership, and Errors

1. Classes, invariants, constructors, destructors, special-member generation.
2. Lifetime/storage visualizer using a supplied tracer.
3. Exceptions, `optional`, `expected`, `error_code`, and policy selection.
4. RAII file/resource wrapper.
5. Raw allocation micro-lab.
6. Deep copy and Rule of Three.
7. Value categories, move, elision, `noexcept`, Rule of Five.
8. Rule of Zero refactor and `span`/`string_view`.
9. Smart-pointer/ID ownership graph.
10. Config parser phase project.

### Phase 3 - Standard Library and Data Processing

1. Container operation/complexity selection.
2. Iterator categories and invalidation.
3. Lambdas/callables and callback lifetime.
4. Classic algorithms and numeric algorithms.
5. Range/sentinel/view/borrowed-range lab.
6. Correct range pipeline with materialization.
7. Independent system-library tracks: filesystem, formatting, chrono.
8. One portfolio project plus small completion labs for the other two tracks.

### Phase 4 - Generic Programming and Design

1. Regular value types, defaulted comparison, `<=>`, operators.
2. Basic runtime polymorphism safety lab.
3. Variant/composition/inheritance comparison.
4. Function and class templates; deduction and compilation model.
5. Move-only types, forwarding, and `emplace`.
6. `constexpr`, `consteval`, and compile-time validation.
7. Concepts and constrained ranges.
8. Traits, variadics, folds, and customization micro-lab.
9. Optional serialization or type-erasure specialization.

### Phase 5 - Concurrency, Performance, and Advanced Facilities

1. Thread lifecycle, join ownership, and a deliberate data race.
2. Mutex-protected state and deadlock prevention.
3. Condition variables and blocking queue.
4. `jthread` cancellation and shutdown.
5. Futures/promises or task result/error transport.
6. Parallel file project.
7. Atomics and memory-model lab.
8. Profiling and benchmark discipline.
9. Optional PMR, modules, generator, and `mdspan` tracks.

### Phase 6 - Delivery and Maintenance

1. Risk-based test plan, properties, fuzzing, coverage, sanitizers, analyzers.
2. Install/export/consume/package/release.
3. Capstone MVP.
4. Post-release maintenance: bug report, regression fix, dependency update,
   compatibility decision, and patch release.

## Proposed New Table of Contents

```txt
README.md
main-quest.md
checklists.md
project-template.md
phase-01-language-foundations.md
phase-02-object-lifetime-errors.md
phase-03-standard-library-data.md
phase-04-generic-design.md
phase-05-concurrency-performance.md
phase-06-delivery-maintenance.md
lessons/
  01-compile-run-diagnostics.md
  02-types-conversions-integers.md
  ...
tracks/
  filesystem.md
  formatting.md
  chrono.md
  serialization.md
  type-erasure.md
  modules.md
  coroutines-generator.md
  mdspan.md
```

The `lessons/` directory need not become a textbook. Each lesson can be a compact
concept brief containing prerequisites, key rules, one worked example, common
errors, five review questions, and references.

## Projects to Add or Modify

### Add: Reference, Pointer, and View Lab

Place before Inventory Editor. Use one object, a reference, a pointer, `nullptr`,
`string_view`, and `span`; identify owner, observer, lifetime, and mutation rights.
This isolates non-owning semantics before vector invalidation complicates them.

### Add: Integer and Conversion Failure Lab

Place before Expression Calculator. Exercise signed/unsigned warnings, narrowing,
overflow boundaries, integer division, floating tolerance, and safe text parsing.
This prevents arithmetic bugs from being misdiagnosed as control-flow bugs.

### Add: Class and Special-Member Mechanics Lab

Place before Lifetime Visualizer. Cover constructor order, destructor order,
copy-generation rules, `=default`, `=delete`, and compiler diagnostics. This makes
the lifetime experiment an observation exercise rather than unexplained magic.

### Add: Range Model Lab

Place before Data Processing with Ranges. Use iterator/sentinel pairs, a view,
materialization, a dangling example kept out of normal tests, and one borrowed
range. This supplies the vocabulary Project 22 assumes.

### Add: Template Mechanics Lab

Place between Generic Stack and Compile-Time Math. Cover deduction, overload
resolution, forwarding references, `std::forward`, dependent names, a type trait,
and a fold expression in small isolated functions.

### Add: Thread Lifecycle and Race Lab

Place before Cancellable Worker. Start/join a thread, pass values safely, observe
an isolated race under TSan, fix it with a mutex, and explain ownership at thread
exit. This makes `jthread` cancellation an extension of understood thread
lifecycle.

### Add: Maintenance Release Project

Place after the capstone release. Supply or simulate a defect report, incompatible
dependency update, performance regression, and consumer compatibility constraint.
Require a regression test, changelog entry, compatibility decision, and patch
release. This is closer to professional work than another greenfield feature.

## Final Improvement Checklist

### Priority 0 - Correct contradictions

- [ ] Make Projects 23, 24, and 25 independent alternatives.
- [ ] Make Project 39 unambiguously optional.
- [ ] Align Main Quest choices with Phase 3-5 gates.
- [ ] Fix README's repository-layout example.
- [ ] Label every project as core lab, core project, portfolio project, or optional track.

### Priority 1 - Repair prerequisites

- [ ] Split Project 1 onboarding.
- [ ] Delay library/source-unit requirements until the compile-model lesson.
- [ ] Introduce `vector` before Project 6 requires returned rolls.
- [ ] Add reference/pointer/view work before Inventory Editor.
- [ ] Teach class mechanics before Lifetime Visualizer.
- [ ] Teach exception/error mechanics before RAII exception guarantees.
- [ ] Add raw-allocation prerequisites before Dynamic String.
- [ ] Add range vocabulary before borrowed-range work.
- [ ] Add inheritance safety before Shape Design.
- [ ] Add template mechanics before forwarding/variadics.
- [ ] Add basic thread lifecycle before cancellable workers.

### Priority 2 - Smooth difficulty

- [ ] Split Project 10 into compile/link and CMake/quality labs.
- [ ] Split manual copy and move work into smaller checkpoints.
- [ ] Make Projects 31-32 advanced branches.
- [ ] Split mutex/deadlock from condition-variable queue work.
- [ ] Narrow Capstone Options B and D.
- [ ] Provide a real prerequisite track for POSIX Capstone Option C.

### Priority 3 - Fill core gaps

- [ ] Add integer behavior, signedness, overflow, and UB.
- [ ] Make `std::array` and scoped enums core Phase 1 topics.
- [ ] Add C strings, `string_view`, `span`, and `from_chars`.
- [ ] Add special-member generation and destructor exception rules.
- [ ] Add iterator categories/sentinels and standard container adaptors.
- [ ] Add `<=>`, defaulted comparisons, slicing, `override`, and `final`.
- [ ] Add futures/promises or another task-result mechanism.
- [ ] Add Git, review, compatibility, dependency-update, and maintenance work.

### Priority 4 - Improve curriculum delivery

- [ ] Add compact concept briefs or explicit reading assignments before projects.
- [ ] Define the test harness/framework by Phase 1.
- [ ] Introduce formatter, static analysis, and basic CI incrementally.
- [ ] Separate shared quality gates from project-specific acceptance criteria.
- [ ] Re-estimate difficult projects using beginner completion data.
- [ ] Add short diagnostic quizzes at every phase gate.
- [ ] State explicitly that the outcome is modern C++23 professional foundations,
      not exhaustive mastery of the language or ecosystem.

With these changes, the curriculum would become a coherent, defensible route from
beginner syntax through modern C++ object semantics and library fluency to
independent project delivery. Without them, a motivated beginner can still
succeed, but only with substantial external teaching and a mentor who supplies
the missing prerequisite explanations.
