//
// Created by xulzee on 2019/2/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    void rotate1(vector<int>& nums, int k) {
        for (int i = 0; i < k ; ++i) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }

    void rotate(vector<int>& nums, int k) {
        int l = static_cast<int>(nums.size());
        k %= l;
        if (k > 0)
        {
            reverse(nums.begin(), nums.end() - k);
            reverse(nums.end() - k, nums.end());
            reverse(nums.begin(), nums.end());
        }
    }
};

int main() {
    vector<int> A = {1,2};
    int k = 1;
    Solution().rotate(A, k);
    printIntVector(A);
}