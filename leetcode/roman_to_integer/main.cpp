#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>

class Solution {
    std::unordered_map<char, int> table{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

   public:
    int romanToInt0(std::string s) {
        int n = 0;
        int number = 0;
        while (s[n] != '\0') {
            int currentVal = table[s[n]];
            // check for reducer
            if (s[n + 1] != '\0') {
                int nextVal = table[s[n + 1]];
                if (currentVal < nextVal) {
                    number += nextVal - currentVal;
                    n = n + 2;
                    continue;
                }
            }
            number += currentVal;
            n++;
        }
        return number;
    }
    int romanToInt(std::string s) {
        int number = 0;
        int prevVal = 0;
        for (int n = s.length(); n >= 0; --n) {
            int currentVal = table[s[n]];
            if (prevVal > currentVal)
                number -= currentVal;
            else
                number += currentVal;
            prevVal = currentVal;
        }
        return number;
    }
};

int main() {
    Solution s;
    std::string romanString = "XIV";
    int result = s.romanToInt(romanString);
    std::cout << "input = " << romanString << ", result = " << result << std::endl;

    return 0;
}