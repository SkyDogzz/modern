# Phase 6 — Professional C++ 💖

This phase turns your code from "it works" into "I can trust it."

Focus on:

- tests
- tooling
- sanitizers
- static analysis
- CI
- architecture
- documentation

## 40. Test Everything

### Concepts

- unit tests
- edge cases
- regression tests
- test organization
- test-driven design

### Goal

Add tests to earlier projects.

### Recommended targets

```txt
Vector2
Config File Parser
Contact Book
Generic Stack
Serialization Library
```

### Suggested frameworks

- Catch2
- GoogleTest
- doctest

### Requirements

- Test normal cases.
- Test edge cases.
- Test invalid input.
- Make tests easy to run.

### Stretch goal

Add code coverage.

---

## 41. Professionalize One Project

### Concepts

- CMake
- clang-format
- clang-tidy
- sanitizers
- CI
- README
- benchmarks

### Goal

Take your best previous project and make it feel professional.

### Requirements

Add:

```txt
CMake
clang-format
clang-tidy
sanitizer build
unit tests
GitHub Actions
README
benchmarks
```

### Stretch goal

Add generated documentation.

---

## 42. Final Boss Project

Choose one final project and build it seriously.

## Option A: Mini Game Engine

### Features

```txt
entities
components
systems
events
resources
input
serialization
```

### Concepts used

- RAII
- containers
- smart pointers
- polymorphism
- templates
- type erasure
- file I/O
- testing
- architecture

---

## Option B: Mini Database

### Features

```txt
tables
rows
schema
queries
indexes
persistence
transactions-lite
```

### Concepts used

- parsing
- containers
- algorithms
- RAII
- error handling
- serialization
- filesystem
- testing

---

## Option C: Mini Shell

### Features

```txt
tokenizer
parser
AST
commands
pipes
redirections
environment
process handling
```

### Concepts used

- ownership
- RAII wrappers for file descriptors
- smart pointers for AST nodes
- error handling
- containers
- architecture
- tests

This option fits especially well if you already have C or minishell experience.
