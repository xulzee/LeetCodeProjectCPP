// @Time    : 2019/3/30 20:20
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 线筛法
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        vector<bool> flag(n + 1, false); // false 素数， true 不是素数
        vector<int> prime;
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (!flag[i]) {
                prime.push_back(i);
                res++;
            }
            for (int j = 0; j < res; ++j) {
                if (i * prime[j] > n) {
                    break;
                }
                flag[i * prime[j]] = true;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    int test = 2;
    cout << Solution().countPrimes(test) << endl;
}

