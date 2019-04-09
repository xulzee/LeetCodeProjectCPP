// @Time    : 2019/4/9 20:02
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>
#include <vector>

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
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string &s) {
        if (s.empty()) {
            return;
        }
        TrieNode *cur = root;
        for (const auto &item : s) {
            if (cur->next[item - 'a'] == nullptr) {
                cur->next[item - 'a'] = new TrieNode();
            }
            cur = cur->next[item - 'a'];
            cur->path++;
        }
        cur->end++;
    }

    bool search(const string &s) {
        if (s.empty()) {
            return false;
        }
        TrieNode *cur = root;
        for (const auto &item : s) {
            if (cur->next[item - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[item - 'a'];
        }
        return cur->end != 0;
    }

    bool startWith(const string &prefix){
        if (prefix.empty()){
            return false;
        }
        TrieNode *cur = root;
        for (const auto &item : prefix) {
            if (cur->next[item - 'a'] == nullptr){
                return false;
            }
            cur = cur->next[item - 'a'];
        }
        return true;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

    }
};
