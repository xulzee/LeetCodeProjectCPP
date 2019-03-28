//
// Created by xulzee on 2019/3/28.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 一块金条切成两半，是需要花费和长度数值一样的铜板的。
// 比如长度为20的 金条，不管切成长度多大的两半，都要花费20个铜板。
// 一群人想整分整块金 条，怎么分最省铜板。
// 哈夫曼编码类型题目
class Less_Money {
public:
    int lessMoney(vector<int> &array) {
        if (array.empty()) {
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> pQ;
        for (auto i = array.begin(); i != array.end(); ++i) {
            pQ.push(*i);
        }
        int cost = 0;
        while (pQ.size() > 1) {
            int temp1 = pQ.top();
            pQ.pop();
            int temp2 = pQ.top();
            pQ.pop();
            pQ.push(temp1 + temp2);
            cost += temp1 + temp2;
        }
        return cost;
    }
};


int main() {
    vector<int> array = {30, 20, 10};
    cout << Less_Money().lessMoney(array) << endl;
}

