//
// Created by xulzee on 2019/2/26.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hashmap{};
        int another_num = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            another_num = target - nums[i];
            if (hashmap.find(another_num) != hashmap.end())
                return vector<int>{hashmap[another_num], i};
            hashmap[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main() {

    const int M = 1000000007;
    const int MAXN = 100;
    int C[MAXN+1][MAXN+1];

    int i,j;
//    for(i=0; i<=MAXN; ++i)
//    {
//        C[0][i] = 0;
//        C[i][0] = 1;
//    }
    for(i=0; i<=MAXN; ++i)
    {
        C[0][i] = 0;
        C[i][0] = 1;
        for(j=1; j<=MAXN; ++j)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
    }
    vector<int> A = {2, 7, 11, 15};
    int target = 9;
    printIntVector(Solution().twoSum(A, target));
}
