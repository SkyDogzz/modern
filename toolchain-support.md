# Toolchain and Feature Support Policy

Last reviewed: 2026-06-13

This policy distinguishes the C++23 standard from implementation availability.
Selecting C++23 mode is necessary but does not prove that every library facility is
present.

## Supported Baseline Profiles

At least one primary profile and one secondary profile must configure, build, and run
the required tests.

| Profile | Minimum baseline | Standard mode | Purpose |
|---|---|---|---|
| GCC | GCC 14 with libstdc++ 14 | `-std=c++23` | Primary Linux profile |
| Clang | Clang 18 with libc++ 18 | `-std=c++23` | Secondary independent library profile |
| MSVC | Visual Studio 2022 17.10 toolset | `/std:c++latest` or documented C++23 mode | Windows and multi-config profile |

These are curriculum baselines, not claims of complete C++23 conformance. Newer
versions are allowed. Older versions may be used for early projects but cannot sign
off a feature that they do not implement.

The pinned baseline example in
[`.github/workflows/ci.yml`](.github/workflows/ci.yml) selects the Ubuntu 24.04
runner family, explicit compiler/package majors, Ninja, and a commit-pinned checkout
action. [`support/toolchain-profile.cpp`](support/toolchain-profile.cpp) makes the
job fail unless the GCC 14 job resolves libstdc++ 14 and the Clang 18 job resolves
libc++ 18. The workflow records the GitHub runner image and package versions because
security and patch updates within those major profiles remain intentionally movable;
an artifact requiring bit-for-bit reproduction must additionally pin a container
digest.

## Compatibility Source Snapshot

Source IDs and the fixed C++23 draft are defined in
[references.md](references.md#canonical-sources).

| Component | Supported curriculum baseline | Official implementation source | Reviewed | Baseline boundary |
|---|---|---|---|---|
| GCC language | GCC 14 | GCC-L | 2026-06-13 | C++23 mode and individual language features are separate claims; modules remain implementation-sensitive |
| libstdc++ | libstdc++ 14 | GCC-S | 2026-06-13 | Status entries identify first releases, but the installed feature macro and compile probe remain authoritative |
| Clang language | Clang 18 | LLVM-L | 2026-06-13 | Clang language support does not imply libc++ library support |
| libc++ | libc++ 18 | LLVM-S | 2026-06-13 | C++23 entries have independent completion versions; unavailable entries remain visible |
| MSVC language/library | VS 2022 17.10 | MSVC-S, MSSTL | 2026-06-13 | The official table places several C++23 language features in later 17.12-17.14 or newer build tools, so 17.10 must use another profile or the documented fallback |

Official status pages can describe releases newer than the minimum baseline. They
are evidence for when an implementation reports support, not proof that the
learner's installed profile contains it.

The baseline is intentionally capability-driven:

- C++20 concepts and ranges;
- `source_location`, `jthread`, stop tokens, and C++20 synchronization primitives;
- `format`;
- C++23 `expected` and `print`;
- the feature-test header `<version>`.

Implementation-sensitive facilities such as newer C++23 views, flat containers,
`mdspan`, `stacktrace`, and modules are tested independently and use documented
fallbacks.

## Required Feature Record

Every breadth or delta project that uses a post-C++17 facility records:

```txt
compiler:
compiler version:
standard library:
standard library version:
operating system:
language mode:
feature macro:
observed macro value:
native path:
fallback path:
standard clause or WG21 paper:
implementation source:
source review date:
```

A missing macro is an unsupported result, not permission to mark the facility
complete. The learner must use another supported profile, exercise the documented
fallback, or mark the item Survey according to the inventory.

## Required C++23 Checks

| Facility | Required macro/value when native path is assessed | Fallback |
|---|---|---|
| `expected` | `__cpp_lib_expected >= 202202L` | Use another supported profile |
| `print` | `__cpp_lib_print >= 202207L` | `format` plus an output stream |
| `spanstream` | `__cpp_lib_spanstream >= 202106L` | String stream or explicit span buffer adapter |
| `move_only_function` | `__cpp_lib_move_only_function >= 202110L` | Templated callable owner |
| `stacktrace` | `__cpp_lib_stacktrace >= 202011L` | `source_location` plus platform-neutral context |
| `byteswap` | `__cpp_lib_byteswap >= 202110L` | Tested shift/mask implementation |
| `ranges::to` | `__cpp_lib_ranges_to_container >= 202202L` | Explicit materialization loop |
| C++23 fold algorithms | `__cpp_lib_ranges_fold` | `accumulate` or explicit fold |
| `mdspan` | `__cpp_lib_mdspan >= 202207L` | `span` plus explicit extents/indexing |
| Flat associative containers | matching flat-container macro | Sorted vector representation |

For grouped range adaptors, include `<version>` and record the exact macro exposed by
the selected implementation. Do not infer support only from compiler version.

## Compatibility Workaround Register

Every fallback preserves a behavior contract; it does not impersonate the native
facility or satisfy a native feature check. `STD23` and the implementation source
IDs below refer to [references.md](references.md#canonical-sources).

| Native facility/area | Required fallback or alternate path | Standard/history source | Implementation sources | Reviewed | Retire or revise when |
|---|---|---|---|---|---|
| `expected` | use another supported profile; a substitute type does not count as native `expected` evidence | STD23 `[expected]`, [P0323R12](https://wg21.link/p0323r12) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | every required profile exposes the required macro and passes the contract |
| `to_underlying`, `invoke_r`, `bind_back` | explicit underlying-type cast; `invoke` plus the required result conversion; a capture-based lambda | STD23 `[utility]`, `[func.invoke]`, [P1682R3](https://wg21.link/p1682r3), [P2136R3](https://wg21.link/p2136r3), [P2387R3](https://wg21.link/p2387r3) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | each facility's macro and behavior/constraint probes pass everywhere |
| C++23 string query members | `find`, prefix/suffix comparison, or an equivalent bounded operation | STD23 `[string]`, [P1679R3](https://wg21.link/p1679r3) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | selected member probes pass on every required profile |
| heterogeneous erasure and container range insertion | heterogeneous lookup followed by erase; iterator-pair insertion | STD23 `[associative.reqmts]`, `[container.ranges]`, [P2077R3](https://wg21.link/p2077r3), [P1206R7](https://wg21.link/p1206r7) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | feature macros and equivalent mutation tests pass everywhere |
| C++23 constexpr library additions | execute the same operation at runtime and record that constant evaluation is unavailable | STD23 facility-specific clauses, SD6 | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | required constexpr expressions compile on every profile |
| `format` | stream insertion with the same domain output contract | STD23 `[format]`, [P0645R10](https://wg21.link/p0645r10) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | all required profiles pass format and custom-formatter probes |
| `print` | `format` plus an output stream | STD23 `[print]`, [P2093R14](https://wg21.link/p2093r14) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | `__cpp_lib_print` and output tests pass on every required profile |
| span streams | string streams or an explicit caller-buffer adapter | STD23 `[spanstream]`, [P0448R4](https://wg21.link/p0448r4) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | `__cpp_lib_spanstream` and buffer-boundary tests pass everywhere |
| `move_only_function` | a narrow templated callable owner | STD23 `[func.wrap.move]`, [P0288R9](https://wg21.link/p0288r9) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | the native macro and move-only contract pass everywhere |
| `stacktrace` | `source_location` plus platform-neutral diagnostic context | STD23 `[stacktrace]`, [P0881R7](https://wg21.link/p0881r7) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | capture, linking, and formatting probes pass on every required profile |
| `byteswap` | tested unsigned shift/mask implementation | STD23 `[bit.byteswap]`, [P1272R4](https://wg21.link/p1272r4) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | `__cpp_lib_byteswap` and endian fixtures pass everywhere |
| `ranges::to` | explicit materialization loop | STD23 `[range.utility.conv.to]`, [P1206R7](https://wg21.link/p1206r7) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | macro and representative container conversions pass everywhere |
| C++23 range folds | `accumulate` or an explicit left/right fold matching the contract | STD23 `[alg.fold]`, [P2322R6](https://wg21.link/p2322r6) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | fold macros and order-sensitive tests pass everywhere |
| C++23 range adaptors | classic loop/pipeline with the same ownership and ordering contract | STD23 `[range.adaptors]` | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | each selected adaptor has a passing feature probe on every required profile |
| `mdspan` | `span` plus explicit extents and indexing | STD23 `[mdspan]`, [P0009R18](https://wg21.link/p0009r18) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | `__cpp_lib_mdspan`, layout, and bounds fixtures pass everywhere |
| flat associative containers | sorted vector representation with the same lookup/update contract | STD23 `[flat.map]`, `[flat.set]`, [P0429R9](https://wg21.link/p0429r9), [P1222R4](https://wg21.link/p1222r4) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | native macros and workload tests pass everywhere |
| `out_ptr`/`inout_ptr` | explicit C-adapter cleanup and ownership transfer | STD23 `[out.ptr]`, [P1132R8](https://wg21.link/p1132r8) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | native adapter probes pass on every required profile |
| execution policies | serial algorithm as the reference path | STD23 `[algorithms.parallel]` | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | parallel backend availability and behavior are verified on every selected CI profile |
| chrono time zones | UTC-only behavior with an explicit unavailable-local-zone result | STD23 `[time.zone]`, [P0355R7](https://wg21.link/p0355r7) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | timezone API and runtime database probes pass on every required deployment |
| `if consteval` | `is_constant_evaluated` plus a C++20-compatible branch where equivalent | STD23 `[stmt.if]`, [P1938R3](https://wg21.link/p1938r3) | GCC-L, LLVM-L, MSVC-S | 2026-06-13 | the language macro and compile-time/runtime contract pass everywhere |
| explicit object parameters | ordinary cv/ref-qualified members or a free function | STD23 `[dcl.fct]`, [P0847R7](https://wg21.link/p0847r7) | GCC-L, LLVM-L, MSVC-S | 2026-06-13 | the language macro and call-contract probes pass everywhere |
| multidimensional/static call operators | `operator()` or an ordinary stateless call operator | STD23 `[over.sub]`, `[over.call]`, [P2128R6](https://wg21.link/p2128r6), [P1169R4](https://wg21.link/p1169r4) | GCC-L, LLVM-L, MSVC-S | 2026-06-13 | both language macros and syntax probes pass everywhere |
| `auto(x)` decay-copy | explicit `std::decay_t` construction with the same value-category contract | STD23 `[expr.type.conv]`, [P0849R8](https://wg21.link/p0849r8) | GCC-L, LLVM-L, MSVC-S | 2026-06-13 | the C++23 syntax and value-category tests pass everywhere |
| simpler implicit move | explicit return-type design and a C++20 compile probe; add `move` only when required and tested for elision impact | STD23 `[class.copy.elision]`, [P2266R3](https://wg21.link/p2266r3) | GCC-L, LLVM-L, MSVC-S | 2026-06-13 | the C++23 return case compiles and preserves the C++20 behavior contract everywhere |
| range-for lifetime extension | bind the owning range/object to a named local before iteration | STD23 `[stmt.ranged]`, [P2718R0](https://wg21.link/p2718r0) | GCC-L, LLVM-L, MSVC-S | 2026-06-13 | the range-for macro/probe and lifetime tests pass everywhere |
| named universal character escapes | numeric universal character name with the same code point | STD23 `[lex.universal.char]`, [P2071R2](https://wg21.link/p2071r2) | GCC-L, LLVM-L, MSVC-S | 2026-06-13 | the language macro and encoding probe pass everywhere |
| modules | installed header/package target | STD23 `[module]`, [P1103R3](https://wg21.link/p1103r3) | GCC-L, LLVM-L, MSVC-S | 2026-06-13 | compiler, generator, dependency scanning, install, and consumer workflows pass |
| `generator` | iterator/range implementation or the documented small coroutine type | STD23 `[coro.generator]`, [P2502R2](https://wg21.link/p2502r2) | GCC-S, LLVM-S, MSVC-S/MSSTL | 2026-06-13 | native generator macro and frame-lifetime contract pass everywhere |

When a workaround is exercised, the learner's feature record links the relevant row,
installed versions, observed macro/probe, and native/fallback behavior test. Updating
a claim requires a new review date; a toolchain version guess alone never closes the
record.

## CMake Portability Policy

Every CMake target requests C++23 and disables compiler extensions:

```cmake
target_compile_features(target PRIVATE cxx_std_23)
set_target_properties(target PROPERTIES CXX_EXTENSIONS OFF)
```

CI must include:

- one single-config generator;
- one multi-config generator or a documented Windows verification job;
- a build with warnings;
- a separate sanitizer configuration where supported.

## Official Status Sources

Review implementation status before changing the baseline:

- [Reference and source index](references.md)
- [GCC C++ language status](https://gcc.gnu.org/projects/cxx-status.html)
- [libstdc++ implementation status](https://gcc.gnu.org/onlinedocs/libstdc++/manual/status.html)
- [Clang C++ language status](https://clang.llvm.org/cxx_status.html)
- [libc++ C++23 status](https://libcxx.llvm.org/Status/Cxx23.html)
- [Microsoft C++ conformance](https://learn.microsoft.com/cpp/overview/visual-cpp-language-conformance)
- [CMake `CXX_EXTENSIONS`](https://cmake.org/cmake/help/latest/prop_tgt/CXX_EXTENSIONS.html)

Compatibility statements must include a review date and distinguish standard
requirements from implementation limitations.
