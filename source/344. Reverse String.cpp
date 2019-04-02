// @Time    : 2019/2/28 10:09
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../include/utils.h"

using namespace std;

class Solution {
public:
    void reverseString1(vector<char> &s) {
        reverse(s.begin(), s.end());
    }

    void reverseString(vector<char> &s) {
        auto l = s.size();
        if (l > 0) {
            for (int i = 0; i <= (l - 1) / 2; ++i) {
                swap(s[i], s[l - i - 1]);
            }
        }
    }
};

int main() {
    vector<char> A = {};
    Solution().reverseString(A);
    printCharVector(A);
}