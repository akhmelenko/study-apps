#include <iostream>
#include <string>

bool PermutedToPalindrome(std::string &str) {
    if (!str.length())
        return false;
    int hash[26] = {0};
    for (auto c : str)
        hash[c - 'a']++;
    bool center = false;
    for (int i = 0; i < 26; i++) {
        if (hash[i] % 2 != 0) {
            if (center == true)
                return false;
            else
                center = true;
        }
    }
    return true;
}

int main() {
    std::string str{"ppa"};
    std::cout << " PermutedToPalindrome = " << PermutedToPalindrome(str) << std::endl;
    str = "ppana";
    std::cout << " PermutedToPalindrome = " << PermutedToPalindrome(str) << std::endl;
    str = "pppanan";
    std::cout << " PermutedToPalindrome = " << PermutedToPalindrome(str) << std::endl;
    str = "pppanana";
    std::cout << " PermutedToPalindrome = " << PermutedToPalindrome(str) << std::endl;

    return 0;
}
