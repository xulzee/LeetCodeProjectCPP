// @Time    : 2019/4/10 23:34
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>
#include <climits>
#include <iostream>

using namespace std;
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int a = INT_MAX;
        int b = INT_MAX;
        for (const auto &item : nums) {
            if (item <= a) {
                a = item;
            } else if (item <= b) {
                b = item;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> test = {5,4,3,2,1};
    cout << Solution().increasingTriplet(test) << endl;
}