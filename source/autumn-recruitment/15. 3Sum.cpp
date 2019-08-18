//
// Created by liuze.xlz on 2019-08-18.
//

#include "utils.h"


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    ++left;
                    --right;
                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution().threeSum(nums);
}