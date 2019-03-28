// @Time    : 2019/3/28 16:09
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 一些项目要占用一个会议室宣讲，会议室不能同时容纳两个项目
// 的宣讲。 给你每一个项目开始的时间和结束的时间(给你一个数
// 组，里面 是一个个具体的项目)，你来安排宣讲的日程，要求会
// 议室进行 的宣讲的场次最多。返回这个最多的宣讲场次。

struct Node {
    int start;
    int end;

    Node(int a, int b) {
        start = a;
        end = b;
    }
};

static bool endComparator(const Node &a, const Node &b) {
    return a.end < b.end; // priority_queue和sort的默认排序相反
}

class BestArrange {
public:
    int bestArrange(vector<vector<int>> &arr, int cur) {
        vector<Node> node;
        node.reserve(arr.size()); //预留空间
        for (auto i : arr) {
            node.emplace_back(i[0], i[1]);
        }
        sort(node.begin(), node.end(), endComparator); // 根据end从小到大排序
        int res = 0;
        for (auto &j : node) {
            if (cur < j.start) {
                res++;
                cur += j.end;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> test = {{0,  30},
                                {5,  10},
                                {15, 20}};
    cout << BestArrange().bestArrange(test, 0) << endl;
}

