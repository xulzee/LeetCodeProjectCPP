//
// Created by xulzee on 2019/1/24.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        while (b != 0){
            c = a ^ b;
            b = (a & b) << 1;
            a = c;
        }
        return c;
    }
};

int main() {
    cout << "Expected result is " << "0 " << endl;
    int a = 1;
    int b = -1;
    cout << "Our solution result is " << Solution().getSum(a, b) << endl;
}