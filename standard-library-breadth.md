# Required Standard-Library Breadth Labs

These labs complete Route B together with Projects 25-33. Complete B1-B9 in order,
then pass B10. Surveys S1-S5 are integrated into the named labs and require written
evidence even when no production implementation is appropriate.

Total target time: 94-146 hours, including survey work and the final assessment.

## Survey Evidence and Pass Rules

Surveys are bounded reference-and-experiment exercises, not implementation projects.
Their parts may be completed in the named B labs, but each survey has one final
evidence record containing:

1. a scope table mapping every listed facility to purpose, limitations, ownership or
   global-state concerns, standard version, and one cited requirement;
2. the required probe, diagnosis, or comparison with reproducible commands and
   observed output;
3. one task where the facility fits and one where another facility is preferable;
4. implementation-support findings separated from standard requirements;
5. answers to two reviewer changes of input, environment, lifetime, or failure mode.

Score each survey dimension from 0 to 2:

| Dimension | 0 | 1 | 2 |
|---|---|---|---|
| Scope | listed facilities are omitted | all are named but important limits are missing | every listed facility has purpose, limits, and boundary conditions |
| Accuracy | a central guarantee or safety claim is wrong | claims are mostly correct but imprecise | cited claims and implementation observations are clearly separated and correct |
| Retrieval | sources are absent or do not support decisions | sources are present but weakly connected | exact requirements are cited and applied to the probe or comparison |
| Application | no concrete use or rejection decision | examples exist without a defensible selection rule | fit and rejection cases follow from stated task requirements |
| Reproduction | evidence cannot be reproduced | commands or expected observations are incomplete | another reviewer can reproduce every required probe and result |

A survey passes at 8/10 or better, with no zero and with Accuracy and Application
both scoring 2. Every required deliverable below must be present; a score cannot
compensate for an omitted facility. Use the remediation rules in
[assessment-and-retention.md](assessment-and-retention.md#remediation-rules) after a
failed survey.

### S1. Text, Regex, and Localization

- Compare `char_traits`, byte/code-unit storage, `char8_t`, and Unicode processing
  boundaries without claiming that the standard library normalizes Unicode.
- Diagnose one regex that accepts a malformed record or is unsuitable for the task,
  then implement or specify the clearer token/parser alternative.
- Run one locale-sensitive numeric or collation probe under the classic locale and
  one available named locale; record an explicit unsupported result if no named
  locale is installed.
- **Oracle:** the same bytes/code units, regex cases, and locale inputs produce the
  recorded outcomes, and the selection table states where locale-independent
  `charconv` is required.

### S2. Specialized Numeric and Flat Storage

- Compare `valarray` with `vector` plus algorithms/ranges for one numeric expression.
- Compare a flat associative container, or a sorted-vector fallback, with a
  node-based associative container for lookup and mutation requirements.
- Probe one floating-point environment operation such as exception flags or rounding
  mode, then document compiler/platform limitations and optimization assumptions.
- **Oracle:** both alternatives agree on defined result data, container ordering and
  duplicate policy are tested, and floating-environment claims match observed flags
  or an explicitly unsupported result.

### S3. C Boundaries and Execution Policies

- Audit one C compatibility API for ownership, null termination, error signaling,
  locale/global state, thread safety, and its preferred C++ alternative.
- Compare a serial algorithm with one execution-policy form using an independent
  callable and equivalent result check; implementation unavailability is acceptable
  when documented.
- Retrieve the selected policy's ordering and exception constraints.
- **Oracle:** the boundary adapter passes success and failure tests without ownership
  ambiguity, and the policy comparison checks result equivalence without requiring
  a speedup.

### S4. Runtime Diagnostics and Termination

- Compare RTTI/`type_index` with an explicit variant, virtual operation, or registry
  protocol for one task.
- Probe `source_location` and feature-gated `stacktrace` while excluding unstable
  implementation text from the test oracle.
- Classify assertion, `error_code` category/condition, exception, and termination
  examples; run fatal behavior only in an isolated subprocess.
- **Oracle:** the diagnostic path preserves domain context, the alternative design
  comparison uses the same behavior contract, and the subprocess observes the
  expected termination category rather than exact diagnostic text.

### S5. Allocators, PMR, and C Pointer Adapters

- Trace one `allocator_traits` allocate/construct/destroy/deallocate lifecycle and
  state which responsibilities belong to the container, allocator, and element.
- Measure one bounded allocation-heavy workload with a normal allocator and one PMR
  resource; record a case where PMR is not justified.
- Compare a manual C out-parameter owner adapter with feature-gated `out_ptr` or
  `inout_ptr`, including success and failure ownership transfer.
- **Oracle:** allocation/deallocation counts balance, the PMR comparison reports
  workload and measurements without assuming improvement, and both pointer-adapter
  paths have equivalent leak-free ownership behavior.

## B1. Vocabulary Types, Utilities, and Callable Toolbox

**Category:** Required breadth lab

**Prerequisites:** Phase 2 transfer gate and
[Brief 1](standard-library-briefs.md#1-vocabulary-types-utilities-and-callables).

**Estimated time:** 7-12 hours

### Outcomes

- Select among named structs, tuples, optional, expected, variant, and any.
- Use standard invocation and callable wrappers deliberately.
- Apply traits, concepts, integer sequences, and reference wrappers safely.
- Explain allocator and PMR purpose without making them default application tools.

### Required Work

- Refactor one multi-value return between tuple and a named struct; compare clarity.
- Implement one operation with optional, expected, and exception adapters.
- Visit a variant exhaustively and compare it with any plus explicit type checks.
- Use `apply`, `invoke`, `reference_wrapper`, and one bind/not adapter.
- Compare `function`, `move_only_function`, and a templated callable parameter.
- Implement one trait/concept diagnostic and one `integer_sequence` or ratio task.
- Complete Survey S5 on allocators, PMR, and C pointer adapters.

### Acceptance

- [ ] Every vocabulary type has a state-model justification.
- [ ] No non-owning wrapper is described as extending lifetime.
- [ ] Unsupported `move_only_function` and pointer-adapter paths are feature-gated.
- [ ] S5 names one measured PMR use case and one reason not to use PMR.

## B2. Complete Container and Adaptor Comparison

**Category:** Required breadth lab

**Prerequisites:** B1, Project 25, and
[Brief 2](standard-library-briefs.md#2-container-families-and-adaptors).

**Estimated time:** 8-14 hours

### Outcomes

- Use every standard container family at least once.
- Select duplicate-key, hashed, ordered, contiguous, segmented, and node storage
  deliberately.
- Apply adaptors, node handles, heterogeneous lookup, and range insertion.

### Required Work

- Implement one workload against vector, deque, list, and forward_list.
- Model duplicate keys with one ordered and one unordered multicontainer.
- Use unordered set and map forms with tested hash/equality agreement.
- Use stack, queue, and priority_queue for naturally restricted operations.
- Transfer an associative node and perform heterogeneous lookup.
- Feature-gate C++23 range insertion and flat containers.
- Complete the flat-container portion of Survey S2.

### Acceptance

- [ ] The operation table includes complexity, ordering, layout, and invalidation.
- [ ] Hash and equality define compatible equivalence.
- [ ] No node-based container is called faster without workload evidence.
- [ ] Flat-container fallback behavior is equivalent on the tested workload.

## B3. Iterator Adaptors and Algorithm Families

**Category:** Required breadth lab

**Prerequisites:** B2, Projects 26 and 29-30, and
[Brief 3](standard-library-briefs.md#3-iterators-algorithms-and-ranges).

**Estimated time:** 12-19 hours

### Outcomes

- Use iterator adaptors and structured algorithm results.
- Apply every major classic algorithm family.
- Compare classic, ranges, numeric, and raw-memory algorithms.
- Manage explicit object lifetime, address conversion, and alignment only inside an
  isolated raw-storage exercise.

### Required Work

- Use insert, move, reverse, counted/common, and stream iterators.
- Implement partition, selection, binary search, merge, set, heap, and permutation
  exercises with explicit preconditions.
- Use at least four numeric algorithms, including one scan.
- Use ranges projections and inspect one structured algorithm result.
- Diagnose an invalid comparator and an invalidated iterator.
- Allocate raw storage for several non-trivial objects; use `construct_at`,
  `destroy_at`, at least one `uninitialized_*` algorithm, and `destroy` or
  `destroy_n`, including cleanup after an injected constructor failure.
- Use `addressof`, `pointer_traits`, and `to_address` to distinguish an object address
  from a pointer-like representation.
- Use `align` to carve an aligned region from a byte buffer, pair aligned allocation
  with the matching deallocation, and call `assume_aligned` only after a proven
  alignment precondition.
- Feature-gate `start_lifetime_as`; compare its native path with construction of a
  value from copied bytes without treating arbitrary bytes as a live object.
- Compare a serial algorithm with its execution-policy interface without claiming a
  speedup.

### Acceptance

- [ ] Sorted-input and iterator-category requirements are documented and tested.
- [ ] The raw-memory lab has one storage owner, destroys exactly the constructed
      elements after success or injected failure, and has no leak under sanitizers.
- [ ] Every dereferenced pointer designates a live object of the correct type, and no
      unchecked alignment promise is executed.
- [ ] Allocation/deallocation form and alignment match; native and fallback lifetime
      paths record their feature evidence.
- [ ] Classic and ranges versions agree on behavior.
- [ ] Parallel-policy discussion identifies callable and exception constraints.

## B4. Numerics, Mathematics, Randomness, and Bits

**Category:** Required breadth lab

**Prerequisites:** B3 and
[Brief 4](standard-library-briefs.md#4-numerics-mathematics-bits-and-randomness).

**Estimated time:** 10-15 hours

### Outcomes

- Use numeric limits, math classification, constants, and complex arithmetic.
- Select numeric algorithms with deliberate result types.
- Use bit facilities for a documented representation or protocol task.
- Separate random engines, seeding, and distributions.

### Required Work

- Build a statistics pipeline with accumulate, inner product, adjacent difference,
  partial sum, reduce, and scans where applicable.
- Demonstrate one floating-point regrouping difference.
- Use finite/NaN/infinity classification and standard constants.
- Implement one complex-number domain example.
- Use bit count, rotation, endian, bit_cast, and feature-gated byteswap.
- Compare at least two random engines or distributions and record reproducible seeds.
- Complete the numerical portion of Survey S2, including valarray and floating-point
  environment limitations.

### Acceptance

- [ ] Initial accumulator and result types cannot truncate silently.
- [ ] `bit_cast` preconditions and protocol byte order are explicit.
- [ ] Random tests do not depend on one unspecified sequence.
- [ ] S2 identifies when a dedicated numerical library is more appropriate.

## B5. Streams, Text Conversion, Formatting, and Buffers

**Category:** Required breadth lab

**Prerequisites:** B4, Project 32, and
[Brief 5](standard-library-briefs.md#5-text-streams-formatting-and-buffers).

**Estimated time:** 12-19 hours

### Outcomes

- Control stream state and formatted/unformatted input.
- Use file, string, span, and synchronized streams with correct ownership.
- Apply modern string search, prefix/suffix, containment, and resize operations.
- Explain and test the stream-buffer boundary beneath a stream.
- Compare locale-independent conversion with stream conversion.
- Implement and test a custom formatter.

### Required Work

- Diagnose and recover from stream fail, bad, and EOF states.
- Implement a string command/parser task using `find`/search, `starts_with`,
  `ends_with`, feature-gated `contains`, and a resize operation; distinguish byte
  positions from user-perceived text positions.
- Parse equivalent input with streams and charconv.
- Use file streams with explicit finalization/error policy.
- Use string streams and a feature-gated spanstream path.
- Implement one bounded output `streambuf` or forwarding/counting `streambuf`; test
  `overflow`, bulk writes, EOF/failure propagation, and the lifetime of the wrapped
  sink or buffer.
- Write one stream-iterator algorithm.
- Implement one custom formatter and equivalent stream fallback.
- Demonstrate synchronized output without treating it as data synchronization.
- Complete Survey S1 on regex, locales, char traits, and encoding boundaries.

### Acceptance

- [ ] Every stream owner and buffer lifetime is documented.
- [ ] String search and resize boundary cases are tested, and unsupported C++23
      members use behaviorally equivalent fallbacks.
- [ ] The custom stream buffer preserves its stated capacity/forwarding invariant and
      exposes write failure through stream state.
- [ ] Partial and malformed input cannot create an infinite loop.
- [ ] Native and fallback formatted output are behaviorally equivalent.
- [ ] S1 includes one regex rejection in favor of a parser and one locale-sensitive
      example.

## B6. Filesystem Operations and Civil Time

**Category:** Required breadth lab

**Prerequisites:** B5 and Projects 31 and 33, plus
[Brief 6](standard-library-briefs.md#6-filesystem-and-chrono-breadth).

**Estimated time:** 9-14 hours

### Outcomes

- Apply metadata, normalization, canonicalization, permission, space, copy, rename,
  and remove operations.
- Use calendars, time zones, parsing, and formatting with explicit assumptions.

### Required Work

- Build a temporary filesystem fixture containing files, directories, and symlinks.
- Compare lexical normalization, weak canonicalization, and canonicalization.
- Inspect metadata and free-space information without assuming files remain stable.
- Implement copy/rename/remove only behind dry-run and confirmation boundaries.
- Perform calendar arithmetic and detect invalid civil dates.
- Parse, format, and convert a zoned timestamp where timezone support exists.
- Provide a documented UTC-only fallback when timezone data is unavailable.

### Acceptance

- [ ] Destructive tests operate only inside RAII-managed temporary directories.
- [ ] Symlink, permission, race, and changing-file policies are explicit.
- [ ] Ambiguous/nonexistent local times have defined behavior.
- [ ] Timezone support and database availability are recorded separately.

## B7. Diagnostics, Exceptions, Runtime Support, and C Boundaries

**Category:** Required breadth lab

**Prerequisites:** B6 and
[Brief 7](standard-library-briefs.md#7-diagnostics-runtime-support-and-compatibility).

**Estimated time:** 7-11 hours

### Outcomes

- Enrich diagnostics with source location and nested causes.
- Use exception pointers across a controlled boundary.
- Compare RTTI, error categories, assertions, and termination facilities.
- Audit a C compatibility boundary.

### Required Work

- Add source-location context to one error without exposing absolute paths in stable
  output.
- Transport and rethrow one exception through an exception pointer.
- Preserve a lower-level cause with a nested exception or typed error chain.
- Compare an RTTI/type_index registry with an explicit variant or virtual protocol.
- Define assertion, recoverable error, and fatal-termination examples.
- Feature-gate stacktrace and compare its output with the source-location fallback.
- Complete Survey S4 on diagnostics/runtime support and the C-boundary portion of S3.

### Acceptance

- [ ] Diagnostics preserve domain context and do not become the error policy.
- [ ] No test depends on exact implementation-specific stacktrace text.
- [ ] The C boundary documents ownership, null termination, error signaling, locale,
      and thread-safety.
- [ ] Fatal examples run only in isolated subprocess tests.

## B8. Concurrency Coordination, Atomic Utilities, and Parallel Algorithms

**Category:** Required breadth lab

**Prerequisites:** B7 and Projects 44-50, plus
[Brief 8](standard-library-briefs.md#8-concurrency-library-breadth).

**Estimated time:** 10-16 hours

### Outcomes

- Select shared/timed locking and coordination primitives deliberately.
- Use packaged tasks, atomic_ref, and atomic wait/notify safely.
- Evaluate parallel algorithms against a serial reference.

### Required Work

- Implement one read-mostly experiment with shared locking and measurement.
- Use a timed lock only where timeout is part of observable behavior.
- Build separate latch, reusable barrier, and semaphore examples.
- Compare packaged_task with promise and async.
- Use atomic_ref on a suitably aligned object with no concurrent non-atomic access.
- Replace a polling loop with atomic wait/notify.
- Run one parallel algorithm and compare results, workload, and timing with serial.
- Complete the execution-policy portion of Survey S3.

### Acceptance

- [ ] Each synchronization primitive has a state predicate or phase invariant.
- [ ] Timeout tests do not claim deterministic scheduler timing.
- [ ] Atomic-ref lifetime, alignment, and access restrictions are documented.
- [ ] Parallel output matches the serial reference and no speedup is assumed.

## B9. C++23 Standard-Library Integration

**Category:** Required breadth lab

**Prerequisites:** B1-B8, [Brief 9](standard-library-briefs.md#9-c23-library-additions),
and [toolchain-support.md](toolchain-support.md).

**Estimated time:** 11-16 hours

### Outcomes

- Detect representative C++23 library facilities through feature-test macros.
- Implement native and fallback paths with one behavior contract.
- Distinguish standard requirements from implementation limitations.

### Required Work

- Exercise expected, print, spanstream, move_only_function, and byteswap.
- Use ranges::to, one fold algorithm, and at least four new C++23 views.
- Exercise container range insertion and heterogeneous erasure where supported.
- Compare one flat container with its sorted-vector fallback.
- Apply mdspan to non-owning multidimensional data where supported.
- Compare out_ptr/inout_ptr with a manual C API adapter.
- Record stacktrace support without requiring stable formatting.
- Produce the feature record required by `toolchain-support.md`.

### Acceptance

- [ ] Every native path names the observed feature macro and value.
- [ ] Every required unavailable facility has a tested fallback.
- [ ] Survey-only facilities are not mislabeled as core mastery.
- [ ] Compiler version checks are not used as the sole support test.

## B10. Facility Selection and Documentation Navigation

**Category:** Required breadth assessment

**Prerequisites:** B1-B9, Surveys S1-S5, and
[Brief 10](standard-library-briefs.md#10-facility-selection-and-reference-navigation).

**Estimated time:** 8-10 hours

### Assessment

Complete an unseen problem containing:

- heterogeneous records and optional/error states;
- ordered and unordered lookup workloads;
- one lazy transformation and one owning result;
- numeric aggregation and reproducible randomness;
- text parsing, formatting, filesystem, and timestamp boundaries;
- one synchronization or task-result requirement;
- one C++23 facility unavailable on a secondary profile.

Submit:

1. operation and ownership tables;
2. selected facilities and rejected alternatives;
3. citations for complexity, invalidation, preconditions, and guarantees;
4. a tested implementation;
5. native/fallback feature evidence;
6. one compile-fail or diagnostic fixture exposing a mistaken assumption.

### Pass Criteria

- [ ] Every Core and Working inventory row has linked evidence.
- [ ] All five surveys have reviewer-approved notes.
- [ ] The unseen implementation passes behavior and quality gates and scores at
      least 12/15 under the
      [project rubric](assessment-and-retention.md#project-rubric).
- [ ] Reference citations support the actual design decisions.
- [ ] Unsupported facilities are neither hidden nor counted as native completion.
