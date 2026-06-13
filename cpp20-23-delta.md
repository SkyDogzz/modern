# C++20-to-C++23 Language and Library Delta

This module separates language evolution from standard-library evolution. D1-D4 are
required for the Advanced Language and Delivery route. D5-D7 are optional
implementation-sensitive tracks.

Required estimate: 24-40 hours.

## Detection Model

Language features are generally detected with predefined `__cpp_*` macros. Library
features are detected after including `<version>` with `__cpp_lib_*` macros.
`__cplusplus` identifies the selected language mode, not complete implementation
support. MSVC users must record whether `/Zc:__cplusplus` is enabled.

If a standardized feature has no dedicated macro, use a focused compile probe.
Compiler version checks may select known workarounds only after the feature check;
they are never the sole evidence of support.

Use [references.md](references.md) for the fixed C++23 draft, searchable clauses,
WG21 feature history, and maintained API lookup. Use
[toolchain-support.md](toolchain-support.md) only for implementation availability
and registered fallbacks.

## Representative Feature Lineage

### C++20 Language

| Feature | Detection |
|---|---|
| Concepts and requires expressions | `__cpp_concepts` |
| Three-way comparison language support | `__cpp_impl_three_way_comparison` |
| Designated initializers | `__cpp_designated_initializers` |
| `consteval` | `__cpp_consteval` |
| `constinit` | `__cpp_constinit` |
| Coroutines | `__cpp_impl_coroutine` |
| Modules | `__cpp_modules` |
| Class non-type template parameters | `__cpp_nontype_template_parameter_class` |

### C++20 Library

| Feature | Detection |
|---|---|
| `span` | `__cpp_lib_span` |
| Ranges | `__cpp_lib_ranges` |
| Formatting | `__cpp_lib_format` |
| Source location | `__cpp_lib_source_location` |
| `jthread` and stop tokens | `__cpp_lib_jthread` |
| Latches, barriers, semaphores | facility-specific library macros |
| Chrono calendars and time zones | `__cpp_lib_chrono` |
| `bit_cast` | `__cpp_lib_bit_cast` |
| Mathematical constants | `__cpp_lib_math_constants` |

### C++23 Language

| Feature | Detection |
|---|---|
| `if consteval` | `__cpp_if_consteval` |
| Explicit object parameters | `__cpp_explicit_this_parameter` |
| Multidimensional subscript | `__cpp_multidimensional_subscript` |
| Static call operator | `__cpp_static_call_operator` |
| Simpler implicit move | `__cpp_implicit_move` |
| Named universal character escapes | `__cpp_named_character_escapes` |
| Range-for lifetime extension | `__cpp_range_based_for` |
| `auto(x)` decay-copy | focused compile probe when no dedicated macro is exposed |

### C++23 Library

The required representative set is maintained in
`stdlib-facility-inventory.md` and `toolchain-support.md`. It includes expected,
printing, span streams, move-only callables, range materialization/folds/views, flat
containers, multidimensional views, byte utilities, pointer adapters, and stack
traces.

## D1. C++20 Language Foundations

**Category:** Required delta lab

**Prerequisites:** Competency G2 and a compiler capable of selecting C++17, C++20,
and C++23 modes.

**Estimated time:** 6-10 hours

### Required Work

- Compile one feature-report program in C++17, C++20, and C++23 modes.
- Implement a constrained overload and compare diagnostics with an unconstrained
  template.
- Implement and test a three-way-comparable integral value type.
- Use designated initialization only where aggregate/member order remains clear.
- Compare `constexpr`, `consteval`, and `constinit`.
- Write a minimal coroutine code-reading exercise and identify frame lifetime,
  suspension points, and promise responsibilities.
- Build a module support probe without requiring the learner's main project to use
  modules.

### Acceptance

- [ ] Every example identifies its introducing standard.
- [ ] Language-mode selection is not described as proof of implementation support.
- [ ] Coroutine and module concepts are explained even when the selected toolchain
      cannot complete the optional implementation tracks.
- [ ] Failed feature probes produce a recorded unsupported result.

## D2. C++20 Library Integration

**Category:** Required delta lab

**Prerequisites:** D1 and standard-library competencies L1-L3.

**Estimated time:** 6-10 hours

### Required Work

- Refactor one pointer-plus-length interface to span.
- Implement equivalent classic and ranges pipelines.
- Format one domain value and compare with stream output.
- Capture call-site diagnostics with source_location.
- Own a cancellable worker with jthread and stop tokens.
- Build focused latch, barrier, and semaphore examples.
- Perform calendar arithmetic and record timezone support.
- Use bit_cast and a mathematical constant in domain-matched examples.

### Acceptance

- [ ] Every library facility records its feature macro and observed value.
- [ ] Span and ranges lifetimes are documented.
- [ ] Formatting and chrono fallbacks preserve required behavior.
- [ ] Synchronization examples state their phase or permit invariants.

## D3. C++23 Language Delta

**Category:** Required delta lab

**Prerequisites:** D1-D2.

**Estimated time:** 6-10 hours

### Required Work

- Use `if consteval` to separate compile-time and runtime handling.
- Implement one explicit-object-parameter example and an ordinary-member fallback.
- Use multidimensional subscript syntax for a bounded matrix type.
- Implement a stateless static call operator and compare object requirements.
- Demonstrate `auto(x)` decay-copy against plain `auto` and `decltype(auto)`.
- Demonstrate simpler implicit move from a local return.
- Test range-for lifetime extension with a C++20 comparison or compile probe.
- Use one named universal character escape in an isolated encoding example.

### Acceptance

- [ ] Each feature has a conventional fallback or a documented reason none is needed.
- [ ] Explicit object parameters are not presented as mandatory style.
- [ ] The range-for example distinguishes the C++23 rule from unrelated dangling
      views.
- [ ] No example relies only on compiler-version detection.

## D4. C++23 Library Delta and Feature Inventory

**Category:** Required delta assessment

**Prerequisites:** D1-D3, B9 or equivalent facility evidence, and
`toolchain-support.md`.

**Estimated time:** 6-10 hours

### Required Work

- Generate a feature report from `<version>` for the selected primary and secondary
  profiles.
- Implement at least six representative C++23 library additions across four
  different library areas.
- Exercise one native/fallback pair whose native path is unavailable on the
  secondary profile.
- Classify every representative feature as language, library, implementation
  extension, or unavailable.
- Cite the proposal or standard-library status source for each implemented feature.
- Explain which C++20 feature each C++23 example builds upon.

### Acceptance

- [ ] The report identifies the introducing standard and feature macro or compile
      probe for every item.
- [ ] Primary and secondary profile results are kept separate.
- [ ] Native and fallback tests share one behavior contract.
- [ ] Unsupported features remain visible in the report.

## D5. Optional Module Packaging Track

**Category:** Optional delta specialization

- Convert one small header/library target to a named module.
- Keep the installed header/package fallback.
- Record compiler, generator, dependency scanning, and install limitations.
- Compare build graph and distribution behavior rather than source syntax alone.

## D6. Optional Coroutine Generator Track

**Category:** Optional delta specialization

- Use `std::generator` where available or a small provided coroutine type.
- Trace coroutine frame ownership, suspension, exceptions, and destruction.
- Compare the generator with an iterator/range implementation.
- Keep a custom promise type out of the mandatory route.

## D7. Optional `mdspan` Layout Track

**Category:** Optional delta specialization

- Apply `mdspan` to a matrix or image view.
- Compare static/dynamic extents and layout mappings.
- Document that `mdspan` is non-owning.
- Keep a span-plus-indexing fallback and test both against one contract.

## Delta Gate

- [ ] D1-D4 pass the
      [project rubric](assessment-and-retention.md#project-rubric), with D4 scoring
      at least 12/15.
- [ ] Every representative feature names its introducing standard.
- [ ] Language and library feature detection are not conflated.
- [ ] The primary and secondary toolchain inventories are attached.
- [ ] Optional D5-D7 tracks are not required for route completion.
