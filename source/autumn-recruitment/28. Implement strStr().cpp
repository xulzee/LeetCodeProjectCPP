//
// Created by liuze.xlz on 2019-08-02.
//

#include "utils.h"

class Solution {
public:
    vector<int> getNext(const string &s) {
        if (s.size() <= 1) {
            return {-1};
        }
        vector<int> next(s.size(), -1);
        int i = 1;
        int j = -1;
        while (i < s.size()) {
            if (j == -1 || s[i - 1] == s[j]) {
                next[i++] = j+1;
                ++j;
            } else {
                j = next[j];
            }
        }
        return next;
    }

    int KMP(const string &s, const string &t) {
        if (t.empty()) {
            return 0;
        }
        if (s.empty() || s.size() < t.size()) {
            return -1;
        }
        vector<int> next = getNext(t);
        int i = 0, j = 0;
        while (i < s.size() && j < static_cast<int>(t.size())) {
            if (j == -1 || s[i] == t[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }

        if (j == t.size()) {
            return i - j;
        } else {
            return -1;
        }
    }


    int strStr(string haystack, string needle) {
        return KMP(haystack, needle);
    }
};

int main() {
    cout << Solution().strStr("mississippi", "issip") << endl;
}

