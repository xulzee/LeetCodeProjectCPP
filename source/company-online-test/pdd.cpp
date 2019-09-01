//
// Created by xulzee on 2019/9/1.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <list>

using namespace std;


int main() {
    vector<int> nums;
    string input;
    cin >> input;

    string temp;
    stringstream ss;
    ss.str(input);

    string nums_str;
    getline(ss, nums_str, ';');
    getline(ss, temp, ';');

    int n = stoi(temp);
    ss.clear();
    ss.str(input);

    while (true) {
        if (!getline(ss, temp, ',')) {
            break;
        }
        nums.push_back(stoi(temp));
    }

    vector<int> odd;
    vector<int> even;
    for (auto &num : nums) {
        if (num % 2 == 0) {
            even.push_back(num);
        } else{
            odd.push_back(num);
        }
    }
    sort(odd.begin(), odd.end(), [](int &s1, int &s2) { return s1 >= s2; });
    sort(even.begin(),even.end(), [](int &s1, int &s2) { return s1 >= s2; });

    int flag = n;
    auto iter_odd = odd.begin();
    auto iter_even = even.begin();
    while (n > 0){
        if (n != flag){
            cout << ",";
        }
        if(iter_even != even.end()){
            cout << *iter_even;
            --n;
            ++iter_even;
            continue;
        }
        if(iter_odd != odd.end()){
            cout << *iter_odd;
            --n;
            ++iter_odd;
        }
    }
    cout << endl;
}