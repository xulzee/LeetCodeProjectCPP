//
// Created by xulzee on 2019/3/28.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(const string &str1, const string &str2){
    return str1 + str2 < str2 + str1;
}


class LowestLexicography{
public:
    string lowestLexicography(vector<string> &array){
        string ret;
        sort(array.begin(), array.end(), cmp);
        for (auto & i : array) {
            ret += i;
        }
        return ret;
    }
};

int main(){
    vector<string> array = {"aaa", "b", "ab", "bb", "a"};
    string ret = LowestLexicography().lowestLexicography(array);
}