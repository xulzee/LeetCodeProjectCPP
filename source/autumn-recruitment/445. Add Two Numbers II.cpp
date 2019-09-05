//
// Created by liuze.xlz on 2019-09-05.
//
#include "utils.h"

class Solution {
public:
    int GetListLength(ListNode *l1) {
        int res = 0;
        auto cur = l1;
        while (cur != nullptr) {
            ++res;
            cur = cur->next;
        }
        return res;
    }

    int addTwoList(ListNode *l1, ListNode *l2) {
        if (l1->next == nullptr) {
            int sum = l1->val + l2->val;
            l1->val = sum % 10;
            return sum / 10;
        }
        int carry = addTwoList(l1->next, l2->next);
        int sum = l1->val + l2->val + carry;
        l1->val = sum % 10;
        return sum / 10;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int m = GetListLength(l1);
        int n = GetListLength(l2);
        if (n > m) {
            swap(l1, l2);
            swap(m, n);
        }
        int k = m - n;
        while (k > 0) {
            auto node = new ListNode(0);
            node->next = l2;
            l2 = node;
            --k;
        }

        int carry = addTwoList(l1, l2);
        if (carry != 0) {
            auto node = new ListNode(carry);
            node->next = l1;
            l1 = node;
        }
        return l1;
    }

    ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2) {
        stack<int> l1_stack;
        stack<int> l2_stack;
        while (l1 != nullptr) {
            l1_stack.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            l2_stack.push(l2->val);
            l2 = l2->next;
        }
        stack<int> res;
        int in = 0;
        int add = 0;
        while (!l1_stack.empty() && !l2_stack.empty()) {
            add = (l1_stack.top() + l2_stack.top() + in) % 10;
            in = (l1_stack.top() + l2_stack.top() + in) / 10;
            res.push(add);
            l1_stack.pop();
            l2_stack.pop();
        }
        while (!l1_stack.empty()) {
            add = (l1_stack.top() + in) % 10;
            in = (l1_stack.top() + in) / 10;
            res.push(add);
            l1_stack.pop();
        }
        while (!l2_stack.empty()) {
            add = (l2_stack.top() + in) % 10;
            in = (l2_stack.top() + in) / 10;
            res.push(add);
            l2_stack.pop();
        }
        if (in != 0) {
            res.push(in);
        }
        ListNode *head = nullptr;
        if (res.empty()) {
            return head;
        } else {
            head = new ListNode(res.top());
            res.pop();
        }
        ListNode *cur = head;
        while (!res.empty()) {
            cur->next = new ListNode(res.top());
            cur = cur->next;
            res.pop();
        }
        return head;
    }
};

int main() {
    auto l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
//    l1->next->next->next = new ListNode(0);
    auto l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution().addTwoNumbers(l1, l2);
}