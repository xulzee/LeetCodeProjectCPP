//
// Created by xulzee on 2019/3/3.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *res = NULL;

        if (l1->val <= l2->val) {
            res = l1;
            res->next = mergeTwoLists(l1->next, l2);
        } else {
            res = l2;
            res->next = mergeTwoLists(l1, l2->next);
        }
        return res;
    }
};

