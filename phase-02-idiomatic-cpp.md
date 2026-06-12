# Phase 2 — Idiomatic C++ 🖤

This phase is where C++ starts becoming C++.

Focus on:

- classes
- constructors
- destructors
- RAII
- ownership
- copy semantics
- move semantics
- smart pointers
- lifetime
- error handling

## 10. Bank Account Simulator

### Concepts

- `class`
- `struct`
- public/private
- member functions
- constructors
- invariants

### Goal

Create a small banking simulator.

### Suggested classes

```cpp
class BankAccount;
class Transaction;
```

### Requirements

Support:

```txt
deposit
withdraw
transfer
print balance
print transaction history
```

### Important rule

Never allow an invalid account state.

### Stretch goal

Add multiple accounts.

---

## 11. Logger Object

### Concepts

- constructors
- destructors
- scope
- automatic lifetime
- object creation/destruction order

### Goal

Create a `Logger` class that prints when it is constructed and destroyed.

### Example

```cpp
{
    Logger log("combat");
}
```

### Requirements

- Print construction message.
- Print destruction message.
- Create objects in nested scopes.
- Observe order.

### Stretch goal

Write logs to a file.

---

## 12. File Wrapper

### Concepts

- RAII
- resource ownership
- destructor cleanup
- exception-safe cleanup
- non-copyable resources

### Goal

Create a class that opens a file in its constructor and closes it in its destructor.

### Example

```cpp
File file("data.txt");
file.write("hello");
```

### Requirements

- Open file in constructor.
- Close file in destructor.
- Prevent invalid writes.
- Report errors clearly.

### Stretch goal

Make the class non-copyable.

---

## 13. Dynamic String Class

### Concepts

- dynamic allocation
- destructor
- copy constructor
- copy assignment
- deep copy
- Rule of Three

### Goal

Build a tiny custom string class.

### Suggested interface

```cpp
class MiniString {
public:
    MiniString(const char* text);
    MiniString(const MiniString& other);
    MiniString& operator=(const MiniString& other);
    ~MiniString();

    const char* c_str() const;
};
```

### Requirements

- Own a dynamic character buffer.
- Copy deeply.
- Free memory correctly.
- Avoid leaks.

### Stretch goal

Add bounds-checked indexing.

---

## 14. Movable Buffer

### Concepts

- move constructor
- move assignment
- `std::move`
- moved-from state
- Rule of Five

### Goal

Extend `MiniString` or create a `Buffer` class with move operations.

### Requirements

- Implement copy operations.
- Implement move operations.
- Print when copy or move happens.
- Test with vectors.

### Stretch goal

Measure fewer allocations after moving.

---

## 15. Dungeon Room Graph

### Concepts

- `std::unique_ptr`
- `std::shared_ptr`
- `std::weak_ptr`
- ownership models
- cycles
- leaks

### Goal

Create rooms connected together.

### Example

```txt
Entrance -> Hall
Hall -> Treasury
Hall -> Dungeon
```

### Requirements

- Decide who owns rooms.
- Connect rooms.
- Move between rooms.
- Avoid ownership cycles.

### Stretch goal

Use `std::weak_ptr` where needed.

---

## 16. Lifetime Visualizer

### Concepts

- stack objects
- heap objects
- temporaries
- dangling references
- dangling pointers
- lifetime extension
- undefined behavior

### Goal

Create tiny examples that demonstrate object lifetime.

### Requirements

Show examples of:

```txt
stack object
heap object
temporary object
reference lifetime
dangling pointer
dangling reference
```

### Important

Use sanitizers to catch bugs.

### Stretch goal

Add AddressSanitizer and UBSan builds.

---

## 17. Config File Parser

### Concepts

- error handling
- `std::optional`
- `std::variant`
- exceptions
- validation
- parsing

### Goal

Parse a config file:

```txt
username=nyx
volume=80
fullscreen=true
```

### Requirements

- Load a file.
- Parse key-value pairs.
- Validate values.
- Report malformed lines.
- Handle missing files.

### Stretch goal

Implement two versions:

1. exception-based
2. return-value-based
