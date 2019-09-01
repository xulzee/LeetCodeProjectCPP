// @Time    : 2019/3/4 16:41
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "utils.h"


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode temp = ListNode(0);
        ListNode *dummy = &temp;
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        while (fast->next != NULL) {
            if (n <= 0) {
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};