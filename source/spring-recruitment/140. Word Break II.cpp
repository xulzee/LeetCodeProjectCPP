// @Time    : 2019/4/9 13:10
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class TrieNode {
public:
    int path;
    int end;
    TrieNode *next[26]{};

    TrieNode() {
        path = 0;
        end = 0;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string &s) {
        if (s.empty()) {
            return;
        }
        TrieNode *cur = root;
        for (auto c : s) {
            if (cur->next[c - 'a'] == nullptr) {
                cur->next[c - 'a'] = new TrieNode();
            }
            cur = cur->next[c - 'a'];
            cur->path++;
        }
        cur->end++;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty()) {
            return false;
        }
        int index = 0;
        TrieNode *cur = root;
        for (char &i : word) {
            index = i - 'a';
            if (cur->next[index] == nullptr) {
                return false;
            }
            cur = cur->next[index];
        }
        return cur->end != 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.empty()) {
            return false;
        }
        int index = 0;
        TrieNode *cur = root;
        for (auto i = prefix.begin(); i < prefix.end(); ++i) {
            index = *i - 'a';
            if (cur->next[index] == nullptr) {
                return false;
            }
            cur = cur->next[index];
        }
        return true;
    }
};

class Solution {
public:
    vector<string> res;

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        Trie *trie = new Trie();
        for (auto str : wordDict) {
            trie->insert(str);
        }
        dynamicProcess(s, trie);
        return res;
    }


    bool process(string &s, Trie *trie, int left, int right) {// s[0 ~ right] 是否可以由 wordSet 构成
        if (left == right) {
            return true;
        }
        bool cur = false;
        for (int i = 0; i < right - left; ++i) {
            if (trie->startsWith(s.substr(left, i + 1))) {
                auto temp = s.substr(left, i + 1);
                if (trie->search(s.substr(left, i + 1))) {
                    cur = cur || process(s, trie, left + i + 1, right);
                }
            } else {
                break;
            }
        }
        return cur;
    }

    void dynamicProcess(string &s, Trie *trie) {
        deque<bool> dp(s.size() + 1, false); // i ~ end 是否可以由 wordSet 构成
        int right = s.size();
        for (int i = s.size(); i >= 0; --i) { // left
            if (right == i) {
                dp[i] = true;
            } else {
                bool cur = false;
                for (int k = 0; k < right - i; ++k) {
                    if (trie->startsWith(s.substr(i, k + 1))) {
                        if (trie->search(s.substr(i, k + 1))) {
                            cur = cur || dp[i + k + 1];
                        }
                    } else {
                        break;
                    }
                }
                dp[i] = cur;
            }
        }
        dfs(trie, s, "", 0, dp);
    }

    void dfs(Trie *trie, const string &s, string curSentence, int pos, const deque<bool> &dp) {
        if (pos == s.size()) {
            res.push_back(curSentence.substr(0, curSentence.size() - 1));
        }
        string tmp = curSentence;
        for (int i = 0; i < s.size() - pos; ++i) {
            if (dp[pos + i + 1] && trie->search(s.substr(pos, i + 1))) {
                auto temp = s.substr(pos, i + 1);
                curSentence.append(s.substr(pos, i + 1)).append(" ");
                dfs(trie, s, curSentence, pos + i + 1, dp);
                curSentence = tmp;
            }
        }
    }
};

int main() {
    string test = "catcatgcatcatg";
    vector<string> wordDict = {"cat", "catg"};
    Solution().wordBreak(test, wordDict);
}