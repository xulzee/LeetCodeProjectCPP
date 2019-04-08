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
        if (root == nullptr) {
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
        while (!s1.empty()) {
            cur = s1.top();
            s1.pop();
            s2.push(cur);
            if (cur->left != nullptr) {
                s1.push(cur->left);
            }
            if (cur->right != nullptr) {
                s1.push(cur->right);
            }
        }
        while (!s2.empty()) {
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

// num 个数， 和为 sum， 第一个数小于等于 start，一共有多少种
int process(int sum, int num, int diff, int lastNum) {
    if (sum <= 0 || (num == 1 && sum > diff + lastNum)) {
        return 0;
    }
    if (num == 1 && sum <= diff + lastNum && sum > lastNum) {
        return 1;
    }
    int ret = 0;
    int curNum;
    for (int i = 1; i <= diff; ++i) {
        curNum = lastNum + i;
        ret += process(sum - curNum, num - 1, diff, curNum);;
    }
    return ret;
}

int dynamicProcess(int input1, int input2, int input3) {
//    vector<vector<vector<int>>> dp(input2 + 1,
//                                   vector<vector<int>>(input1 + 1, vector<int>(input1, 0))); // num, sum, lastNum
//    for (int i = 1; i <= input2; ++i) { // num
//        for (int j = 1; j <= input1; ++j) { // sum
//            for (int k = 0; k <= input1; ++k) {// lastNum
//                if (i == 1 && j <= input3 + k && j > k) {
//                    dp[i][j][k] = 1;
//                } else {
//                    int curNum = 0;
//                    int ret = 0;
//                    for (int l = 1; l <= input3; ++l) {
//                        curNum = k + l;
//                        if (j >= curNum) {
//                            ret += dp[i - 1][j - curNum][curNum];
//                        }
//                    }
//                    dp[i][j][k] = ret;
//                }
//            }
//        }
//    }
//    return dp[input2][input1][0];
    vector<vector<vector<int> > > dp(input2 + 1, vector<vector<int> >(input1 + 1, vector<int>(input1 + 1, 0)));
    for (int i = 1; i <= input2; ++i) {
        for (int j = 1; j <= input1; ++j) {
            for (int k = 0; k <= input1; ++k) {
                if (i == 1 && j <= input3 + k && j > k) {
                    dp[i][j][k] = 1;
                } else {
                    int curNum = 0;
                    int ret = 0;
                    for (int l = 1; l <= input3; ++l) {
                        curNum = k + l;
                        if (j >= curNum) {
                            ret += dp[i - 1][j - curNum][curNum];
                        }
                    }
                    dp[i][j][k] = ret;
                }
            }
        }
    }
    return dp[input2][input1][0];
}


int main() {
//    cout << process(10, 4, 1, 0) << endl;
    cout << dynamicProcess(25, 5, 2) << endl;
//    string line;
//    while (getline(cin, line)) {
//        TreeNode *root = stringToTreeNode(line);
//
//        vector<int> ret = Solution().preorderTraversal(root);
//
//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;



//    int input1 = 4;
//    int input2 = 0;
//    int input3 = 0;
//    int tree_len = max(input2, input3);
//    int high_p = 0;
//    int p = input2;
//    while (p / 2 != 0){
//        p = p / 2;
//        high_p++;
//    }
//    high_p++;
//    if (input2 == 0){
//        high_p = 0;
//    }
//    int high_q = 0;
//    int q = input3;
//    while (q / 2 != 0){
//        q = q / 2;
//        high_q++;
//    }
//    high_q++;
//
//    if (input3 == 0){
//        high_q = 0;
//    }
//
//
//    p = input2;
//    q = input3;
//    int high = 0;
//    if (high_p > high_q){
//        for (int i = 0; i < high_p - high_q; ++i) {
//            p = p / 2;
//            high = high_p - high_q;
//        }
//    } else if (high_p < high_q){
//        for (int i = 0; i < high_q- high_p; ++i) {
//            q = q / 2;
//            high = high_q- high_p;
//        }
//    }
//
//    int res = 0;
//    while (p != q){
//        p = p / 2;
//        q = q / 2;
//        res ++;
//    }
//    return (res * 2 + high) * input1;
}


