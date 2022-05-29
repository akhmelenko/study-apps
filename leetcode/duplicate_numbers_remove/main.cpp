#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>



int main() {
    TestStatic::HelloWorld();
    Solution s;
    std::string str = "(";
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