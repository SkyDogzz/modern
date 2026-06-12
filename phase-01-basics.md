# Phase 1 — Basic Language Survival 🦇

This phase teaches the raw basics needed to survive C++.

Focus on:

- compiling
- source/header separation
- primitive types
- variables
- expressions
- control flow
- functions
- references
- pointers
- strings
- arrays
- vectors

## 1. Hello Build System

### Concepts

- compiler commands
- source files
- header files
- object files
- linking
- warning flags
- Makefile or CMake basics

### Goal

Create a tiny program split into multiple files:

```txt
main.cpp
math_utils.cpp
math_utils.hpp
```

The program should call functions from `math_utils`.

### Requirements

- Compile manually first.
- Then create a `Makefile`.
- Use warnings.
- Keep headers clean.

### Example commands

```bash
c++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp math_utils.cpp -o app
./app
```

### Stretch goal

Add a simple CMake build.

---

## 2. Command-Line Greeter

### Concepts

- `main(int argc, char** argv)`
- command-line arguments
- program structure
- simple parsing
- error messages

### Goal

Create:

```bash
./greeter Thomas
./greeter --shout Thomas
./greeter --repeat 3 Thomas
```

### Requirements

- Print a greeting.
- Support normal and shout mode.
- Support repeated output.
- Validate bad input.

### Stretch goal

Add `--help`.

---

## 3. Unit Converter

### Concepts

- `int`
- `double`
- `bool`
- conversions
- precision
- functions

### Goal

Create:

```bash
./convert 42 km miles
./convert 100 celsius fahrenheit
./convert 10 kg lb
```

### Requirements

- Support at least 3 categories.
- Handle invalid units.
- Keep conversion logic in functions.

### Stretch goal

Add an interactive menu.

---

## 4. Character Stat Sheet

### Concepts

- variables
- initialization
- `const`
- scope
- basic input/output

### Goal

Generate a small RPG character sheet:

```txt
Name: Nyx
Health: 100
Mana: 50
Strength: 12
Agility: 15
```

### Requirements

- Ask for a name.
- Generate or assign stats.
- Print a clean summary.

### Stretch goal

Add random stat generation.

---

## 5. Expression Calculator

### Concepts

- arithmetic operators
- comparison operators
- logical operators
- precedence
- integer division
- floating-point division

### Goal

Create a calculator that supports:

```txt
+ - * / %
```

### Requirements

- Parse two numbers and an operator.
- Support integer and floating-point operations.
- Handle division by zero.

### Stretch goal

Add simple comparison operations like `<`, `>`, `==`.

---

## 6. Number Guessing Game

### Concepts

- `if`
- `else`
- `switch`
- `while`
- `for`
- `break`
- `continue`

### Goal

Make a number guessing game.

### Requirements

- Random secret number.
- User guesses until correct.
- Print too high / too low.
- Count attempts.

### Stretch goal

Add difficulty levels.

---

## 7. Dice Roller

### Concepts

- functions
- parameters
- return values
- function overloads
- separating logic from `main`

### Goal

Create:

```bash
./dice 3d6
./dice 1d20
./dice 4d10+2
```

### Requirements

- Parse dice expressions.
- Roll random numbers.
- Print individual rolls and total.

### Stretch goal

Support expressions like:

```txt
2d8+1d6+3
```

---

## 8. Inventory Editor

### Concepts

- pass by value
- pass by reference
- `const&`
- pointers
- `nullptr`
- search functions

### Goal

Create an inventory system.

### Requirements

Support:

```txt
add item
remove item
rename item
upgrade item
list items
```

### Stretch goal

Create a function that returns a pointer to an item if found.

---

## 9. Todo List CLI

### Concepts

- `std::string`
- `std::vector`
- indexing
- loops
- simple data modeling

### Goal

Create:

```bash
./todo add "Learn RAII"
./todo list
./todo done 2
./todo remove 3
```

### Requirements

- Store tasks in memory first.
- Each task has text and completion state.
- Validate indexes.

### Stretch goal

Save and load from a text file.
