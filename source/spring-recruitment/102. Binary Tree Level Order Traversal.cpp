// @Time    : 2019/3/11 14:56
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<vector<int>> levelOrder1(TreeNode *root) {
        vector<vector<int>> res{};
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            vector<int> temp;
            unsigned long len_q = node_queue.size();
            for (int i = 0; i < len_q; ++i) {
                temp.push_back(node_queue.front()->val);

                if (node_queue.front()->left != nullptr) {
                    node_queue.push(node_queue.front()->left);
                }
                if (node_queue.front()->right != nullptr) {
                    node_queue.push(node_queue.front()->right);
                }

                node_queue.pop();
            }
            res.push_back(temp);
        }
        return res;
    }
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res{};
        if (root == nullptr) {
            return res;
        }
        dfs(0, &res, root);
        return res;
    }

    void dfs(int level, vector<vector<int>> *res,TreeNode *node){
        if (node != nullptr) {
            if (level == res->size()) {
                res->push_back(vector<int>());
            }
            (*res)[level].push_back(node->val);
            dfs(level + 1, res, node->left);
            dfs(level + 1, res, node->right);
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

        vector<vector<int>> ret = Solution().levelOrder(root);

        cout << "done" << endl;
    }
    return 0;
}