//
// Created by xulzee on 2020/3/15.
//
#include "utils.h"

class Solution {
public:
    int dfs(vector<vector<int>> &grid, int row, int column) {
        if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || grid[row][column] == 0) {
            return 0;
        }
        grid[row][column] = 0;
        return dfs(grid, row + 1, column) + dfs(grid, row - 1, column) +
                dfs(grid, row, column + 1) + dfs(grid, row, column - 1) + 1;
    }


    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int res = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int column = 0; column < grid[0].size(); ++column) {
                res = max(res, dfs(grid, row, column));
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << Solution().maxAreaOfIsland(grid) << endl;
}