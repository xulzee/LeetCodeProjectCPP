// @Time    : 2019/2/28 14:22
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    int firstUniqChar1(string s) {
        unordered_map<char, int> hashmap = {};
        for (auto &i:s) {
            if (hashmap.find(i) != hashmap.end()) {
                hashmap[i]++;
            } else {
                hashmap[i] = 1;
            }
        }
        for (int j = 0; j < s.size(); ++j) {
            if (hashmap[s[j]] == 1) {
                return j;
            }
        }
        return -1;
    }

    int firstUniqChar(string s) {
        int count[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            count[s[i] - 'a'] ++;
        }
        for (int j = 0; j < s.size(); ++j) {
            if (count[s[j] - 'a'] == 1){
                return j;
            }
        }
        return -1;
    }
};

int main() {
    string A = "loveleetcode";
    cout << Solution().firstUniqChar(A) << endl;
}