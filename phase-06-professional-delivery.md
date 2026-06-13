# Phase 6 - Delivery and Maintenance

Earlier phases already require warnings, tests, debugging, formatting, sanitizers,
static analysis, basic CI, and progressively staged CMake. This phase integrates
those habits into risk-based verification, packaging, releases, and maintenance.

Read [Concept Brief 22](concept-briefs.md#22-verification-packaging-and-maintenance)
before this phase.

Focus on:

- unit, integration, property, fuzz, regression, and concurrency testing;
- sanitizer, static-analysis, compiler, and platform matrices;
- dependency management and reproducible builds;
- CMake installation, export, packaging, and presets;
- documentation, compatibility, versioning, releases, and maintenance;
- scoped capstones with explicit non-goals.

## 54. Quality Engineering Pass

**Category:** Delivery project

**Prerequisites:** Projects 24, 37, and 49 plus the Phase 5 transfer gate.

**Difficulty:** 4/5

**Estimated time:** 14-22 hours

**Tooling stage:** Integrate test labels, sanitizers, coverage, static analysis, and fuzz targets.

### Learning Outcomes

- Select verification techniques by risk.
- Combine regression, property, fuzz, integration, and concurrency tests.
- Distinguish warnings, sanitizers, analyzers, coverage, and review evidence.

### Goal

Apply an advanced verification plan to Config Parser, Generic Stack, and one
concurrent project using the framework and CI established earlier.

### Requirements

- Upgrade or consolidate the maintained test framework without replacing it gratuitously.
- Add property tests for a value, parsing, or serialization invariant.
- Fuzz the in-memory Config Parser with libFuzzer or an equivalent.
- Run ASan/UBSan and TSan in separate jobs.
- Run the configured static analyzer and formatter checks in CI.
- Add coverage reporting without using a percentage as a correctness claim.
- Label slow, platform-specific, sanitizer, fuzz, and stress tests separately.

### Acceptance Criteria

- [ ] One real defect becomes a permanent regression test.
- [ ] A documented fuzzing session has no sanitizer finding at completion.
- [ ] The concurrent target is TSan-clean where supported.
- [ ] The verification report maps each technique to a concrete risk.

### Stretch Goal

Add mutation or model-based testing to one component.

---

## 55. Package and Release One Project

**Category:** Delivery project

**Prerequisites:** Project 54 and one reusable library project.

**Difficulty:** 4.5/5

**Estimated time:** 20-32 hours

**Tooling stage:** Install, export, consume, package, and release.

### Learning Outcomes

- Create target-based install and export rules.
- Manage dependencies and tool versions reproducibly.
- Publish documented, versioned artifacts with compatibility policy.

### Goal

Turn Vector2, Config Parser, Generic Stack, or the optional Serialization project
into a library usable by a separate clean consumer.

### Requirements

- Provide namespaced exported targets and generated package configuration files.
- Support `cmake --install` and verify a separate consumer through `find_package`.
- Use the [supplied package skeleton](support/package-skeleton/README.md) before
  customizing it.
- Document one dependency strategy: system package, FetchContent, package manager,
  or vendoring; pin or constrain versions.
- Provide developer, sanitizer, and release presets.
- Run formatter, tests, static analysis, and at least two supported compiler
  configurations where practical.
- Generate API documentation and buildable examples.
- Define semantic versioning, source compatibility, binary compatibility scope,
  license, changelog, and release notes.
- Produce a source archive, checksums, and one platform-appropriate artifact.

### Acceptance Criteria

- [ ] A clean external project locates and links the installed package.
- [ ] Dependency acquisition and supported tool versions are reproducible.
- [ ] CI verifies build-tree and install-tree use.
- [ ] A tagged release contains documentation, checksums, and artifacts.

### Stretch Goal

Publish a package-manager recipe; this is intentionally outside the baseline estimate.

---

## 56. Milestone-Driven Capstone

**Category:** Delivery project

**Prerequisites:** Projects 54-55 and the Phase 5 gate.

**Difficulty:** 5/5

**Estimated time:** 50-90 hours for the defined MVP

**Tooling stage:** Apply the complete build, test, install, package, and CI workflow.

### Learning Outcomes

- Control scope through explicit milestones and non-goals.
- Integrate language, library, design, concurrency, testing, and delivery skills.
- Produce an engineering report supported by tests and measurements.

### Goal

Design, implement, verify, package, and release one deliberately limited product.

### Requirements

- Choose one option and write a proposal before implementation.
- Keep the MVP within the stated budget and non-goals.
- Complete every milestone in order.
- Apply the Project 54-55 quality and release workflow.

### Required Milestones

1. **Proposal:** users, use cases, constraints, risks, and non-goals.
2. **Walking skeleton:** one end-to-end operation in CI.
3. **MVP:** only required features, with stable interfaces and error policies.
4. **Hardening:** sanitizers, fuzzing where relevant, analysis, and failure tests.
5. **Performance review:** profile representative work; optimize only measured bottlenecks.
6. **Release:** installable package, documentation, examples, changelog, and artifact.
7. **Retrospective:** decisions, defects, tradeoffs, and deferred work.

### Option A: Headless Game Simulation Core

Required MVP:

- entities with stable IDs;
- components stored by composition;
- two deterministic systems;
- event handling;
- save/load;
- fixed-step simulation tests.

Non-goals:

- graphics API;
- editor;
- networking;
- production engine claims.

### Option B: Embedded Record Store

Required MVP:

- one declared schema format;
- typed rows;
- insert, get, update, and delete;
- one in-memory index;
- append-only log;
- startup recovery that accepts complete records and rejects or truncates only an
  incomplete final record;
- one predicate-based query operation.

Non-goals:

- SQL parsing;
- concurrent writers;
- transactions or ACID claims;
- query optimization;
- arbitrary crash consistency.

### Option C: Concurrent File Catalog

Required MVP:

- filesystem scan;
- cancellable bounded worker pool;
- metadata or content-hash index;
- query CLI;
- explicit full-rescan update that replaces a prior snapshot;
- snapshot persistence;
- measured single-thread and concurrent modes.

Non-goals:

- kernel filesystem notifications;
- continuous background synchronization;
- distributed indexing;
- desktop GUI.

### Acceptance Criteria

- [ ] Proposal scope is reviewed before implementation.
- [ ] Every milestone has reproducible commands and tests.
- [ ] Ownership, lifetime, concurrency, and error policies are documented.
- [ ] CI runs supported warnings, tests, sanitizers, and analysis.
- [ ] Profiling evidence supports every optimization.
- [ ] A clean user can build, install, run, and test the release.
- [ ] Deferred features remain documented rather than entering the MVP silently.

### Stretch Goal

Implement exactly one deferred feature after release and record its maintenance cost.

---

## 57. Maintenance and Patch Release

**Category:** Delivery project

**Prerequisites:** Project 56 and [Concept Brief 22](concept-briefs.md#22-verification-packaging-and-maintenance).

**Difficulty:** 4.5/5

**Estimated time:** 16-24 hours

**Tooling stage:** Reproduce, review, upgrade, preserve compatibility, and issue a patch.

### Learning Outcomes

- Change existing software safely under compatibility constraints.
- Turn a defect report into reproduction and regression evidence.
- Upgrade a dependency or toolchain deliberately.
- Produce a reviewed patch release.

### Goal

Maintain the released capstone instead of immediately adding another greenfield feature.

### Requirements

- Use a real or mentor-provided defect report with incomplete initial information.
- Reproduce the defect on the last release and add a failing regression test.
- Fix the root cause and document debugger, sanitizer, analyzer, or profiler evidence.
- Review source, binary, behavioral, data-format, and dependency compatibility.
- Upgrade one dependency, compiler, or analysis tool within documented constraints.
- Record the change in an issue and a short architecture or decision note where appropriate.
- Have another person or a structured self-review checklist review the diff.
- Release a semantic-versioning-appropriate patch with changelog, notes, artifacts,
  and checksums.

### Acceptance Criteria

- [ ] The regression test fails on the old release and passes on the patch.
- [ ] The fix does not silently expand product scope.
- [ ] Consumer and install-tree tests still pass.
- [ ] Compatibility effects and dependency changes are explicit.
- [ ] Release artifacts reproduce from the documented process.

### Stretch Goal

Backport the fix to one supported maintenance branch and document the merge strategy.
