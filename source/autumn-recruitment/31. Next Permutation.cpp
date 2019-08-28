//
// Created by liuze.xlz on 2019-08-28.
//
#include "utils.h"

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1) {
            return;
        }

        int index = 0;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                index = i;
                break;
            }
        }

        reverse(nums.begin() + index, nums.end());
        if (index != 0) {
            --index;
            auto item = upper_bound(nums.begin() + index, nums.end(), nums[index]);
            swap(nums[index], *item);
        }
    }
};

int main() {
//    vector<int> nums = {1, 5, 8, 4, 7, 6, 5, 3, 1};
    vector<int> nums = {2, 1};
    Solution().nextPermutation(nums);
    printIntVector(nums);
}
