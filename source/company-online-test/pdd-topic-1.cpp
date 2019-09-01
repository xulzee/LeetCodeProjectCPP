//
// Created by xulzee on 2019/9/1.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


int main() {
    vector<int> nums;
    string input;
    cin >> input;

    vector<string> split_result = SplitByStringItem(input, ';');
    nums = SplitByIntItem(split_result[0], ',');
    int n = stoi(split_result[1]);

    vector<int> odd;
    vector<int> even;
    sort(nums.begin(), nums.end(), [](int &num1, int &num2) { return num1 >= num2; });
    for (auto &num : nums) {
        if (num % 2 == 0) {
            even.push_back(num);
        } else {
            odd.push_back(num);
        }
    }

    int flag = n;
    auto iter_odd = odd.begin();
    auto iter_even = even.begin();
    while (n > 0) {
        if (n != flag) {
            cout << ",";
        }
        if (iter_even != even.end()) {
            cout << *iter_even;
            --n;
            ++iter_even;
            continue;
        }
        if (iter_odd != odd.end()) {
            cout << *iter_odd;
            --n;
            ++iter_odd;
        }
    }
    cout << endl;
}