//
// Created by liuze.xlz on 2019-07-30.
//

class Solution {
public:
    bool containsDuplicate1(vector<int> &nums) {
        unordered_set<int> nums_set;
        for (const auto &item : nums) {
            if (nums_set.find(item) != nums_set.end()) {
                return true;
            }
            nums_set.insert(item);
        }
        return false;
    }

    bool containsDuplicate(vector<int> &nums) {
        if (nums.empty()) {
            return false;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};