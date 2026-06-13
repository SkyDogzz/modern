#pragma once

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace roadmap::test {

using TestFunction = void (*)();

struct TestCase {
    std::string_view name;
    TestFunction function;
};

inline auto registry() -> std::vector<TestCase>& {
    static std::vector<TestCase> cases;
    return cases;
}

class Registrar {
public:
    Registrar(std::string_view name, TestFunction function) {
        registry().push_back(TestCase{name, function});
    }
};

inline void require(
    bool condition,
    std::string_view expression,
    std::string_view file,
    int line) {
    if (!condition) {
        throw std::runtime_error(
            std::string{file} + ":" + std::to_string(line) +
            ": requirement failed: " + std::string{expression});
    }
}

inline int run_all() {
    int failures{0};

    for (const auto& test_case : registry()) {
        try {
            test_case.function();
            std::cout << "[pass] " << test_case.name << '\n';
        } catch (const std::exception& error) {
            ++failures;
            std::cerr << "[fail] " << test_case.name << ": "
                      << error.what() << '\n';
        } catch (...) {
            ++failures;
            std::cerr << "[fail] " << test_case.name
                      << ": unknown exception\n";
        }
    }

    return failures == 0 ? 0 : 1;
}

}  // namespace roadmap::test

#define ROADMAP_TEST_CONCAT_INNER(left, right) left##right
#define ROADMAP_TEST_CONCAT(left, right) ROADMAP_TEST_CONCAT_INNER(left, right)
#define ROADMAP_TEST_CASE_IMPL(name, line)                                    \
    static void ROADMAP_TEST_CONCAT(roadmap_test_function_, line)();         \
    static ::roadmap::test::Registrar                                        \
        ROADMAP_TEST_CONCAT(roadmap_test_registrar_, line){                  \
            name, ROADMAP_TEST_CONCAT(roadmap_test_function_, line)};        \
    static void ROADMAP_TEST_CONCAT(roadmap_test_function_, line)()
#define ROADMAP_TEST_CASE(name) ROADMAP_TEST_CASE_IMPL(name, __LINE__)
#define ROADMAP_REQUIRE(expression)                                           \
    ::roadmap::test::require(                                                 \
        static_cast<bool>(expression), #expression, __FILE__, __LINE__)
