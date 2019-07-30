//
// Created by liuze.xlz on 2019-07-30.
//
#include "utils.h"

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
        }

        for (int k = i; k < nums.size(); ++k) {
            nums[k] = 0;
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution().moveZeroes(nums);
    printIntVector(nums);
}