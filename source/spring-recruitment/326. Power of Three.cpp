// @Time    : 2019/3/30 19:44
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree1(int n) {
        if (n == 0) {
            return true;
        }
        while (n % 3 == 0) {
            n = n / 3;
        }
        return n == 1;
    }

    bool isPowerOfThree(int n) {
        return max % 3 == 0;
    }

private:
    int max = 1162261467;
};


int main() {
    int test = 4;
    cout << Solution().isPowerOfThree(test) << endl;
}
