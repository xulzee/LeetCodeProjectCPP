//
// Created by liuze.xlz on 2019-08-03.
//

#include "utils.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()){
            return res;
        }
        for (size_t i = 0; i < strs[0].size(); ++i) {
            char ch = strs[0][i];
            for (int j = 0; j < strs.size(); ++j) {
                if (ch != strs[j][i]){
                    return res;
                }
            }
            res += ch;
        }
        return res;
    }
};