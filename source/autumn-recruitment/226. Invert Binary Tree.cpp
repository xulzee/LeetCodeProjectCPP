//
// Created by liuze.xlz on 2019-08-27.
//
#include "utils.h"

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr){
            return nullptr;
        }
        TreeNode* left = invertTree(root->right);
        TreeNode* right = invertTree(root->left);
        root->left = left;
        root->right = right;
        return root;
    }
};
