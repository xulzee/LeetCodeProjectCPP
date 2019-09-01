// @Time    : 2019/4/10 22:57
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        vector<pair<int, int>> ret(nums.size(), pair<int, int>(0, 0));
        int res = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i == nums.size() - 1) {
                ret[i] = {nums[i], nums[i]};
            } else {
                ret[i].first = max(nums[i], max(nums[i] * ret[i + 1].first, nums[i] * ret[i + 1].second));
                ret[i].second = min(nums[i], min(nums[i] * ret[i + 1].first, nums[i] * ret[i + 1].second));
            }
            if (ret[i].first > res) {
                res = ret[i].first;
            }
        }
        return res;
    }

    // return (max, min)
    // 以 cur 开头
    pair<int, int> process(const vector<int> &nums, int cur) {
        if (cur == nums.size() - 1) {
            return {nums[cur], nums[cur]};
        }
        pair<int, int> ret = process(nums, cur + 1);
        pair<int, int> res;
        res.first = max(nums[cur], max(nums[cur] * ret.first, nums[cur] * ret.second));
        res.second = min(nums[cur], min(nums[cur] * ret.first, nums[cur] * ret.second));
        return res;
    }
};

int main() {
    vector<int> test = {0, 2};
    cout << Solution().maxProduct(test) << endl;
}