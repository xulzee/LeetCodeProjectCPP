//
// Created by liuze.xlz on 2019-07-30.
//
#include "utils.h"

class Solution {
public:
    void rotate1(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i; j < matrix[0].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (auto &k : matrix) {
            reverse(k.begin(), k.end());
        }
    }

    void rotate(vector<vector<int>> &matrix) {

    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    Solution().rotate(matrix);
    for (const auto &item : matrix) {
        printIntVector(item);
        cout << endl;
    }
}

