//
// Created by liuze.xlz on 2019-08-03.
//

#include "utils.h"

class Solution {
public:
    ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2) {
        auto *dummy_node = new ListNode(0);
        ListNode *head = dummy_node;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                dummy_node->next = l1;
                dummy_node = dummy_node->next;
                l1 = l1->next;
            } else {
                dummy_node->next = l2;
                dummy_node = dummy_node->next;
                l2 = l2->next;
            }
        }

        dummy_node->next = l1 == nullptr ? l2 : l1;

        return head->next;

    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};