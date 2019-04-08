// @Time    : 2019/4/5 17:35
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return dynamicProcess(s, k);
    }

    // 返回 i 到 j(不包含) 中每个字符都出现了k次的字符串字串长度
    int process(string &s, int start, int end, int k) {
        int max_index = 0;
        int res = 0;
        int mask[26] = {0}; // 记录重复字符 mask
        bool ok = true;
        for (int i = start; i < end; ++i) {
            mask[s[i] - 'a']++;
        }
        for (int j = start; j < end; ++j) {
            if (mask[s[j] - 'a'] < k) {
                res = max(res, process(s, max_index, j, k));
                ok = false;
                max_index = j + 1;
            }
        }
        return ok ? end - start : max(res, process(s, max_index, end, k));
    }

    int dynamicProcess(string &s, int k) {
        vector<vector<int >> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j <= s.size(); ++j) {
                int max_index = 0;
                int res = 0;
                bool ok = true;
                int mask[26] = {0}; // 记录出现次数 mask
                for (int l = i; l < j; ++l) {
                    mask[s[l] - 'a']++;
                }
                for (int m = i; m < j; ++m) {
                    if (mask[s[m] - 'a'] < k) {
                        res = max(res, dp[max_index][m]);
                        ok = false;
                        max_index = m + 1;
                    }
                }
                dp[i][j] = ok ? j - i : max(res, dp[max_index][j]);
            }
        }
        return dp[0][s.size()];
    }
};


int main() {
    vector<vector<bool>> road;
    road.emplace_back(vector<bool>());
    road.emplace_back(vector<bool>());
    string s = "ababbc";
    int k = 2;
    cout << Solution().longestSubstring(s, k) << endl;
    return 0;
}