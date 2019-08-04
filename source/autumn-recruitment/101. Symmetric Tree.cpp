//
// Created by liuze.xlz on 2019-08-04.
//

#include "utils.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        if (t1 == nullptr || t2 == nullptr) {
            return false;
        }
        return t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};

