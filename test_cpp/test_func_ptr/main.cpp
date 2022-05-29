#include <array>
#include <iostream>
#include <vector>

void Print1() {
    std::cout << "1" << std::endl;
}

void Print2() {
    std::cout << "2" << std::endl;
}

void Print3() {
    std::cout << "3" << std::endl;
}

int main() {
    // typedef void (*p)();
    // std::array<void (*)(), 3> functions = {Print1, Print2, Print3};
    void (*functions[3])() = {Print1, Print2, Print3};

    for (int i = 0; i < 3; ++i) {
        functions[i]();
    }

    for (const auto func : functions)
        func();

    return 0;
}