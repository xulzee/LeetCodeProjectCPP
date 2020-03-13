//
// Created by xulzee on 2020/3/13.
//

#include "utils.h"

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int res = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                res = num;
            }
            count += (num == res) ? 1 : -1;
        }
        return res;
    }
};


int main() {
    vector<int> test = {6, 5, 5};
    cout << Solution().majorityElement(test) << endl;
}