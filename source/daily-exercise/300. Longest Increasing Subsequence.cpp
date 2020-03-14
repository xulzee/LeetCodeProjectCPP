//
// Created by xulzee on 2020/3/14.
//

#include "utils.h"

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()){
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int max_val = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                max_val = max(max_val, dp[j]);
            }
            dp[i] = max_val + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(nums) << endl;
}