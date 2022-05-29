#include <iostream>

class Base {
   public:
    Base(int i, int j) = delete;
    Base() {
        std::cout << "Correct empty constr" << std::endl;
    }
    Base(int i) {
        std::cout << "Correct 1 arg constr" << std::endl;
    }
};

int main() {
    Base baseEmpty{};
    Base baseOneArg{5};
    // Base baseTwoArg{5, 6};

    Base* pBase = new Base();
    Base b0;
    Base b1();
    Base b2(0);

    return 0;
}