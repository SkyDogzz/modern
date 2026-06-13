# Audit Resolution

Status: complete

Closure date: 2026-06-13

This record closes the actionable findings in:

- [audit-report.md](audit-report.md);
- [stdlib-coverage-audit.md](stdlib-coverage-audit.md);
- [audit-remediation-plan.md](audit-remediation-plan.md).

Those files are retained as historical baselines. Current curriculum requirements
are authoritative in the route, inventory, breadth, delta, assessment, toolchain,
and reference documents linked below.

## Closure Standard

An item is closed only when the repository contains:

1. an unambiguous current requirement;
2. an exercise, assessment, or executable support artifact where the finding
   requires one;
3. observable acceptance evidence;
4. a focused remediation commit;
5. a final structural or executable verification.

Learner completion is intentionally separate. This audit proves that the curriculum
specification and support repository are complete enough to issue the work; it does
not claim that a learner has completed the roadmap.

## Finding Ledger

| ID | Original finding | Resolution evidence | Focused commits |
|---|---|---|---|
| F1 | Standard-library coverage did not match the goal | [facility inventory](stdlib-facility-inventory.md), required [B1-B10 and S1-S5](standard-library-breadth.md), and the coverage crosswalk below | `0e2cf97`, `82a0e01`, `b09a48f` through `ae85c70` |
| F2 | Curriculum was not self-contained | [support files](support/README.md), [project fixtures](projects/README.md), root CMake/tests, package skeleton, and linked repository assets | `fe21398`, `de0a363`, `728e519`, `06f8bc4` |
| F3 | C++23 mode was not a C++23 curriculum | required [D1-D4](cpp20-23-delta.md), inventory delta column, feature detection, and explicit Route B/Route C ownership | `1ab1c2b`, `ae85c70`, `27e41f9` |
| F4 | Required route was large and strictly serial | three estimated [curriculum routes](curriculum-routes.md), diagnostic replacement, rebalanced hours, and current calendars | `24760f2`, `51fc55f`, `728e0a7` |
| F5 | Assessment was mostly self-attested | evidence bundle, rubric, hard fails, six transfer gates, scored surveys, and [reviewer calibration](reviewer-calibration.md) | `7c2914e`, `b09a48f`, `ef71858` |
| F6 | Data-race definition was incomplete | corrected definition in [Concept Brief 18](concept-briefs.md#18-threads-races-and-locks) | `1100b26` |
| F7 | Manual allocation had disproportionate mandatory time | one scaffolded Project 20 sequence and 57-81 recovered hours | `51fc55f` |
| F8 | Retention and transfer were unscheduled | R2/R6/R15 retrieval, M2-M6 maintenance revisions, and phase transfer gates | `7c2914e` |
| F9 | Prerequisites were broader than necessary | competency graph, placement diagnostics, and project-level O/L prerequisite codes | `51fc55f`, `def27c6` |
| F10 | Range-view ownership criterion was inaccurate | owning/referencing/generated-state, invalidation, and returned-view lifetime criteria | `60f9114` |
| F11 | Initial thread ownership was not exception-safe | `jthread` or scope-bound joining plus exception-path testing | `02bbcfc` |
| F12 | Callback lifetime contract was unenforceable | owned state or weak-owner subscription contract; capture opacity is explicit | `24be642` |
| F13 | File finalization errors were omitted | explicit error-reporting `close()`/`finish()` plus injected finalization failure | `61ad4c9` |
| F14 | Build instructions were Unix/single-config oriented | portable CMake policy, single/multi-config commands, presets, and pinned CI profiles | `411adf9`, `fe21398`, `728e519`, `06f8bc4` |
| F15 | Feature support was not measurable | dated profiles, per-facility macros/fallbacks, 28 workaround records, and guarded CI profiles | `0e2cf97`, `a244af0`, `ae85c70`, `728e519`, `06f8bc4` |
| F16 | Technical claims lacked traceability | [canonical sources](references.md), references for all 22 concept and 10 library briefs, and dated compatibility sources | `a244af0` |
| F17 | Floating equality was mislabeled | represented-value equality is distinguished from text and approximate comparison | `68b9935` |
| F18 | Portfolio route was too large | six evolving portfolio tracks replace 16 isolated portfolio artifacts | `51fc55f` |

All 18 findings are resolved. No finding is deferred to an optional track.

## Remediation Task Ledger

| Task | Status | Completion evidence |
|---|---|---|
| 1. Define claims and routes | Complete | [scope claims, three routes, topic ownership, estimates, and calendars](curriculum-routes.md) |
| 2. Add facility inventory | Complete | 9 area tables with facility, header, standard, C++20/C++23 delta, one tier, exercise, assessment, and fallback |
| 3. Supply infrastructure | Complete | project/playground paths, assertion helper, broken fixtures, compile-fail tests, sanitizers, allocation failpoint, type-erasure guidance, package skeleton, and pinned CI |
| 4. Correct technical specifications | Complete | all seven named specification corrections have testable acceptance criteria |
| 5. Rebalance mandatory work | Complete | merged ownership sequence, diagnosis-first labs, six portfolio tracks, competency placement, and 57-81 recovered hours |
| 6. Expand library breadth | Complete | [B1-B9](standard-library-breadth.md) plus scored S1-S5 cover every former Thin/Absent area; B10 is the final unseen gate |
| 7. Add C++20-to-C++23 delta | Complete | D1-D4 separate language/library detection and require lineage, profiles, and fallbacks |
| 8. Add objective assessment and retention | Complete | rubric, thresholds, subjective evidence, reviewer protocol/calibration, six transfer gates, retrieval, maintenance, and remediation |
| 9. Add references and compatibility records | Complete | every brief is sourced; every workaround has sources, review date, and retirement trigger |

## Standard-Library Coverage Crosswalk

The original ratings below remain in
[stdlib-coverage-audit.md](stdlib-coverage-audit.md) as historical observations. The
current required treatment is:

| Original area | Current required evidence |
|---|---|
| Language support and diagnostics | B7, S4, B9 |
| Concepts and type traits | Projects 38/40 and B1 |
| General utilities | B1 and B4 |
| Functional utilities | Project 27, B1, B9 |
| Memory management | Project 23, B3, S5, B9 |
| Strings and text conversion | Projects 3/9, B5, S1, B9 |
| Sequence containers | Projects 8/25/26, B2, B9 |
| Associative containers | Project 25, B2, S2, B9 |
| Container adaptors | Project 28 and B2 |
| Iterators | Projects 26/29, B3, B5 |
| Classic algorithms | Project 28 and B3 |
| Numeric algorithms | B4 |
| Raw-memory algorithms | B3 explicit lifetime/alignment lab |
| Ranges algorithms | Project 30, B3, B9 |
| Range views | Projects 29/30, B3, all seven C++23 families in B9 |
| C++23 range utilities | B9 native-or-fallback evidence |
| I/O streams | B5 |
| Formatting and printing | Project 32, B5, B9 |
| Filesystem | Project 31 and B6 |
| Chrono | Project 33 and B6 |
| Numerics and mathematics | B4 and S2 |
| Bit manipulation | B4 and B9 |
| Random numbers | Project 7 and B4 |
| Regular expressions | S1 integrated with B5 |
| Localization | S1 integrated with B5 |
| Concurrency: threads and locks | Projects 44/45 and B8 |
| Concurrency: coordination | B8 |
| Concurrency: atomics | Project 50 and B8 |
| Futures and task results | Project 48 and B8 |
| Parallel algorithms | S3 and B8 |
| Memory resources | mandatory S5; optional measured implementation in Project 52 |
| C compatibility library | S3 and B7 |
| C++23 headline additions | B9 for facility mastery; D4 for lineage and support analysis |

The inventory contains 76 Core/Working rows. Every one has a P/B exercise,
assessment mode, C++20/C++23 delta entry, and support/fallback record. All 14 Survey
rows map to scored S1-S5 work.

## Final Verification

Verification performed on 2026-06-13:

- exact pinned CI container
  `ubuntu@sha256:786a8b558f7be160c6c8c4a54f9a57274f3b4fb1491cf65146521ae77ff1dc54`;
- GCC 14.2/libstdc++ 14 guard, root configure/build, 3/3 tests, package test,
  install, clean `find_package` consumer, and consumer test;
- Clang 18.1/libc++ 18 guard with the same root/package/consumer flow;
- local GCC 16 and Clang 22 root test runs;
- single-config, Ninja Multi-Config, ASan/UBSan, and TSan test runs;
- package installation and clean consumer discovery from fresh `/tmp` trees;
- expected unresolved-symbol behavior for the Project 13 broken linker fixture;
- Project 1, Project 16, and Project 20 fixture compilation checks;
- all local Markdown files, links, anchors, and code fences;
- all inventory table widths, tiers, exercise mappings, assessments, and delta
  entries;
- 22/22 concept briefs and 10/10 library briefs with reference links;
- 28/28 compatibility workarounds with sources, review dates, and retirement
  conditions;
- every current curriculum asset promise linked to an existing local file;
- CAL-01 reviewer calibration: identical 15/15 pass decisions and no hard fails.

The root support suite is intentionally small: it verifies the curriculum
infrastructure, not learner solutions that do not yet exist. MSVC is documented as a
supported profile but was not executable on this Linux host. The pinned Linux
profiles and multi-config generator path were executed successfully.

## Conclusion

The original audit verdict is superseded. The repository now defines a truthful,
route-based C++23 roadmap with measurable broad standard-library coverage,
self-contained support artifacts, objective assessment, retention, compatibility
records, and source traceability. No actionable problem from the three audit files
remains open.
