// @Time    : 2019/3/29 14:37
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) {
            return 0;
        }
        return dynamicProcess(grid);
    }

private:
    // row, column 表示当前所在位置
    int process(vector<vector<int>> &grid, int row, int column) {
        int res = grid[row][column];
        if (row == grid.size() - 1 && column == grid[0].size() - 1) {
            return res;
        }
        if (column == grid[0].size() - 1) {
            return res + process(grid, row + 1, column);
        } else if (row == grid.size() - 1) {
            return res + process(grid, row, column + 1);
        } else {
            return res + min(process(grid, row + 1, column), process(grid, row, column + 1));
        }
    }

    int dynamicProcess(vector<vector<int>> &grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        int row_len = grid.size();
        int column_len = grid[0].size();
        dp[row_len - 1][column_len - 1] = grid[row_len - 1][column_len - 1];
        for (int i = column_len - 2; i >= 0; --i) {
            dp[row_len - 1][i] = dp[row_len - 1][i + 1] + grid[row_len - 1][i];
        }
        for (int j = row_len - 2; j >= 0; --j) {
            dp[j][column_len - 1] = dp[j + 1][column_len - 1] + grid[j][column_len - 1];
        }
        for (int k = row_len - 2; k >= 0 ; --k) {
            for (int i = column_len - 2; i >= 0 ; --i) {
                dp[k][i] = grid[k][i] + min(dp[k][i + 1], dp[k + 1][i]);
            }
        }
        return dp[0][0];
    }
};

int main() {
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout << Solution().minPathSum(grid) << endl;
}