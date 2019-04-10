// @Time    : 2019/4/11 0:09
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        if (nums.empty()) {
            return {0};
        }
        vector<int> res(nums.size(), 1);
        int help = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = help;
            help *= nums[i];
        }
        help = 1;
        for (int j = nums.size() - 1; j >= 0; --j) {
            res[j] *= help;
            help *= nums[j];
        }
        return res;
    }
};
