#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maxSubArray0(std::vector<int>& nums) {
        std::vector<int> count(nums.size());
        int res;
        count[0] = nums[0];
        res = count[0];
        for (int i = 1; i < nums.size(); i++) {
            count[i] = std::max(count[i - 1] + nums[i], nums[i]);
            std::cout << "count[i]=" << count[i] << std::endl;
            if (count[i] > res)
                res = count[i];
        }
        return res;
    }
    int maxSubArray(std::vector<int>& nums) {
        // std::vector<int> count(nums.size());
        int currentSum;
        int res;
        currentSum = nums[0];
        res = currentSum;
        for (int i = 1; i < nums.size(); i++) {
            currentSum = std::max(currentSum + nums[i], nums[i]);
            std::cout << "currentSum=" << currentSum << std::endl;
            if (currentSum > res)
                res = currentSum;
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "result = " << s.maxSubArray(nums) << std::endl;
    std::vector<int> nums1 = {1};
    std::cout << "result = " << s.maxSubArray(nums1) << std::endl;
    std::vector<int> nums2 = {5, 4, -1, 7, 8};
    std::cout << "result = " << s.maxSubArray(nums2) << std::endl;
    std::vector<int> nums3 = {-1, 2, 3, -4, 5, -1, 8, -1};
    std::cout << "result = " << s.maxSubArray(nums3) << std::endl;

    return 0;
}

/*
[-2,1,-3,4,-1,2,1,-5,4]
[1]
[5,4,-1,7,8]
*/