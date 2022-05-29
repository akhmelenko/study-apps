#include <iostream>

int main()
{
    int sum = 1;
    char *p = (char *)malloc(sizeof(char));

    std::cout << "*p =" << (int)*p << " *p++ =" << (int)*p++ << "\n";
    /* ... */
    sum = '0' - (*p++ = getchar());

    std::cout << "sum =" << sum << " *p++ =" << (int)*p << "\n";

    return 0;
};
