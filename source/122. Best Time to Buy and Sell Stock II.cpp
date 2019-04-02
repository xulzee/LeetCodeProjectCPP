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
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (auto i = prices.begin() + 1; i < prices.end() ; ++i) {
            if (*i > *(i-1)) {
                profit += *i - *(i-1);
            }
        }
        return profit;
    }
};

int main() {
    vector<int> A = {7,1,5,3,6,4};
    cout << Solution().maxProfit(A) << endl;
    printIntVector(A);
}
