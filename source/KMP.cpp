// @Time    : 2019/4/8 16:20
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> getNext(const string &s) {
    if (s.size() <= 1) {
        return {-1};
    }
    vector<int> next(s.size(), -1);
    int i = 1; // cur
    int j = -1; // pre
    while (i < s.size()) {
        if (j == -1 || s[i - 1] == s[j]) {
            next[i++] = j + 1;
            j++; // next[i -1]
        } else {
            j = next[j];
        }
    }
    return next;
}

int getIndexOf(const string &s, const string &t) {
    if (s.empty() || t.empty() || s.size() < t.size()) {
        return -1;
    }
    vector<int> next = getNext(t);
    int i = 0;
    int j = 0;
    while (i < s.size() && j < int(t.size())) {
        if (j == -1 || s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == t.size()) {
        return i - j;
    } else {
        return -1;
    }
}

int canArrangWords(int num, char **arr) {
    vector<int> preMap(26, 0);
    for (int i = 0; i < num; ++i) {
        char pre = arr[i][0];
        char end = arr[i][strlen(arr[i]) - 1];
        preMap[pre - 'a']++;
        if (end != pre) {
            preMap[end - 'a']--;
        }
    }
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        if (preMap[i] != 0) {
            res++;
        }
    }
    return res == 2 ? 1 : -1;
}

int main() {
    string s = "123qweabababab123";
    string test = "abababab";
    auto ret = getIndexOf(s, test);
    char c[4][8]={{"ab"},{"bc"},{"cd"}};

}



