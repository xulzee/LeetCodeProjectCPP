//
// Created by liuze.xlz on 2019-08-06.
//
#include "utils.h"

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = nums[0];
        int sum = 0;
        for (int num : nums) {
            if (sum > 0){
                sum += num;
            } else{
                sum = num;
            }
            res = max(res, sum);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Solution().maxSubArray(nums) << endl;
}
