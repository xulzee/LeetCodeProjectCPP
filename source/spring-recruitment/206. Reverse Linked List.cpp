//
// Created by xulzee on 2019/2/28.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList1(ListNode *head) {
        ListNode* last_node = NULL;
        ListNode* next_node = NULL;
        if (head != NULL && head->next != NULL) {
            while (head != NULL) {
                next_node = head->next;
                head->next = last_node;
                last_node = head;
                head = next_node;
            }
            return last_node;
        }
        return head;
    }

    ListNode *reverseList(ListNode *head) {
        //如果链表为空或者链表中只有一个元素
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *t = NULL;
        t = reverseList(head->next);//先反转后面的链表，走到链表的末端结点

        head->next->next = head;//再将当前节点设置为后面节点的后续节点
        head->next = NULL;

        return t; //new head
    }
};
