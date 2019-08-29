//
// Created by liuze.xlz on 2019-08-28.
//
#include "utils.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return head == nullptr ? nullptr : MergeSortList(head);
    }

    ListNode *MergeList(ListNode *l1, ListNode *l2) {
        ListNode *dummy_head = new ListNode(0);
        ListNode *head = dummy_head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            } else {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }

        if (l1 != nullptr) {
            head->next = l1;
        }
        if (l2 != nullptr) {
            head->next = l2;
        }
        return dummy_head->next;
    }

    // 1 2 3 4 5
    // 1 2 3 4
    ListNode *MergeSortList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = head;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        ListNode *left = MergeSortList(head);
        ListNode *right = MergeSortList(slow);
        return MergeList(left, right);
    }
};
