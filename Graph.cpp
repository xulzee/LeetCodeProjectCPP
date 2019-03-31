// @Time    : 2019/3/31 20:14
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <unordered_map>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Node;

class Edge;

class Edge {
public:
    int weight;
    Node *from;
    Node *to;

    Edge(int w, Node *f, Node *t) {
        weight = w;
        from = f;
        to = t;
    }
};

class Node {
public:
    int value;
    int in; // 入度
    int out; // 出度
    vector<Node *> nexts;
    vector<Edge *> edges;

    explicit Node(int n) {
        value = n;
        in = 0;
        out = 0;
    }

};

class Graph {
public:
    unordered_map<int, Node *> nodes;
    set<Edge *> edges;
};


// [1, 2, 50] : 出发点，到达点,权重
Graph *createGraph(vector<vector<int>> &matrix) {
    auto *graph = new Graph;
    for (auto &i : matrix) {
        int from = i[0];
        int to = i[1];
        int weight = i[2];
        if (graph->nodes.find(from) == graph->nodes.end()) {
            graph->nodes[from] = new Node(from);
        }
        if (graph->nodes.find(to) == graph->nodes.end()) {
            graph->nodes[to] = new Node(to);
        }
        // 点
        Node *fromNode = graph->nodes[from];
        Node *toNode = graph->nodes[to];
        // 边
        Edge *newEdge = new Edge(weight, fromNode, toNode);
        fromNode->nexts.push_back(toNode);
        fromNode->out++;
        toNode->in++;
        fromNode->edges.push_back(newEdge);
        graph->edges.insert(newEdge);
    }
    return graph;
}

void graphBreadthFirstSearch(Node *node) {
    if (node == nullptr) {
        return;
    }
    queue<Node *> nodeQueue;
    set<Node *> nodeSet; // used Node
    nodeQueue.push(node);
    nodeSet.insert(node);
    while (!nodeQueue.empty()){
        Node *cur = nodeQueue.front();
        nodeQueue.pop();
        // 遍历操作
        cout << cur->value << endl;
        for (auto next : cur->nexts) {
            if (nodeSet.find(next) == nodeSet.end()){
                nodeSet.insert(next);
                nodeQueue.push(next);
            }
        }

    }
}

void graphDepthFirstSearch(Node *node){
    if (node == nullptr){
        return;
    }
    stack<Node *> nodeStack;
    set<Node *> nodeSet;
    nodeStack.push(node);
    nodeSet.insert(node);
    //遍历操作
    cout << node->value << endl;
    while (!nodeStack.empty()){
        Node *cur = nodeStack.top();
        nodeStack.pop();
        for (auto next : cur->nexts) {
            if (nodeSet.find(next) == nodeSet.end()){
                nodeStack.push(cur);
                nodeStack.push(next);
                nodeSet.insert(next);
                //遍历操作
                cout << next->value << endl;
                break;
            }
        }
    }
}