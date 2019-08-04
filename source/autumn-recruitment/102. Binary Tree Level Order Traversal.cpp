//
// Created by liuze.xlz on 2019-08-04.
//
#include "utils.h"

class Solution {
public:
    vector<vector<int>> levelOrder1(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            vector<int> tmp;
            int level_length = node_queue.size();
            for (int i = 0; i < level_length; ++i) {
                TreeNode *cur = node_queue.front();
                node_queue.pop();
                tmp.push_back(cur->val);
                if (cur->left != nullptr) {
                    node_queue.push(cur->left);
                }
                if (cur->right != nullptr) {
                    node_queue.push(cur->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return res;
        }

        helper(root, 0);
        return res;
    }

    void helper(TreeNode *root, int level) {
        if (res.size() == level) {
            res.emplace_back();
        }

        res[level].push_back(root->val);

        if (root->left != nullptr) {
            helper(root->left, level + 1);
        }
        if (root->right != nullptr) {
            helper(root->right, level + 1);
        }
    }

private:
    vector<vector<int>> res;
};
