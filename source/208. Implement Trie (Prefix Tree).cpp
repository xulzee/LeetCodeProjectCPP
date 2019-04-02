// @Time    : 2019/3/24 16:43
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <string>
#include <array>
#include <cstring>

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

    ~TrieNode() {
        delete *next;
    }
};

class Trie {
public:
    TrieNode *root;

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        if (word.empty()) {
            return;
        }
        int index = 0;
        TrieNode *cur = root;
        for (auto i = word.begin(); i != word.end(); ++i) {
            index = *i - 'a';
            if (cur->next[index] == nullptr) {
                cur->next[index] = new TrieNode();
            }
            cur = cur->next[index];
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
        for (auto i = word.begin(); i != word.end(); ++i) {
            index = *i - 'a';
            if (cur->next[index] == nullptr) {
                return false;
            }
            cur = cur->next[index];
        }
        return cur->end != 0;
    }


    void deleteWord(string word) {
        if (!search(word)) {
            return;
        }
        int index = 0;
        TrieNode *cur = root;
        for (auto i = word.begin(); i != word.end(); ++i) {
            index = *i - 'a';
            cur->next[index]->path--;
            if (cur->next[index]->path == 0) {
                cur->next[index] = nullptr;
                return;
            }
            cur = cur->next[index];
        }
        cur->end--;
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

int main() {
    Trie *trie = new Trie;
    trie->insert("xaaxw");
    trie->insert("xaaxw1");
    trie->insert("xaaxw2");
    trie->insert("xaaxw3");
    cout << trie->search("xaaxw") << endl;
    trie->deleteWord("xaaxw");
    cout << trie->search("xaaxw") << endl;
    trie->insert("xa1axw");
    trie->insert("xa2axw");
    cout << trie->search("xa") << endl;
    cout << trie->startsWith("x") << endl;
}