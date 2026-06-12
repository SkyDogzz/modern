# Phase 4 — Abstraction Power 🦇

This phase teaches how C++ builds expressive abstractions.

Focus on:

- operator overloading
- inheritance
- polymorphism
- templates
- constexpr
- concepts
- ranges
- advanced templates
- type erasure

## 25. Vector2 Math Library

### Concepts

- operator overloading
- member vs non-member operators
- equality
- stream output
- readable APIs

### Goal

Create a small 2D vector math library.

### Example

```cpp
Vector2 a{1, 2};
Vector2 b{3, 4};

auto c = a + b;
std::cout << c << '\n';
```

### Requirements

Implement:

```txt
operator+
operator-
operator*
operator==
operator<<
length()
normalized()
dot()
```

### Stretch goal

Add `Vector3`.

---

## 26. Shape Renderer

### Concepts

- inheritance
- virtual functions
- abstract classes
- dynamic dispatch
- virtual destructors
- owning polymorphic objects

### Goal

Create shapes with common behavior.

### Suggested hierarchy

```cpp
class Shape;
class Circle;
class Rectangle;
class Triangle;
```

### Requirements

Each shape should support:

```txt
draw
area
perimeter
```

Store them in:

```cpp
std::vector<std::unique_ptr<Shape>>
```

### Stretch goal

Load shapes from a text file.

---

## 27. Generic Stack

### Concepts

- function templates
- class templates
- type parameters
- generic containers
- compile-time polymorphism

### Goal

Implement:

```cpp
Stack<int>
Stack<std::string>
Stack<Player>
```

### Requirements

Support:

```txt
push
pop
top
empty
size
```

### Stretch goal

Add iterator support.

---

## 28. Compile-Time Math Library

### Concepts

- `constexpr`
- `consteval`
- `static_assert`
- constant expressions
- compile-time evaluation

### Goal

Write compile-time math functions.

### Requirements

Implement:

```txt
factorial
fibonacci
power
is_prime
gcd
```

### Stretch goal

Generate lookup tables at compile time.

---

## 29. Constrained Generic Algorithms

### Concepts

- concepts
- `requires`
- template constraints
- readable template errors
- generic API design

### Goal

Write constrained generic functions.

### Example functions

```txt
average(container)
max_value(container)
print_all(container)
```

### Requirements

- Create a `Numeric` concept.
- Create a container-like concept.
- Reject invalid types cleanly.

### Stretch goal

Compare compiler errors with and without concepts.

---

## 30. Data Processing Pipeline

### Concepts

- `std::ranges`
- views
- lazy transformations
- filters
- composable pipelines

### Goal

Process a list of records.

### Requirements

Given users with:

```txt
name
score
active
```

Create a pipeline:

```txt
filter active users
transform names
sort by score
take top 10
```

### Stretch goal

Compare ranges version vs classic algorithm version.

---

## 31. Tiny Serialization Library

### Concepts

- variadic templates
- forwarding references
- type traits
- `if constexpr`
- specialization

### Goal

Serialize simple structs into text.

### Example

```cpp
Player player{"Nyx", 100, 50};
serialize(player);
```

### Requirements

- Serialize primitive values.
- Serialize strings.
- Serialize simple structs manually.
- Keep output readable.

### Stretch goal

Create JSON-like output.

---

## 32. Plugin Command System

### Concepts

- type erasure
- runtime polymorphism
- `std::function`
- value-semantics wrappers
- API boundaries

### Goal

Create a command system.

### Example

```cpp
Command save;
Command load;
Command quit;
```

### Requirements

- Store different command implementations behind one type.
- Execute commands through a common interface.
- Add commands dynamically.

### Stretch goal

Compare three approaches:

1. inheritance
2. templates
3. type erasure
