// @Time    : 2019/2/27 16:10
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix.size(); ++j) {
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
                matrix[j][i] = matrix[i][j] ^ matrix[j][i];
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
            }
            reverse(matrix[i].begin(), matrix[i].end());
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