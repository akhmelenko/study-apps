#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
    if (!s.length())
        return true;
    // rid off not alpha characters
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            s[i] = tolower(s[i]);
        } else {
            s.erase(i, 1);
            i--;
        }
    }
    // cout << "s=" << s << endl;
    // check for palindrome
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool isPalindrome2(std::string s) {
    if (!s.length())
        return true;
    // cout << "s=" << s << endl;
    // check for palindrome
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        // check alpha and numeric i and move
        while (i < j && !isalpha(s[i]) && !isdigit(s[i]))
            i++;
        s[i] = tolower(s[i]);
        // check alpha and numeric j and move
        while (i < j && !isalpha(s[j]) && !isdigit(s[j]))
            j--;
        s[j] = tolower(s[j]);

        // check equation and move
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool isPalindrome3(std::string s) {
    if (!s.length())
        return true;
    // cout << "s=" << s << endl;
    // check for palindrome
    while (s.length()) {
        // check alpha and numeric i and move
        while (s.length() && !isalpha(s.front()) && !isdigit(s.front()))
            s.erase(s.begin());
        s.front() = tolower(s.front());
        // check alpha and numeric j and move
        while (s.length() && !isalpha(s.back()) && !isdigit(s.back()))
            s.pop_back();
        s.back() = tolower(s.back());

        // check equation and move
        if (s.length() && s.front() != s.back())
            return false;
        s.erase(s.begin());
        if (s.length())
            s.pop_back();
    }
    return true;
}

int main() {
    std::string s = "A man, a plan, a canal: Panama";
    std::cout << s << " | is palindrome=" << isPalindrome(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome2(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome3(s) << std::endl;
    s = "race a car";
    std::cout << s << " | is palindrome=" << isPalindrome(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome2(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome3(s) << std::endl;
    s = "0a";
    std::cout << s << " | is palindrome=" << isPalindrome(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome2(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome3(s) << std::endl;
    s = ".,";
    std::cout << s << " | is palindrome=" << isPalindrome(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome2(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome3(s) << std::endl;
    s = " ";
    std::cout << s << " | is palindrome=" << isPalindrome(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome2(s) << std::endl;
    std::cout << s << " | is palindrome=" << isPalindrome3(s) << std::endl;

    return 0;
}
