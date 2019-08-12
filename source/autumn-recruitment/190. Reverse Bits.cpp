//
// Created by liuze.xlz on 2019-08-12.
//
#include "utils.h"

class Solution {
public:
    uint32_t reverseBits1(uint32_t n) {
        string res;
        while (n > 0) {
            res += to_string(n % 2);
            n /= 2;
        }

        while (res.size() < 32) {
            res += "0";
        }

        char *end;
        auto ret = strtol(res.c_str(), &end, 2);
        return ret;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res <<= 1;
            res += (n & 1);
            n >>= 1;
        }
        return res;
    }
};

int main() {
    cout << Solution().reverseBits(8) << endl;
}

