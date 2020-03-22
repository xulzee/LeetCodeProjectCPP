//
// Created by xulzee on 2020/3/16.
//

#include "utils.h"

class Solution {
public:
    string compressString(string S) {
        if (S.empty()) {
            return S;
        }
        char cur;
        string res;
        int count = 0;
        for (int i = 0; i < S.size(); ++i) {
            cur = S[i];
            count = 1;
            res += cur;
            while (++i < S.size()) {
                if (S[i] == cur) {
                    ++count;
                } else {
                    --i;
                    break;
                }
            }
            res += to_string(count);
        }
        return res.size() < S.size() ? res : S;
    }
};

int main() {
    string s = "aabcccccaaa";
    cout << Solution().compressString(s) << endl;
}