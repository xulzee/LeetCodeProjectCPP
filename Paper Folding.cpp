// @Time    : 2019/3/20 17:48
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <sys/types.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void printAllFolds(int n) {
        if (n == 0) {
            return;
        }
        process(1, n, "down");
    }

    void process(int currentlevel, int totallevel, const string &up_down) {
        if (currentlevel > totallevel) {
            return;
        }
        process(currentlevel + 1, totallevel, "down");
        cout << up_down << endl;
        process(currentlevel + 1, totallevel, "up");
    }
};

int main(){
    int n = 3;
    Solution().printAllFolds(n);
}