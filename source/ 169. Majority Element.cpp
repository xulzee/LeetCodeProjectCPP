// @Time    : 2019/3/31 12:52
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>

using namespace std;

class Solution {
public:
    // 摩尔投票法
    int majorityElement(vector<int> &nums) {
        int cnt = 1;
        int cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != cur) {
                cnt--;
            } else {
                cnt++;
            }
            if (cnt == 0) {
                cur = nums[i];
                cnt = 1;
            }
        }
        return cur;
    }
};
