#include <iostream>

int main() {
    std::cout << "Modern C++23 roadmap\n";

    std::string a_local_variable = "Here we come\n";
    if (!a_local_variable.c_str()) return 1;

    std::cout << a_local_variable;
    return 0;
}

// compile: c++ --std=c++23 -Wall -Wextra -Werror -Wpedantic main.cpp
// run: ./a.out
