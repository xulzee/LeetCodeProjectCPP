// @Time    : 2019/2/27 14:59
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
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<unordered_map<char, char>> row(9);
        vector<unordered_map<char, char>> column(9);
        vector<unordered_map<char, char>> box(9);
        int box_index = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                auto iter_row = row[i].find(board[i][j]);
                auto iter_column = column[j].find(board[i][j]);
                auto iter_box = box[(i / 3) * 3 + j / 3].find(board[i][j]);
                if (iter_row != row[i].end() || iter_column != column[j].end() ||
                    iter_box != box[(i / 3) * 3 + j / 3].end()) {
                    return false;
                }
                row[i][board[i][j]] = 1;
                column[j][board[i][j]] = 1;
                box[(i / 3) * 3 + j / 3][board[i][j]] = 1;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> A = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << Solution().isValidSudoku(A) << endl;
}