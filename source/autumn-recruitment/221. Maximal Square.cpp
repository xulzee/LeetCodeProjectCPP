//
// Created by liuze.xlz on 2019-08-27.
//
#include "utils.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        return DynamicProcess(matrix);
    }

    int process(vector<vector<char>> &matrix, int cur_row, int cur_column) {
        if (cur_row < 0 || cur_row >= matrix.size() || cur_column < 0 || cur_column > matrix[0].size()
                || matrix[cur_row][cur_column] == '0') {
            return 0;
        }
        return min(process(matrix, cur_row - 1, cur_column),
                   min(process(matrix, cur_row - 1, cur_column - 1), process(matrix, cur_row, cur_column - 1))) + 1;

    }

    int DynamicProcess(vector<vector<char>> &matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << Solution().maximalSquare(matrix) << endl;
}

