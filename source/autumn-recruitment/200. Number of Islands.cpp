//
// Created by liuze.xlz on 2019-08-26.
//
#include "utils.h"

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> &grid, int row, int column) {
        if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || grid[row][column] != '1') {
            return;
        }

        grid[row][column] = '0';
        dfs(grid, row + 1, column);
        dfs(grid, row - 1, column);
        dfs(grid, row, column + 1);
        dfs(grid, row, column - 1);
    }
};

int main() {
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};

    cout << Solution().numIslands(grid) << endl;
}

