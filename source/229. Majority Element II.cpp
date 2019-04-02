// @Time    : 2019/3/31 13:18
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int x = 0, y = 0;
        int count_x = 0, count_y = 0;
        for (int num : nums) {
            if ((count_x == 0 || num == x) && num != y) {
                x = num;
                count_x++;
            } else if (count_y == 0 || num == y) {
                y = num;
                count_y++;
            } else {
                count_x--;
                count_y--;
            }
        }
        count_x = 0;
        count_y = 0;
        for (int num : nums) {
            count_x = num == x ? count_x + 1 : count_x;
            count_y = num == y ? count_y + 1 : count_y;
        }
        vector<int> res;
        if (count_x > nums.size() / 3) {
            res.push_back(x);
        }
        if (x != y && count_y > nums.size() / 3) {
            res.push_back(y);
        }
        return res;
    }
};

int main() {
    vector<int> test = {0,0,0};
    Solution().majorityElement(test);
}
