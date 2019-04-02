// @Time    : 2019/3/30 15:01
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        return dynamicProcess(nums);
    }

private:
    //i 表示第 i个数
    int process(vector<int> &nums, int i) {
        if (i < 0) {
            return 0;
        }
        return max(nums[i] + process(nums, i - 2), process(nums, i - 1));
    }

    int dynamicProcess(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};