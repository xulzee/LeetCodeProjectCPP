//
// Created by xulzee on 2020/3/21.
//


#include "utils.h"

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        stack<pair<int, int>> rec_stk;
        rec_stk.emplace(0, 0);
        auto hash_func = [](const pair<int, int> &o) {
            return hash<int>()(o.first) ^ hash<int>()(o.first);
        };
        unordered_set<pair<int, int>, decltype(hash_func)> state(0, hash_func);
        while (!rec_stk.empty()) {
            if (state.find(rec_stk.top()) != state.end()) {
                rec_stk.pop();
                continue;
            }
            state.emplace(rec_stk.top());

            int remain_x = rec_stk.top().first;
            int remain_y = rec_stk.top().second;
            rec_stk.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                return true;
            }
            rec_stk.emplace(x, remain_y);
            rec_stk.emplace(remain_x, y);
            rec_stk.emplace(0, remain_y);
            rec_stk.emplace(remain_x, 0);
            rec_stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
            rec_stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
        }
        return false;
    }
};
