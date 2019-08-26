//
// Created by liuze.xlz on 2019-08-26.
//

#include "utils.h"

class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int begin = 0;
        int end = height.size() - 1;
        while (begin < end) {
            res = max(res, (end - begin) * min(height[end], height[begin]));
            if (height[begin] < height[end]){
                ++begin;
            } else{
                --end;
            }
        }
        return res;
    }
};