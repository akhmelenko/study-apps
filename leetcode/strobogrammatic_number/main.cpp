#include <iostream>
#include <string>

bool IsStrobogrammatic(int number) {
    std::string str = std::to_string(number);
    // check for other numbers except 0, 1, 8, 6, 9
    for (auto c : str) {
        if (c != '0' && c != '1' && c != '8' & c != '6' && c != '9')
            return false;
    }
    // check like palindrome (with condition for 6 and 9)
    for (int i = 0, j = str.length() - 1; i <= j; i++, j--) {
        if (i == j && (str[i] == '6' || str[i] == '9'))
            return false;
        if (str[i] == '6' && str[j] == '9' || str[i] == '9' && str[j] == '6')
            continue;
        if (str[i] != str[j])
            return false;
    }
    return true;
}

int main() {
    std::cout << " 181=" << IsStrobogrammatic(181) << std::endl;
    std::cout << " 16891=" << IsStrobogrammatic(16891) << std::endl;
    std::cout << " 6918196=" << IsStrobogrammatic(6918196) << std::endl;
    std::cout << " 6918196=" << IsStrobogrammatic(6919196) << std::endl;

    return 0;
}
