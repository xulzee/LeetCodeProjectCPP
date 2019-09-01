// @Time    : 2019/4/15 16:17
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp = {nums.front()};
        for (const auto &num : nums) {
            if (num > dp.back()) {
                dp.push_back(num);
            } else if (num < dp.back()) {
                auto pos = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
                dp[pos] = num;
            } else {
                continue;
            }
        }
        return dp.size();
    }

    int _lengthOfLIS(vector<int> &nums) {
        return dynamicProcess(nums);
    }

    int process(vector<int> &arr, int cur) {
        if (cur == 0) {
            return 1;
        }
        int ret = 1;
        for (int i = cur; i >= 0; --i) {
            if (arr[i] < arr[cur]) {
                ret = max(ret, process(arr, i) + 1);
            }
        }
        return ret;
    }

    int dynamicProcess(vector<int> &arr) {
        vector<int> dp(arr.size(), 0);
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < arr.size(); ++i) {
            int ret = 1;
            for (int j = i; j >= 0; --j) {
                if (arr[j] < arr[i]) {
                    ret = max(ret, dp[j] + 1);
                }
            }
            dp[i] = ret;
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main() {
    vector<int> test = {4, 10, 4, 3, 8, 9};
    cout << Solution().lengthOfLIS(test);
}