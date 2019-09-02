//
// Created by xulzee on 2019/1/23.
//
#ifndef LEETCODEPROJECTCPP_UTILS_H
#define LEETCODEPROJECTCPP_UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


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

inline void SplitByItem(const string &s, const char item, vector<string> &res) {
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

vector<int> SplitByIntItem(const string &s, const char item){
    // item is int
    vector<int>res;
    string temp;
    stringstream ss;
    ss.str(s);
    while (true){
        if (!getline(ss, temp, item)){
            break;
        }
        res.push_back(stoi(temp));
    }
    return res;
}

vector<string> SplitByStringItem(const string &s, const char item){
    // item is string
    vector<string>res;
    string temp;
    stringstream ss;
    ss.str(s);
    while (true){
        if (!getline(ss, temp, item)){
            break;
        }
        res.push_back(temp);
    }
    return res;
}

#endif //LEETCODEPROJECTCPP_UTILS_H
