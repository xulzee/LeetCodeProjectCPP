// @Time    : 2019/3/16 22:01
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
        int row = 0;
        int col = static_cast<int>(matrix[0].size() - 1);
        while (row < matrix.size() && col > -1) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{0,   1,   2,   3,   4,   5,   6},// 0
                                  {10,  12,  13,  15,  16,  17,  18},// 1
                                  {23,  24,  25,  26,  27,  28,  29},// 2
                                  {44,  45,  46,  47,  48,  49,  50},// 3
                                  {65,  66,  67,  68,  69,  70,  71},// 4
                                  {96,  97,  98,  99,  100, 111, 122},// 5
                                  {166, 176, 186, 187, 190, 195, 200},// 6
                                  {233, 243, 321, 341, 356, 370, 380} // 7
    };
    cout << Solution().searchMatrix(matrix, 233) << endl;
}

