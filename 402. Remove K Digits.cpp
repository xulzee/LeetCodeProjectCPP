//
// Created by xulzee on 2019/4/1.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k || num.empty()) {
            return "0";
        }
        string res;
        int last = k;
        for (char i : num) {
            while (k > 0 && !res.empty() && i < res.back()){
                k--;
                res.pop_back();
            }
            res.push_back(i);
        }
        int cur = 0;
        while (res[cur] == '0'){
            cur++;
        }
        res = res.substr(cur, num.size() - cur - last);
        if(res.empty()){
            return "0";
        }
        return res;
    }
};

int main() {
    string test = "1173";
    Solution().removeKdigits(test, 2);
}
