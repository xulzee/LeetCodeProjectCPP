// @Time    : 2019/4/14 20:45
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int rowLen = matrix.size();
        int left = matrix[0][0];
        int right = matrix.back().back();
        while (left < right) {
            int count = 0;
            int mid = left + ((right - left) >> 1);
            for (const auto &item : matrix) {
                count += upper_bound(item.begin(), item.end(), mid) - item.begin();
            }
            if (count < k){
                left = mid + 1;
            } else{
                right = mid;
            }
        }
        return left;
    }
};