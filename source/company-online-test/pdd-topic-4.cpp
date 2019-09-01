//
// Created by xulzee on 2019/9/1.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
int main(){
    int m, n, k;
    cin >> n >> m >> k;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            matrix[i - 1][j - 1] = i * j;
        }
    }

    for (int kI = 0; kI < ; ++kI) {
        
    }
}
