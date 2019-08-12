//
// Created by liuze.xlz on 2019-08-12.
//
#include "utils.h"

class Solution {
public:
    int hammingWeight1(uint32_t n) {
        uint32_t res = 0;
        while (n > 0) {
            res += n % 2;
            n /= 2;
        }
        return res;
    }

    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            ++res;
            n &= (n - 1);
        }
        return res;
    }
};


int main() {
    cout << Solution().hammingWeight(9) << endl;
}
