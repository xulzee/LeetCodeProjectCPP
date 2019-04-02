// @Time    : 2019/3/18 11:12
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node *copyRandomList1(Node *head) { // 时间：O(n) ：空间O(n)
        unordered_map<Node *, Node *> hash;
        Node *cur = head;
        while (cur != nullptr) {
            hash[cur] = new Node(cur->val, nullptr, nullptr);
            cur = cur->next;
        }
        cur = head;
        while (cur != nullptr) {
            hash[cur]->next = hash[cur->next];
            hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }
        return hash[head];
    }

    Node *copyRandomList(Node *head) { // 时间：O(n) ：空间O(1)
        if (head == nullptr){
            return nullptr;
        }
        Node *next = nullptr;
        Node *cur = head;
        while (cur != nullptr){ // insert copy node behind the origin node
            next = cur->next;
            cur->next = new Node(cur->val, nullptr, nullptr);
            cur->next->next = next;
            cur = next;
        }
        cur = head;
        Node * curCopy = nullptr;
        while (cur != nullptr){ // copy rand
            curCopy = cur->next;
            curCopy->random = cur->random == nullptr ? nullptr : cur->random->next;
            cur = cur->next->next;
        }

        Node * res = head->next;
        cur = head;
        while (cur != nullptr){ // split
            next = cur->next->next;
            curCopy = cur->next;
            cur->next = next;
            curCopy->next = next == nullptr ? nullptr : next->next; // next maybe nullptr
            cur = next;
        }
        return res;
    }

};
