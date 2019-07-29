// @Time    : 2019/4/15 18:08
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(const string &beginWord, const string &endWord, vector<string> &wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        queue<pair<string, int>> wordQueue;
        wordQueue.push(make_pair(beginWord, 1));
        while (!wordQueue.empty()) {
            pair<string, int> cur = wordQueue.front();
            wordQueue.pop();
            if (cur.first == endWord) {
                return cur.second;
            }
            for (int i = 0; i < cur.first.size(); ++i) {
                char c = cur.first[i];
                for (int j = 0; j < 26; ++j) {
                    cur.first[i] = 'a' + j;
                    if (wordDict.find(cur.first) != wordDict.end()) {
                        wordQueue.push(make_pair(cur.first, cur.second + 1));
                        wordDict.erase(cur.first);
                    }
                }
                cur.first[i] = c;
            }
        }
        return 0;
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << Solution().ladderLength(beginWord, endWord, wordList);
}