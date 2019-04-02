// @Time    : 2019/3/30 21:07
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^y;
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (n >> i) & 1 == 1 ? res + 1 : res;
        }
        return res;
    }
};