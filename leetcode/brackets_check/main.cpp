#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
    std::unordered_map<char, char> table{
        {'{', '}'},
        {'[', ']'},
        {'(', ')'}};

   public:
    bool isOpen(const char c) {
        for (const auto &line : table) {
            if (line.first == c)
                return true;
        }
        return false;
    }
    bool recursive0(
        std::string &s,
        char prev,
        int &n,
        int &depth) {
        // check end of string
        while (s[n] != '\0') {
            char current = s[n];
            // check open / close
            if (isOpen(current)) {
                // input recursion
                if (recursive0(s, current, ++n, ++depth) == false) {
                    return false;
                }
            } else {
                // check correct close
                if (n > 0) {
                    if (current == table[prev]) {
                        // output recursion
                        depth--;
                        n++;
                        return true;
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool recursive(
        std::string &s,
        char prev,
        int &n) {
        // check end of string
        while (s[n] != '\0') {
            char current = s[n];
            // check open / close
            if (isOpen(current)) {
                // input recursion
                if (recursive(s, current, ++n) == false) {
                    return false;
                }
            } else {
                // check correct close
                if (n > 0) {
                    if (current == table[prev]) {
                        // output recursion
                        // delete pair
                        s.erase(n - 1, 2);
                        n--;
                        return true;
                    }
                }
                return false;
            }
        }
        if (s.length())
            return false;
        return true;
    }
    bool isValid0(std::string &s) {
        int n = 0;
        return recursive(s, '0', n);
    }
    bool isValid(std::string &s) {
        std::stack<char> st;
        for (int i = 0; i < s.length(); ++i) {
            if (isOpen(s[i])) {
                st.push(s[i]);
                continue;
            }
            if (st.empty())
                return false;
            if (table[st.top()] == s[i])
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};

class TestStatic {
   public:
    static void HelloWorld() {
        std::cout << "Hello world" << std::endl;
    }
};

void foo() {
    int j = 0;
    for (int i = 0; i < j; ++i, j = j + j) {
        std::cout << "!" << std::endl;
    }
}

int main() {
    TestStatic::HelloWorld();
    Solution s;
    std::string str = "(";
    std::cout << "result = " << s.isValid(str) << std::endl;
    str = "()[]{}";
    std::cout << "result = " << s.isValid(str) << std::endl;
    str = "(]";
    std::cout << "result = " << s.isValid(str) << std::endl;
    str = "([)]";
    std::cout << "result = " << s.isValid(str) << std::endl;
    str = "{[]}";
    std::cout << "result = " << s.isValid(str) << std::endl;

    return 0;
}

/*
"()"
"()[]{}"
"(]"
"([)]"
"{[]}"


true
true
false
false
true
*/