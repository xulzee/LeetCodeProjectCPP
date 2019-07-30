//
// Created by liuze.xlz on 2019-07-30.
//
#include "utils.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<unordered_set<char>> row_maps(9, unordered_set<char>());
        vector<unordered_set<char>> column_maps(9, unordered_set<char>());
        vector<unordered_set<char>> box_maps(9, unordered_set<char>());

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != '.') {
                    // check row
                    if (row_maps[i].find(board[i][j]) != row_maps[i].end()) {
                        return false;
                    } else {
                        row_maps[i].insert(board[i][j]);
                    }

                    // check column
                    if (column_maps[j].find(board[i][j]) != column_maps[j].end()) {
                        return false;
                    } else {
                        column_maps[j].insert(board[i][j]);
                    }

                    // check box
                    int index = 3 * (j / 3) + i / 3;
                    if(box_maps[index].find(board[i][j]) != box_maps[index].end()){
                        return false;
                    } else{
                        box_maps[index].insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
