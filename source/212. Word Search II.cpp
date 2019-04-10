// @Time    : 2019/4/10 10:10
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    int end;
    string word;
    TrieNode *next[26]{};

    TrieNode() {
        end = 0;
        word = "";
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
        for (auto c : s) {
            if (cur->next[c - 'a'] == nullptr) {
                cur->next[c - 'a'] = new TrieNode();
            }
            cur = cur->next[c - 'a'];
        }
        cur->end++;
        cur->word = s;
    }
};

class Solution {
public:
    vector<string> res;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie *trie = new Trie();
        for (const auto &word : words) {
            trie->insert(word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, trie->root, i, j);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

    void dfs(vector<vector<char>> &board, TrieNode *cur, int row, int column) {
        if (row < 0 || row > board.size() - 1 || column < 0 || column > board[0].size() - 1 ||
            board[row][column] == '#' || cur->next[board[row][column] - 'a'] == nullptr) {
            return;
        }
        cur = cur->next[board[row][column] - 'a'];
        if (cur->end != 0) {
            res.push_back(cur->word);
            cur->end--;
        }
        char curChar = board[row][column];
        board[row][column] = '#'; // mark char in use
        dfs(board, cur, row + 1, column);
        dfs(board, cur, row - 1, column);
        dfs(board, cur, row, column + 1);
        dfs(board, cur, row, column - 1);
        board[row][column] = curChar; // no longer in use, reset
    }
};

int main() {
//    vector<string> test = {"oath", "pea", "eat", "rain"};
//    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
//                                  {'e', 't', 'a', 'e'},
//                                  {'i', 'h', 'k', 'r'},
//                                  {'i', 'f', 'l', 'v'}};
    vector<string> test = {"a"};
    vector<vector<char>> board = {{'a'}};
    Solution().findWords(board, test);
}
