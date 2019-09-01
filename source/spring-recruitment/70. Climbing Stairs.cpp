// @Time    : 2019/3/29 18:04
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        return dynamicProcess(n);
    }

private:
    // n : 剩余多少阶
    int process(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return process(n - 1) + process(n - 2);
    }

    int dynamicProcess(int n) {
        if (n < 1) {
            return 1;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};