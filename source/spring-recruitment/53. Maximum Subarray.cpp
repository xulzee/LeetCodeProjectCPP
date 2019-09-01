//
// Created by xulzee on 2019/3/29.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        return dynamicProcess(nums);
    }

private:
    // 以第i个数结尾的最大子序和
    int process(vector<int> &nums, int i) {
        if (i == 0) {
            return nums[0];
        }
        return max(nums[i], nums[i] + process(nums, i - 1));
    }

    int dynamicProcess(vector<int> &nums){
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int j = 1; j < nums.size(); ++j) {
            dp[j] = max(nums[j], nums[j] + dp[j - 1]);
            res = max(dp[j], res);
        }
        return res;
    }
};

int main() {
    vector<int> test = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Solution().maxSubArray(test);
}
