// @Time    : 2019/2/27 16:10
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../include/utils.h"

using namespace std;

class Solution {
public:
    void rotate1(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix.size(); ++j) {
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
                matrix[j][i] = matrix[i][j] ^ matrix[j][i];
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    void rotate(vector<vector<int>> &matrix) {
        int start_row = 0;
        int start_column = 0;
        int end_row = static_cast<int>(matrix.size()) - 1;
        int end_column = static_cast<int>(matrix.size()) - 1;
        while (start_row < end_row) {
            rotateEdge(matrix, start_row++, start_column++, end_row--, end_column--);
        }
    }

    void rotateEdge(vector<vector<int>> &matrix, int start_row, int start_column, int end_row, int end_column) {
        int times = end_row - start_row;
        for (int i = 0; i < times; ++i) {
            int temp = matrix[start_row][start_column + i];
            matrix[start_row][start_column + i] = matrix[end_row - i][start_column];
            matrix[end_row - i][start_column] = matrix[end_row][end_column - i];
            matrix[end_row][end_column - i] = matrix[start_row + i][end_column];
            matrix[start_row + i][end_column] = temp;
        }
    }

};

int main() {
    vector<vector<int>> A = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution().rotate(A);
    printIntVector(A[0]);
    printIntVector(A[1]);
    printIntVector(A[2]);
}