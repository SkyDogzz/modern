#include <iostream>
#include <version>

#if defined(ROADMAP_EXPECT_GCC14)

#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ != 14
#error "The GCC CI profile requires GCC major version 14"
#endif

#if !defined(_GLIBCXX_RELEASE) || _GLIBCXX_RELEASE != 14
#error "The GCC CI profile requires libstdc++ major version 14"
#endif

#elif defined(ROADMAP_EXPECT_CLANG18_LIBCPP18)

#if !defined(__clang__) || __clang_major__ != 18
#error "The Clang CI profile requires Clang major version 18"
#endif

#if !defined(_LIBCPP_VERSION) || _LIBCPP_VERSION < 180000 || _LIBCPP_VERSION >= 190000
#error "The Clang CI profile requires libc++ major version 18"
#endif

#else
#error "Select one ROADMAP_EXPECT_* toolchain profile"
#endif

int main() {
#if defined(ROADMAP_EXPECT_GCC14)
    std::cout << "gcc=" << __GNUC__ << '.' << __GNUC_MINOR__
              << " libstdc++=" << _GLIBCXX_RELEASE << '\n';
#else
    std::cout << "clang=" << __clang_major__ << '.' << __clang_minor__
              << " libc++=" << _LIBCPP_VERSION << '\n';
#endif
}
