//
// Created by liuze.xlz on 2019-08-11.
//
#include "utils.h"
#include <regex>
#include <cmath>

//迭代实现
void ConvertIteration(string &s, int n, int base) {
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};//新进制下的数位
    while (n > 0) {
        int remainder = int(n % base);
        s += (digit[remainder]);
        n /= base;
    }
    reverse(s.begin(), s.end());
}

class Solution {
public:
    bool isPowerOfThree1(int n) {
        if (n < 1) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }

    bool isPowerOfThree2(int n) {
        if (n < 1) {
            return false;
        }
        string str;
        ConvertIteration(str, n, 3);
        regex re = regex("^10*$");
        return regex_match(str, re);
    }

    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }
        int x = log(INT32_MAX) / log(3);
        int y = pow(3, x);
        return y % n == 0;
    }
};

int main() {
    cout << Solution().isPowerOfThree(3) << endl;
}
