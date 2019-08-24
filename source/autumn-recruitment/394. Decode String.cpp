//
// Created by liuze.xlz on 2019-08-20.
//
#include "utils.h"

class Solution {
public:
    // s = "3[a]2[bc]", 返回 "aaabcbc".
    pair<string, int> dfs(string &s, int i){
        string res;
        int num = 0;
        while (i < s.size()){
            if (s[i] >= '0' && s[i] < '9'){
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '['){
                pair<string, int> tmp = dfs(s, i + 1);
                i = tmp.second;
                while (num > 0){
                    res += tmp.first;
                    --num;
                }
                num = 0;
            } else if (s[i] == ']'){
                return make_pair(res, i);
            } else{
                res += s[i];
            }
            ++i;
        }
        return make_pair(res, i);
    }

    string decodeString(string s) {
        return dfs(s, 0).first;
    }

    string decodeString1(string s) {
        string res;

        stack<string> alpha_stack;
        stack<int> num_stack;
        int num = 0;
        for (char i : s) {
            if (i >= '0' && i <= '9') {
                num = num * 10 + (i - '0');
            } else if (i == '[') {
                num_stack.push(num);
                alpha_stack.push(res);
                res = "";
                num = 0;
            } else if (i == ']') {
                int cur_num = num_stack.top();
                num_stack.pop();
                string last_res = alpha_stack.top();
                alpha_stack.pop();
                string temp;
                while (cur_num > 0){
                    temp += res;
                    --cur_num;
                }
                res = last_res + temp;
            } else {
                res += i;
            }
        }
        return res;
    }
};

int main() {
    cout << Solution().decodeString("3[a2[c]]2[bc]") << endl;
}
