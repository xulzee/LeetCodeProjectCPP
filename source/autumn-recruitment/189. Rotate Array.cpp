//
// Created by liuze.xlz on 2019-07-30.
//

class Solution {
public:
    // O ( k * n )
    void rotate1(vector<int> &nums, int k) {
        if (nums.empty()) {
            return;
        }
        for (int i = 0; i < k; ++i) {
            for (size_t j = nums.size() - 1; j > 0; --j) {
                swap(nums[j], nums[j - 1]);
            }
        }
    }

    // O ( n )
    void rotate(vector<int> &nums, int k){
        if (nums.empty()){
            return;
        }
        k = k % (nums.size());
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};