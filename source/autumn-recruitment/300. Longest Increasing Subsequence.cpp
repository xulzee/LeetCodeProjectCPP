//
// Created by liuze.xlz on 2019-08-26.
//
#include "utils.h"

class Solution {
public:
    // [10,9,2,5,3,7,101,18] -> [2,3,7,101]
    int lengthOfLIS(vector<int> &nums) {
        return BinaryDynamicProcess(nums);
    }

    int process(vector<int> &nums, int cur) {
        int ret = 1;
        for (int i = cur - 1; i >= 0; --i) {
            if (nums[i] < nums[cur]) {
                ret = max(ret, 1 + process(nums, i));
            }
        }
        return ret;
    }

    int DynamicProcess(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, 1);
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int ret = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    ret = max(ret, 1 + dp[j]);
                }
            }
            dp[i] = ret;
            res = max(res, ret);
        }
        return res;
    }

    int BinaryDynamicProcess(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        int res = 0;
        for (auto &num : nums) {
            int i = lower_bound(dp.begin(), dp.begin() + res, num) - dp.begin();
            dp[i] = num;
            if (i == res){
                ++res;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0, 8, 4, 12, 2};
//    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(nums) << endl;
}

