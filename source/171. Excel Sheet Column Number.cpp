// @Time    : 2019/4/12 10:42
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(const string &s) {
        long long res = 0;
        long long weight = 1;
        for (auto item = s.rbegin(); item != s.rend(); ++item) {
            res += (*item - 'A' + 1) * weight;
            weight *= 26;
        }
        return res;
    }
};