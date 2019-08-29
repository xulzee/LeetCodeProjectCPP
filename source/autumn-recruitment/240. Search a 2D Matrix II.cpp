//
// Created by liuze.xlz on 2019-08-28.
//
#include "utils.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int row = matrix.size() - 1, column = 0;
        while (row >= 0 && column < matrix[0].size()) {
            if (matrix[row][column] == target) {
                return true;
            }
            if (matrix[row][column] < target) {
                ++column;
            } else if (matrix[row][column] > target) {
                --row;
            } else {
                return false;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,  4,  7,  11, 15},
                                  {2,  5,  8,  12, 19},
                                  {3,  6,  9,  16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    cout << Solution().searchMatrix(matrix, 20) << endl;

}
