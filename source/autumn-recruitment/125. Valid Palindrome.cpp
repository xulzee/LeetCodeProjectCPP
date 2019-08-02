//
// Created by liuze.xlz on 2019-08-02.
//
#include "utils.h"

class Solution {
public:
    bool isPalindrome1(string s) {
        string t;
        for (const auto &ch : s) {
            if (isalpha(ch)) {
                if (ch >= 'A' && ch <= 'Z') {
                    t += ch + ('a' - 'A');
                } else {
                    t += ch;
                }
            } else if (ch >= '0' && ch <= '9') {
                t += ch;
            }
        }

        int i = 0, j = t.size() - 1;
        while (i < j) {
            if (t[i] != t[j]) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }


    bool isPalindrome(string s) {
        int i = 0, j = s.size();
        while (i < j){
            while (!isalnum(s[i])){
                ++i;
            }
            while (!isalnum(s[j])){
                --j;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};

int main() {
    cout << Solution().isPalindrome("0P") << endl;
}
