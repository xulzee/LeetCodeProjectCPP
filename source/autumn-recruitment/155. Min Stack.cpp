//
// Created by liuze.xlz on 2019-08-11.
//
#include "utils.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        num_stack.push(x);
        if (min_stack.empty()) {
            min_stack.push(x);
        } else {
            if (x < min_stack.top()) {
                min_stack.push(x);
            } else {
                min_stack.push(min_stack.top());
            }
        }
    }

    void pop() {
        if (!num_stack.empty()) {
            num_stack.pop();
            min_stack.pop();
        }
    }

    int top() {
        if (!num_stack.empty()) {
            return num_stack.top();
        } else {
            return -1;
        }
    }

    int getMin() {
        if (!min_stack.empty()){
            return min_stack.top();
        } else{
            return -1;
        }
    }

private:
    stack<int> num_stack;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
