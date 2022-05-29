#include <iostream>

struct TEST {
    int intVar0;
    int intVar1;
    char charVar0;
};

struct COLUMN {
    uint8_t column : 4;
    uint8_t column2 : 4;
};

struct MATRIX {
    struct COLUMN columns[4];
};

int main() {
    printf("TEST struct size = %d\n\r", (int)sizeof(struct TEST));
    printf("TEST struct size = %d\n\r", (int)sizeof(struct COLUMN));
    printf("TEST struct size = %d\n\r", (int)sizeof(struct MATRIX));

    return 0;
}