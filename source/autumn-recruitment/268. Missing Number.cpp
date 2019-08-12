//
// Created by liuze.xlz on 2019-08-12.
//
#include "utils.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return nums.size() * (1 + nums.size()) / 2 - sum;
    }
};
