// @Time    : 2019/3/2 19:08
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include "utils.h"

using namespace std;

class Solution {
public:
    int getnext(const string &str, int pos, char sign) {
        string nums = "";
        int INTMAX = 0x7fffffff;
        int INTMIN = 0x80000000;
        for (auto i = pos; i < str.length(); ++i) {
            if (str[i] < '0' or str[i] > '9') {
                break;
            }
            nums = nums + str[i];
        }
        int length = 0;
        for (auto i = 0; i < nums.length(); ++i) {
            if (nums[i] != ' ' and nums[i] != '0') {
                break;
            }
            length ++;
        }
        nums = nums.substr(length, nums.length() - length);


        int num = 0;
        if (nums == "") {
            return 0;
        }
        if (sign == '-') {
            long long weight = 1;
            for (int j = static_cast<int>(nums.length() - 1); j >= 0; --j) {
                if (num <= INTMIN + (nums[j] - '0') * weight || weight > INTMAX) {
                    return INTMIN;
                }
                num -= (nums[j] - '0') * weight;
                weight *= 10;
            }
        } else if (sign == '+') {
            long long weight = 1;
            for (int j = static_cast<int>(nums.length() - 1); j >= 0; --j) {
                if (num >= INTMAX - (nums[j] - '0') * weight || weight > INTMAX) {
                    return INTMAX;
                }
                num += (nums[j] - '0') * weight;
                weight *= 10;
            }
        }
        return num;
    }

    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        int INTMAX = 0x7fffffff;
        int INTMIN = 0x80000000;

        for (auto i = 0; i < str.length(); ++i) {
            if (str[i] != ' ') {
                str = str.substr(i, str.length() - i);
                break;
            }
        }

        long long num = 0;
        if (str[0] == '-') {
            num = getnext(str, 1, '-');
        } else if (str[0] == '+') {
            num = getnext(str, 1, '+');
        } else if (str[0] >= '0' and str[0] <= '9') {
            num = getnext(str, 0, '+');
        } else {
            return 0;
        }
        if (num < INTMIN) {
            num = INTMIN;
        }
        if (num > INTMAX) {
            num = INTMAX;
        }

        return static_cast<int>(num);
    }
};

int main() {
    string A = "    0000000000000   ";
    cout << Solution().myAtoi(A) << endl;
}
