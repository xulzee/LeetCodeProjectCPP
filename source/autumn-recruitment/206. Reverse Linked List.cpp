//
// Created by liuze.xlz on 2019-08-03.
//
#include "utils.h"

class Solution {
public:
    ListNode *reverseList1(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *ret = reverseList1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }

    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = cur;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

int main() {
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode *ret = Solution().reverseList(head);
}