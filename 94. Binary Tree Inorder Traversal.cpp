// @Time    : 2019/3/25 20:17
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        inorderTraversalUnRecur(root, res);
        return res;
    }

    void inorderTraversalRecur(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        inorderTraversalRecur(root->left, res);
        res.push_back(root->val);
        inorderTraversalRecur(root->right, res);
    }

    void inorderTraversalUnRecur(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        TreeNode *cur = root;
        stack<TreeNode *> s;
        while (!s.empty() || cur != nullptr){
            if (cur != nullptr){
                s.push(cur);
                cur = cur->left;
            } else{
                cur = s.top();
                s.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
};
