# Reference and Source Index

Last reviewed: 2026-06-13

Use sources in this order:

1. the fixed C++23 draft for normative wording at the curriculum target;
2. the live working draft for searchable clause links and later defect resolutions;
3. WG21 papers for feature history and feature-test macro policy;
4. maintained reference pages for signatures, examples, and navigation;
5. official compiler, standard-library, build-tool, and analysis documentation for
   implementation behavior.

An implementation status page cannot change a standard requirement. A standard
clause cannot prove that an installed toolchain implements that requirement.

## Canonical Sources

| ID | Source | Use |
|---|---|---|
| STD23 | [N4950 C++23 working draft snapshot](https://wg21.link/n4950) | Fixed target wording; search bracketed clause labels |
| LIVE | [Live C++ working draft](https://eel.is/c++draft/) | Searchable current clauses; not an ISO publication |
| DRAFTSRC | [WG21 draft sources](https://github.com/cplusplus/draft) | Provenance for the generated working draft |
| SD6 | [WG21 SD-6 feature-test recommendations](https://wg21.link/sd6) | Language/library feature-test macro policy |
| CPPREF | [cppreference C++ index](https://en.cppreference.com/w/cpp) | Maintained signature, requirement, example, and header navigation |
| GCC-L | [GCC language status](https://gcc.gnu.org/projects/cxx-status.html) | GCC language implementation status |
| GCC-S | [libstdc++ status](https://gcc.gnu.org/onlinedocs/libstdc++/manual/status.html) | libstdc++ library implementation status |
| LLVM-L | [Clang language status](https://clang.llvm.org/cxx_status.html) | Clang language implementation status |
| LLVM-S | [libc++ C++23 status](https://libcxx.llvm.org/Status/Cxx23.html) | libc++ library implementation status |
| MSVC-S | [Microsoft C/C++ conformance](https://learn.microsoft.com/en-us/cpp/overview/visual-cpp-language-conformance?view=msvc-170) | MSVC language and library implementation status |
| MSSTL | [Microsoft STL changelog](https://github.com/microsoft/STL/wiki/Changelog) | Version-specific Microsoft STL implementation record |
| CMAKE | [CMake build-system manual](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html) | Targets, usage requirements, and build configurations |
| CTEST | [CTest manual](https://cmake.org/cmake/help/latest/manual/ctest.1.html) | Portable test execution |
| CMPKG | [CMake packages manual](https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html) | Installed packages and consumers |
| ASAN | [Clang AddressSanitizer documentation](https://clang.llvm.org/docs/AddressSanitizer.html) | Tool behavior and limitations |

The live draft observed during this review was generated on 2026-05-17 from the WG21
draft sources. Treat that date as provenance, not as the curriculum's standard
version. N4950 remains the fixed C++23 target.

## Concept-Brief References

Each row supplies C++23 clause labels plus a maintained or official navigation
source. Search the bracketed labels in STD23 when exact C++23 wording matters.

| Brief | C++23 clauses | Maintained or official lookup |
|---|---|---|
| 1. Translation and execution | `[lex.phases]`, `[basic.def.odr]`, `[basic.start.main]` | [translation phases](https://en.cppreference.com/w/cpp/language/translation_phases), [CMake build systems](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html) |
| 2. Initialization, types, integers | `[basic.fundamental]`, `[dcl.init]`, `[conv]` | [initialization](https://en.cppreference.com/w/cpp/language/initialization), [implicit conversions](https://en.cppreference.com/w/cpp/language/implicit_conversion) |
| 3. Control flow, functions, scope | `[stmt]`, `[dcl.fct]`, `[basic.scope]` | [statements](https://en.cppreference.com/w/cpp/language/statements), [functions](https://en.cppreference.com/w/cpp/language/functions) |
| 4. Records, enums, containers | `[class]`, `[dcl.enum]`, `[container.requirements]` | [classes](https://en.cppreference.com/w/cpp/language/classes), [containers](https://en.cppreference.com/w/cpp/container) |
| 5. References, pointers, views | `[dcl.ref]`, `[basic.compound]`, `[span]`, `[string.view]` | [references](https://en.cppreference.com/w/cpp/language/reference), [span](https://en.cppreference.com/w/cpp/container/span) |
| 6. Tests, debugging, CMake, Git | `[intro.compliance]`, `[basic.def.odr]` | [CMake](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html), [CTest](https://cmake.org/cmake/help/latest/manual/ctest.1.html), [ASan](https://clang.llvm.org/docs/AddressSanitizer.html), [Git reference](https://git-scm.com/docs) |
| 7. Classes and special members | `[class]`, `[class.special]`, `[class.copy.ctor]`, `[class.copy.assign]` | [special member functions](https://en.cppreference.com/w/cpp/language/member_functions#Special_member_functions) |
| 8. Storage duration and lifetime | `[basic.life]`, `[basic.stc]`, `[class.temporary]` | [object lifetime](https://en.cppreference.com/w/cpp/language/lifetime), [storage duration](https://en.cppreference.com/w/cpp/language/storage_duration) |
| 9. Errors and exceptions | `[except]`, `[res.on.exception.handling]`, `[expected]`, `[optional]` | [exceptions](https://en.cppreference.com/w/cpp/language/exceptions), [expected](https://en.cppreference.com/w/cpp/utility/expected) |
| 10. RAII, copy, move, ownership | `[class.copy]`, `[unique.ptr]`, `[util.smartptr.shared]` | [RAII](https://en.cppreference.com/w/cpp/language/raii), [memory management](https://en.cppreference.com/w/cpp/memory) |
| 11. Containers, iterators, algorithms | `[containers]`, `[iterator.requirements]`, `[algorithms]` | [containers](https://en.cppreference.com/w/cpp/container), [algorithms](https://en.cppreference.com/w/cpp/algorithm) |
| 12. Lambdas and callables | `[expr.prim.lambda]`, `[func.wrap]`, `[func.invoke]` | [lambda expressions](https://en.cppreference.com/w/cpp/language/lambda), [functional library](https://en.cppreference.com/w/cpp/utility/functional) |
| 13. Ranges and views | `[ranges]`, `[range.view]` | [ranges library](https://en.cppreference.com/w/cpp/ranges) |
| 14. Filesystem, formatting, chrono | `[fs]`, `[format]`, `[time]` | [filesystem](https://en.cppreference.com/w/cpp/filesystem), [format](https://en.cppreference.com/w/cpp/utility/format), [chrono](https://en.cppreference.com/w/cpp/chrono) |
| 15. Regular types and polymorphism | `[concepts]`, `[class.virtual]`, `[over]` | [object concepts](https://en.cppreference.com/w/cpp/concepts), [virtual functions](https://en.cppreference.com/w/cpp/language/virtual) |
| 16. Templates and forwarding | `[temp]`, `[temp.deduct]`, `[temp.constr]` | [templates](https://en.cppreference.com/w/cpp/language/templates), [constraints](https://en.cppreference.com/w/cpp/language/constraints) |
| 17. Constant evaluation | `[expr.const]`, `[dcl.constexpr]` | [constant expressions](https://en.cppreference.com/w/cpp/language/constant_expression), [constexpr](https://en.cppreference.com/w/cpp/language/constexpr) |
| 18. Threads, races, locks | `[intro.races]`, `[thread.threads]`, `[thread.mutex]` | [multi-threaded executions](https://en.cppreference.com/w/cpp/language/multithread), [thread support](https://en.cppreference.com/w/cpp/thread) |
| 19. Conditions, cancellation, tasks | `[thread.condition]`, `[stoptoken]`, `[futures]` | [condition variables](https://en.cppreference.com/w/cpp/thread/condition_variable), [jthread](https://en.cppreference.com/w/cpp/thread/jthread), [future](https://en.cppreference.com/w/cpp/thread/future) |
| 20. Atomics and memory ordering | `[intro.multithread]`, `[atomics]` | [memory order](https://en.cppreference.com/w/cpp/atomic/memory_order), [atomic library](https://en.cppreference.com/w/cpp/atomic) |
| 21. Measurement, profiling, PMR | `[time.clock.steady]`, `[mem.res]` | [steady clock](https://en.cppreference.com/w/cpp/chrono/steady_clock), [memory resources](https://en.cppreference.com/w/cpp/memory/memory_resource) |
| 22. Verification, packaging, maintenance | `[support.runtime]`, `[version.syn]` | [CMake packages](https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html), [CTest](https://cmake.org/cmake/help/latest/manual/ctest.1.html), [CMake presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html) |

## Standard-Library-Brief References

| Brief | C++23 clauses | Maintained lookup |
|---|---|---|
| 1. Vocabulary and callables | `[utilities]`, `[function.objects]`, `[meta]`, `[mem.res]` | [utilities](https://en.cppreference.com/w/cpp/utility), [functional](https://en.cppreference.com/w/cpp/utility/functional) |
| 2. Containers and adaptors | `[containers]`, `[container.adaptors]` | [containers](https://en.cppreference.com/w/cpp/container) |
| 3. Iterators, algorithms, ranges | `[iterators]`, `[algorithms]`, `[ranges]`, `[numeric.ops]` | [iterators](https://en.cppreference.com/w/cpp/iterator), [algorithms](https://en.cppreference.com/w/cpp/algorithm), [ranges](https://en.cppreference.com/w/cpp/ranges) |
| 4. Numerics, bits, random | `[numerics]`, `[bit]`, `[rand]` | [numerics](https://en.cppreference.com/w/cpp/numeric), [bit utilities](https://en.cppreference.com/w/cpp/numeric#Bit_manipulation), [random](https://en.cppreference.com/w/cpp/numeric/random) |
| 5. Text, streams, formatting | `[strings]`, `[iostreams]`, `[format]`, `[charconv]`, `[re]`, `[locale]` | [strings](https://en.cppreference.com/w/cpp/string), [I/O](https://en.cppreference.com/w/cpp/io), [regex](https://en.cppreference.com/w/cpp/regex), [locale](https://en.cppreference.com/w/cpp/locale) |
| 6. Filesystem and chrono | `[fs]`, `[time]` | [filesystem](https://en.cppreference.com/w/cpp/filesystem), [chrono](https://en.cppreference.com/w/cpp/chrono) |
| 7. Diagnostics and runtime | `[support]`, `[diagnostics]`, `[c.files]` | [language support](https://en.cppreference.com/w/cpp/utility), [error handling](https://en.cppreference.com/w/cpp/error) |
| 8. Concurrency | `[thread]`, `[atomics]`, `[algorithms.parallel]` | [concurrency support](https://en.cppreference.com/w/cpp/thread), [execution policies](https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag) |
| 9. C++23 additions | N4950 library clauses plus SD6 | [feature-test macros](https://en.cppreference.com/w/cpp/feature_test), [toolchain policy](toolchain-support.md) |
| 10. Facility selection | `[structure.specifications]`, `[res.on.functions]`, facility-specific clauses | [standard-library index](https://en.cppreference.com/w/cpp/standard_library), [headers index](https://en.cppreference.com/w/cpp/header) |

## Citation Record

For a design or compatibility claim, record:

```txt
claim:
standard/version:
standard clause or WG21 paper:
maintained reference page:
implementation source:
implementation/profile tested:
observed behavior or feature macro:
review date:
```

Exact signatures and guarantees come from the target standard and maintained
reference. Availability comes from the installed feature probe plus the official
implementation source. Record both when a fallback or workaround is used.
