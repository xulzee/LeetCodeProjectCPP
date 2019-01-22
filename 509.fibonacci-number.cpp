//
// Created by xulzee on 2019/1/22.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int fib1(int N) {
        if (N < 2) {
            return N;
        }
        return fib(N-1) + fib(N-2);
    }

    int fib(int N){
        if (N < 2) {
            return N;
        }
        int fn = 0, fn_1 = 1, fn_2 = 0;
        while (N>=2) {
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
            N--;
        }
        return fn;
    }
};

int main() {
    cout << "Expected result is " << "5 " << endl;
    int N = 5;
    cout << "Our Solution result is " << Solution().fib(N) << endl;
}
