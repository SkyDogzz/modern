# Standard-Library Facility Inventory

This is the completion inventory for the Standard-Library Breadth route. Incidental
use does not count as coverage: each Core or Working item requires the named exercise
and assessment evidence.

Feature-detection and fallback entries use the sourced, dated
[compatibility workaround register](toolchain-support.md#compatibility-workaround-register).
An unregistered workaround cannot satisfy a route gate.

Exercise identifiers:

- `Pnn` refers to an existing numbered project.
- `B1`-`B10` refer to the required standard-library breadth labs.
- `S1`-`S5` refer to required survey exercises.
- `R` means reference-only recognition and does not block completion.

Assessment codes:

- **Implement:** tested implementation using the facility.
- **Compare:** written selection or tradeoff comparison backed by examples.
- **Diagnose:** repair or explain provided incorrect code.
- **Retrieve:** locate exact requirements in a current reference and cite them.
- **Transfer:** solve an unseen facility-selection problem.

## Utilities, Types, and Memory

| Facility | Header | Standard | Tier | Exercise | Assessment | Feature detection or fallback |
|---|---|---:|---|---|---|---|
| `pair`, `tuple`, structured access, `apply` | `<utility>`, `<tuple>` | C++11/17 | Core | B1 | Implement, Compare | Always required |
| `optional` | `<optional>` | C++17 | Core | P18, B1 | Implement | `__cpp_lib_optional`; no fallback in core profile |
| `expected` | `<expected>` | C++23 | Core | P18, P24 | Implement, Compare | `__cpp_lib_expected >= 202202L`; use a supported profile |
| `variant`, `visit` | `<variant>` | C++17 | Core | P24, B1 | Implement | `__cpp_lib_variant` |
| `any` | `<any>` | C++17 | Working | B1 | Compare, Implement | `__cpp_lib_any`; compare with variant and type erasure |
| `bitset` | `<bitset>` | C++98 | Working | B4 | Implement | C++23 constexpr additions are feature-gated |
| `reference_wrapper`, `ref`, `cref` | `<functional>` | C++11 | Working | B1 | Implement, Diagnose | Always required |
| `exchange`, `swap`, `as_const`, `to_underlying` | `<utility>` | C++11-23 | Working | B1, B9 | Implement, Retrieve | Gate `to_underlying` with `__cpp_lib_to_underlying` |
| `source_location` | `<source_location>` | C++20 | Working | B7 | Implement | `__cpp_lib_source_location` |
| `stacktrace` | `<stacktrace>` | C++23 | Survey | S4, B9 | Compare, Retrieve | `__cpp_lib_stacktrace >= 202011L`; use source-location fallback |
| Type traits and transformations | `<type_traits>` | C++11-23 | Core | P38, B1 | Implement, Diagnose | Required in every profile |
| Standard concepts | `<concepts>` | C++20 | Core | P40, B1 | Implement, Diagnose | `__cpp_concepts >= 202002L` |
| `integer_sequence`, compile-time ratios | `<utility>`, `<ratio>` | C++11 | Working | B1 | Implement | Always required |
| `unique_ptr`, `shared_ptr`, `weak_ptr` | `<memory>` | C++11 | Core | P23 | Implement, Compare | Required in every profile |
| Allocator model and `allocator_traits` | `<memory>` | C++11 | Working | B1, S5 | Compare, Retrieve | Use normal allocator as baseline |
| Raw-memory algorithms | `<memory>` | C++17-23 | Working | B3 | Implement, Diagnose | No manual owner in production artifact |
| `out_ptr`, `inout_ptr` | `<memory>` | C++23 | Survey | S5, B9 | Compare, Retrieve | `__cpp_lib_out_ptr`; document manual C-adapter fallback |
| PMR resources and containers | `<memory_resource>` | C++17 | Survey | S5, P52 | Compare | Optional implementation after profiling |

## Callables and Functional Utilities

| Facility | Header | Standard | Tier | Exercise | Assessment | Feature detection or fallback |
|---|---|---:|---|---|---|---|
| Function objects and lambdas | language, `<functional>` | C++11-23 | Core | P27 | Implement, Diagnose | Required |
| `invoke`, `invoke_r` | `<functional>` | C++17/23 | Core | B1 | Implement | Gate `invoke_r` with `__cpp_lib_invoke_r` |
| `function` | `<functional>` | C++11 | Core | P27 | Implement, Compare | Required |
| `move_only_function` | `<functional>` | C++23 | Working | B1, B9 | Implement, Compare | `__cpp_lib_move_only_function >= 202110L`; fallback to templated owner |
| `bind_front`, `bind_back`, `mem_fn`, `not_fn` | `<functional>` | C++11-23 | Working | B1 | Implement, Compare | Gate C++23 additions individually |
| Hashing and standard hash support | `<functional>` | C++11 | Working | B2 | Implement, Retrieve | Required |

## Strings and Text

| Facility | Header | Standard | Tier | Exercise | Assessment | Feature detection or fallback |
|---|---|---:|---|---|---|---|
| `string`, `string_view` | `<string>`, `<string_view>` | C++98/17 | Core | P3, P9, B5 | Implement, Diagnose | Required |
| `char_traits` and text storage boundaries | `<string>` | C++98 | Survey | S1 | Compare, Retrieve | No customization required |
| `from_chars`, `to_chars` | `<charconv>` | C++17 | Core | P4, B5 | Implement | Required for integers; document floating support |
| Search, prefix/suffix, contains, resize operations | `<string>` | C++20/23 | Working | B5, B9 | Implement | Feature-gate C++23 members |
| Encoding types and `char8_t` boundaries | `<string>`, `<string_view>` | C++20 | Survey | S1 | Compare | No claim of Unicode normalization |
| Regular expressions | `<regex>` | C++11 | Survey | S1 | Compare, Diagnose | Compare with manual/token parser; no performance claim |

## Containers and Adaptors

| Facility | Header | Standard | Tier | Exercise | Assessment | Feature detection or fallback |
|---|---|---:|---|---|---|---|
| `array`, `vector`, `deque` | `<array>`, `<vector>`, `<deque>` | C++98/11 | Core | P8, P25, B2 | Implement, Compare | Required |
| `list`, `forward_list` | `<list>`, `<forward_list>` | C++98/11 | Working | P26, B2 | Implement, Compare | Required |
| `map`, `multimap`, `set`, `multiset` | `<map>`, `<set>` | C++98 | Core/Working | P25, B2 | Implement, Compare | Multicontainers are Working |
| `unordered_map`, `unordered_multimap` | `<unordered_map>` | C++11 | Core/Working | P25, B2 | Implement, Compare | Multicontainers are Working |
| `unordered_set`, `unordered_multiset` | `<unordered_set>` | C++11 | Working | B2 | Implement, Compare | Required |
| `stack`, `queue`, `priority_queue` | `<stack>`, `<queue>` | C++98 | Core | P28, B2 | Implement, Compare | Required |
| Node handles, merge, heterogeneous lookup and erasure | associative headers | C++17-23 | Working | B2, B9 | Implement, Retrieve | Gate heterogeneous erasure |
| Range construction and insertion | container headers | C++23 | Working | B2, B9 | Implement | Gate with container-range feature macros |
| `flat_map`, `flat_multimap`, `flat_set`, `flat_multiset` | flat container headers | C++23 | Survey | S2, B9 | Compare, Retrieve | Feature-gate; fallback to sorted vector |

## Iterators, Algorithms, and Ranges

| Facility | Header | Standard | Tier | Exercise | Assessment | Feature detection or fallback |
|---|---|---:|---|---|---|---|
| Iterator concepts, traits, sentinel model | `<iterator>` | C++20 | Core | P26, P29 | Implement, Diagnose | Required |
| Insert, move, reverse, counted, common iterators | `<iterator>` | C++98-20 | Working | B3 | Implement | Required |
| Stream iterators | `<iterator>` | C++98 | Working | B3, B5 | Implement, Compare | Required |
| Non-modifying and modifying algorithms | `<algorithm>` | C++98-23 | Core | P28, B3 | Implement, Transfer | Required |
| Sorting, binary search, partition, selection | `<algorithm>` | C++98 | Core | P28, B3 | Implement, Diagnose | Required |
| Merge, set, heap, permutation families | `<algorithm>` | C++98 | Working | B3 | Implement, Compare | Required |
| Numeric algorithms and scans | `<numeric>` | C++98-17 | Core | B4 | Implement, Transfer | Required |
| Execution policies and parallel algorithms | `<execution>`, algorithms | C++17 | Survey | S3, B8 | Compare, Retrieve | Serial fallback required |
| Range algorithms and projections | `<algorithm>` | C++20 | Core | P30, B3 | Implement | `__cpp_lib_ranges` |
| Core views: filter, transform, take/drop, split/join | `<ranges>` | C++20 | Core | P29, P30, B3 | Implement, Diagnose | Required |
| `ranges::to` | `<ranges>` | C++23 | Working | B9 | Implement | `__cpp_lib_ranges_to_container >= 202202L`; manual materialization fallback |
| Zip, adjacent, chunk, slide, stride, repeat, cartesian views | `<ranges>` | C++23 | Working | B9 | Implement, Compare | Feature-gate each family; classic-loop fallback |
| C++23 fold and new range algorithms | `<algorithm>` | C++23 | Working | B9 | Implement | `__cpp_lib_ranges_fold`; `accumulate` fallback |

## Numerics, Math, Bits, and Random

| Facility | Header | Standard | Tier | Exercise | Assessment | Feature detection or fallback |
|---|---|---:|---|---|---|---|
| Numeric limits and representations | `<limits>` | C++98 | Core | P4, B4 | Implement, Diagnose | Required |
| Mathematical functions and classification | `<cmath>` | C++98-23 | Core | B4 | Implement | Constexpr use is feature-gated |
| Mathematical constants | `<numbers>` | C++20 | Working | B4 | Implement | `__cpp_lib_math_constants` |
| Complex numbers | `<complex>` | C++98 | Working | B4 | Implement | Required |
| `valarray` | `<valarray>` | C++98 | Survey | S2 | Compare, Retrieve | Prefer ranges/containers unless workload fits |
| Bit operations, endian, `bit_cast`, `byteswap` | `<bit>` | C++20/23 | Working | B4, B9 | Implement, Diagnose | Gate `byteswap` with `__cpp_lib_byteswap` |
| Random engines, seeding, and distributions | `<random>` | C++11 | Core | P7, B4 | Implement, Compare | Required |
| Sampling and shuffling algorithms | `<algorithm>` | C++11/17 | Working | B4 | Implement | Required |
| Floating-point environment | `<cfenv>` | C++11 | Survey | S2 | Compare, Retrieve | Document platform limits |

## I/O, Formatting, Filesystem, and Time

| Facility | Header | Standard | Tier | Exercise | Assessment | Feature detection or fallback |
|---|---|---:|---|---|---|---|
| Stream state, formatted/unformatted I/O | `<iostream>`, `<ios>` | C++98 | Core | B5 | Implement, Diagnose | Required |
| File and string streams | `<fstream>`, `<sstream>` | C++98 | Core | B5 | Implement | Required |
| Span streams | `<spanstream>` | C++23 | Working | B5, B9 | Implement | `__cpp_lib_spanstream >= 202106L`; stringstream fallback |
| Stream buffers and synchronized output | `<streambuf>`, `<syncstream>` | C++98/20 | Working | B5 | Implement, Compare | `__cpp_lib_syncbuf` |
| `format`, custom formatter, format errors | `<format>` | C++20/23 | Core | P32, B5 | Implement, Diagnose | `__cpp_lib_format`; stream fallback |
| `print`, `println` | `<print>` | C++23 | Core | P32, B9 | Implement | `__cpp_lib_print >= 202207L`; format plus stream fallback |
| Filesystem paths, traversal, metadata, operations | `<filesystem>` | C++17 | Core | P31, B6 | Implement, Transfer | Required |
| Path normalization, canonicalization, permissions, space | `<filesystem>` | C++17 | Working | B6 | Implement, Diagnose | Required |
| Durations, clocks, time points | `<chrono>` | C++11 | Core | P33, B6 | Implement | Required |
| Calendars, time zones, parsing and formatting | `<chrono>` | C++20 | Working | B6 | Implement, Retrieve | Check chrono feature macro and timezone database |

## Concurrency

| Facility | Header | Standard | Tier | Exercise | Assessment | Feature detection or fallback |
|---|---|---:|---|---|---|---|
| `thread`, `jthread`, stop tokens | `<thread>`, `<stop_token>` | C++11/20 | Core | P44, P47 | Implement, Diagnose | `__cpp_lib_jthread` |
| Mutex and lock families | `<mutex>`, `<shared_mutex>` | C++11/14/17 | Core/Working | P45, B8 | Implement, Compare | Shared/timed variants are Working |
| Condition variables | `<condition_variable>` | C++11 | Core | P46 | Implement, Diagnose | Required |
| Futures, promises, packaged tasks, async | `<future>` | C++11 | Core/Working | P48, B8 | Implement, Compare | Packaged task is Working |
| Latches, barriers, semaphores | synchronization headers | C++20 | Working | B8 | Implement | Feature-test each primitive |
| Atomic scalars and memory ordering | `<atomic>` | C++11 | Core | P50 | Implement, Diagnose | Required |
| `atomic_ref`, wait, notify | `<atomic>` | C++20 | Working | B8 | Implement, Compare | `__cpp_lib_atomic_ref`, `__cpp_lib_atomic_wait` |

## Diagnostics, Localization, and Compatibility Surveys

| Facility area | Header | Standard | Tier | Exercise | Assessment | Required scope |
|---|---|---:|---|---|---|---|
| Exception pointers and nested exceptions | `<exception>` | C++11 | Working | B7 | Implement, Diagnose | Transport and preserve diagnostic context |
| RTTI and `type_index` | `<typeinfo>`, `<typeindex>` | C++98/11 | Survey | S4 | Compare | Prefer explicit protocols where practical |
| Assertions, error categories, termination | support headers | C++98-23 | Survey | S4 | Compare, Retrieve | Distinguish contract, recoverable error, and fatal termination |
| Locales and facets | `<locale>` | C++98 | Survey | S1 | Compare, Retrieve | Numeric, collation, and formatting effects |
| C compatibility headers | `<c*>` headers | C++98-23 | Survey | S3 | Compare, Retrieve | Identify ownership, error, locale, and thread-safety boundaries |

## Final Route Gate

Route B completion requires:

- evidence for every Core and Working row;
- completion of Surveys S1-S5;
- a toolchain feature record using `toolchain-support.md`;
- B10, an unseen facility-selection and documentation-navigation assessment;
- no unsupported facility silently counted as complete.
