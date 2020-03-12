//
// Created by xulzee on 2020/3/12.
//

#include "utils.h"

class Solution {
    bool check(string &str1, string &str2) {
        int count = static_cast<int>(str2.length() / str1.length());
        string ans;
        while (count > 0) {
            ans += str1;
            count--;
        }
        return ans == str2;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = static_cast<int>(str1.length());
        int len2 = static_cast<int>(str2.length());
        string s = str1.substr(0, __gcd(len1, len2));
        if (check(s, str1) && check(s, str2)){
            return s;
        }
        return "";
    }
};

int main() {
    string s1 = "ABCAB";
    string s2 = "ABC";
    cout << Solution().gcdOfStrings(s1, s2) << endl;
}