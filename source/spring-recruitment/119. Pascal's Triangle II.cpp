// @Time    : 2019/3/30 21:26
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }

    vector<int> getRow1(int rowIndex) {
        vector<vector<int>> res;
        for (int i = 0; i <= rowIndex; ++i) {
            vector<int> temp(i+1, 1);
            for (int j = 1; j < i; ++j) {
                temp[j] = res[i - 1][j] + res[i - 1][j - 1];
            }
            res.push_back(temp);
        }
        return res[rowIndex];
    }
};

int main(){
    int test = 3;
    vector<int> temp = Solution().getRow(test);
    int temp1 = test;
}
