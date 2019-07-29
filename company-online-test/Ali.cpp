// @Time    : 2019/3/28 18:19
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class solution {
public:
    // n : 一共有 1 ~ n个位置
    // p ： 最终目标是要到达 p 位置
    // m :  初始时所在位置
    // k ： 可以走 k 步
    int ways(int n, int p, int m, int k) {
        if (n < 2 || p < 1 || p > n || m < 1 || m > n || k < 1) {
            return 0;
        }
        process(n, p, m, k);
    }

    // n : 一共有 1 ~ n个位置
    // p ： 最终目标是要到达 p 位置
    // current_position : 当前所在位置
    // rest_step : 剩余步数
    int process(int n, int p, int current_position, int rest_step) {
        if (rest_step == 0) {
            return current_position == p ? 1 : 0;
        }
        if (current_position == 1) {
            return process(n, p, 2, rest_step - 1);
        } else if (current_position == n) {
            return process(n, p, n - 1, rest_step - 1);
        } else {
            return process(n, p, current_position + 1, rest_step - 1) +
                   process(n, p, current_position - 1, rest_step - 1);
        }
    }

    int dynamicprocess(int n, int p, int m, int k) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        dp[0][p] = 1;
        for (int i = 1; i <= k; ++i) { // step
            for (int j = 1; j <= n; ++j) {
                if (j == 1) {
                    dp[i][j] = dp[i - 1][j + 1];
                } else if (j == n) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
                }
            }
        }
        return dp[k][m];
    }
};


int main() {
    cout << solution().process(100, 50, 40, 210) << endl;
    cout << solution().dynamicprocess(100, 50, 40, 210) << endl;
}
