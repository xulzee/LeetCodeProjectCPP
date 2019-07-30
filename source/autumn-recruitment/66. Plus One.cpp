//
// Created by liuze.xlz on 2019-07-30.
//
#include "utils.h"


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty()) {
            return {};
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] + 1 > 9) {
                digits[i] = 0;
            } else {
                ++digits[i];
                return digits;
            }
        }
        vector<int> res(digits.size(), 0);
        res.insert(res.begin(), 1);
        return res;
    }
};

int main() {
    vector<int> digits = {1,2,3};
    printIntVector(Solution().plusOne(digits));
}