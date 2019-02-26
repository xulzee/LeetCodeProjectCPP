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
            c = a ^ b; // 不带进位加
            b = (a & b) << 1; //求进位
            a = c;
        }
        return c;
    }
};

int main() {
    cout << "Expected result is " << "0 " << endl;
    int a = 22;
    int b = 44;
    cout << "Our solution result is " << Solution().getSum(a, b) << endl;
}