// @Time    : 2019/3/29 11:28
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>

using namespace std;
// 假设农场中成熟的母牛每年都会生 1 头小母牛，并且永远不会死。
// 第一年有 1 只小母牛，从第二年开始，母牛开始生小母牛。
// 每只小母牛 3 年之后成熟又可以生小母牛。给定整数 N，求 N 年后牛的数量。
class Cow {
public:
    int cowNumber(int years) {
        return dynamicProcess(years);
    }

private:
    // n : 当前为第几年, 从第一年开始
    int process(int n) {
        if (n == 1 || n == 2 || n == 3 || n == 4) {
            return n;
        }
        return process(n - 1) + process(n - 3);
    }

    int dynamicProcess(int n){
        vector<int> dp(n, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 4;
        for (int i = 5; i <= n ; ++i) {
            dp[i] = dp[i-1] + dp[i - 3];
        }
        return dp[n];
    }
};


int main() {
    int years = 5;
    cout << Cow().cowNumber(years) << endl;
}

