// @Time    : 2019/3/1 11:22
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> get_next(const string &needle) {
        int i = 0;
        int j = -1;
        vector<int> next;
        next.push_back(-1);
        while (i < needle.length() - 1) {
            if (j == -1 || needle[j] == needle[i]) {
                ++j;
                ++i;
                next.push_back(j);
            } else {
                j = next[j];
            }
        }
        return next;

    }

    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        int lh = static_cast<int>(haystack.size());
        int ln = static_cast<int>(needle.size());
        if (ln == 0){
            return 0;
        }
        if (lh < ln){
            return -1;
        }
        vector<int> next = get_next(needle);
        while (i < lh && j < ln) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++j;
                ++i;
            } else {
                j = next[j];
            }
        }
        if (j == needle.length()) {
            return i - j;
        } else{
            return -1;
        }
    }
};

int main() {
    string haystack = "";
    string needle = "";
    cout << Solution().strStr(haystack, needle) << endl;
}