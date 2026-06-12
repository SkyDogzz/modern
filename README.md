# Modern C++ Project Roadmap 🦇✨

A project-based path to learn modern C++ in a clean order.

This roadmap is designed around this progression:

1. Language basics
2. Idiomatic C++
3. Standard library mastery
4. Abstraction power
5. Advanced modern C++
6. Professional C++

The goal is not to memorize the language.  
The goal is to build small projects that force you to understand:

- types
- ownership
- lifetime
- RAII
- value semantics
- standard containers
- algorithms
- templates
- modern tooling
- architecture

## Recommended usage

Create one repository:

```txt
modern-cpp-roadmap/
├── README.md
├── projects/
│   ├── 01-hello-build-system/
│   ├── 02-command-line-greeter/
│   └── ...
├── notes/
│   ├── phase-01-basics.md
│   ├── phase-02-idiomatic-cpp.md
│   └── ...
└── playground/
```

For every project:

1. Read the objective.
2. Implement the minimum version.
3. Add the stretch goal only if the concept feels clear.
4. Write a tiny `README.md` for what you learned.
5. Compile with warnings enabled.

Recommended flags:

```bash
-std=c++20 -Wall -Wextra -Wpedantic
```

For learning, also use sanitizers when possible:

```bash
-fsanitize=address,undefined -g
```

## The full project order

1. Hello Build System
2. Command-Line Greeter
3. Unit Converter
4. Character Stat Sheet
5. Expression Calculator
6. Number Guessing Game
7. Dice Roller
8. Inventory Editor
9. Todo List CLI
10. Bank Account Simulator
11. Logger Object
12. File Wrapper
13. Dynamic String Class
14. Movable Buffer
15. Dungeon Room Graph
16. Lifetime Visualizer
17. Config File Parser
18. Contact Book
19. Playlist Manager
20. Student Grade Analyzer
21. Event Dispatcher
22. Directory Cleaner
23. Pretty Table Printer
24. Pomodoro Timer
25. Vector2 Math Library
26. Shape Renderer
27. Generic Stack
28. Compile-Time Math Library
29. Constrained Generic Algorithms
30. Data Processing Pipeline
31. Tiny Serialization Library
32. Plugin Command System
33. Safe Conversion Lab
34. Parallel File Hasher
35. Lazy Number Generator
36. Modular Math Library
37. Arena-Based Text Processor
38. Warning-Clean Utility Library
39. Modern CLI Toolkit
40. Test Everything
41. Professionalize One Project
42. Final Boss Project

## Suggested serious projects

Not every project needs to be huge.

Make these ones more serious:

1. Todo List CLI
2. Bank Account Simulator
3. File Wrapper
4. Dynamic String / Buffer
5. Config File Parser
6. Contact Book
7. Student Grade Analyzer
8. Event Dispatcher
9. Vector2 Math Library
10. Shape Renderer
11. Generic Stack
12. Data Processing Pipeline
13. Tiny Serialization Library
14. Parallel File Hasher
15. Final Boss Project

Everything else can be a small lab.
