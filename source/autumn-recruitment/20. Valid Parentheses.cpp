//
// Created by liuze.xlz on 2019-08-12.
//
#include "utils.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses_stack;
        for (auto &item  : s) {
            if (item == '(' || item == '{' || item == '[') {
                parentheses_stack.push(item);
            } else {
                if (parentheses_stack.empty() || (item == ')' && parentheses_stack.top() != '(') ||
                    (item == ']' && parentheses_stack.top() != '[') ||
                    (item == '}' && parentheses_stack.top() != '{')) {
                    return false;
                } else{
                    parentheses_stack.pop();
                }
            }
        }
        return parentheses_stack.empty();
    }
};

