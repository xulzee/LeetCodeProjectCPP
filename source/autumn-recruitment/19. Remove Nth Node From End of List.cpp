//
// Created by liuze.xlz on 2019-08-03.
//

#include "utils.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *slow = new ListNode(0);
        slow->next = head;
        ListNode *fast = slow;
        head = slow; // protect head node

        while (n > 0) {
            fast = fast->next;
            --n;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head->next;
    }
};

int main() {
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode *ret = Solution().removeNthFromEnd(head, 2);
}