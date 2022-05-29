#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int searchInsert0(vector<int>& nums, int target) {
        if (target < nums[0])
            return 0;
        if (target > nums[nums.size() - 1])
            return nums.size();
        int min = 0;
        int max = nums.size() - 1;
        int middle;
        while (min <= max) {
            middle = (max + min) / 2;
            // cout << target << ":" << min << " " << middle << " " << max << endl;
            if (target == nums[middle]) {
                // cout << middle << endl;
                return middle;
            } else if (target < nums[middle])
                max = middle - 1;
            else
                min = middle + 1;
        }
        // int ret = nums[middle] > target ? middle : middle + 1;
        // cout << ret << endl;
        return nums[middle] > target ? middle : middle + 1;
    }
    int searchInsert(std::vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        return std::distance(nums.begin(), it);
    }
};

int main() {
    Solution s;
    std::vector<int> nums{1, 3, 5, 6};
    std::cout << "result = " << s.searchInsert(nums, 5) << std::endl;
    std::cout << "result = " << s.searchInsert(nums, 2) << std::endl;
    std::cout << "result = " << s.searchInsert(nums, 7) << std::endl;
    std::cout << "result = " << s.searchInsert(nums, 0) << std::endl;
    nums.clear();
    nums.push_back(1);
    std::cout << "result = " << s.searchInsert(nums, 0) << std::endl;

    return 0;
}

/*
[1,3,5,6]
5
[1,3,5,6]
2
[1,3,5,6]
7
[1,3,5,6]
0
[1]
0
*/