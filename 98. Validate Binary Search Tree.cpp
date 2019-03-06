// @Time    : 2019/3/5 17:29
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "utils.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool helper(TreeNode *root, long lower, long upper){
        if (root == NULL){
            return true;
        }
        if (root->val >= upper or root->val <= lower){
            return false;
        }
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode *root) {
        return helper(root, INT64_MIN, INT64_MAX);
    }

    void inorder(TreeNode *root, vector<int> &list) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }

    bool isValidBST1(TreeNode *root) {
        if (root == NULL || (root->right == NULL && root->left == NULL)) {
            return true;
        }
        vector<int> list;
        inorder(root, list);
        for (int i = 1; i < list.size(); ++i) {
            if(list[i] > list[i-1]){
                return false;
            }
        }
        return true;
    }
};