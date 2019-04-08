//
// Created by xulzee on 2019/3/18.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        inOrderTraversalUnRecur(root, res);
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
        stack<TreeNode *> s;
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

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

    }

    void inOrderTraversalRecur(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversalRecur(root->left, res);
        res.push_back(root->val);
        inOrderTraversalRecur(root->right, res);
    }

    void inOrderTraversalUnRecur(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        TreeNode *cur = root;
        stack<TreeNode *> s;
        while (!s.empty() || cur != nullptr) {
            if (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                // 遍历
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

    void postOrderRecur(TreeNode *root, vector<int> &res) {
        if (root == nullptr){
            return;
        }
        postOrderRecur(root->left, res);
        postOrderRecur(root->right, res);
        res.push_back(root->val);
    }

    void postOrderUnRecur(TreeNode *root, vector<int> &res) {
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


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "nullptr") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);

        vector<int> ret = Solution().preorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}