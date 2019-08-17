//
// Created by liuze.xlz on 2019-08-17.
//
#include "utils.h"

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        int res = 0;
        size_t cur = 0;
        unordered_map<char, int> alpha_map;
        while (cur < s.size()) {
            if (alpha_map.find(s[cur]) == alpha_map.end()) {
                alpha_map[s[cur]] = cur;
                res = max(res, static_cast<int>(alpha_map.size()));
            } else {
                cur = alpha_map[s[cur]] + 1;
                alpha_map.clear();
                alpha_map[s[cur]] = cur;
            }
            ++cur;
        }
        return res;
    }

    int lengthOfLongestSubstring2(string s) {
        int res = 0;
        size_t begin = 0, end = 0;
        unordered_map<char, int> alpha_map;
        while (end < s.size()) {
            if (alpha_map.find(s[end]) == alpha_map.end() || alpha_map[s[end]] < begin) {
                alpha_map[s[end]] = end;
                res = max(res, static_cast<int>(end - begin + 1));
            } else {
                begin = alpha_map[s[end]] + 1;
                alpha_map[s[end]] = end;
            }
            ++end;
        }
        return res;
    }

    int lengthOfLongestSubstring3(string s) {
        int res = 0;
        size_t begin = 0, end = 0;
        unordered_set<char> alpha_set;
        while (begin < s.size() && end < s.size()) {
            if (alpha_set.find(s[end]) == alpha_set.end()) {
                alpha_set.insert(s[end]);
                res = max(res, static_cast<int>(end - begin + 1));
                ++end;
            } else {
                alpha_set.erase(s[begin]);
                ++begin;
            }
        }
        return res;
    }

    int lengthOfLongestSubstring(string s) {
        int res = 0;
        size_t begin = 0, end = 0;
        unordered_map<char, int> alpha_map;
        while (begin < s.size() && end < s.size()) {
            if (alpha_map.find(s[end]) != alpha_map.end()){
                if (alpha_map[s[end]] >= begin){
                    begin  = alpha_map[s[end]] + 1;
                }
            }
            res = max(res, static_cast<int>(end - begin + 1));
            alpha_map[s[end]] = end;
            ++end;
        }
        return res;
    }
};

int main() {
    cout << Solution().lengthOfLongestSubstring("aab") << endl;
}
