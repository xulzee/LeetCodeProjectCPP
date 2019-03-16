// @Time    : 2019/3/16 15:17
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int horizon_column = 0;
        int horizon_row = 0;
        int vertical_column = 0;
        int vertical_row = 0;
        int end_row = static_cast<int>(matrix.size()) - 1;
        int end_column = static_cast<int>(matrix[0].size()) - 1;
        bool flag = true;
        while (horizon_column <= end_column && horizon_row <= end_row) {
            printLevel(matrix, horizon_row, horizon_column, vertical_row, vertical_column, flag, res);
            horizon_row = horizon_column == end_column ? horizon_row + 1 : horizon_row;
            horizon_column = horizon_column == end_column ? horizon_column : horizon_column + 1;
            vertical_column = vertical_row == end_row ? vertical_column + 1 : vertical_column;
            vertical_row = vertical_row == end_row ? vertical_row : vertical_row + 1;
            flag = !flag;
        }
        return res;
    }

    void
    printLevel(vector<vector<int>> &matrix, int horizon_row, int horizon_column, int vertical_row, int vertical_column,
               bool flag, vector<int> &res) {
        if (flag) {
            while (vertical_column <= horizon_column) {
                res.push_back(matrix[vertical_row--][vertical_column++]);
            }
        } else {
            while (horizon_column >= vertical_column) {
                res.push_back(matrix[horizon_row++][horizon_column--]);
            }
        }
    }

};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    vector<int> res = Solution().findDiagonalOrder(matrix);
    printIntVector(res);
}