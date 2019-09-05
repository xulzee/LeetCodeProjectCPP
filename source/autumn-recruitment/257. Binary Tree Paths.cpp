//
// Created by liuze.xlz on 2019-09-05.
//
#include "utils.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        bfs(root);
        return res_;
    }

    void dfs(TreeNode *root, string temp) {
        if (root == nullptr) {
            return;
        }
        temp.append(to_string(root->val));
        if (root->left == nullptr && root->right == nullptr) {
            res_.push_back(temp);
        } else {
            temp.append("->");
            dfs(root->left, temp);
            dfs(root->right, temp);
        }
    }

    void bfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        stack<pair<TreeNode *, string>> path_stack;
        path_stack.push(make_pair(root, to_string(root->val)));
        while (!path_stack.empty()) {
            auto cur = path_stack.top();
            path_stack.pop();
            if (cur.first->left != nullptr) {
                path_stack.push(make_pair(cur.first->left, cur.second + "->" + to_string(cur.first->left->val)));
            }
            if (cur.first->right != nullptr) {
                path_stack.push(make_pair(cur.first->right, cur.second + "->" + to_string(cur.first->right->val)));
            }
            if (cur.first->left == nullptr && cur.first->right == nullptr) {
                res_.push_back(cur.second);
            }
        }
    }

private:
    vector<string> res_;
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution().binaryTreePaths(root);
}