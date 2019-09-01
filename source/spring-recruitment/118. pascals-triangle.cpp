//
// Created by xulzee on 2019/1/23.
//
#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        for (int row_index = 0; row_index < numRows ; ++row_index) {
            vector<int> current(row_index+1, 0);
            current[0] = 1;
            current[row_index] = 1;
            for (int column_index = 1; column_index < row_index; ++column_index) {
                current[column_index] = output[row_index-1][column_index-1] + output[row_index-1][column_index];
            }
            output.push_back(current);
        }
        return output;
    }
};


int main() {
    int N = 5;
    vector<vector<int>> output = Solution().generate(5);
    for(auto& iter : output){
        printIntVector(iter);
        cout << endl;
    }
}

