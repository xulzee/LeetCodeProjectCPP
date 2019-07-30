//
// Created by liuze.xlz on 2019-07-30.
//
#include "utils.h"

class Solution {
public:
    void reverseString1(vector<char> &s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }

    void reverseString(vector<char> &s) {
        reverse(s.begin(), s.end());
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution().reverseString(s);
    printCharVector(s);
}

