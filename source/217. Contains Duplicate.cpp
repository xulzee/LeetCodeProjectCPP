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
    bool containsDuplicate1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto i = nums.begin() + 1; i < nums.end(); ++i) {
            if (*i == *(i - 1)) {
                return true;
            }
        }
        return false;
    }

};

int main() {
    vector<int> A = {1,2,2};
    cout << Solution().containsDuplicate(A) << endl;
}
