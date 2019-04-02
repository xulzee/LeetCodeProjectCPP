//
// Created by xulzee on 2019/2/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/utils.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (auto i = nums.begin(); i < nums.end(); ++i) {
            a ^= *i;
        }
        return a;
    }
};

int main() {
    vector<int> A = {4,1,2,1,2};
    cout << Solution().singleNumber(A) << endl;
}


