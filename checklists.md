# Modern C++ Learning Checklists 🖤

## Per-project checklist

- [ ] I can explain the main concept.
- [ ] I compiled with warnings.
- [ ] I tested invalid input.
- [ ] I separated code into functions/classes when useful.
- [ ] I avoided unnecessary raw pointers.
- [ ] I used standard library tools where appropriate.
- [ ] I wrote a short README.
- [ ] I can explain one bug I fixed.

## Warning flags

Use these often:

```bash
-std=c++20 -Wall -Wextra -Wpedantic
```

Optional stricter flags:

```bash
-Wconversion -Wshadow -Werror
```

## Sanitizers

Use during learning:

```bash
-fsanitize=address,undefined -g
```

## Good habits

- Prefer `std::vector` over raw dynamic arrays.
- Prefer `std::string` over C strings.
- Prefer RAII over manual cleanup.
- Prefer `std::unique_ptr` for single ownership.
- Prefer `const` where possible.
- Prefer algorithms over hand-written loops when clearer.
- Prefer value semantics when possible.
- Avoid inheritance until it actually solves a problem.
- Avoid raw `new` and `delete`.
- Avoid casts unless you can justify them.

## Questions to ask after each project

1. Who owns each resource?
2. When is each object created?
3. When is each object destroyed?
4. Can this code leak memory?
5. Can this code throw?
6. What happens on invalid input?
7. What would I test?
8. What could be simpler?
