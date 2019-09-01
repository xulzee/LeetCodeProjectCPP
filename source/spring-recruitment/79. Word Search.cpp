// @Time    : 2019/4/9 20:02
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>
#include <vector>
#include <iostream>
#include <queue>

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

    bool startWith(const string &prefix) {
        if (prefix.empty()) {
            return false;
        }
        TrieNode *cur = root;
        for (const auto &item : prefix) {
            if (cur->next[item - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[item - 'a'];
        }
        return true;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || word.empty()) {
            return false;
        }
        bool res = false;
        for (int i = 0; i < board.size(); ++i) { // row
            for (int j = 0; j < board[0].size(); ++j) { // column
                if (board[i][j] == word[0]) {
                    res = res || dfs(board, word, 0, j, i);
                    if (res) {
                        return res;
                    }
                }
            }
        }
        return res;
    }

    bool dfs(vector<vector<char>> &board, string &word, int wordPosition, int column,
             int row) { // 回溯
        if (wordPosition == word.size()) {
            return true;
        }
        if (column < 0 || column > board[0].size() - 1 || row < 0 || row > board.size() - 1 ||
            board[row][column] == '#') {
            return false;
        }
        bool ret = false;
        if (board[row][column] == word[wordPosition]) {
            char cur = word[wordPosition];
            board[row][column] = '#';
            ret = ret || dfs(board, word, wordPosition + 1, column, row + 1)
                  || dfs(board, word, wordPosition + 1, column, row - 1)
                  || dfs(board, word, wordPosition + 1, column + 1, row)
                  || dfs(board, word, wordPosition + 1, column - 1, row);
            board[row][column] = cur;
        }
        return ret;
    }
};

int main() {
    string test = "ab";
    vector<vector<char>> board = {{'a'}};
    cout << Solution().exist(board, test) << endl;
}
