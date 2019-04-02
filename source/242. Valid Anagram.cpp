//
// Created by xulzee on 2019/2/28.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../include/utils.h"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_list[26] = {0};
        auto l_s = s.size();
        auto l_t = t.size();
        if (l_s != l_t) {
            return false;
        } else {
            for (int i = 0; i < s.size(); ++i) {
                s_list[s[i] - 'a'] += 1;
                s_list[t[i] - 'a'] -= 1;
            }
            for (auto j : s_list) {
                if (j != 0) {
                    return false;
                }
            }
            return true;
        }
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    cout << Solution().isAnagram(s, t) << endl;
}
