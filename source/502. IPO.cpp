// @Time    : 2019/3/28 14:56
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

struct Node {
    int cost;
    int profit;

    Node(int x, int y) {
        cost = x;
        profit = y;
    }

    Node() = default;
};

struct costComparator {
    bool operator()(const Node &a, const Node &b) const
    {
        return a.cost > b.cost; // '>' -> 从小到大
    }
};

struct profitComparator {
    bool operator()(const Node &a, const Node &b) const
    {
        return a.profit < b.profit;// '<' -> 从大到小
    }
};


class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital) {
        vector<Node> node;
        for (int i = 0; i < Profits.size(); ++i) {
            node.emplace_back(Capital[i], Profits[i]);
        }
        priority_queue<Node, vector<Node>, costComparator> cost_pQ; // 小根堆
        priority_queue<Node, vector<Node>, profitComparator> profit_pQ; // 大根堆
        for (auto j:node) {
            cost_pQ.push(j);
        }
        for (int l = 0; l < k; ++l) {
            while (!cost_pQ.empty() && cost_pQ.top().cost <= W) {
                profit_pQ.push(cost_pQ.top());
                cost_pQ.pop();
            }

            if (profit_pQ.empty()){
                return W;
            }

            W += profit_pQ.top().profit;
            profit_pQ.pop();
        }
        return W;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        int k = stringToInteger(line);
        getline(cin, line);
        int W = stringToInteger(line);
        getline(cin, line);
        vector<int> Profits = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> Capital = stringToIntegerVector(line);

        int ret = Solution().findMaximizedCapital(k, W, Profits, Capital);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}