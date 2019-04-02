//
// Created by xulzee on 2019/3/18.
//
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        preOrderUnRecur(root, res);
        return res;
    }

    void preOrderRecur(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        preOrderRecur(root->left, res);
        preOrderRecur(root->right, res);
    }

    void preOrderUnRecur(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        stack < TreeNode * > s;
        TreeNode *cur = root;
        s.push(root);
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (cur->right != nullptr) {
                s.push(cur->right);
            }
            if (cur->left != nullptr) {
                s.push(cur->left);
            }
        }
    }
};
