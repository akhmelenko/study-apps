#include <iostream>

int main() {
    // unsigned int a[15][2] = {
    //     1, 2,
    //     3, 4,
    //     5, 6,
    //     7, 8,
    //     9, 10};
    // printf("%u %u %u\n\r", a, *(a + 3), *(*(a + 3) + 1));

    // What is the output of the following C code?
    // Assume that the address of x is 2000 (in decimal) and an integer requires four bytes of memory.

    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    printf("%u,%u, %u", x + 3, *(x + 3), *(x + 2) + 3);

    return 0;
}