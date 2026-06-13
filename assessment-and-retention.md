# Objective Assessment and Retention

This document is the scoring authority for projects, phase transfer gates, retrieval
practice, and remediation. Checkboxes record work; they do not by themselves prove
completion.

The required assessment and retention budget is 17-21 hours across the full roadmap:

- 1.5-2 hours for closed-book retrieval checkpoints;
- 6-7 hours for required revisions of older projects;
- 9.5-12 hours for six phase transfer exercises.

Remediation time after a failed gate is additional and depends on the failed
competency.

## Evidence Bundle

Every required project, diagnostic, B/D lab, S survey, and transfer attempt has an
immutable evidence record:

| Evidence | Required content |
|---|---|
| Identity | project/exercise ID, repository revision, date, toolchain profile |
| Requirement map | each requirement and acceptance criterion linked to code, test, command, or explanation |
| Reproduction | clean configure, build, test, and run commands with representative output |
| Quality | warning, formatter, analyzer, sanitizer, or documented unsupported result required at that stage |
| Reasoning | invariants, ownership/lifetime, error policy, complexity, and compatibility where applicable |
| Defect record | symptom, reproduction, diagnosis evidence, root cause, correction, and regression test |
| Review | rubric scores, hard-fail checks, reviewer ID, decision, and remediation if needed |

Generated logs may be attached, but the record must summarize what each command
proves. A screenshot or "tests pass" statement without reproducible commands is not
evidence.

## Project Rubric

Score each dimension from 0 to 3. Reviewers score observable evidence, not effort or
intent.

| Dimension | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| Behavior | does not build or core behavior is wrong | happy path only or major requirement missing | required behavior and defined failures pass | boundary behavior and invariants are demonstrated beyond the minimum |
| Verification | no reproducible tests | weak/manual evidence or important path untested | required automated and quality checks pass | tests isolate risks and include a useful regression, property, stress, or compile-fail check |
| Reasoning | cannot explain the implementation | explanation repeats code or misses a central rule | explains choices, invariants, lifetimes, errors, and complexity that apply | compares credible alternatives and predicts failure or invalidation cases accurately |
| Design and library use | unsafe, needlessly custom, or violates phase rules | works but has avoidable coupling or unjustified machinery | focused interfaces and appropriate standard-library facilities | simpler design, stronger contract, or clearer composition is demonstrated and justified |
| Evidence and maintenance | evidence is missing or not reproducible | partial commands, stale docs, or unfocused change | complete evidence bundle and focused reviewed diff | another user can reproduce, diagnose, and extend the result from the record |

A project passes only when:

- the total is at least 11 out of 15;
- Behavior and Verification are each at least 2;
- no dimension is 0;
- every mandatory acceptance criterion and hard-fail rule passes.

A score cannot compensate for a missing mandatory criterion. Stretch goals never
increase a failing baseline score.

Survey exercises use the dedicated 10-point rubric and pass rules in
[standard-library-breadth.md](standard-library-breadth.md#survey-evidence-and-pass-rules).
They use the same evidence, hard-fail, reviewer, and remediation rules as projects.

### Global Hard Fails

An attempt cannot pass when any applicable condition is true:

- the required clean profile does not configure, build, or run its mandatory tests;
- a required behavior, acceptance criterion, or exercise oracle is missing;
- normal tests execute known undefined behavior, a data race, a leak, or an invalid
  access that the current quality gate is intended to detect;
- required unsupported/feature-fallback evidence is hidden or counted as native
  support;
- the evidence bundle cannot identify the reviewed revision or reproduce the claim;
- a transfer solution was practiced, copied, or authored before the issued variant
  started.

Tool unavailability is not automatically a hard fail when the curriculum permits it,
but the unsupported result, alternative evidence, and remaining risk must be
recorded.

## Evidence for Subjective Criteria

These rules apply wherever a project says explain, understand, justify, appropriate,
clear, safe, portable, or maintainable.

| Claim | Minimum expected evidence |
|---|---|
| "I understand" or "I can explain" | a closed-note explanation followed by one reviewer follow-up that changes an input, lifetime, or failure condition |
| choice is justified | at least two credible alternatives compared using the operations, guarantees, invalidation, complexity, or ownership that matter |
| lifetime or ownership is safe | owner/observer description, invalidation points, one relevant failure-path test, and sanitizer evidence where supported |
| error behavior is robust | public error contract plus tests for success, invalid input, partial work, and the relevant resource failure |
| implementation is portable | standard requirement separated from implementation behavior; compiler/library profile and feature evidence recorded |
| interface is maintainable | focused diff, named invariant, compatibility effect, and a test that permits internal change |
| performance is better | workload, hardware, build mode, repetitions, noise treatment, and before/after data |

`Not applicable` passes only with a concrete reason tied to the project boundary.

## Review-Question Answer Guide

The questions in `checklists.md` are prompts, not yes/no items. A passing answer
contains the following:

| Question area | Passing answer names |
|---|---|
| invariants | valid states, transition that preserves each state, and the test or assertion that detects violation |
| ownership | owner, observers, transfer rules, and destruction order |
| storage and lifetime | storage duration, lifetime start/end, and any temporary or subobject dependency |
| dangling risk | each pointer/reference/iterator/view/callback invalidation event and mitigation |
| errors | preconditions, error channel, exception guarantee, cleanup, and caller obligation |
| hostile input | limits, malformed/partial cases, and externally observable failure behavior |
| tests | which risk each test proves and which risks remain outside the test oracle |
| tool evidence | the exact warning/debugger/sanitizer/analyzer/profiler observation and resulting decision |
| complexity | dominant operation, expected input scale, time/space bound, and invalidation/layout tradeoff |
| compatibility | source, binary, behavioral, data-format, and dependency effects that apply |
| simplification | one removable abstraction, state, allocation, branch, or dependency, or a reason the current minimum is necessary |

An answer that only restates a definition or says "not a problem" without project
evidence does not pass.

## Reviewer Protocol

1. Freeze the submitted revision and receive the evidence bundle before scoring.
2. For a transfer gate, issue the exact input/defect variant only when the attempt
   starts. Do not reuse a practiced project or published solution.
3. Reproduce the clean build and tests, then inspect evidence for every mandatory
   criterion.
4. Apply hard-fail rules before assigning rubric scores.
5. Record one sentence of evidence for every score below 3 and every pass/fail
   decision.
6. Ask at least two follow-up questions, including one changed failure, lifetime, or
   compatibility condition.
7. Return `pass`, `remediation required`, or `invalid attempt`; do not award an
   undocumented conditional pass.

For calibration, two reviewers independently score the same frozen evidence. The
rubric is calibrated when they agree on pass/fail, agree on every hard fail, and
their totals differ by no more than two points. They resolve larger differences by
identifying ambiguous evidence or wording and record the agreed interpretation.
Scores are not averaged to turn a failure into a pass.

A project may use structured self-review while it is being developed. A phase
transfer and final route claim require a reviewer who did not author the submitted
solution. A reviewer may be a mentor, peer, instructor, or code-review partner.

## Transfer Gate Rules

Each phase ends with one unseen implementation or diagnosis exercise. The competency
areas and oracle below are public; the exact names, values, fixture, defect location,
and follow-up questions are withheld until the attempt.

Transfer exercises use the project rubric with a higher pass threshold:

- at least 12 out of 15;
- Behavior, Verification, and Reasoning each at least 2;
- no dimension is 0;
- every exercise-specific oracle and hard-fail rule passes.

The learner gets 20 closed-note minutes to inspect, plan, and predict failures.
Current standard and compiler references may then be used for exact APIs. Existing
project code may not be copied unless the exercise explicitly supplies it.

### Phase 1 Transfer

**Exercise:** repair and complete a small three-translation-unit command-line data
converter.

The issued variant contains one compile/link defect, one numeric or conversion
defect, one invalid-input/status defect, and one weak test. The learner must diagnose
the defects, implement the missing boundary behavior, and add focused tests.

**Oracle:** a clean target-based build succeeds; valid, boundary, malformed, and help
inputs return specified output and status; the tests do not depend on terminal input;
the learner explains declaration/definition placement and the diagnosed conversion.

**Timebox:** 80-90 minutes.

### Phase 2 Transfer

**Exercise:** repair a fallible value/resource component and integrate it into a
small parser.

The issued variant contains one invariant violation, one lifetime or special-member
defect, and one cleanup/error-propagation defect. The learner chooses Rule of Zero or
implements the required ownership mechanics, then exposes a typed result.

**Oracle:** success and injected failure paths preserve the stated guarantee; no
resource leaks or invalid accesses occur; copy/move policy is explicit; partial
configuration is not exposed; the error channel is justified.

**Timebox:** 90-105 minutes.

### Phase 3 Transfer

**Exercise:** implement an unfamiliar data-summary command from a supplied input
contract and sample dataset.

The learner must select containers, iterator/range operations, text conversion, one
filesystem or stream adapter, and one time or formatting facility. The variant
changes data shape and ordering requirements from the roadmap projects.

**Oracle:** the implementation matches the supplied reference rows and ordering;
empty, duplicate, malformed, and boundary records are tested; invalidation and view
lifetime are explained; facility choices cite operations and guarantees.

**Timebox:** 95-110 minutes.

### Phase 4 Transfer

**Exercise:** design one regular domain value and a constrained generic operation
against a supplied behavior contract.

The variant requires a compile-time rejection, a runtime behavior test, and a
comparison with either runtime polymorphism, a variant, or a callable design.

**Oracle:** regular operations satisfy the stated algebraic properties; unsupported
types fail at the intended constraint; diagnostics are attributable to the public
contract; the simpler competing design is evaluated honestly.

**Timebox:** 95-110 minutes.

### Phase 5 Transfer

**Exercise:** diagnose and repair a cancellable producer/consumer component.

The issued fixture contains one shutdown/lifetime failure and either a race, missed
wakeup, deadlock risk, or unjustified memory-order claim. The learner must state the
shared invariant before changing code.

**Oracle:** all threads have deterministic ownership and shutdown; result and error
delivery are defined; stress tests terminate; TSan is run where supported; any
atomic ordering claim includes a valid happens-before argument.

**Timebox:** 100-125 minutes.

### Phase 6 Transfer

**Exercise:** issue a patch release for an unfamiliar installed library from an
incomplete defect report.

The learner must reproduce the defect, add a regression test, fix it, evaluate
compatibility, verify a clean consumer, and produce release records.

**Oracle:** the test fails on the supplied release and passes on the patch; build-
tree and install-tree consumers pass; version/changelog decisions match compatibility
impact; artifacts and checksums reproduce from documented commands.

**Timebox:** 110-140 minutes.

## Retrieval Schedule

Retrieval attempts are closed-note and closed-AI. Record the prompt, answer, elapsed
time, confidence before checking, correction, and one follow-up test.

| Checkpoint | When | Required retrieval |
|---|---|---|
| R2 | after Project 2 | write the compile-to-run pipeline, five diagnostic flags/policies, debugger steps for a wrong value, and the difference between a smoke test and behavior test |
| R6 | after Project 6 | implement one small conversion/function task, predict integer and floating behavior, and write normal/boundary/invalid tests without copying earlier code |
| R15 | after Project 15 | draw lifetime/storage for a supplied snippet, predict generated special members, identify one dangling observer, and repair an invariant violation |

Check answers only after committing the closed-note response. Any incorrect rule is
added to the next two project concept checks. Retrieval is formative, but a missing
checkpoint blocks the next phase gate.

## Required Older-Project Revisions

Later knowledge must change existing code rather than remain isolated:

| Revision | Due | Required change |
|---|---|---|
| M2 | before the Phase 2 transfer | revise Project 11 with an invariant-preserving task value and explicit operation errors while preserving its behavior tests |
| M3 | before the Phase 3 transfer | integrate Project 24 parsing/error policy into Project 11 or another maintained portfolio track |
| M4 | before the Phase 4 transfer | replace one Project 28-30 concrete data operation with a constrained reusable operation and keep one behavioral test contract |
| M5 | before the Phase 5 transfer | evolve Project 31 into the Project 49 concurrent file track with deterministic output and cancellation/error tests |
| M6 | before the Phase 6 transfer | apply Project 54 quality engineering and Project 55 clean-consumer packaging to Project 34 or 37 |

Each revision supplies a before revision, focused diff, unchanged behavior tests,
new risk-focused tests, and a short compatibility note. Rewriting the project from
scratch does not satisfy maintenance transfer.

## Remediation Rules

1. Preserve the failed revision, commands, scores, and reviewer comments.
2. Convert each failed criterion into a small named competency and reproduce the
   defect or missing behavior.
3. Complete the linked concept review and one focused repair task; do not add
   unrelated features.
4. Add or improve a test that would have exposed the failure.
5. Reattempt a project after the evidence bundle is corrected. Reattempt a transfer
   gate with a new variant after at least one intervening practice session.
6. After two failed transfer attempts, require a reviewer-approved prerequisite lab
   before a third variant.
7. Do not average attempts, use stretch work as compensation, or progress to the
   next phase while a transfer gate is failed.

The final record links every failed attempt to its remediation and passing attempt.
This keeps completion measurable without hiding the learning history.
