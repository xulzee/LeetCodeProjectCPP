// @Time    : 2019/2/28 10:42
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    void reverseString(string &s) {
        auto l = s.size();
        if (l > 0) {
            for (int i = 0; i <= (l - 1) / 2; ++i) {
                swap(s[i], s[l - i - 1]);
            }
        }
    }

    int reverse1(int x) {
        string temp = to_string(x);
        long long sum = 0;
        if (temp[0] == '-') {
            auto l = temp.size();
            if (l > 0) {
                for (int i = 1; i <= (l) / 2; ++i) {
                    swap(temp[i], temp[l - i]);
                }
            }
            long long weight = 1;
            for (auto j = temp.rbegin(); j < temp.rend() - 1; ++j) {
                sum += weight * ((*j) - 48); //ascii '0' is 48
                weight *= 10;
            }
            sum = -sum;
        } else {
            auto l = temp.size();
            if (l > 0) {
                for (int i = 0; i <= (l - 1) / 2; ++i) {
                    swap(temp[i], temp[l - i - 1]);
                }
            }
            long long weight = 1;
            for (auto j = temp.rbegin(); j < temp.rend(); ++j) {
                sum += weight * ((*j) - 48); //ascii '0' is 48
                weight *= 10;
            }
        }
        long long y = 1 << 31; // - 2^31
        if (sum < y || sum > -y - 1) {
            return 0;
        } else {
            return static_cast<int>(sum);
        }
    }

    int reverse(int x) {
        const int MAXINT = 0x7fffffff;
        const int MININT = 0x80000000;
        int temp = 0;
        long long sum = 0;
        while (x != 0) {
            temp = x % 10;
            sum = sum * 10 + temp;
            x /= 10;
        }
        if (sum < MININT || sum > MAXINT){
            return 0;
        }
        return static_cast<int>(sum);
    }
};

int main() {
    int target = -223124;
    cout << Solution().reverse(target) << endl;

}