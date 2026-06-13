# Reviewer Calibration Record

This record demonstrates the calibration procedure required by
[assessment-and-retention.md](assessment-and-retention.md#reviewer-protocol). The
fixture is synthetic so it can remain stable as the curriculum evolves. Reviewers
score only the frozen evidence below, independently and without seeing the other
review.

## Frozen Evidence Packet CAL-01

**Identity:** `CAL-01-v1`, issued 2026-06-13, GCC 14/libstdc++ 14 profile,
`-std=c++23`.

**Task:** implement `parse_count(string_view) -> expected<int, ParseError>` for a
decimal count in the inclusive range 0-100.

**Requirements:**

1. accept only a complete decimal representation in range;
2. distinguish empty/invalid text from representation or domain overflow;
3. retain no view or pointer into the caller's input;
4. provide automated normal, boundary, invalid, and regression evidence;
5. build with the required warnings and pass ASan/UBSan.

**Submitted implementation:**

```cpp
enum class ParseError { invalid_text, out_of_range };

std::expected<int, ParseError> parse_count(std::string_view text) {
    if (text.empty()) {
        return std::unexpected(ParseError::invalid_text);
    }

    int value{};
    const auto [next, error] =
        std::from_chars(text.data(), text.data() + text.size(), value);
    if (error == std::errc::invalid_argument || next != text.data() + text.size()) {
        return std::unexpected(ParseError::invalid_text);
    }
    if (error == std::errc::result_out_of_range || value < 0 || value > 100) {
        return std::unexpected(ParseError::out_of_range);
    }
    return value;
}
```

**Requirement map:**

| Requirement | Evidence |
|---|---|
| complete decimal and range | table tests for `0`, `1`, `42`, `100`, `-1`, `101`, and an integer overflow string |
| error distinction | separate expected errors for empty/partial text and numeric/domain overflow |
| no retained input | return type contains only `int` or `ParseError`; lifetime explanation states that `from_chars` pointers are not stored |
| automated coverage | table tests, the `12x` regression, and a round-trip property over every integer from 0 through 100 |
| quality | `-Wall -Wextra -Wpedantic -Werror` build and ASan/UBSan test run |

**Reproduction record:**

```text
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DROADMAP_SANITIZER=none
cmake --build build
ctest --test-dir build --output-on-failure
Result: 9/9 tests passed

cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug \
  -DROADMAP_SANITIZER=address-undefined
cmake --build build-asan
ctest --test-dir build-asan --output-on-failure
Result: 9/9 tests passed; no sanitizer finding
```

**Reasoning record:** `from_chars` was selected because the boundary is
locale-independent, non-allocating, and reports the consumed range. `stoi` was
rejected because it requires an owning string adapter and exception handling.
Stream extraction was rejected because stream state and locale add machinery this
single-field parser does not need. The learner states that `next` must equal the end
to reject partial parses and that the returned value does not depend on input
lifetime.

**Defect record:** the first version checked only `error`, so `12x` returned 12.
The failing regression showed `next != end`; the correction added the complete-input
condition. The regression remains in the nine-test suite.

**Maintenance record:** the submitted change adds one implementation file, one test
file, and no unrelated edits. The public error enum and range are documented so a
future range change has one implementation check and one table boundary to update.

## Independent Reviews

Review date: 2026-06-13

Reviewer A and Reviewer B were independent model reviewers given the same frozen
packet and rubric. Neither received the other's result before submitting.

| Dimension | Reviewer A | Reviewer B | Recorded evidence |
|---|---:|---:|---|
| Behavior | 3 | 3 | complete parse, boundary, overflow, partial-input, and lifetime outcomes are demonstrated |
| Verification | 3 | 3 | automated boundary tests, retained regression, full valid-domain property check, and sanitizer run |
| Reasoning | 3 | 3 | credible alternatives, complete-consumption rule, error policy, and lifetime are explained |
| Design and library use | 3 | 3 | focused `from_chars` and `expected` interface matches the locale-independent task |
| Evidence and maintenance | 3 | 3 | frozen identity, commands, defect history, focused diff, and extension guidance are reproducible |
| **Total** | **15/15** | **15/15** | |
| **Hard fails** | **none** | **none** | |
| **Decision** | **pass** | **pass** | |

Reviewer A asked how whitespace acceptance and a runtime-configurable upper bound
would change the contract and tests. Reviewer B asked how to classify an
overflow-length digit sequence with trailing text and how a 0-1000 range would change
the implementation and tests. These are retained as future calibration variants;
they did not change the frozen packet's score.

## Calibration Result

The reviewers:

- agreed on pass/fail;
- agreed that no hard fail applied;
- differed by 0 points, within the maximum two-point calibration threshold;
- assigned identical dimension scores.

CAL-01 therefore passes the published reviewer-calibration rule. This record
demonstrates that two independent reviewers can apply the rubric consistently to one
frozen packet. It does not certify a learner project, replace the required reviewer
for a route gate, or prove that every future pair of reviewers is calibrated. Repeat
the exercise with a failing packet and a borderline packet when the rubric changes.
