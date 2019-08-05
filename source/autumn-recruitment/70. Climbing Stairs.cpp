//
// Created by liuze.xlz on 2019-08-05.
//
#include "utils.h"

class Solution {
public:
    int process(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return process(n - 1) + process(n - 2);
    }

    int dynamicProcess(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        return dynamicProcess(n);
    }
};

int main() {
    cout << Solution().climbStairs(3) << endl;
}
