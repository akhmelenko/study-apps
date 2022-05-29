#include <iostream>

std::string convertToTitle(int columnNumber) {
    std::string str = "";
    while (columnNumber) {
        if (columnNumber % 26 == 0) {
            str = "Z" + str;
            columnNumber--;
        } else {
            str = char((columnNumber % 26) + 'A' - 1) + str;
        }
        columnNumber /= 26;
    }
    return str;
}

int main() {
    std::cout << convertToTitle(53) << std::endl;

    return 0;
}
