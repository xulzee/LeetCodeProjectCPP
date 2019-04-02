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

class UnionFind {
public:
    unordered_map<Node *, Node *> fatherMap; // {node : father}
    unordered_map<Node *, int> rankMap; // 集合中元素数量

    UnionFind() = default;

    Node *findHeadNode(Node *node) {
        stack<Node *> nodeStack;
        Node *cur = node;
        Node *father = fatherMap[cur];

        while (cur != father) { // 找到集合首个节点
            nodeStack.push(cur);
            cur = father;
            father = fatherMap[father];
        }
        while (!nodeStack.empty()) {
            fatherMap[nodeStack.top()] = father;
            nodeStack.pop();
        }
        return father;
    }

    void makeSets(const unordered_map<int, Node *> &nodes) {
        fatherMap.clear();
        rankMap.clear();
        for (auto node : nodes) {
            fatherMap[node.second] = node.second;
            rankMap[node.second] = 1;
        }
    }

    bool isSameSet(Node *node1, Node *node2) {
        auto ret1 = findHeadNode(node1);
        auto ret2 = findHeadNode(node2);
        return ret1 == ret2;
//        return findHeadNode(node1) == findHeadNode(node2);
    }

    void unionSet(Node *a, Node *b) {
        if (a == nullptr || b == nullptr) {
            return;
        }
        Node *aHead = findHeadNode(a);
        Node *bHead = findHeadNode(b);
        if (aHead != bHead) {
            int aSetSize = rankMap[aHead];
            int bSetSize = rankMap[bHead];
            if (aSetSize > bSetSize) {
                fatherMap[bHead] = aHead;
                rankMap[aHead] = aSetSize + bSetSize;
            } else {
                fatherMap[aHead] = bHead;
                rankMap[bHead] = aSetSize + bSetSize;
            }
        }
    }
};

// [1, 2, 50] : 出发点，到达点,权重
// 有向图
Graph *createGraph(vector<vector<int>> &matrix) {
    auto *graph = new Graph;
    for (auto &i: matrix) {
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
    };
    return graph;
}

// bfs
void graphBreadthFirstSearch(Node *node) {
    if (node == nullptr) {
        return;
    }
    queue<Node *> nodeQueue;
    set<Node *> nodeSet; // used Node
    nodeQueue.push(node);
    nodeSet.insert(node);
    while (!nodeQueue.empty()) {
        Node *cur = nodeQueue.front();
        nodeQueue.pop();
        // 遍历操作
        cout << cur->value << endl;
        for (auto next : cur->nexts) {
            if (nodeSet.find(next) == nodeSet.end()) {
                nodeSet.insert(next);
                nodeQueue.push(next);
            }
        }

    }
}

// dfs
void graphDepthFirstSearch(Node *node) {
    if (node == nullptr) {
        return;
    }
    stack<Node *> nodeStack;
    set<Node *> nodeSet;
    nodeStack.push(node);
    nodeSet.insert(node);
    //遍历操作
    cout << node->value << endl;
    while (!nodeStack.empty()) {
        Node *cur = nodeStack.top();
        nodeStack.pop();
        for (auto next : cur->nexts) {
            if (nodeSet.find(next) == nodeSet.end()) {
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

// 需要保证是有向无环图
vector<Node *> sortedTopology(Graph &graph) {
    unordered_map<Node *, int> inMap;
    queue<Node *> zeroInQueue;// in == 0;
    for (auto node : graph.nodes) { // 初始化 zeroQueue
        if (node.second->in == 0) {
            zeroInQueue.push(node.second);
        }
    }
    vector<Node *> res;
    while (!zeroInQueue.empty()) {
        auto cur = zeroInQueue.front();
        zeroInQueue.pop();
        res.push_back(cur);
        for (auto next : cur->nexts) {
            inMap[next] = next->in - 1;
            if (inMap[next] == 0) {
                zeroInQueue.push(next);
            }
        }
    }
    return res;
}

struct EdgeComparator {
    bool operator()(const Edge *a, const Edge *b) const {
        return a->weight > b->weight;
    }
};

set<Edge *> kruskalMST(Graph *graph) {
    auto *unionFind = new UnionFind();
    unionFind->makeSets(graph->nodes);
    priority_queue<Edge *, vector<Edge *>, EdgeComparator> edgeQueue; // Small top
    for (auto edge : graph->edges) {
        edgeQueue.push(edge);
    }
    set<Edge *> resEdgeSet;
    while (!edgeQueue.empty()) {
        auto curEdge = edgeQueue.top();
        edgeQueue.pop();
        if (!unionFind->isSameSet(curEdge->from, curEdge->to)) {
            resEdgeSet.insert(curEdge);
            unionFind->unionSet(curEdge->from, curEdge->to);
        }
    }
    return resEdgeSet; // 返回边集合
}

set<Edge *> primMST(Graph *graph) {
    priority_queue<Edge *, vector<Edge *>, EdgeComparator> edgeQueue; // small top
    set<Node *> nodeSet; // 使用过的节点
    set<Edge *> resEdgeSet;
    for (auto node : graph->nodes) { // 解决森林
        if (nodeSet.find(node.second) == nodeSet.end()) {
            nodeSet.insert(node.second);
            for (auto edge : node.second->edges) {
                edgeQueue.push(edge);
            }
            while (!edgeQueue.empty()) {
                auto curEdge = edgeQueue.top();
                edgeQueue.pop();
                auto fromNode = curEdge->from;
                if (nodeSet.find(fromNode) == nodeSet.end()) {
                    nodeSet.insert(fromNode);
                    resEdgeSet.insert(curEdge);
                    for (auto nextEdge : fromNode->edges) {
                        edgeQueue.push(nextEdge);
                    }
                }
                auto toNode = curEdge->to;
                if (nodeSet.find(toNode) == nodeSet.end()) { // 不形成环
                    nodeSet.insert(toNode);
                    resEdgeSet.insert(curEdge);
                    for (auto nextEdge : toNode->edges) {
                        edgeQueue.push(nextEdge);
                    }
                }
            }

        }
    }
    return resEdgeSet;
}

int main() {
    vector<vector<int >> test = {{0, 1, 20},
//                                 {1, 0, 20},
                                 {0, 4, 1},
//                                 {4, 0, 1},
                                 {4, 5, 15},
//                                 {5, 4, 15},
                                 {5, 6, 10},
//                                 {6, 5, 10},
                                 {6, 2, 2},
//                                 {2, 6, 2},
                                 {2, 1, 6},
//                                 {1, 2, 6},
                                 {5, 3, 12},
//                                 {3, 5, 12},
                                 {6, 3, 8},
//                                 {3, 6, 8},
//                                 {1, 3, 4},
                                 {3, 1, 4}};
    Graph *graph = createGraph(test);
    auto ret = primMST(graph);
}