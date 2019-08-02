//
// Created by liuze.xlz on 2019-08-01.
//
#include "utils.h"

class Solution {
public:
    bool isAnagram1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> alphas(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++alphas[s[i] - 'a'];
            --alphas[t[i] - 'a'];
        }

        for (int alpha : alphas) {
            if (alpha != 0){
                return false;
            }
        }

        return true;
    }
};
