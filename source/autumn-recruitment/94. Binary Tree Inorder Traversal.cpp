//
// Created by liuze.xlz on 2019-09-04.
//
#include "utils.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        InOrderTraversalUnRecursive(root);
        return res_;
    }

    void InOrderTraversalRecursive(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        InOrderTraversalRecursive(root->left);
        res_.push_back(root->val);
        InOrderTraversalRecursive(root->right);
    }

    void InOrderTraversalUnRecursive(TreeNode *root) {
        if (root == nullptr){
            return;
        }
        stack<TreeNode *> node_stack;
        TreeNode *cur = root;
        while (!node_stack.empty() || cur != nullptr) {
            if (cur != nullptr) {
                node_stack.push(cur);
                cur = cur->left;
            } else {
                cur = node_stack.top();
                node_stack.pop();
                res_.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

private:
    vector<int> res_;
};

int main(){
    auto *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    Solution().inorderTraversal(root);
}