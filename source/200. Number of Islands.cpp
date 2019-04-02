//
// Created by xulzee on 2019/3/23.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) {
            return 0;
        }
        int res = 0;
        int column_len = static_cast<int>(grid[0].size() - 1);
        int row_len = static_cast<int>(grid.size() - 1);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    res++;
                    infect(grid, i, j, column_len, row_len);
                }
            }
        }
        return res;
    }

    void infect(vector<vector<char>> &grid, int i, int j, int column_len, int row_len) {
        if (i < 0 || j < 0 || i > column_len || j > row_len || grid[i][j] != 1){
            return;
        }
        grid[i][j] = '2';
        infect(grid, i, j + 1, column_len, row_len);
        infect(grid, i, j - 1, column_len, row_len);
        infect(grid, i - 1, j, column_len, row_len);
        infect(grid, i + 1, j, column_len, row_len);
    }
};

