//
// Created by liuze.xlz on 2019-07-30.
//

#include "utils.h"

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        string x_std = to_string(x);
        bool is_positive = true;
        if (x_std.front() == '-') {
            x_std = x_std.substr(1, x_std.size() - 1);
            is_positive = false;
        }

        if (is_positive) {
            for (auto i = x_std.rbegin(); i != x_std.rend(); ++i) {
                if (res > (INT32_MAX - (*i - '0')) / 10) {
                    return 0;
                } else {
                    res = res * 10 + (*i - '0');
                }
            }
        } else{
            for (auto i = x_std.rbegin(); i != x_std.rend(); ++i) {
                if (res < (INT32_MIN + (*i - '0')) / 10) {
                    return 0;
                } else {
                    res = res * 10 - (*i - '0');
                }
            }
        }

        return res;
    }
};

int main() {
    int x = 1534236469;
    cout << Solution().reverse(x) << endl;
}