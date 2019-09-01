// @Time    : 2019/4/9 10:50
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
    bool wordBreak(string s, vector<string> &wordDict) {
        Trie *trie = new Trie();
        for (const auto &str : wordDict) {
            trie->insert(str);
        }
        return dynamicProcess(s, trie);
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
            } else{
                break;
            }
        }
        return cur;
    }

    bool dynamicProcess(string &s, Trie *trie) {
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
                    } else{
                        break;
                    }
                }
                dp[i] = cur;
            }
        }
        return dp[0];
    }
};

int main() {
    string test = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << Solution().wordBreak(test, wordDict) << endl;
}