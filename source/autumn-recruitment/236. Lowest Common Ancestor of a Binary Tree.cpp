//
// Created by liuze.xlz on 2019-09-05.
//
#include "utils.h"

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return res_;
    }

    bool dfs(TreeNode *cur, TreeNode *p, TreeNode *q) {
        if (cur == nullptr) {
            return false;
        }
        int left = dfs(cur->left, p, q) ? 1 : 0;
        int right = dfs(cur->right, p, q) ? 1 : 0;
        int mid = (cur == p || cur == q) ? 1 : 0;
        if (left + mid + right >= 2){
            res_ = cur;
        }
        return (left + right + right >= 1)
    }

private:
    TreeNode *res_;
};