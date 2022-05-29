
#include <iostream>

int main()
{
    // create array of pointers to 1d arrays
    int size = 4;
    int **M = new int *[size];
    // create 1d arrays
    for (int i = 0; i < size; i++)
        M[i] = new int[size];
    // fill 2d array
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            M[i][j] = i + j;
    return 0;
}