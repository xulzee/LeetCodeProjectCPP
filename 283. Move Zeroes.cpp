// @Time    : 2019/2/27 11:56
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
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[count] = nums[i];
                ++count;
            }
        }
        for (int j = count; j < nums.size(); ++j) {
            nums[j] = 0;
        }
    }
};

int main() {
    vector<int> A = {0,1,0,3,12};
    Solution().moveZeroes(A);
    printIntVector(A);
}
