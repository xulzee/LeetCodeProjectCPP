// @Time    : 2019/4/6 19:51
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int value;

    Node(int v) {
        value = v;
    }
};

class UnionFind {
private:
    unordered_map<Node *, Node *> fatherMap; // index to father
    unordered_map<Node *, int> sizeMap; // set's size
    int maxSize;

    Node *findHead(Node *node) {
        stack<Node *> nodeStack;
        Node *cur = node;
        Node *parent = fatherMap[node];
        while (cur != parent) {
            nodeStack.push(cur);
            cur = parent;
            parent = fatherMap[cur];
        }

        while (!nodeStack.empty()) {
            fatherMap[nodeStack.top()] = parent;
            nodeStack.pop();
        }
        return parent;
    }

public:
    explicit UnionFind(const vector<Node *> &nodes) {
        for (auto node : nodes) {
            fatherMap[node] = node;
            sizeMap[node] = 1;
        }
        if (!nodes.empty()) {
            maxSize = 0;
        }
    }

    bool isSameSet(Node *a, Node *b) {
        return findHead(a) == findHead(b);
    }

    void unionSet(Node *a, Node *b) {
        Node *aHead = findHead(a);
        Node *bHead = findHead(b);
        if (aHead != bHead) {
            int aSetSize = sizeMap[aHead];
            int bSetSize = sizeMap[bHead];
            if (aSetSize > bSetSize) {
                sizeMap[aHead] += sizeMap[bHead];
                maxSize = max(maxSize, sizeMap[aHead]);
                fatherMap[bHead] = aHead;
            } else {
                sizeMap[bHead] += sizeMap[aHead];
                maxSize = max(maxSize, sizeMap[bHead]);
                fatherMap[aHead] = bHead;
            }
        }
    }

    int getMaxSize() {
        return maxSize;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (!nums.empty()){
            return 0;
        }
        vector<Node *> nodes;
        unordered_map<int, Node *> nodeIndex;
        unordered_set<int> numSet;
        for (auto num : nums) { // make union find
            Node *cur = new Node(num);
            nodes.push_back(cur);
            nodeIndex[num] = cur;
        }
        auto nodeUnionFind = new UnionFind(nodes);
        for (auto num :nums) {
            if (numSet.find(num) != numSet.end()) {
                continue;
            }
            numSet.insert(num); // used num
            if (numSet.find(num - 1) != numSet.end() &&
                !nodeUnionFind->isSameSet(nodeIndex[num], nodeIndex[num - 1])) { // num, num - 1 不在同一个状态中
                nodeUnionFind->unionSet(nodeIndex[num], nodeIndex[num - 1]);
            }
            if (numSet.find(num + 1) != numSet.end() &&
                !nodeUnionFind->isSameSet(nodeIndex[num], nodeIndex[num + 1])) { // num, num - 1 不在同一个状态中
                nodeUnionFind->unionSet(nodeIndex[num], nodeIndex[num + 1]);
            }
        }

        return nodeUnionFind->getMaxSize();
    }
};

int main() {
    vector<int> test = {100, 4, 200, 1, 3, 2};
    cout << Solution().longestConsecutive(test) << endl;
}

