// @Time    : 2019/3/20 10:40
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include "../include/utils.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Codec1 {
public:
    // level serialize
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "";
        }
        string res;
        queue<TreeNode *> nodeQueue;
        TreeNode *cur;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            cur = nodeQueue.front();
            nodeQueue.pop();
            if (cur != nullptr) {
                res += to_string(cur->val);
                nodeQueue.push(cur->left);
                nodeQueue.push(cur->right);
            } else {
                res += "null";
            }
            res += ",";
        }
        return res.substr(0, res.length() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        string item;
        stringstream ss;
        ss.str(data);
        queue<TreeNode *> nodeQueue;
        if (data.empty()) {
            return nullptr;
        }
        // get root
        getline(ss, item, ',');
        auto *root = new TreeNode(stoi(item));
        nodeQueue.push(root);
        TreeNode *cur;
        while (true) {
            cur = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ',')) {
                break;
            }
            if (item != "null") {
                int leftNumber = stoi(item);
                cur->left = new TreeNode(leftNumber);
                nodeQueue.push(cur->left);
            }
            if (!getline(ss, item, ',')) {
                break;
            }
            if (item != "null") {
                int rightNumber = stoi(item);
                cur->right = new TreeNode(rightNumber);
                nodeQueue.push(cur->right);
            }
        }
        return root;
    }
};

class Codec2 {
public:
    string preOrder(TreeNode *root) {
        if (root == nullptr) {
            return "n,";
        }
        string s = to_string(root->val) + ",";
        s += preOrder(root->left);
        s += preOrder(root->right);
        return s;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "n";
        }
        string res = preOrder(root);
        return res.substr(0, res.length() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        string temp;
        stringstream ss;
        queue<string> q;
        ss.str(data);
        while (true) {
            if (!getline(ss, temp, ',')) {
                break;
            }
            q.push(temp);
        }
        return reconPreOrder(q);
    }

    TreeNode *reconPreOrder(queue<string> &q) {
        string value = q.front();
        q.pop();
        if (value == "n") {
            return nullptr;
        }
        TreeNode *head = new TreeNode(stoi(value));
        head->left = reconPreOrder(q);
        head->right = reconPreOrder(q);
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            TreeNode *cur = nodeQueue.front();
            nodeQueue.pop();
            if (cur == nullptr) {
                res += "null";
            } else {
                res.append(to_string(cur->val));
            }
            if (cur != nullptr) {
                nodeQueue.push(cur->left);
                nodeQueue.push(cur->right);
            }
            res.append(",");
        }
        return res.substr(0, res.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &data) {
        if (data == "null"){
            return nullptr;
        }
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode *root = new TreeNode(stoi(item));
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (true) {
            TreeNode *cur = nodeQueue.front();
            nodeQueue.pop();

            // left
            if (!getline(ss, item, ',')) { // ""
                break;
            }
            if (item == "null") {
                cur->left = nullptr;
            } else {
                cur->left = new TreeNode(stoi(item));
                nodeQueue.push(cur->left);
            }

            //right
            if (!getline(ss, item, ',')) { // ""
                break;
            }
            if (item == "null") {
                cur->right = nullptr;
            } else {
                cur->right = new TreeNode(stoi(item));
                nodeQueue.push(cur->right);
            }
        }
        return root;
    }
};


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
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);

        string ret = Codec().serialize(root);
        TreeNode *head = Codec().deserialize(ret);
        string out = (ret);
        cout << out << endl;
    }
    return 0;
}