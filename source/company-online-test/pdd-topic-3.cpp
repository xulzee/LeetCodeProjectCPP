//
// Created by xulzee on 2019/9/1.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <list>
#include <iomanip>

using namespace std;

int main1() {
    int n;
    cin >> n;
    vector<int> p(n, 0);
    int max_num = 0;
    for (int &i : p) {
        cin >> i;
        max_num = max(max_num, i);
    }
    sort(p.begin(), p.end());

    vector<double> res(max_num, 1);
    double sum = 0;
    for (int i = 1; i <= max_num; ++i) {
        double different = 1;
        for (int & j : p) {
            res[i - 1] *= i > j ? j : i;
            different *= i > j ? j : i - 1;
        }
        res[i - 1] -= different;
        sum += res[i - 1];
    }

    double ret = 0;
    for (int i = 0; i < res.size(); ++i) {
        ret += static_cast<double>(i + 1) * res[i] / sum;
    }

    cout << fixed << setprecision(2) << ret << endl;
}

