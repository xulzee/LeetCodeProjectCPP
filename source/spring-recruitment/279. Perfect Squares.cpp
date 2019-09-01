// @Time    : 2019/4/15 14:40
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <queue>
#include <math.h>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        deque<bool> usedNumber(n + 1, false);
        usedNumber[n] = true;
        queue<pair<int, int>> numQueue; // num - step
        numQueue.push(make_pair(n, 0));
        while (!numQueue.empty()) {
            pair<int, int> cur = numQueue.front();
            numQueue.pop();
            for (int i = 1;; ++i) {
                int next = cur.first - i * i;
                if (next < 0) {
                    break;
                }
                if (next == 0) {
                    return cur.second + 1;
                }
                if (!usedNumber[next]) {
                    numQueue.push(make_pair(next, cur.second + 1));
                    usedNumber[next] = true;
                }
            }
        }
        return -1;
    }

    int process(int n) {
        if (n == 0) {
            return 0;
        }
        int ret = INT_MAX;
        for (int i = 1; i * i <= n; ++i) {
            ret = min(ret, process(n - i * i));
        }
        return ret + 1;
    }

    int dynamicProcess(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int ret = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                ret = min(ret, dp[i - j * j]);
            }
            dp[i] = ret + 1;
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().dynamicProcess(12);
}