// @Time    : 2019/3/30 21:09
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <stack>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        stack<int> s;
        for (int i = 0; i < 32; ++i) {
            s.push((n >> i) & 1);
        }
        int res = 0;
        for (int j = 0; j < 32; ++j) {
            res = res | (s.top() << j);
            s.pop();
        }
        return res;
    }
};

int main() {
    int test = 0b00000010100101000001111010011100;
    Solution().reverseBits(test);
}
