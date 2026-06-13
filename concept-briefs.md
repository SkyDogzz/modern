# C++23 Concept Briefs

These briefs provide the minimum conceptual preparation for the roadmap projects.
They are not a language reference. Follow links from each phase, run every small
example, answer the review questions without notes, and consult a current standard
library reference for exact signatures and guarantees.

## 1. Translation and Execution

A C++ source file is translated before it is executed:

1. preprocessing handles directives such as `#include`;
2. compilation checks syntax and semantics and produces an object file;
3. linking combines object files and libraries into a program;
4. execution begins at `main`.

A compiler diagnostic names a location, severity, and explanation. Read the first
relevant error before reacting to cascaded errors. Warnings are potential defects,
not decoration.

```cpp
#include <iostream>

int main() {
    std::cout << "Hello\n";
    return 0;
}
```

The exit status is part of a command-line program's interface: zero means success
by convention; non-zero values report failure.

**Review**

1. What is the difference between compilation and execution?
2. What does the linker combine?
3. Why should the first relevant diagnostic be fixed first?
4. What observable behavior does an exit status provide?

## 2. Initialization, Types, and Integer Behavior

Every object has a type. Prefer initialization at the declaration:

```cpp
int lives{3};
double temperature{21.5};
bool active{true};
const std::string name{"Ada"};
```

Brace initialization rejects many narrowing conversions. Integer division discards
the fractional part. Signed integer overflow is undefined behavior; unsigned
arithmetic wraps modulo a power of two but is not automatically correct. Mixed
signed/unsigned comparisons can produce surprising results. Check ranges before
converting and use a type that represents the domain.

Floating-point values are approximations. Compare computed results using a
domain-appropriate tolerance rather than exact equality.

`static_cast<T>(value)` makes an intended conversion visible, but it does not prove
the value fits. Validate first. Use `auto` when the initializer makes the type
obvious or the exact type is intentionally implementation-facing; do not use it to
hide important domain types.

Other named casts have narrower roles. `dynamic_cast` checks selected polymorphic
conversions, `const_cast` changes cv-qualification, and `reinterpret_cast` performs
low-level reinterpretation. Prefer designs that do not need the latter two.

**Review**

1. Which conversions can brace initialization reject?
2. What is the result of integer division?
3. Why is signed overflow more serious than an inaccurate result?
4. Why can a negative signed value compare unexpectedly with an unsigned value?
5. When is exact floating-point equality appropriate?
6. When does `auto` improve rather than obscure code?

## 3. Control Flow, Functions, and Scope

Use `if` for conditions, `switch` for a closed set of discrete alternatives, and
loops when repetition is required. Every loop needs a progress argument and a
reachable termination condition.

A function should have one clear responsibility. Prefer pure calculation functions
for business rules and thin adapters for input/output.

```cpp
[[nodiscard]] double celsius_to_fahrenheit(double value) {
    return value * 9.0 / 5.0 + 32.0;
}
```

Names have scope. Objects also have storage duration and lifetime; these are
related but not interchangeable. A local object's name usually has block scope,
its storage is automatic, and its lifetime runs from initialization to destruction.

Pass small cheap values by value. Use `const T&` to observe an existing object
without copying when lifetime is guaranteed. Use `T&` only when mutation is part
of the interface.

**Review**

1. What proves that a loop terminates?
2. Why separate calculation from terminal input?
3. What is the difference between scope and lifetime?
4. What does a non-const reference communicate?

## 4. Records, Enums, and Basic Containers

Use a `struct` for a passive record whose public values form a valid state. Use a
scoped enum for a closed domain:

```cpp
enum class CharacterClass { warrior, mage, rogue };

struct Character {
    std::string name;
    CharacterClass character_class;
    int health;
};
```

`std::array<T, N>` has fixed size known at compile time. `std::vector<T>` owns a
dynamic contiguous sequence. `std::string` owns text. Prefer these owners over raw
arrays.

Vector growth can reallocate, invalidating every pointer, reference, and iterator
to its elements. Erasure also invalidates positions according to container rules.
Never retain an observer across an operation that may invalidate it.

**Review**

1. When is a scoped enum better than an integer code?
2. What is the ownership difference between `array` and `vector`?
3. Why can `vector::push_back` invalidate an element pointer?
4. What makes a `struct` state valid?

## 5. References, Pointers, Views, and C Strings

A reference aliases an existing object and cannot represent absence. A pointer can
represent an object address or no object with `nullptr`. Neither owns an object
unless an interface explicitly says otherwise.

`std::span<T>` observes a contiguous sequence. `std::string_view` observes
character data. Both are cheap and non-owning, so the referenced storage must
outlive every use of the view.

```cpp
void print_values(std::span<const int> values);
std::size_t count_words(std::string_view text);
```

Command-line `argv` values are null-terminated C strings owned by the process
startup environment. Convert them promptly to safer views or owning strings.
`std::from_chars` parses numbers without locale or allocation and reports both a
result pointer and an error code.

**Review**

1. Which observer can represent absence: a reference or a pointer?
2. Who owns the characters in a `string_view`?
3. What invalidates a span over vector elements?
4. Why is reading past a C string's null terminator invalid?
5. What two conditions must be checked after `from_chars`?

## 6. Tests, Debugging, CMake, and Git

A smoke test proves that a program starts and reports expected success. A unit
test exercises isolated logic. An integration test crosses component boundaries.
Tests should cover normal, boundary, invalid-input, and failure behavior.

`assert` is useful for internal assumptions during development, but it can be
disabled and is not a user-input error mechanism. A test framework should report
independent failures without aborting the whole suite.

Use a debugger to inspect control flow and state. Use sanitizers to detect classes
of runtime defects. They answer different questions.

CMake targets model build products and usage requirements. Prefer target-scoped
compile features, include directories, options, and linked dependencies. Request
standard C++ mode explicitly by disabling vendor extensions when portability is an
objective. Single-config generators choose a configuration while configuring;
multi-config generators choose it while building and testing.

Git history should contain focused commits with messages that explain intent.
Review `git diff` before committing; never commit build directories or secrets.

**Review**

1. What does a smoke test fail to prove?
2. Why is `assert` unsuitable for hostile input?
3. What is the difference between debugger and sanitizer evidence?
4. Why are target usage requirements preferable to global CMake settings?
5. How do single-config and multi-config build commands differ?
6. What should a focused commit contain?

## 7. Classes, Invariants, and Special Members

A class protects an invariant by controlling construction and mutation. Initialize
members in the member initializer list. Mark observer member functions `const`.

```cpp
class Counter {
public:
    explicit Counter(int initial) : value_{initial} {}
    [[nodiscard]] int value() const { return value_; }
private:
    int value_;
};
```

The compiler may generate a default constructor, destructor, copy operations, and
move operations. Declaring one special member can suppress or alter generation of
others. Use `=default` to request normal behavior and `=delete` to forbid an
operation. Prefer owning standard-library members so no custom special members are
needed: the Rule of Zero.

Object construction follows member declaration order, not initializer-list order.
Destruction occurs in reverse construction order.

**Review**

1. What makes an invariant different from a validation performed only in `main`?
2. In what order are data members initialized?
3. What does `=delete` communicate?
4. Why is the Rule of Zero the default?

## 8. Storage Duration and Lifetime

Automatic objects normally live until their block exits. Static objects live for
the program duration. Thread-local objects live for a thread duration. Dynamic
objects live until their owning mechanism releases them.

Lifetime begins only after initialization and ends when destruction starts. A
pointer can still contain an address after the object's lifetime ends; dereferencing
it is invalid. Leaks and dangling observers are different defects.

Temporaries usually live to the end of the full expression. A reference can extend
some temporary lifetimes, but views and pointers generally do not.

**Review**

1. Name the four storage-duration categories.
2. Why can a non-null pointer still be invalid?
3. What is the difference between a leak and a dangling pointer?
4. Does constructing a `string_view` extend string lifetime?

## 9. Errors, Exceptions, and Guarantees

Choose an error mechanism according to the interface:

- a precondition states what a caller must satisfy;
- `std::optional<T>` represents expected absence without error detail;
- `std::expected<T, E>` represents a recoverable result or typed error;
- exceptions propagate failures that cannot be handled locally;
- `std::error_code` supports non-throwing system and library error reporting.

An exception is thrown, stack unwinding destroys completed automatic objects, and
a compatible `catch` handler may recover. Destructors should not emit exceptions
during unwinding.

`std::variant<A, B, ...>` owns exactly one value from a closed set of alternatives.
Use `std::visit` to handle alternatives deliberately. A variant is useful when
the set of value types is closed; it is not an error mechanism by itself.

Exception guarantees:

- no-throw: the operation does not throw;
- strong: failure leaves observable state unchanged;
- basic: invariants hold and resources do not leak, but state may change.

**Review**

1. When is absence not an error?
2. What does stack unwinding destroy?
3. What does the strong guarantee promise?
4. Why is a throwing destructor dangerous?
5. When is `error_code` useful?
6. What problem does `variant` solve?

## 10. RAII, Copy, Move, and Ownership

RAII binds a resource to object lifetime: acquire during successful construction,
release in the destructor. This applies to memory, files, locks, sockets, temporary
directories, and process handles.

A destructor must not be the only place to report a fallible finalization operation.
For buffered output or transactional resources, provide an explicit `close`,
`finish`, or `commit` operation that returns the failure. The no-throw destructor
remains a best-effort cleanup fallback for callers that did not finalize explicitly.

Manual owners need correct destruction and copy/move behavior. A copy creates an
independent logical value. A move transfers resources and leaves the source valid
but otherwise unspecified unless documented.

`std::move` is a cast that permits move overload resolution; it does not move by
itself. A `noexcept` move can let containers relocate elements without falling
back to copying. Guaranteed copy elision constructs some return values directly.

Prefer values and stable IDs. Use `std::unique_ptr` for exclusive dynamic ownership.
Use `std::shared_ptr` only for genuine shared lifetime, and `std::weak_ptr` to
observe without extending that lifetime.

**Review**

1. What two events does RAII couple?
2. Why might a file owner need an explicit fallible `close` operation?
3. What must remain true about a moved-from object?
4. Why can `noexcept` affect vector relocation?
5. Does `std::move` itself transfer a resource?
6. Why is shared ownership not a default graph design?

## 11. Containers, Iterators, and Algorithms

Choose a container from required operations, complexity, ordering, invalidation,
memory layout, and measured workload. Average hash-table lookup is not a worst-case
guarantee.

An iterator denotes a position. Iterator categories describe supported movement
and access. A sentinel marks an end and need not have the same type as the
iterator. Algorithms impose requirements on iterators, values, predicates, and
comparators.

A strict weak ordering comparator must be consistent; returning true for equal
values violates it. Use projections when the algorithm should compare one field
of a larger record.

Standard adaptors such as `std::stack`, `std::queue`, and `std::priority_queue`
should be preferred in production when their interfaces fit. A custom stack in
this roadmap exists to teach templates.

**Review**

1. Which facts besides Big-O influence container selection?
2. What can invalidate an iterator?
3. What is a sentinel?
4. Why must a comparator return false for equivalent values?
5. When is a standard container adaptor sufficient?

## 12. Lambdas, Callables, and Callback Lifetime

A lambda creates a callable object. Capture by value owns a copy; capture by
reference observes an external object. A callback that outlives a referenced
capture dangles.

Function pointers represent a narrow callable form. Templates accept generic
callables without type erasure. `std::function` stores compatible callables behind
a runtime-erased interface, potentially adding allocation and indirection.

A dispatcher cannot inspect an arbitrary callable to discover unsafe reference
captures. Enforce lifetime through the API instead: require self-contained callable
values, associate registrations with an owner token checked before invocation, or
state a caller precondition. A subscription token controls registration lifetime but
does not by itself extend the lifetime of captured objects.

Mutation during callback dispatch needs a defined policy: immediate, deferred, or
forbidden. Do not invoke unknown user code while holding an internal mutex.

**Review**

1. What lifetime must a reference capture satisfy, and why can a dispatcher not
   verify that capture automatically?
2. When does a template preserve a callable's concrete type?
3. What costs can `std::function` introduce?
4. How can an owner token make callback lifetime enforceable?
5. Why must mutation during dispatch be specified?

## 13. Ranges and Views

A range provides a beginning and an end. A view is a lightweight, usually lazy
range adaptor. Many views reference an external range, while owning and generated
views can own their underlying state or produce values without external element
storage. Composing views can express pipelines, but the programmer must identify
what state is owned, what is referenced, and what invalidates iteration.

Materialize an owning container before returning data that must outlive its source
or before an operation such as sorting should not mutate the source. A borrowed
range permits selected iterators to remain valid when the range object itself is a
temporary; this does not make element storage immortal.

Safe pipeline order for records:

1. filter records;
2. materialize selected records when ownership or mutation is required;
3. sort or partially select;
4. take the required count;
5. transform into presentation values.

**Review**

1. Which kinds of views reference external storage, own an underlying range, or
   generate values?
2. Why can sorting through a view mutate the source?
3. When should a pipeline materialize?
4. What does borrowed range actually guarantee, and what does it not say about
   element ownership?

## 14. Filesystem, Formatting, and Chrono

`std::filesystem::path` represents paths; do not treat paths as arbitrary text.
Traversal must define recursion, permission, error, and symlink policy. Non-throwing
overloads report `std::error_code`; throwing overloads provide exceptions.

`std::format` produces text and `std::print` writes formatted output where
supported. Byte count, Unicode code-point count, and terminal display width are
different concepts.

Use `std::chrono::steady_clock` for elapsed intervals because it is monotonic.
Use a wall clock for timestamps. Inject clock and sleep behavior so tests do not
wait in real time.

**Review**

1. Why should paths remain `filesystem::path` values?
2. Which traversal policies must be explicit?
3. Why does string length not equal terminal width?
4. Which clock should measure elapsed work?

## 15. Regular Types, Operators, and Polymorphism

A regular value type behaves predictably under construction, copy/move, equality,
and assignment. Overloaded operators should preserve conventional meaning and
avoid hidden mutation.

Defaulted equality and three-way comparison (`<=>`) can derive consistent
comparisons when member-wise ordering matches the domain. Approximate floating
comparison is usually a separate named operation.

For runtime polymorphism, use a virtual destructor when deleting through a base,
mark overrides with `override`, and use `final` only to state a deliberate design
constraint. Passing derived objects by base value slices them. Avoid downcasts when
the base interface can express the required operation.

Composition is the default reuse mechanism. Variants fit closed sets of types;
virtual interfaces fit open type extension; type erasure fits runtime behavior
behind value-like APIs.

**Review**

1. What behavior makes a type regular?
2. When is defaulted `<=>` appropriate?
3. What is object slicing?
4. Why does a polymorphic base need a virtual destructor?
5. Which design favors a closed set of alternatives?

## 16. Templates, Deduction, and Forwarding

Templates are blueprints instantiated for concrete arguments. Definitions are
usually visible where instantiation occurs. Deduction determines template
arguments from calls; constraints should express only operations the implementation
actually needs.

In a deduced context, `T&&` can be a forwarding reference. Use
`std::forward<T>(value)` only to preserve the caller's value category. Overusing
forwarding makes interfaces and diagnostics harder.

Dependent names may require `typename` or `template` disambiguation. Type traits
compute type properties. Variadic templates accept parameter packs, and fold
expressions combine them. `decltype(expression)` inspects an expression's type and
value category; `decltype(auto)` preserves deduction rules that plain `auto` may
discard, so use it only when that preservation is part of the interface.

Prefer constrained overloads and named customization functions over clever
specialization. Unsupported calls should fail with readable diagnostics.

**Review**

1. Why are template definitions commonly in headers?
2. When is `T&&` a forwarding reference?
3. What does `std::forward` preserve?
4. What is a dependent name?
5. What should a concept describe?
6. How can `decltype(auto)` differ from `auto`?

## 17. Constant Evaluation

`constexpr` means an entity can participate in constant evaluation when its inputs
and operations permit. `consteval` requires compile-time evaluation. `static_assert`
checks a compile-time condition.

Compile-time work should improve correctness, interface guarantees, or runtime
cost. It should not be added only to demonstrate syntax. Validate overflow and
invalid inputs in both compile-time and runtime paths.

**Review**

1. Must every `constexpr` call run at compile time?
2. What does `consteval` require?
3. What makes a compile-time calculation worthwhile?

## 18. Threads, Races, and Locks

A thread must have a defined owner and shutdown path. Destroying a joinable
`std::thread` calls `std::terminate`, including when an exception bypasses a manual
`join`. Use a scope-bound joining owner or `std::jthread` for application work.
Detached threads are usually unsuitable for owned work. `std::jthread` joins during
destruction and supports stop tokens.

Two evaluations conflict when they access overlapping memory and at least one
modifies the memory or starts or ends an object's lifetime. A data race occurs when
conflicting evaluations are potentially concurrent, at least one is non-atomic, and
neither happens before the other. A data race is undefined behavior. Relaxed atomic
operations can be weakly ordered without creating a data race on the atomic object.

A mutex protects an invariant, not merely a variable. RAII lock objects release
the mutex during all exits. Multiple locks need a consistent strategy such as
`std::scoped_lock`. Never call unknown user code while holding an internal lock.
Use `std::call_once` when one initialization must occur exactly once across
threads; do not recreate it with an unprotected Boolean flag.

**Review**

1. What happens if a joinable `std::thread` is destroyed during stack unwinding?
2. What conditions form a data race, and why do relaxed atomic operations differ?
3. What should a mutex protect?
4. Why is detached ownership difficult?
5. When does `call_once` fit better than a hand-written flag?

## 19. Condition Variables, Cancellation, and Task Results

A condition variable waits for a state predicate while atomically releasing and
reacquiring a mutex. Always wait with a predicate because wakeups can be spurious.
Closing a queue must wake every waiter and make future behavior explicit.

Cancellation is cooperative. A stop request does not forcibly terminate a thread;
blocking and repeated operations must observe it and leave invariants intact.

`std::future` represents a later result or exception. `std::promise` publishes a
result. `std::async` has policy-dependent behavior, so specify or document the
launch policy. Use these facilities for task result transport, not shared mutable
state.

**Review**

1. Why must a condition-variable wait test a predicate?
2. What does cooperative cancellation require from work?
3. How does a future transport an exception?
4. Why must queue closure wake all waiters?

## 20. Atomics and the Memory Model

Atomic operations prevent data races on the atomic object, but they do not
automatically protect a multi-object invariant. Start with sequential consistency.
Weaker ordering is justified only by a written happens-before argument and tests
cannot prove that argument.

Use a mutex for compound state until evidence shows a suitable atomic design is
both correct and beneficial. Lock-free does not mean wait-free or faster.

**Review**

1. What does atomicity not guarantee about multiple fields?
2. Why begin with sequential consistency?
3. What must justify release/acquire ordering?
4. Does a passing stress test prove memory-order correctness?

## 21. Measurement, Profiling, and PMR

Benchmarking measures a workload; profiling attributes cost. Record hardware,
compiler, flags, build type, input, warmup, repetitions, and noise. Optimize the
measured bottleneck and keep correctness tests unchanged.

Algorithmic improvements usually matter more than hints or allocator changes.
`std::pmr` containers obtain storage through a `memory_resource`; every container
using a resource must die before the resource. Retain PMR only when allocation
evidence justifies the complexity.

**Review**

1. What is the difference between benchmark and profile evidence?
2. Which experimental details make a timing reproducible?
3. Why optimize algorithms before branch hints?
4. What lifetime relation must a PMR resource satisfy?

## 22. Verification, Packaging, and Maintenance

Verification combines examples, unit and integration tests, properties, fuzzing,
sanitizers, static analysis, concurrency tests, and review. Coverage shows executed
code, not correctness.

A reusable CMake package needs install rules, exported namespaced targets, package
configuration files, and a clean external consumer test. Dependencies need a
documented, reproducible strategy and version constraints.

A release defines versioning, compatibility, license, changelog, artifacts, and
checksums. Professional work continues afterward: reproduce a reported defect,
write a regression test, upgrade dependencies deliberately, evaluate API/ABI
impact, and issue a patch release.

**Review**

1. What does high coverage fail to prove?
2. Why test an installed package from an external consumer?
3. What makes dependency acquisition reproducible?
4. What evidence belongs in a defect fix?
5. How does a patch release differ from a feature release?
