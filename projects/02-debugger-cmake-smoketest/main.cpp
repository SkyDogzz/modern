#include <iostream>
#include <string>

int main(int arg, char** argv) {
    std::string var = "Just a random string\n";

    if (!var.c_str()) return 1;

    std::cout << var;

    return 0;
}
