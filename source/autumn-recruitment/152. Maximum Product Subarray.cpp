//
// Created by liuze.xlz on 2019-09-02.
//
#include "utils.h"

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int cur_max = 1;
        int cur_min = 1;
        int res = INT32_MIN;
        for (auto &num : nums) {
            if (num < 0) {
                swap(cur_max, cur_min);
            }
            cur_max = max(cur_max * num, num);
            cur_min = min(cur_min * num, num);

            res = max(res, cur_max);
        }
        return res;
    }
};
