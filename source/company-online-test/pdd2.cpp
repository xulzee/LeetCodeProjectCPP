//
// Created by xulzee on 2019/9/1.
//
#include <iostream>
#include <vector>

using namespace std;
string t;
vector<string> ans;


void dfs(vector<string> &res, string &temp, string &s1, string &s2, string &target) {

}

void dfs(string res, string path, int left, int right){
    if(left > right + 1){
        return;
    } else{
        if (res == t && left == right + 1){
            ans.push_back(path);
        } else{
            dfs(res, path + "d", left + 1, right);
            dfs(, path + "d", left + 1, right);
            dfs(res, path + "d", left + 1, right);
        }
    }
}

string help(string &s, string &target) {
    vector<string> res;
    string temp, s2;
    dfs(res, temp, s, s2, target);
    string ret;
    ret += "{\n";
    for (auto &item : res) {
        for (char &ch : item) {
            ret = ret + ch + " ";
        }
        ret += "\n";
    }
    ret += "}\n";
    return ret;
};


int main() {
    int input;
    cin >> input;

    string string_nums;
    string target;
    string res;
    while (input > 0) {
        cin >> string_nums >> target;
        res += help(string_nums, target);
        --input;
    }
    cout << res;
}
//{
//d d l
//d d r
//}
//{
//l l l
//r l l
//}
//{
//}

//{
//d d l
//d d r
//}
//{
//l l l
//r l l
//}
//{
//}