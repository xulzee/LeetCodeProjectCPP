//
// Created by liuze.xlz on 2019-09-06.
//
#include "utils.h"

class Solution {
public:
    bool PredictTheWinner(vector<int> &nums) {
        return DynamicProcess(nums);
    }

    int Process(vector<int> &nums, int i, int j) { // 从i到j,先手取比后手多的最大分数
        if (i == j) {
            return nums[i];
        }
        return max(nums[i] - Process(nums, i + 1, j), nums[j] - Process(nums, i, j - 1));
    }


    bool DynamicProcess(vector<int> &nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i; j < nums.size(); ++j) {
                if (i == j) {
                    dp[i][j] = nums[i];
                } else {
                    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
                }
            }
        }
        return dp.front().back() > 0;
    }
};

int main() {
    vector<int> nums = {1, 5, 2};
    Solution().PredictTheWinner(nums);
}

