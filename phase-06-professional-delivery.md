# Phase 6 - Professional Delivery

Earlier phases already require warnings, tests, debugging, sanitizers, and progressively staged
CMake. This phase extends those habits into verification, packaging, CI, and
release engineering.

Focus on:

- advanced unit, integration, property, fuzz, and regression testing;
- sanitizer and static-analysis matrices;
- dependency management and reproducible builds;
- CMake installation, export, packaging, and presets;
- documentation, versioning, releases, and scoped capstones.

## 40. Quality Engineering Pass

**Prerequisites:** Phases 1-5.

**Difficulty:** 4/5

**Estimated time:** 12-18 hours

**CMake stage:** Add test labels, sanitizer presets, coverage, and optional fuzz targets.

### Learning Outcomes

- Select tests by risk rather than only by code unit.
- Use regression, property, fuzz, integration, and concurrency tests.
- Combine compiler warnings, sanitizers, and static analysis without conflating them.

### Goal

Apply an advanced verification plan to the Config Parser, Generic Stack, and one
concurrent project.

### Requirements

- Use a maintained test framework or a clearly documented minimal harness.
- Add property tests for a value or serialization invariant.
- Fuzz the in-memory Config Parser entry point with libFuzzer or an equivalent tool.
- Run ASan/UBSan and TSan in separate jobs.
- Add `clang-tidy` or an equivalent static analyzer.
- Add coverage reporting, but do not treat percentage as proof of correctness.

### Acceptance Criteria

- [ ] At least one real defect becomes a permanent regression test.
- [ ] The parser survives a documented fuzzing session without sanitizer findings.
- [ ] The concurrent target is clean under TSan in a supported environment.
- [ ] Slow, platform-specific, and sanitizer tests are labeled separately.

### Stretch Goal

Add mutation testing or model-based tests for one component.

---

## 41. Package and Release One Project

**Prerequisites:** Project 40 and one reusable library project.

**Difficulty:** 4.5/5

**Estimated time:** 16-24 hours

**CMake stage:** Install, export, consume, package, and release the project.

### Learning Outcomes

- Create target-based install and export rules.
- Manage dependencies reproducibly.
- Publish usable documentation and versioned release artifacts.

### Goal

Turn the Vector2, Config Parser, or Serialization project into a library that a
separate consumer can install and use.

### Requirements

- Provide namespaced CMake targets and generated package configuration files.
- Add `cmake --install` support and verify a separate consumer project.
- Choose and document a dependency strategy: system packages, FetchContent,
  package manager, or vendoring.
- Add CMake presets for developer, sanitizer, and release builds.
- Run formatting, tests, static analysis, and supported compiler jobs in CI.
- Generate API documentation and include examples.
- Define semantic versioning, compatibility policy, license, changelog, and release notes.
- Produce a source archive and at least one platform-appropriate package or artifact.

### Acceptance Criteria

- [ ] A clean consumer project can locate and link the installed package.
- [ ] Dependencies are pinned or constrained reproducibly.
- [ ] CI builds at least two supported compiler configurations where practical.
- [ ] A tagged release contains documentation, checksums, and artifacts.

### Stretch Goal

Publish the package through a package-manager-compatible recipe.

---

## 42. Milestone-Driven Capstone

**Prerequisites:** Projects 40-41 and the phase gate in `checklists.md`.

**Difficulty:** 5/5

**Estimated time:** 40-80 hours for the defined MVP

**CMake stage:** Apply the complete build, test, install, package, and CI workflow.

### Learning Outcomes

- Control scope through explicit milestones and non-goals.
- Integrate language, library, design, testing, and delivery skills.
- Produce an autonomous engineering report supported by evidence.

### Goal

Design, implement, verify, package, and release one deliberately limited product
that integrates the roadmap's core skills.

### Requirements

- Choose one option and write a proposal before implementation.
- Keep the MVP within the stated time budget and non-goals.
- Complete every required milestone in order.
- Apply the full quality and delivery workflow from Projects 40-41.

### Required Milestones

1. **Proposal:** users, use cases, constraints, risks, and explicit non-goals.
2. **Walking skeleton:** one end-to-end operation built and tested in CI.
3. **MVP:** only required features, with stable interfaces and error policies.
4. **Hardening:** sanitizers, fuzzing where relevant, static analysis, and failure tests.
5. **Performance review:** profile representative workloads; optimize only measured bottlenecks.
6. **Release:** installable package, documentation, examples, changelog, and tagged artifact.
7. **Retrospective:** architecture decisions, defects found, tradeoffs, and deferred work.

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
- production game-engine claims.

### Option B: Embedded Record Store

Required MVP:

- declared schemas;
- typed rows;
- insert, get, update, and delete;
- one in-memory index;
- append-only persistence and recovery;
- a small query predicate API.

Non-goals:

- SQL parser;
- distributed operation;
- full ACID guarantees;
- query optimizer.

### Option C: POSIX Command Runner

Additional prerequisite: prior POSIX process and file-descriptor study.

Required MVP:

- tokenizer with quoting rules;
- command AST;
- external command execution;
- one pipe;
- input/output redirection;
- RAII wrappers for file descriptors and child processes.

Non-goals:

- full shell grammar;
- job control;
- terminal emulation;
- Windows portability.

### Option D: Concurrent File Indexer

Required MVP:

- filesystem scan;
- cancellable worker pool;
- content or metadata index;
- query CLI;
- incremental update;
- persistent index;
- measured single-thread and concurrent modes.

Non-goals:

- kernel filesystem notifications;
- distributed indexing;
- desktop GUI.

### Acceptance Criteria

- [ ] The proposal is approved against the 40-80 hour MVP scope before implementation.
- [ ] Every milestone has demonstrable commands and tests.
- [ ] Ownership, lifetime, concurrency, and error policies are documented.
- [ ] CI runs warnings, tests, sanitizers, and static analysis as supported.
- [ ] Profiling evidence supports every performance optimization.
- [ ] A clean user can build, install, run, and test the released artifact.
- [ ] Deferred features remain documented rather than silently expanding scope.

### Stretch Goal

Implement exactly one deferred feature after the MVP release and document the
maintenance cost it adds.
