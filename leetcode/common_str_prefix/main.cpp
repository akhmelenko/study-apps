#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::string longestCommonPrefix0(const std::vector<std::string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        std::string prefix = "";
        int n = 0;
        for (const auto& c : strs[0]) {
            for (const auto& str : strs) {
                if (c != str[n])
                    return prefix;
            }
            prefix += c;
            n++;
        }
        return prefix;
    }
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        std::string prefix = "";
        int n = 0;
        for (const auto& c : strs[0]) {
            for (int k = 1; k < strs.size(); ++k) {
                if (c != strs[k][n])
                    return prefix;
            }
            prefix += c;
            n++;
        }
        return prefix;
    }
};

int main() {
    Solution s;
    std::vector<std::string> strs = {"flower", "flower", "flower"};
    std::cout << "result = " << s.longestCommonPrefix(strs) << std::endl;

    return 0;
}