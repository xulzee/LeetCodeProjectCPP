//
// Created by liuze.xlz on 2019-08-17.
//

#include "utils.h"

class Solution {
public:
    int myAtoi(string str) {
        // trim left space
        str.erase(str.begin(), find_if(str.begin(), str.end(), [](int ch) { return !isspace(ch); }));

        // get sign and trim sign
        bool sign = true;
        if (str.front() == '-') {
            sign = false;
            str.erase(str.begin());
        }else if (str.front() == '+') {
            sign = true;
            str.erase(str.begin());
        }


        // get num (string)
        size_t index = 0;
        for (index = 0; index < str.size(); ++index) {
            if (str[index] < '0' || str[index] > '9') {
                break;
            }
        }
        str = str.substr(0, index);

        // get numeric result
        int res = 0;
        if (sign) {
            for (auto iter = str.begin(); iter != str.end(); ++iter) {
                if (res > (INT32_MAX - (*iter - '0')) / 10) {
                    res = INT32_MAX;
                    break;
                } else {
                    res = res * 10 + (*iter - '0');
                }
            }
        } else {
            for (auto iter = str.begin(); iter != str.end(); ++iter) {
                if (res < (INT32_MIN + (*iter - '0')) / 10) {
                    res = INT32_MIN;
                    break;
                } else {
                    res = res * 10 - (*iter - '0');

                }
            }
        }
        return res;
    }
};

int main() {
    Solution().myAtoi("  -0000000000012345678");
}

