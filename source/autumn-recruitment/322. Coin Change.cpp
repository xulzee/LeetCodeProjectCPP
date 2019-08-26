//
// Created by liuze.xlz on 2019-08-26.
//
#include "utils.h"

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        return dynamicProcess(coins, amount);
    }

    int process(vector<int> &coins, int target_amount, int cur_amount) {
        if (cur_amount == 0) {
            return 0;
        }

        if (cur_amount < 0) {
            return INT32_MAX;
        }

        int ret = INT32_MAX;
        for (int i = 0; i < coins.size(); ++i) {
            ret = min(ret, process(coins, target_amount, cur_amount - coins[i]));
        }

        return ret == INT32_MAX ? -1 : ret + 1;
    }

    int dynamicProcess(vector<int> &coins, int target_amount) {
        vector<int> dp(target_amount + 1, target_amount + 1);
        dp[0] = 0;

        for (int i = 1; i < dp.size(); ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[target_amount] > target_amount ? -1 : dp[target_amount];
    }
};

int main() {
    vector<int> coins = {1,2,5};
    cout << Solution().coinChange(coins, 11) << endl;
}