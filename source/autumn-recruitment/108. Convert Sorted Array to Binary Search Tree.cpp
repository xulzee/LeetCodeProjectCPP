//
// Created by liuze.xlz on 2019-08-14.
//
#include "utils.h"

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return Helper(nums, 0, nums.size() - 1);
    }

    TreeNode *Helper(vector<int> &nums, int i, int j) {
        if (i > j) {
            return nullptr;
        }

        int mid = i + (j - i >> 1);
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = Helper(nums, i, mid - 1);
        cur->right = Helper(nums, mid + 1, j);
        return cur;
    }
};

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    auto ret = Solution().sortedArrayToBST(nums);
    return 0;
}
