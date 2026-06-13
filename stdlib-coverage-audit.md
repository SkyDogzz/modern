# Standard-Library Coverage Audit

> Historical baseline, closed on 2026-06-13. The original ratings describe the
> pre-remediation curriculum. Current required coverage is mapped in
> [audit-resolution.md](audit-resolution.md#standard-library-coverage-crosswalk).

This matrix evaluates the required curriculum, not incidental mentions or optional
stretch goals.

Coverage levels:

- **Strong:** repeated practical use with explicit correctness constraints.
- **Partial:** representative facilities are used, but the area is not surveyed
  systematically.
- **Thin:** one or two facilities appear without broad working familiarity.
- **Absent:** no meaningful required coverage.

## Coverage Matrix

| Library area | Current coverage | Current evidence | Important gaps |
|---|---|---|---|
| Language support and diagnostics | Thin | Exit status, exceptions, feature tests | `source_location`, `stacktrace`, RTTI, exception utilities, termination |
| Concepts and type traits | Partial | Concepts, traits, constrained algorithms | Broader standard concepts and traits, `integer_sequence`, `ratio` |
| General utilities | Partial | `optional`, `expected`, `variant`, smart pointers | `pair`, `tuple`, `any`, `bitset`, `reference_wrapper`, utility helpers |
| Functional utilities | Partial | Lambdas, `std::function`, forwarding | `invoke`, `bind_front`, `mem_fn`, `not_fn`, `move_only_function` |
| Memory management | Partial | RAII, smart pointers, PMR optional | Allocator model, raw-memory algorithms, `out_ptr`, `inout_ptr`, alignment utilities |
| Strings and text conversion | Partial-thin | `string`, `string_view`, `from_chars` | `to_chars`, string operations survey, text encoding boundaries |
| Sequence containers | Partial | `array`, `vector`, `list`, optional `deque` | `forward_list`, deeper `deque`, advanced APIs, C++23 range insertion |
| Associative containers | Partial | `map`, `set`, `unordered_map`, optional `flat_map` | Multicontainers, unordered sets, `flat_set`, node handles, heterogeneous lookup |
| Container adaptors | Thin | Mentioned and one optional exercise | Systematic `stack`, `queue`, and `priority_queue` use |
| Iterators | Thin | Categories, sentinel loop, invalidation | Insert, move, reverse, counted, common, and stream iterators; iterator utilities |
| Classic algorithms | Partial | Sort, search, count, transform | Partition, merge, set, heap, permutation, binary-search families |
| Numeric algorithms | Thin | Averages and unspecified numeric work | `accumulate`, reductions, scans, inner product, adjacent difference, iota |
| Raw-memory algorithms | Absent | None | Uninitialized construction, destruction, relocation-related facilities |
| Ranges algorithms | Partial | Projections and selected range algorithms | Result types, broader families, systematic classic/ranges comparison |
| Range views | Partial | Filter, transform, borrowed ranges | Split, join, zip, adjacent, chunk, slide, repeat, cartesian product |
| C++23 range utilities | Thin | Optional feature-macro stretch goal | `ranges::to`, fold algorithms, range insertion, new views |
| I/O streams | Thin | Basic `cout` and terminal input | Stream state, manipulators, files, strings, span streams, buffers, `osyncstream` |
| Formatting and printing | Partial | `format`, `print`, alignment and precision | Formatter contracts, locale interactions, format errors, broader formatting model |
| Filesystem | Partial | Paths, iteration, errors, symlink policy | Metadata, normalization, canonicalization, copying, permissions, space operations |
| Chrono | Partial | Durations, clocks, injected time | Calendars, time zones, parsing, formatting, clock conversion |
| Numerics and mathematics | Thin | Arithmetic, random engine, profiling | `<cmath>`, constants, complex numbers, `valarray`, floating environment |
| Bit manipulation | Absent | `std::byte` only | `bitset`, `<bit>`, endian, rotations, population count, `bit_cast`, `byteswap` |
| Random numbers | Partial-thin | Engine, distribution, deterministic seed | Engine/distribution selection, seeding, sampling, distribution breadth |
| Regular expressions | Absent | None | Matching, searching, replacement, grammar and performance limitations |
| Localization | Absent | None | Locales, facets, collation, numeric and time formatting interactions |
| Concurrency: threads and locks | Strong | Threads, `jthread`, mutexes, condition variables | Shared/timed mutexes and broader lock utilities |
| Concurrency: coordination | Thin | Latch, barrier, semaphore are stretch material | Required practical synchronization primitive survey |
| Concurrency: atomics | Partial | Atomic counters, ordering foundations | `atomic_ref`, wait/notify, broader atomic specializations |
| Futures and task results | Partial | Promise, future, async | Packaged tasks and broader composition limitations |
| Parallel algorithms | Absent | None | Execution policies, safety constraints, measurement and portability |
| Memory resources | Optional | PMR text processor | Mandatory allocator-awareness survey |
| C compatibility library | Minimal | `FILE*`, C strings, `argc`/`argv` | Structured survey and modern replacement guidance |
| C++23 headline additions | Thin | `expected`, `print`, optional generator/mdspan | `stacktrace`, span streams, flat containers, `move_only_function`, pointer adapters |

## Recommended Coverage Tiers

Teaching every overload is neither realistic nor useful. Assign facilities to these
tiers.

### Core Mastery

The learner should select, use, test, and explain these without step-by-step guidance:

- strings, string views, spans, arrays, vectors;
- maps, sets, unordered maps, queues, stacks, and priority queues;
- iterators, algorithms, ranges, and common views;
- optional, expected, variant, smart pointers, and callable wrappers;
- chrono durations and clocks;
- filesystem paths and traversal;
- formatting and printing;
- thread ownership, locks, condition variables, futures, and basic atomics.

### Working Familiarity

The learner should complete focused labs and know when to consult references:

- remaining sequence and associative containers;
- tuples, pairs, any, bitset, reference wrappers, and utility helpers;
- stream state, file/string/span streams, and stream buffers;
- numeric algorithms, mathematical functions, complex numbers, random facilities;
- bit utilities;
- chrono calendars and time zones;
- coordination primitives and advanced atomic utilities;
- broader C++23 range facilities.

### Survey

The learner should understand purpose, limitations, and alternatives:

- regular expressions;
- localization;
- PMR and allocators;
- parallel algorithms and execution policies;
- C compatibility headers;
- stack traces and runtime diagnostics;
- modules, coroutines, generators, and `mdspan`.

### Reference Only

Rare, obsolete, highly specialized, or implementation-sensitive details should be
recognized but not memorized. Completion should require the learner to find and apply
documentation correctly rather than reproduce APIs from memory.

## Suggested Standard-Library Track

1. Utility vocabulary types and callable utilities.
2. Complete container and adaptor comparison.
3. Iterator adaptors and algorithm families.
4. Numeric algorithms, math, random, and bit utilities.
5. Streams, files, buffers, formatting, and text conversion.
6. Chrono calendars/time zones and filesystem operations.
7. Diagnostics, regex, localization, and C compatibility survey.
8. Concurrency library breadth and parallel algorithms.
9. C++20/C++23 library delta with feature detection.
10. Final facility-selection and documentation-navigation assessment.
