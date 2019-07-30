//
// Created by liuze.xlz on 2019-07-30.
//
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res = {};
        unordered_map<int, int> nums_map;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums_map.find(target - nums[i]) != nums_map.end() && i != nums_map[target - nums[i]]) {
                return res = {nums_map[target - nums[i]], i};
            }else{
                nums_map[nums[i]] = i;
            }
        }
        return res;
    }
};
