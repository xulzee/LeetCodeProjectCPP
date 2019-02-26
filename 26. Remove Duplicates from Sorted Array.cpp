//
// Created by Txin on 2019/2/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        if (!nums.empty()) {
//            for (auto i = nums.begin() + 1; i < nums.end() ; ++i) {
//                if (*i != *(i-1)) {
//                    nums[j] = *i;
//                    ++j;
//                }
//            }
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] != nums[i-1]) {
                    nums[j] = nums[i];
                    ++j;
                }
            }
        } else {
            j = 0;
        }
        return j;
    }
};

int main() {
    vector<int> A = {1,1,2};
    cout << Solution().removeDuplicates(A) << endl;
    printIntVector(A);
}