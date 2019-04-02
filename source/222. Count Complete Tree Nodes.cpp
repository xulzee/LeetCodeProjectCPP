//
// Created by xulzee on 2019/3/20.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
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

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == nullptr){
            return 0;
        }
        int all_level = mostLeftLevel(root, 1);
        return binarySearch(root, 1, all_level);
    }

    // 返回以node为头节点的完全二叉树的节点个数，level为node所在层的深度，alllevel为二叉树的总深度
    int binarySearch(TreeNode *node, int level, int alllevel) {
        if (level == alllevel) { // 最后一层
            return 1;
        }
        if (mostLeftLevel(node->right, level + 1) == alllevel) { // 左子树为满二叉树
            return (1 << (alllevel - level)) + binarySearch(node->right, level + 1, alllevel);
        } else { // 右子树为满二叉树
            return (1 << (alllevel - level - 1)) + binarySearch(node->left, level + 1, alllevel);
        }
    }

    // 返回以node为头节点的最左节点的深度， level表示node所在的深度
    int mostLeftLevel(TreeNode *node, int level) {
        TreeNode *cur = node;
        while (cur != nullptr) {
            level++;
            cur = cur->left;
        }
        return level - 1;
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

        int ret = Solution().countNodes(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

