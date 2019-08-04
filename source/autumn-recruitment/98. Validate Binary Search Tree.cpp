//
// Created by liuze.xlz on 2019-08-04.
//
#include "utils.h"

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        vector<int> res;
        inOrder(root, res);
        for (int i = 1; i < res.size(); ++i) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool helper(TreeNode *root, long lower, long upper) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= lower || root->val >= upper) {
            return false;
        }

        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }

    void inOrder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
};