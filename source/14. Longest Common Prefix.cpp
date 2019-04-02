// @Time    : 2019/3/1 16:53
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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){
            return "";
        }
        string prefix = strs[0];
        int j = 0;
        for (auto i = strs.begin() + 1; i < strs.end(); ++i) {
            j = 0;
            while (j < (*i).length() and j < prefix.length()){
                if ((*i)[j] != prefix[j]){
                    break;
                }
                ++j;
            }
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};

int main() {
    vector<string> A = {"flower","flow","flight"};
    cout << Solution().longestCommonPrefix(A) << endl;
}