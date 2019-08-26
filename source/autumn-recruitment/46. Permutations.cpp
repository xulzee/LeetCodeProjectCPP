//
// Created by liuze.xlz on 2019-08-24.
//

#include "utils.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> cur_nums;
        visited_.assign(nums.size(), 0);
        backtrack(nums, 0);
        return res_;
    }


    void backtrack1(vector<int> &nums, vector<int> &cur_nums, int len) {
        if (len >= nums.size()) {
            res_.push_back(cur_nums);
            return;
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (visited_[j] == 0) {
                visited_[j] = 1;
                cur_nums.push_back(nums[j]);
                backtrack1(nums, cur_nums, len + 1);
                cur_nums.pop_back();
                visited_[j] = 0;
            }
        }
    }

    void backtrack(vector<int> &nums, int i) {
        if (i == nums.size())
            res_.push_back(nums);
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

private:
    vector<vector<int>> res_;
    vector<int> visited_;
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution().permute(nums);
}

