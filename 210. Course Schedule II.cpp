// @Time    : 2019/4/1 16:54
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

class Node;

class Graph;

class Node {
public:
    int value;
    int in;
    vector<Node *> nexts;

    explicit Node(int v) {
        value = v;
        in = 0;
    }
};


class Graph {
public:
    unordered_map<int, Node *> nodes;

    explicit Graph(int num, vector<pair<int, int>> &prerequisites) {
        createGraph(num, prerequisites);
    }

    void createGraph(int num, vector<pair<int, int>> &prerequisites) {
        for (int i = 0; i < num; ++i) {
            if (nodes.find(i) == nodes.end()) {
                nodes[i] = new Node(i);
            }
        }
        // [to, from]
        for (auto &prerequisite : prerequisites) {
            int to = prerequisite.first;
            int from = prerequisite.second;
            // creat to Node
            if (nodes.find(to) == nodes.end()) {
                nodes[to] = new Node(to);
            }
            // creat from Node
            if (nodes.find(from) == nodes.end()) {
                nodes[from] = new Node(from);
            }
            auto toNode = nodes[to];
            auto fromNode = nodes[from];

            // attribute
            fromNode->nexts.push_back(toNode);
            toNode->in++;
        }
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        if (numCourses == 0) {
            return {};
        }
        auto graph = new Graph(numCourses, prerequisites);
        unordered_map<Node *, int> inMap;
        queue<Node *> zeroInQueue;
        for (auto node : graph->nodes) {
            if (node.second->in == 0) {
                zeroInQueue.push(node.second);
            }
        }
        vector<int> res;
        while (!zeroInQueue.empty()) {
            auto curNode = zeroInQueue.front();
            zeroInQueue.pop();
            res.push_back(curNode->value);
            for (auto next : curNode->nexts) {
                next->in--;
                if (next->in == 0) {
                    zeroInQueue.push(next);
                }
            }
        }
        if (res.size() != numCourses) {
            return {};
        } else {
            return res;
        }
    }
};

int main() {
//    int numCourses = 4;
//    vector<pair<int, int>> test = {{1, 0},
//                                   {2, 0},
//                                   {3, 1},
//                                   {3, 2}};
    vector<pair<int, int>> test = {};
    Solution().findOrder(4, test);
}
