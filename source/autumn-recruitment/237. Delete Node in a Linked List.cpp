//
// Created by liuze.xlz on 2019-08-03.
//

#include "utils.h"


class Solution {
public:
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

