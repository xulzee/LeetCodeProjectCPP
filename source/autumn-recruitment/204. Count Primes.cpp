//
// Created by liuze.xlz on 2019-08-11.
//
#include "utils.h"

class Solution {
public:
    int countPrimes(int n) {
        deque<bool> is_prime(n + 1, true);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                ++res;
                for (long j = (long) i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return res;
    }
};

int main() {
    cout << Solution().countPrimes(10) << endl;
}