# Phase 5 — Advanced Modern C++ 😳🖤

This phase contains specialized, powerful, and sometimes cursed tools.

Focus on:

- casts
- concurrency
- coroutines
- modules
- allocators
- PMR
- attributes
- C++23 additions

## 33. Safe Conversion Lab

### Concepts

- `static_cast`
- `dynamic_cast`
- `const_cast`
- `reinterpret_cast`
- const correctness
- representation danger

### Goal

Create examples showing what each cast does.

### Requirements

- Demonstrate safe numeric conversions.
- Demonstrate polymorphic downcast.
- Demonstrate why `reinterpret_cast` is dangerous.
- Demonstrate how to avoid unnecessary casts.

### Stretch goal

Refactor examples to remove most casts.

---

## 34. Parallel File Hasher

### Concepts

- `std::thread`
- `std::mutex`
- `std::lock_guard`
- race conditions
- shared state
- task splitting

### Goal

Hash many files in a directory using multiple threads.

### Requirements

- Traverse directory.
- Assign files to workers.
- Hash each file.
- Store results safely.
- Print summary.

### Stretch goal

Add a thread pool.

---

## 35. Lazy Number Generator

### Concepts

- coroutines
- `co_yield`
- lazy evaluation
- suspend/resume
- promise type basics

### Goal

Create lazy generators.

### Example generators

```txt
numbers()
fibonacci()
read_lines()
```

### Requirements

- Implement a basic generator type.
- Yield values lazily.
- Iterate through generated values.

### Stretch goal

Create a lazy file line reader.

---

## 36. Modular Math Library

### Concepts

- C++20 modules
- `export module`
- imports
- module interface files
- build system support

### Goal

Turn your `Vector2` library into a module.

### Requirements

- Export a module.
- Import it from `main`.
- Build it successfully.
- Document compiler commands.

### Stretch goal

Compare compile times with headers.

---

## 37. Arena-Based Text Processor

### Concepts

- allocators
- `std::pmr`
- memory resources
- allocation performance
- arena allocation

### Goal

Parse lots of small strings using PMR containers.

### Use:

```cpp
std::pmr::vector
std::pmr::string
std::pmr::monotonic_buffer_resource
```

### Requirements

- Parse text into tokens.
- Store tokens in PMR containers.
- Compare with normal containers.

### Stretch goal

Benchmark allocation behavior.

---

## 38. Warning-Clean Utility Library

### Concepts

- attributes
- API safety
- warning control
- compiler hints

### Goal

Create a small utility library using attributes.

### Use:

```cpp
[[nodiscard]]
[[maybe_unused]]
[[deprecated]]
[[likely]]
[[unlikely]]
```

### Requirements

- Make misuse trigger warnings.
- Keep build warning-clean.
- Document each attribute.

### Stretch goal

Add compiler-specific attributes conditionally.

---

## 39. Modern CLI Toolkit

### Concepts

- C++23 library additions
- feature-test macros
- compiler support
- graceful fallbacks

### Goal

Build a polished CLI toolkit using newer features when available.

### Possible features

```txt
std::print
std::expected
improved ranges
std::mdspan
std::flat_map
std::generator
```

### Requirements

- Detect feature support.
- Use fallbacks when needed.
- Compile on at least one modern compiler.

### Stretch goal

Make it compile on both GCC and Clang.
