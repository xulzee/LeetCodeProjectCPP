//
// Created by xulzee on 2019/1/23.
//
#ifndef LEETCODEPROJECTCPP_UTILS_H
#define LEETCODEPROJECTCPP_UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

inline void printIntVector(const vector<int> &vec) {
    for (auto &iter : vec) {
        cout << iter << " ";
    }
}

inline void printCharVector(const vector<char> &vec) {
    for (auto &iter : vec) {
        cout << iter << " ";
    }
}

inline void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

inline void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

inline void splitByItem(const string &s, const char item, vector<string> &res) {
    string temp;
    stringstream ss;
    ss.str(s);
    while (true) {
        if (!getline(ss, temp, item)) {
            break;
        }
        res.push_back(temp);
    }
}

#endif //LEETCODEPROJECTCPP_UTILS_H
