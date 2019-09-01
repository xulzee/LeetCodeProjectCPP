// @Time    : 2019/4/11 18:26
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;
        while(even != nullptr && even->next != nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};