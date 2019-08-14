//
// Created by liuze.xlz on 2019-08-12.
//

#include "utils.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            if (i == 0) {
                res.push_back({1});
            } else if (i == 1) {
                res.push_back({1, 1});
            } else {
                vector<int> tmp(vector<int>(i + 1, 0));
                for (int j = 0; j <= i; ++j) {
                    if (j == 0 || j == i) {
                        tmp[j] = 1;
                    } else {
                        tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
                    }
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};

int main() {
    Solution().generate(5);
}
