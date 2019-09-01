//
// Created by xulzee on 2019/4/1.
//
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<int> numStack;
        stack<string> stringStack;
        int num = 0;
        for (auto c : s) {
            if (isdigit(c)) {
                num = 10 * num + c - '0';
            } else if (isalpha(c)) {
                res += c;
            } else if (c == '[') {
                stringStack.push(res);
                numStack.push(num);
                num = 0;
                res = "";
            } else if (c == ']') {
                int curNum = numStack.top();
                numStack.pop();
                string temp = res;
                for (int i = 0; i < curNum - 1; ++i) {
                    res += temp;
                }
                res = stringStack.top() + res;
                stringStack.pop();
            }
        }
        return res;
    }
};

int main(){
    string test = "10[a10[c]]";
    Solution().decodeString(test);
}

