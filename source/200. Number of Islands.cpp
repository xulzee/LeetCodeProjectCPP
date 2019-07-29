//
// Created by xulzee on 2019/3/23.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class UnionFind {
    unordered_map<int, int> fatherMap;
    unordered_map<int, int> sizeMap;
    int islandSize;

    int findHead(int num) {
        stack<int> numStack;
        int cur = num;
        int parent = fatherMap[cur];
        while (parent != cur) {
            numStack.push(cur);
            cur = parent;
            parent = fatherMap[parent];
        }

        while (!numStack.empty()) {
            fatherMap[numStack.top()] = parent;
            numStack.pop();
        }
        return parent;
    }

public:
    explicit UnionFind(vector<vector<char>> &arr) {
        islandSize = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr[0].size(); ++j) {
                fatherMap[i * arr[0].size() + j] = i * arr[0].size() + j;
                sizeMap[i * arr[0].size() + j] = 1;
                if (arr[i][j] == '1') {
                    islandSize++;
                }
            }
        }

    }

    bool isSameSet(int a, int b) {
        return findHead(a) == findHead(b);
    }

    void unionSet(int a, int b) {
        int aHead = findHead(a);
        int bHead = findHead(b);
        if (aHead != bHead) {
            if (sizeMap[aHead] >= sizeMap[bHead]) {
                fatherMap[bHead] = aHead;
                sizeMap[aHead] += sizeMap[bHead];
            } else {
                fatherMap[aHead] = bHead;
                sizeMap[bHead] += sizeMap[aHead];
            }
            islandSize--;
        }
    }

    int getMaxSize() {
        return islandSize;
    }

};

class UnionFind {
    unordered_map<int, int> fatherMap;
    unordered_map<int, int> sizeMap;
    int islandSize;

    int findHead(int num) {
        stack<int> numStack;
        int cur = num;
        int parent = fatherMap[cur];
        while (parent != cur) {
            numStack.push(cur);
            cur = parent;
            parent = fatherMap[parent];
        }

        while (!numStack.empty()) {
            fatherMap[numStack.top()] = parent;
            numStack.pop();
        }
        return parent;
    }

public:
    explicit UnionFind(vector<vector<char>> &arr) {
        islandSize = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr[0].size(); ++j) {
                fatherMap[i * arr[0].size() + j] = i * arr[0].size() + j;
                sizeMap[i * arr[0].size() + j] = 1;
                if (arr[i][j] == '1') {
                    islandSize++;
                }
            }
        }

    }

    bool isSameSet(int a, int b) {
        return findHead(a) == findHead(b);
    }

    void unionSet(int a, int b) {
        int aHead = findHead(a);
        int bHead = findHead(b);
        if (aHead != bHead) {
            if (sizeMap[aHead] >= sizeMap[bHead]) {
                fatherMap[bHead] = aHead;
                sizeMap[aHead] += sizeMap[bHead];
            } else {
                fatherMap[aHead] = bHead;
                sizeMap[bHead] += sizeMap[aHead];
            }
            islandSize--;
        }
    }

    int getMaxSize() {
        return islandSize;
    }

};




class Solution {
public:
    int numIslands(vector<vector<char>> &grid) { // leetcode 测试数据量太小，不能体现并查集的优势
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        UnionFind *numUnionFind = new UnionFind(grid);
        for (int row = 0; row < grid.size(); ++row) {
            for (int column = 0; column < grid[0].size(); ++column) {
                auto temp = grid[row][column];
                bool x = temp == '1';
                if (grid[row][column] == '1') {
                    if (row >= 1 && grid[row - 1][column] == '1') { // up
                        numUnionFind->unionSet(row * grid[0].size() + column, (row - 1) * grid[0].size() + column);
                    }
                    if (column >= 1 && grid[row][column - 1] == '1') { // left
                        numUnionFind->unionSet(row * grid[0].size() + column, row * grid[0].size() + column - 1);
                    }
                }
            }
        }
        return numUnionFind->getMaxSize();
    }

    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) {
            return 0;
        }
        int res = 0;
        int column_len = static_cast<int>(grid[0].size() - 1);
        int row_len = static_cast<int>(grid.size() - 1);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    res++;
                    infect(grid, i, j, column_len, row_len);
                }
            }
        }
        return res;
    }

    void infect(vector<vector<char>> &grid, int i, int j, int column_len, int row_len) {
        if (i < 0 || j < 0 || i > row_len || j > column_len || grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '2';
        infect(grid, i, j + 1, column_len, row_len);
        infect(grid, i, j - 1, column_len, row_len);
        infect(grid, i - 1, j, column_len, row_len);
        infect(grid, i + 1, j, column_len, row_len);
    }
};

int main() {
    vector<vector<char>> test = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    cout << Solution().numIslands(test) << endl;
}

