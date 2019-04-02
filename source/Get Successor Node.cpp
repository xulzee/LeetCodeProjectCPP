#include <sys/types.h>

//
// Created by xulzee on 2019/3/19.
//
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), parent(nullptr), left(nullptr), right(nullptr) {}
};

// 找到一个节点的后继节点(中序遍历下一个)
class Solution{
public:
    TreeNode * getSuccessorNode(TreeNode * root){
        if (root == nullptr){
            return nullptr;
        }
        TreeNode *cur = nullptr;
        TreeNode *parent = nullptr;
        if (root->right != nullptr){
            cur = root->right;
            while (cur->left != nullptr){
                cur = cur->left;
            }
            return cur;
        } else{
            cur = root;
            parent = root->parent;
            while (parent != nullptr && parent->left != cur){
                cur = parent;
                parent = parent->parent;
            }
        }
        return parent;
    }
};