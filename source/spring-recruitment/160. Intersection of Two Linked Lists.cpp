// @Time    : 2019/4/11 11:15
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <algorithm>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA != nullptr) {
            count++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            count--;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (count >= 0) {
            while (count > 0) {
                curA = curA->next;
                --count;
            }
        } else {
            count = abs(count);
            while (count > 0) {
                curB = curB->next;
                --count;
            }
        }
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }
        return curA == nullptr ? nullptr : curA;
    }
};
