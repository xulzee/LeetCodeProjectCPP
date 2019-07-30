//
// Created by liuze.xlz on 2019-07-30.
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (const auto &num : nums){
            res ^= num;
        }
        return res;
    }
};

