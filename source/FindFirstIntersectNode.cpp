// @Time    : 2019/3/18 16:45
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <algorithm>

class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
    }
};

class Solution {
public:
    Node *getIntersectNode(Node *head1, Node *head2) {
        if (head1 == nullptr || head2 == nullptr) {
            return nullptr;
        }
        Node *loop1 = getLoopNode(head1);
        Node *loop2 = getLoopNode(head2);
        if (loop1 == nullptr && loop2 == nullptr) {
            //no loop 'Y'
            return noLoop(head1, head2);
        }
        if (loop1 != nullptr && loop2 != nullptr) {
            // both loop
            return bothLoop(head1, loop1, head2, loop2);
        }
        return nullptr;
    }

    Node *getLoopNode(Node *head) { // find loop in single Linked list
        if (head == nullptr || head->next == nullptr | head->next->next == nullptr) {
            return nullptr;
        }
        Node *fast = head->next->next;
        Node *slow = head->next;
        while (slow != fast) {
            if (fast->next == nullptr || fast->next->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    Node *noLoop(Node *head1, Node *head2) {
        if (head1 == nullptr || head2 == nullptr) {
            return nullptr;
        }
        int n = 0;
        Node *cur1 = head1;
        Node *cur2 = head2;
        while (cur1->next != nullptr) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2->next != nullptr) {
            n--;
            cur2 = cur2->next;
        }
        if (cur1 != cur2) {
            return nullptr;
        }
        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while (n != 0) {
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }

    Node *bothLoop(Node *head1, Node *loop1, Node *head2, Node *loop2) {
        Node* cur1 = nullptr;
        Node* cur2 = nullptr;
        if (loop1 == loop2){
            cur1 = head1;
            cur2 = head2;
            int n = 0;
            while (cur1->next != loop1){
                n++;
                cur1 = cur1->next;
            }
            while (cur2->next != loop2) {
                n--;
                cur2 = cur2->next;
            }
            cur1 = n > 0 ? head1 : head2;
            cur2 = cur1 == head1 ? head2 : head1;
            n = abs(n);
            while (n != 0) {
                n--;
                cur1 = cur1->next;
            }
            while (cur1 != cur2) {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        } else{
            cur1 = loop1->next;
            while (cur1 != loop1){
                if (cur1 ==loop2){
                    return loop1;
                }
                cur1 = cur1->next;
            }
            return nullptr;
        }
        return nullptr;
    }

};
