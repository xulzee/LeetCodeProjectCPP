//
// Created by liuze.xlz on 2019-08-11.
//
#include <iostream>
#include <vector>
#include <time.h>
//#include <algorithm>
using namespace std;

int getNumber(vector<vector<vector<int>>> &mem_cache, int target, int begin, int restLen) {
    if (restLen == 1 && target >= begin)
        return 1;

    if (restLen <= 0 || begin > target)
        return 0;

//    //cout << target << ", " << begin << ", " << restLen << endl;
    if (mem_cache[target][begin][restLen] == -1) {
        int Ans = 0;
        for (int idx = begin; idx <= int(target / restLen); idx++) {
            Ans += getNumber(mem_cache, target - idx, idx + 1, restLen - 1);
        }
        mem_cache[target][begin][restLen] = Ans;
        return Ans;
    } else {
        return mem_cache[target][begin][restLen];
    }
}

int main() {
    clock_t start = clock();
    cout << "开始时间：" << start << endl;

    int N, S;
//    cin >> N >> S;
    N = 10;
    S = 250;
//    cout << N << ", " << S << endl;
    vector<vector<vector<int>>> mem_cache(S + 1, vector<vector<int>>(S + 1, vector<int>(N + 1, -1)));
    cout << getNumber(mem_cache, S, 1, N) << endl;

    clock_t end = clock();
    cout << "结束时间：" << end << endl;
    cout << "算法执行持续时间：" << end - start << "毫秒" << endl;
    return 0;
}
