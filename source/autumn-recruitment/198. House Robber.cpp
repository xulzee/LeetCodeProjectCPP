//
// Created by liuze.xlz on 2019-08-06.
//
#include "utils.h"

class Solution {
public:
    int process(vector<int> &nums, int cur) {
        if (cur >= nums.size()) {
            return 0;
        }
        return max(nums[cur] + process(nums, cur + 2), process(nums, cur + 1));
    }

    int dynamicProcess(vector<int> &nums) {
        vector<int> dp(nums.size() + 2, 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }

    int rob(vector<int> &nums) {
        return dynamicProcess(nums);
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << Solution().rob(nums) << endl;
}