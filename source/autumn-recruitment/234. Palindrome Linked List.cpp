//
// Created by liuze.xlz on 2019-08-17.
//
#include "utils.h"

class Solution {
public:
    bool isPalindrome1(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        vector<int> nums;
        Helper(head, nums);
        size_t i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] != nums[j]) {
                return false;
            }
            --j;
            ++i;
        }
        return true;
    }

    void Helper(ListNode *head, vector<int> &nums) {
        if (head == nullptr) {
            return;
        }
        nums.push_back(head->val);
        Helper(head->next, nums);
    }

    bool isPalindrome(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        bool res = true;
        // find mid node
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse mid to end
        ListNode *pre = nullptr;
        while (slow != nullptr) {
            ListNode *next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        // compare
        fast = head;
        slow = pre;
        while (fast != nullptr && slow != nullptr) {
            if (fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        // reverse mid to end
        slow = pre;
        pre = nullptr;
        while (slow != nullptr){
            ListNode *next = slow ->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        return res;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    Solution().isPalindrome(head);
}
