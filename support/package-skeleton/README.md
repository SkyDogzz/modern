# Installable Library Skeleton

This is the Project 55 starting point. Copy it to a learner project, rename the
library and namespace, and replace the example API.

Verify it independently:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
cmake --install build --prefix build/prefix
cmake -S consumer -B consumer/build \
  -DCMAKE_PREFIX_PATH="$PWD/build/prefix"
cmake --build consumer/build
ctest --test-dir consumer/build --output-on-failure
```

For a multi-config generator, add `--config Debug` to build/install commands and
`-C Debug` to CTest.
