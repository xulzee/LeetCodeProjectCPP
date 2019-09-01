//
// Created by xulzee on 2019/3/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res = {};
        if (matrix.empty()){
            return res;
        }
        int start_row = 0;
        int start_column = 0;
        int end_row = static_cast<int>(matrix.size() - 1);
        int end_column = static_cast<int>(matrix[0].size() - 1);
        while (start_column <= end_column && start_row <= end_row){
            printEdge(matrix, start_row++, start_column++, end_row--, end_column--, res);
        }
        return res;
    }

    void printEdge(vector<vector<int>> &matrix, int start_row, int start_column, int end_row, int end_column,
                   vector<int> &res) {
        if (start_column == end_column) {
            while (start_row <= end_row) {
                res.push_back(matrix[start_row++][start_column]);
            }
        } else if (start_row == end_row) {
            while (start_column <= end_column) {
                res.push_back(matrix[start_row][start_column++]);
            }
        } else {
            int cur_row = start_row;
            int cur_column = start_column;
            while (cur_column < end_column) {
                res.push_back(matrix[cur_row][cur_column++]);
            }
            while (cur_row < end_row) {
                res.push_back(matrix[cur_row++][cur_column]);
            }
            while (cur_column > start_column){
                res.push_back(matrix[cur_row][cur_column--]);
            }
            while (cur_row > start_row){
                res.push_back(matrix[cur_row--][cur_column]);
            }
        }
    }
};
