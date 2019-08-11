//
// Created by liuze.xlz on 2019-08-11.
//
#include "utils.h"

class Solution {
public:
    Solution(vector<int> &nums) {
        origin_nums = nums;
        nums_backup = nums;
        srand(time(nullptr));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        origin_nums.clear();
        origin_nums = nums_backup;
        return origin_nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < origin_nums.size(); ++i) {
            int index = rand() % (origin_nums.size() - i ) + i;
            swap(origin_nums[i], origin_nums[index]);
        }
        return origin_nums;
    }

private:
    vector<int> origin_nums;
    vector<int> nums_backup;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
