//
// Created by xulzee on 2019/1/23.
//
#ifndef LEETCODEPROJECTCPP_UTILS_H
#define LEETCODEPROJECTCPP_UTILS_H

#include <iostream>
#include <vector>
using namespace std;

inline void printIntVector(const vector<int>& vec){
    for (auto& iter : vec) {
        cout << iter << " ";
    }
}

inline void printCharVector(const vector<char>& vec){
    for (auto& iter : vec) {
        cout << iter << " ";
    }
}

#endif //LEETCODEPROJECTCPP_UTILS_H
