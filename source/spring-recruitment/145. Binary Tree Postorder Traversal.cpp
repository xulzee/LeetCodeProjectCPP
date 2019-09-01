// @Time    : 2019/3/25 20:19
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        postOrderRecur(root, res);
        return res;
    }

    void postOrderRecur(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        TreeNode *cur = root;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        while (!s1.empty()){
            cur = s1.top();
            s1.pop();
            s2.push(cur);
            if (cur->left != nullptr){
                s1.push(cur->left);
            }
            if (cur->right != nullptr){
                s1.push(cur->right);
            }
        }
        while (!s2.empty()){
            cur = s2.top();
            s2.pop();
            res.push_back(cur->val);
        }
    }
};