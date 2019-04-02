// @Time    : 2019/3/2 16:28
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../include/utils.h"

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        if (n == 2) {
            return "11";
        }
        string pre = "11";
        string temp;
        char c;
        int count_c;
        for (int i = 3; i < n + 1; ++i) {
            temp = "";
            count_c = 1;
            c = pre[0];
            for (int j = 1; j < pre.length(); ++j) {
                if (c == pre[j]){
                    ++count_c;
                } else{
                    temp = temp + char(count_c + 48) + c;
                    count_c = 1;
                    c = pre[j];
                }
            }
            temp = temp + char(count_c + 48) + c;
            pre = temp;
        }
        return pre;
    }
};

int main() {
    int n = 10;
    cout << Solution().countAndSay(10) << endl;
}