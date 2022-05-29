#include <iostream>

#include "allocator.h"
#include "unit_tests.h"

int main() {
    // passed config
    std::cout
        << "POOL_SIZE = " << POOL_SIZE
        << " BLOCK_SIZE = " << BLOCK_SIZE
        << " Blocks qty = " << POOL_SIZE / BLOCK_SIZE
        << std::endl;

    // start unit tests
    if (CorrectUseTest(4))
        std::cout << "CorrectUseTest passed" << std::endl;
    else
        std::cout << "CorrectUseTest faled" << std::endl;

    if (IncorrectUseTest())
        std::cout << "IncorrectUseTest passed" << std::endl;
    else
        std::cout << "IncorrectUseTest faled" << std::endl;

    return 0;
}