// @Time    : 2019/3/16 14:07
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        num.push(x);
        if (min.empty()){
            min.push(x);
        } else{
            if (x < min.top()){
                min.push(x);
            } else{
                min.push(min.top());
            };
        }
    }

    void pop() {
        if (num.empty()){
            return;
        } else{
            num.pop();
            min.pop();
        }
    }

    int top() {
        return num.top();
    }

    int getMin() {
        return min.top();
    }

private:
    stack<int> num;
    stack<int> min;
};
