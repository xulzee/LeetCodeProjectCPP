//
// Created by liuze.xlz on 2019-08-17.
//
#include "utils.h"

// (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int in = 0;
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (l1 != nullptr && l2 != nullptr) {
            cur->next = new ListNode((in + l1->val + l2->val) % 10);
            in = (l1->val + l2->val + in) / 10;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr){
            cur->next = new ListNode((in + l1->val) % 10);
            in = (l1->val + in) / 10;
            cur = cur->next;
            l1 = l1->next;
        }

        while (l2 != nullptr){
            cur->next = new ListNode((in + l2->val) % 10);
            in = (l2->val + in) / 10;
            cur = cur->next;
            l2 = l2->next;
        }

        if (in != 0){
            cur->next = new ListNode(in);
        }

        return head->next;
    }
};

int main(){
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);
//    l1->next->next = new ListNode(0);
//    l1->next->next->next = new ListNode(0);
    ListNode *l2 = new ListNode(9);
//    l2->next = new ListNode(9);
//    l2->next->next = new ListNode(9);
//    l2->next->next->next = new ListNode(9);
    Solution().addTwoNumbers(l1, l2);
}

