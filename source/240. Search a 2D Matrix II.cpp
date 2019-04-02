// @Time    : 2019/3/31 14:14
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int cur_row = 0, cur_column = matrix[0].size() - 1;
        int last_value = matrix[cur_row][cur_column];
        int row_len = matrix.size() - 1, column_len = matrix.size() - 1;
        while (cur_row <= row_len && cur_column >= 0) {
            if (target > matrix[cur_row][cur_column]) {
                cur_row++;
            } else if (target < matrix[cur_row][cur_column]) {
                cur_column--;
            } else {
                return true;
            }
        }
        return false;
    }
};
