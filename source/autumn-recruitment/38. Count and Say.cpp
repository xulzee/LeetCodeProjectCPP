//
// Created by liuze.xlz on 2019-08-03.
//

#include "utils.h"

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        if (n == 2) {
            return "11";
        }
        string res = "11";
        for (int i = 3; i <= n; ++i) {
            string temp;
            char ch = res[0];
            int count = 1;
            for (int j = 1; j < res.size(); ++j) {
                if (res[j] == res[j - 1]) {
                    ++count;
                } else {
                    temp += to_string(count) + ch;
                    ch = res[j];
                    count = 1;
                }
            }
            res = temp + to_string(count) + ch;
        }
        return res;
    }
};

int main(){
    cout << Solution().countAndSay(6) << endl;
}