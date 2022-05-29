#include <iostream>

struct TEST {
    int intVar0;
    int intVar1;
    char charVar0;
};

void C_malloc() {
    printf("\n==========C malloc======\n\r");
    // start of allocating array C
    int* pArray = (int*)malloc(5 * sizeof(int));

    // read allocated memoty
    for (int i = 0; i < 5; ++i)
        printf("elem[%d] = %d\n\r", i, *(pArray + i));

    // fill allocated memoty
    for (int i = 0; i < 5; ++i)
        *(pArray + i) = i * 2;

    // read filled memory
    for (int i = 0; i < 5; ++i)
        printf("elem[%d] = %d\n\r", i, *(pArray + i));

    delete[] pArray;
}

void Cpp_new() {
    std::cout << "\n==========Cpp new======\n\r";
    // start of allocating array C
    int* pArray = new int[5];

    // read allocated memoty
    for (int i = 0; i < 5; ++i)
        std::cout << "elem[" << i << "] = " << *(pArray + i) << std::endl;

    // fill allocated memoty
    for (int i = 0; i < 5; ++i)
        *(pArray + i) = i * 3;

    // read filled memory
    for (int i = 0; i < 5; ++i)
        std::cout << "elem[" << i << "] = " << *(pArray + i) << std::endl;

    free(pArray);
}

int main() {
    C_malloc();
    Cpp_new();

    return 0;
}