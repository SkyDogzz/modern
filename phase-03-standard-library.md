# Phase 3 — Standard Library Mastery ✨

This phase teaches the tools you should reach for before writing raw loops and raw data structures.

Focus on:

- containers
- iterators
- algorithms
- lambdas
- filesystem
- I/O
- formatting
- chrono

## 18. Contact Book

### Concepts

- `std::vector`
- `std::map`
- `std::unordered_map`
- `std::set`
- choosing containers

### Goal

Create a contact book.

### Requirements

Support:

```txt
add contact
remove contact
search contact
list contacts
```

Each contact should have:

```txt
name
email
phone
tags
```

### Stretch goal

Benchmark lookup with `std::map` vs `std::unordered_map`.

---

## 19. Playlist Manager

### Concepts

- iterators
- iterator invalidation
- `begin()`
- `end()`
- range-based loops
- container tradeoffs

### Goal

Create a music playlist manager.

### Requirements

Support:

```txt
next song
previous song
shuffle
remove current
insert after current
```

### Stretch goal

Implement once with `std::vector`, once with `std::list`, then compare.

---

## 20. Student Grade Analyzer

### Concepts

- `std::sort`
- `std::find_if`
- `std::count_if`
- `std::transform`
- `std::accumulate`
- predicates
- custom comparators

### Goal

Analyze a list of students.

### Requirements

Compute:

```txt
average grade
highest grade
failed students
sorted ranking
top 10
```

### Rule

Use standard algorithms instead of manual loops where reasonable.

### Stretch goal

Add CSV input/output.

---

## 21. Event Dispatcher

### Concepts

- lambdas
- captures
- function objects
- `std::function`
- callbacks
- callable design

### Goal

Create a tiny event system.

### Example

```cpp
dispatcher.on("damage", [](const Event& event) {
    // handle damage
});

dispatcher.emit("damage");
```

### Requirements

- Register callbacks.
- Emit events.
- Support multiple callbacks per event.

### Stretch goal

Add event priorities.

---

## 22. Directory Cleaner

### Concepts

- `std::filesystem`
- paths
- directory iteration
- file size
- file streams
- recursive traversal

### Goal

Scan a directory and report:

```txt
largest files
empty files
duplicate names
files by extension
```

### Requirements

- Accept a path as argument.
- Print a report.
- Handle invalid paths.

### Stretch goal

Add dry-run delete mode.

---

## 23. Pretty Table Printer

### Concepts

- formatted output
- alignment
- width
- precision
- `std::format` if available
- terminal output

### Goal

Print clean tables.

### Example

```txt
+----------+-------+
| Name     | Score |
+----------+-------+
| Nyx      | 98    |
| Raven    | 87    |
+----------+-------+
```

### Requirements

- Support column names.
- Auto-size columns.
- Align text.
- Align numbers.

### Stretch goal

Export Markdown tables.

---

## 24. Pomodoro Timer

### Concepts

- `std::chrono`
- durations
- time points
- sleeping
- elapsed time
- clocks

### Goal

Create a Pomodoro timer.

### Requirements

Support:

```txt
25 min work
5 min break
long break every 4 cycles
```

### Stretch goal

Write a session log.
