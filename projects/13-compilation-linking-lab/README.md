# Project 13 Broken Linker Fixture

Compile both files:

```bash
c++ -std=c++23 -Wall -Wextra -Wpedantic main.cpp greeting.cpp -o linker-lab
```

The declaration and call exist, but the definition is intentionally missing. Add the
definition in `greeting.cpp`, explain why the original command reached the linker,
and keep the broken version available in history or as a patch.
