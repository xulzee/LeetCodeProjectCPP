// @Time    : 2019/3/30 20:55
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <cstdint>

class Solution {
public:
    int hammingWeight1(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (n >> i) & 1 == 1 ? res + 1 : res;
        }
        return res;
    }

    int hammingWeight(uint32_t n) {
        //第一步
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        //第二步
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        //第三步
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        //第四步
        n = (n * (0x01010101) >> 24);
        return n;
    }
};
