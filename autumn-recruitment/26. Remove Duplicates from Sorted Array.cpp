// @Time    : 2019/7/9 23:27
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>
#include "utils.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        int res = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[res] = nums[i];
                ++res;
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << Solution().removeDuplicates(nums) << endl;
    printIntVector(nums);
}