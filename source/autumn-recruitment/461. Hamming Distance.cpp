//
// Created by liuze.xlz on 2019-08-12.
//
#include "utils.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int res = 0;
        while (n != 0) {
            ++res;
            n &= (n - 1);
        }
        return res;
    }
};

int main(){
    cout << Solution().hammingDistance(1, 4) << endl;
}
