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

- [GCC C++ language status](https://gcc.gnu.org/projects/cxx-status.html)
- [libstdc++ implementation status](https://gcc.gnu.org/onlinedocs/libstdc++/manual/status.html)
- [Clang C++ language status](https://clang.llvm.org/cxx_status.html)
- [libc++ C++23 status](https://libcxx.llvm.org/Status/Cxx23.html)
- [Microsoft C++ conformance](https://learn.microsoft.com/cpp/overview/visual-cpp-language-conformance)
- [CMake `CXX_EXTENSIONS`](https://cmake.org/cmake/help/latest/prop_tgt/CXX_EXTENSIONS.html)

Compatibility statements must include a review date and distinguish standard
requirements from implementation limitations.

