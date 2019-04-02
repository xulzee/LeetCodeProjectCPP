//
// Created by xulzee on 2019/1/23.
//
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        auto len_a = a.size();
        auto len_b = b.size();
        if (len_a == len_b){
            if(a.compare(b) == 0)
                return -1;
            else
                return len_a;
        }
        else
            return (len_a < len_b) ? len_b : len_a;
    }
};

int main() {
    cout << "Expected result is " << "3 " << endl;
    string a = "aba";
    string b = "cbc";
    cout << "Our solution result is " << Solution().findLUSlength(a, b) << endl;
}