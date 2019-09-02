//
// Created by liuze.xlz on 2019-08-06.
//
#include "utils.h"
#include <tuple>

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int res = nums.front();
        int sum = 0;
        for (auto &num : nums) {
            if (sum > 0) {
                sum += num;
            } else {
                sum = num;
            }
            res = max(res, sum);
        }
        return res;
    }

    int maxSubArrayWithIndex(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        tuple<int, int, int> res = {nums[0], 0, 0}; // num, start, end
        int start = 0;
        int end = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum > 0) {
                sum += nums[i];
                ++end;
            } else {
                sum = nums[i];
                start = i;
                end = i;
            }

            if (sum > get<0>(res)) {
                res = make_tuple(sum, start, end);
            }
        }
        return get<0>(res);
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Solution().maxSubArray(nums) << endl;
}
