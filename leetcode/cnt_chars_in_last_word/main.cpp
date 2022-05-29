#include <iostream>
#include <string>

class Solution {
   public:
    int lengthOfLastWord(std::string s) {
        if (s.length() == 0) return 0;
        int sum = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ' ')
                return sum;
            sum++;
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::string str = "sdsd 12";
    std::cout << "result = " << s.lengthOfLastWord(str) << std::endl;

    str = "sdsd sddddd 12345";
    std::cout << "result = " << s.lengthOfLastWord(str) << std::endl;
    return 0;
}
