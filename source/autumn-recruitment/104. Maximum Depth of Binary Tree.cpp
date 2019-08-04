//
// Created by liuze.xlz on 2019-08-04.
//

#include "utils.h"

class Solution {
public:
    int maxDepth1(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth1(root->left), maxDepth1(root->right)) + 1;
    }

    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode *, int>> node_queue;
        node_queue.push(make_pair(root, 1));
        int res = 0;
        while (!node_queue.empty()){
            pair<TreeNode *, int> cur = node_queue.front();
            node_queue.pop();
            res = max(res, cur.second);
            if (cur.first->left != nullptr){
                node_queue.push(make_pair(cur.first->left, cur.second + 1));
            }
            if (cur.first->right != nullptr){
                node_queue.push(make_pair(cur.first->right, cur.second + 1));
            }
        }
        return res;
    }
};

