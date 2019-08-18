//
// Created by liuze.xlz on 2019-08-18.
//
#include "utils.h"

class Solution {
public:
    string GetManacherString(const string &str) {
        string res(str.size() * 2 + 1, 0);
        int index = 0;
        for (size_t i = 0; i < res.size(); ++i) {
            if (i % 2 == 0) {
                res[i] = '#';
            } else {
                res[i] = str[index++];
            }
        }
        return res;
    }

    string GetResultString(const string &str) {
        string res(str.size() / 2, 0);
        int index = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (i % 2 == 1){
                res[index++] = str[i];
            }
        }
        return res;
    }

    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        string str = GetManacherString(s);
        vector<int> radius_vector(str.size(), 0);
        int R = -1; // 最远到达位置
        int C = -1; // 最远到达位置对应的半径
        pair<int, string> res(0, "");
        for (int i = 0; i < str.size(); ++i) {
            radius_vector[i] = R > i ? min(radius_vector[2 * C - i], R - i) : 1;

            while (i + radius_vector[i] < str.size() && i - radius_vector[i] > -1) {
                if (str[i - radius_vector[i]] == str[i + radius_vector[i]]) {
                    ++radius_vector[i];
                } else {
                    break;
                }
            }

            if (i + radius_vector[i] > R) {
                R = i + radius_vector[i];
                C = i;
            }
            if (res.first < radius_vector[i]) {
                res = make_pair(radius_vector[i], str.substr((i - radius_vector[i]) + 1, 2 * radius_vector[i] - 1));
            }
        }
        return GetResultString(res.second);
    }
};

int main() {
    string str1 = "cbbd";
    cout << Solution().longestPalindrome(str1) << endl;
}
