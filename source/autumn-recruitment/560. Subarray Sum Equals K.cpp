//
// Created by liuze.xlz on 2019-09-03.
//
#include "utils.h"

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        int sum = 0;
        int res = 0;
        map[0] = 1;
        for (int num : nums) {
            sum += num;
            int target = sum - k;
            if (map.find(target) != map.end()) {
                res += map[target];
            }

            if (map.find(sum) == map.end()) {
                map[sum] = 1;
            } else {
                ++map[sum];
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << Solution().subarraySum(nums, 0) << endl;
}