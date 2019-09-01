// @Time    : 2019/4/9 18:09
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        dynamicProcess(s);
        return res;
    }

    bool process(const string &s, int i, int j) {
        if (i == j) {
            return true;
        }
        if (i + 1 == j) {
            return s[i] == s[j];
        }
        if (s[i] == s[j]) {
            return process(s, i + 1, j - 1);
        } else {
            return false;
        }
    }

    void dynamicProcess(const string &s) {
        deque<deque<bool>> dp(s.size(), deque<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (j == i) {
                    dp[i][j] = true;
                } else if (j == i + 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }
        vector<string> temp;
        dfs(s, dp, temp, 0);
    }

    void dfs(const string &s, deque<deque<bool>> &dp, vector<string> &cur, int pos) {
        if (pos == s.size()) {
            res.push_back(cur);
        }
        for (int i = 1; i + pos <= s.size(); ++i) {
            if(dp[pos][pos + i - 1]){
                auto temp = s.substr(pos, i);
                cur.push_back(temp);
                dfs(s, dp, cur, pos + i);
                cur.pop_back();
            }
        }
    }

};

int main() {
    string test = "aabaa";
    auto ret = Solution().partition(test);
    return 0;
}
