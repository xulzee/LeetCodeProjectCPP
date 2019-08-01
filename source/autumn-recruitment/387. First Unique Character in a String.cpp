//
// Created by liuze.xlz on 2019-08-01.
//
#include "utils.h"

class Solution {
public:
    int firstUniqChar(string s) {
        int res = -1;
        vector<int> alphas(26, 0);
        for (const auto &item : s) {
            ++alphas[item - 'a'];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (alphas[s[i] - 'a'] == 1) {
                res = i;
                break;
            }
        }

        return res;
    }
};

int main() {
    string s = "leetcode";
    cout << Solution().firstUniqChar(s) << endl;
}