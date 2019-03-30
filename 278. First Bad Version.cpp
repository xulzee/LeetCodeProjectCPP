// @Time    : 2019/3/29 17:59
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        while (left + 1 < right) {
            mid = left + ((right - left) >> 1);
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isBadVersion(left)) {
            return left;
        }
        if (isBadVersion(right)) {
            return right;
        }
        return -1;
    }
};