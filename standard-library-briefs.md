# Standard-Library Breadth Briefs

These briefs prepare the B1-B10 labs in `standard-library-breadth.md`. They emphasize
facility selection, invariants, complexity, lifetime, and reference retrieval rather
than memorizing declarations.

## 1. Vocabulary Types, Utilities, and Callables

Vocabulary types communicate interface states:

- `pair` and `tuple` hold a fixed heterogeneous product;
- `optional` represents a value that may be absent;
- `expected` represents a value or typed recoverable error;
- `variant` represents one value from a closed set;
- `any` stores a runtime-selected copyable value when the set is open and operations
  are intentionally limited.

Prefer a named struct when fields have domain meaning. Use tuple-like values for
generic composition, short internal returns, or protocols that already operate on
tuple-like objects.

`reference_wrapper` allows references inside copyable value containers and callable
adapters. It remains non-owning. `invoke` applies the standard invocation rules to
functions, member pointers, and callable objects. `function` erases a copyable
callable type; `move_only_function` supports move-only callable ownership where
available.

Type traits answer compile-time questions; concepts constrain interfaces. Neither
proves runtime invariants. Allocators separate storage acquisition from container
logic, while PMR selects a runtime memory resource. Most application code should use
normal containers until measurement justifies allocator complexity.

**Review**

1. When is a named struct clearer than a tuple?
2. How do `optional`, `expected`, `variant`, and `any` communicate different states?
3. Why does `reference_wrapper` not solve lifetime?
4. When does `move_only_function` fit better than `function`?
5. What problem does an allocator solve, and what problem does it not solve?

## 2. Container Families and Adaptors

Select containers from operations, ordering, iterator/reference stability, memory
layout, and measured workload.

- contiguous sequences: `array`, `vector`;
- segmented sequence: `deque`;
- node sequences: `list`, `forward_list`;
- ordered associative containers: maps and sets, including multi-key forms;
- unordered associative containers: hash maps and sets, including multi-key forms;
- flat associative containers: sorted sequence storage with associative interfaces;
- adaptors: `stack`, `queue`, and `priority_queue`.

Multicontainers model duplicate keys deliberately. Node handles transfer nodes
between compatible associative containers. Transparent comparators and hash/equality
objects can enable heterogeneous lookup without temporary key construction.

Container complexity guarantees are upper bounds on abstract operations, not
predictions of real performance. Node allocation, cache locality, element size, and
mutation patterns matter.

**Review**

1. Why can `deque` fit a workload that does not fit `vector` or `list`?
2. When is a multimap clearer than a map of vectors?
3. What does heterogeneous lookup avoid?
4. Why is a standard adaptor preferable when its restricted interface fits?
5. What tradeoff do flat associative containers make?

## 3. Iterators, Algorithms, and Ranges

Iterator categories and concepts express movement and access. Iterator adaptors
change how algorithms read or write:

- insertion iterators redirect assignment into a container operation;
- move iterators expose rvalue references;
- reverse iterators invert traversal;
- counted iterators pair a position with remaining length;
- stream iterators bridge formatted I/O and algorithms.

Algorithm families include:

- predicates, search, comparison, counting, and transformation;
- partitioning and selection;
- sorting and binary search;
- merging and set operations;
- heap operations;
- permutations;
- numeric folds, reductions, scans, and adjacent operations;
- raw-memory construction and destruction.

Ranges algorithms can return structured result types and accept projections. Views
compose lazy traversal. Materialize when ownership, stable lifetime, mutation, or
multiple traversal requires it.

Parallel execution policies can change ordering, exception behavior, and callable
requirements. A parallel algorithm is not automatically faster and may be
unavailable or backed by an implementation dependency.

**Review**

1. What operation does an insertion iterator perform on assignment?
2. Which algorithm families require sorted input?
3. Why can a projection be safer than a custom comparator?
4. When must a lazy pipeline be materialized?
5. What new obligations can an execution policy introduce?

## 4. Numerics, Mathematics, Bits, and Randomness

`numeric_limits` describes representational properties. `<cmath>` supplies
mathematical operations and classification such as finite, infinite, and NaN checks.
`<numbers>` supplies standard mathematical constants.

Numeric algorithms express accumulation, inner products, adjacent differences,
partial sums, reductions, and scans. Their result type and operation associativity
matter. Parallel reduction may regroup operations and therefore change
floating-point results.

`complex` models complex arithmetic. `valarray` is a specialized numeric container;
compare it with normal containers, ranges, and dedicated numerical libraries rather
than assuming it is the default.

`<bit>` provides representation-level operations such as bit counting, rotations,
endianness inspection, `bit_cast`, and C++23 `byteswap`. These facilities do not
remove alignment, object representation, or protocol requirements.

Random engines generate deterministic sequences from state. Distributions map engine
output to a domain. `random_device` is an implementation-provided entropy source and
is not itself a general-purpose engine. Tests should inject or record seeds.

**Review**

1. Why does the accumulator's initial type affect `accumulate`?
2. Why may parallel reduction differ from a sequential floating-point fold?
3. What preconditions make `bit_cast` valid?
4. What is the difference between an engine and a distribution?
5. Why is a recorded seed part of defect evidence?

## 5. Text, Streams, Formatting, and Buffers

I/O streams maintain formatting state and error state. A failed extraction leaves the
stream in a failure state until handled. Formatted and unformatted operations have
different whitespace and delimiter behavior.

File streams own file handles. String streams use owned string storage. C++23 span
streams read or write a caller-provided character buffer without making that buffer
immortal. Stream buffers implement the underlying character transport and should be
customized only for a concrete need.

`charconv` performs locale-independent numeric conversion. Streams can be
locale-sensitive. `format` builds formatted strings; `print` writes formatted
output. Custom formatters must define parsing and formatting behavior without
retaining invalid context references.

Regular expressions are useful for bounded pattern tasks but can obscure parsers and
have implementation-dependent performance. Locales affect classification,
collation, number punctuation, and some formatting. They are not a complete Unicode
text-processing solution.

**Review**

1. What must happen after a failed stream extraction?
2. How do file, string, and span streams differ in ownership?
3. Why is `charconv` useful at a locale boundary?
4. What two responsibilities does a custom formatter implement?
5. When should a parser be preferred over a regular expression?

## 6. Filesystem and Chrono Breadth

Filesystem operations work with `path` values and report errors through throwing or
`error_code` overloads. Lexical normalization does not access the filesystem;
canonicalization does. Symlinks, permissions, races, and changing files require
explicit policy.

Metadata operations include file status, size, timestamps, permissions, space, and
link information. Copying, renaming, and removing have platform-sensitive failure
behavior. Destructive operations require dry-run evidence and separated confirmation.

Chrono distinguishes durations, time points, and clocks. Calendars represent civil
dates. Time zones map civil time and UTC while accounting for transitions and
ambiguous or nonexistent local times. The timezone database is runtime data and may
not be available or current on every implementation.

Use `steady_clock` for elapsed intervals. Use `system_clock` or zoned time for
timestamps. Parse and format through documented locale/timezone assumptions.

**Review**

1. How does lexical normalization differ from canonicalization?
2. Why can a file change between metadata inspection and opening?
3. What makes local civil time ambiguous or nonexistent?
4. Which clock measures elapsed work?
5. What runtime dependency does timezone conversion require?

## 7. Diagnostics, Runtime Support, and Compatibility

`source_location` captures call-site file, line, column, and function information.
`stacktrace` captures implementation-dependent execution context where supported.
Neither replaces domain error information.

Exception pointers transport an exception between contexts. Nested exceptions can
preserve a higher-level operation while retaining a lower-level cause. RTTI supports
`typeid`, `type_info`, and `type_index`; prefer explicit protocols when type identity
is not the domain operation.

Assertions and termination facilities address programming errors or unrecoverable
states, not ordinary hostile input. Error categories and conditions let
`error_code` values participate in portable comparisons.

C compatibility headers expose useful platform interfaces and legacy APIs. Every
boundary must define ownership, null termination, locale, error signaling, and
thread-safety. Prefer the C++ library when it expresses the same operation safely.

**Review**

1. What diagnostic information does `source_location` omit?
2. When is an exception pointer useful?
3. Why is runtime type identity often weaker than a domain operation?
4. What distinguishes an assertion from recoverable input validation?
5. Which boundary questions must be asked for a C API?

## 8. Concurrency Library Breadth

Shared and timed mutexes fit workloads with specific read/write or timeout semantics;
they are not automatically faster. Latches coordinate one countdown event. Barriers
coordinate repeated phases. Semaphores count available permits.

Packaged tasks bind a callable to a future-producing shared state. Futures transport
one eventual result but do not form a general continuation framework.

`atomic_ref` applies atomic operations to a suitably aligned existing object while
its lifetime and non-atomic access rules remain valid. Atomic wait/notify can avoid
busy waiting on atomic state. Several atomic variables still do not create one
multi-object transaction.

Parallel algorithms require callable independence and valid iterator/range access.
Measure the selected implementation and workload; use a serial path as the reference
behavior.

**Review**

1. How do latch, barrier, and semaphore semantics differ?
2. What alignment and access rules constrain `atomic_ref`?
3. Why is atomic wait preferable to a polling loop?
4. What does a packaged task add to a promise?
5. Which operations make a parallel algorithm unsafe?

## 9. C++23 Library Additions

C++23 adds vocabulary, I/O, ranges, containers, utility, diagnostics, and
multidimensional-view facilities. Representative additions include:

- `expected`, `move_only_function`, `out_ptr`, and `inout_ptr`;
- `print`, span streams, and stack traces;
- `ranges::to`, fold algorithms, and new views;
- flat associative containers and container range insertion;
- `mdspan`;
- `byteswap`, `to_underlying`, and expanded constexpr support.

Implementation availability varies. Include `<version>`, test the relevant SD-6
macro, compile the native path, and keep a behaviorally equivalent fallback where the
curriculum requires portability. A compiler version check alone is insufficient.

**Review**

1. Why is a feature-test macro better than a compiler-version guess?
2. What ownership does `mdspan` provide?
3. Which C++23 range additions replace explicit materialization loops?
4. When does a flat container's storage model help?
5. What evidence is required before claiming a native C++23 path works?

## 10. Facility Selection and Reference Navigation

Standard-library fluency means selecting a suitable abstraction and verifying exact
requirements. For each task:

1. state operations, ownership, ordering, invalidation, and error needs;
2. shortlist facilities by semantics before performance;
3. read complexity, preconditions, iterator invalidation, and exception guarantees;
4. confirm standard version and implementation support;
5. implement the smallest behavior test;
6. record rejected alternatives.

A reference lookup is successful only when the learner can cite the exact fact used
in the design and construct a test or compile-fail case that would expose a mistaken
assumption.

**Review**

1. Which requirements should be written before choosing a container?
2. Which reference sections matter before calling an algorithm?
3. How do standard availability and implementation availability differ?
4. What makes a rejected alternative useful evidence?
5. How can a compile-fail test verify a type requirement?
