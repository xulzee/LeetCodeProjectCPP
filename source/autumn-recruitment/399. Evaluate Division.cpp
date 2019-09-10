//
// Created by liuze.xlz on 2019-09-06.
//
#include <utility>

#include "utils.h"

class Node;

class Edge;

class Edge {
public:
    double weight;
    Node *from;
    Node *to;

    Edge(double w, Node *f, Node *t) {
        weight = w;
        from = f;
        to = t;
    }
};

class Node {
public:
    string value;
    vector<Node *> nexts;
    vector<Edge *> edges;

    explicit Node(string n) {
        value = std::move(n);
    }
};

class Graph {
public:
    Graph() = default;

    unordered_map<string, Node *> nodes;
    unordered_set<Edge *> edges;
};

Graph *CreateGraph(vector<vector<string>> &equations, vector<double> &values) {
    auto *graph = new Graph();
    for (int i = 0; i < equations.size(); ++i) {
        string from = equations[i].front();
        string to = equations[i].back();
        double weight = values[i];
        if (graph->nodes.find(from) == graph->nodes.end()) {
            graph->nodes[from] = new Node(from);
        }
        if (graph->nodes.find(to) == graph->nodes.end()) {
            graph->nodes[to] = new Node(to);
        }
        // 点
        Node *from_node = graph->nodes[from];
        Node *to_node = graph->nodes[to];
        // 边
        auto edge_from = new Edge(weight, from_node, to_node);
        from_node->nexts.push_back(to_node);
        from_node->edges.push_back(edge_from);
        graph->edges.insert(edge_from);

        auto edge_to = new Edge(1.0 / weight, to_node, from_node);
        to_node->nexts.push_back(from_node);
        to_node->edges.push_back(edge_to);
        graph->edges.insert(edge_to);
    }
    return graph;
}

double dfs(Graph &graph, unordered_set<string> &visited, string &cur, string &target) {
    if (graph.nodes.find(cur) == graph.nodes.end() || graph.nodes.find(target) == graph.nodes.end()){
        return -1;
    }

    if (visited.find(cur) != visited.end()){
        return -1;
    }


}


// dfs
double GraphDepthFirstSearch(Node *node, Node *target) {
    double res = 1.0;
    if (node == nullptr) {
        return -1;
    }
    stack<Node *> node_stack;
    unordered_set<Edge *> node_set;
    node_stack.push(node);
    //遍历操作
    cout << node->value << endl;
    while (!node_stack.empty()) {
        Node *cur = node_stack.top();
        node_stack.pop();
        for (auto &edge : cur->edges) {
            auto &next = edge->to;
            if (node_set.find(edge) == node_set.end()) {
                node_stack.push(cur);
                node_stack.push(next);
                node_set.insert(edge);
                //遍历操作
                cout << next->value << " " << edge->weight << endl;
                if (next == target) {
                    return res;
                }
                break;
            }
        }
    }
    return -1;
}

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        auto graph = CreateGraph(equations, values);
        vector<double> res;
        for (auto &query : queries) {
            if (graph->nodes.find(query.front()) == graph->nodes.end()
                    || graph->nodes.find(query.back()) == graph->nodes.end()) {
                res.push_back(-1.0);
                continue;
            }
//            if (query.front() == query.back()){
//                res.push_back(1.0);
//                continue;
//            }
            auto from = graph->nodes[query.front()];
            auto to = graph->nodes[query.back()];
            res.push_back(GraphDepthFirstSearch(from, to));
        }
        return res;
    }
};

int main() {
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}};//, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    Solution().calcEquation(equations, values, queries);
}
