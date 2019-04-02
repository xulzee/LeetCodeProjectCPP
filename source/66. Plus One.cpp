//
// Created by xulzee on 2019/2/27.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../include/utils.h"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1;
        auto j = digits.size() - 1;
        while (digits[j] == 10) {
            if (j == 0) {
                digits[j] = 0;
                digits[0] = 1;
                digits.push_back(0);
                return digits;
            }
            digits[j] = 0;
            --j;
            digits[j] += 1;
        }
        return digits;
    }
};

int main() {
    vector<int> A = {9,9,9,9};
    printIntVector(Solution().plusOne(A));
}

