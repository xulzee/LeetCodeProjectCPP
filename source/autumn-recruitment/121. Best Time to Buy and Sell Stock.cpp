//
// Created by liuze.xlz on 2019-08-05.
//
#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int min_price = prices[0];
        int max_profit = 0;
        for (int price : prices) {
            if (price <= min_price) {
                min_price = price;
            }
            if (max_profit < price - min_price) {
                max_profit = price - min_price;
            }
        }
        return max_profit;
    }
};
