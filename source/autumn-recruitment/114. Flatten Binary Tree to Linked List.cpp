//
// Created by liuze.xlz on 2019-09-04.
//
#include "utils.h"

class Solution {
public:
    void flatten1(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        flatten1(root->left);
        flatten1(root->right);
        if (root->left != nullptr) {
            TreeNode *pre = root->left; // 左子树
            while (pre->right != nullptr) { // 找到左子树最右节点
                pre = pre->right;
            }
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }

    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        while (root != nullptr) {
            if (root->left != nullptr) {
                auto pre = root->left;
                while (pre->right != nullptr) {
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }

};

int main() {
    auto *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    Solution().flatten1(root);
}
