// @Time    : 2019/3/31 14:17
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        return dynamicProcess2(K, N);
    }

private:
    int process(int K, int N) {
        if (K == 1 || N == 0 || N == 1) {
            return N;
        }
        // 策略：遍历所有情况，找到最小值
        int minimum = N;
        for (int i = 1; i <= N; ++i) {
            int ret = 1 + max(process(K, N - i), process(K - 1, i - 1));
            minimum = minimum < ret ? minimum : ret;
        }
        return minimum;
    }


    // O(KN^2)
    int dynamicProcess(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        for (int i = 0; i <= K; ++i) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for (int j = 0; j <= N; ++j) {
            dp[1][j] = j;
        }
        for (int k = 2; k <= K; ++k) {
            for (int n = 2; n <= N; ++n) {
                int minimum = n;
                for (int i = 1; i < n; ++i) {// i = 0 时 dp[k][0]后面的值应当是无穷大的，因为永远不能可能找到
                    minimum = min(minimum, 1 + max(dp[k][n - i], dp[k - 1][i - 1]));
                }
                dp[k][n] = minimum;
            }
        }
        return dp[K][N];
    }

    // dp[k][m] -> k 个鸡蛋在 m 步内可以测多少层
    int process2(int K, int M) {
        if (M == 0 || K == 0){
            return 0;
        }
        if (K == 1){
            return M;
        }
        return process2(K - 1, M - 1) + process2(K, M - 1) + 1;
    }

    int dynamicProcess2(int K, int N){
       vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        for (int i = 0; i <= K; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= N; ++i) {
            dp[0][i] = 0;
            dp[1][i] = i;
        }
        for (int m = 1; m <= N; ++m) {
            for (int k = 1; k <= K; ++k){
                dp[k][m] = 1 + dp[k - 1][m - 1] + dp[k][m - 1];
                if (dp[k][m] >= N){
                    return m;
                }
            }
        }
        return N;
    }
};

int main() {
    int k = 2, n = 6;
    cout << Solution().superEggDrop(k, n) << endl;
}