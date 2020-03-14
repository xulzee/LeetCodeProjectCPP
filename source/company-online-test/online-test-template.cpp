//
// Created by xulzee on 2019/9/1.
//
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 排序模板
void SortByValue() {
    vector<string> test = {"ab", "aa", "a"};
    for (auto &item : test) {
        cout << item << " ";
    }
    cout << endl;
    // 从小到大
    sort(test.begin(), test.end(), [](string &s1, string &s2) { return s1 <= s2; });
    for (auto &item : test) {
        cout << item << " ";
    }
    cout << endl;
    // 从大到小
    sort(test.begin(), test.end(), [](string &s1, string &s2) { return s1 >= s2; });
    for (auto &item : test) {
        cout << item << " ";
    }
    cout << endl;
}

#include <queue>

// 堆模板
void PriorityQueue() {
    vector<vector<string>> test = {{"c", "aa"}, {"a", "aa"}, {"a", "bb"}};
    for (auto &items : test) {
        for (auto &item : items) {
            cout << item << " ";
        }
        cout << endl;
    }
    // 小顶堆，最小元素在堆顶
    auto cmp_small = [](vector<string> const &v1, vector<string> const &v2) { return v1[0] >= v2[0]; };
    priority_queue<vector<string>, vector<vector<string>>, decltype(cmp_small)> m_small_queue(cmp_small);
    m_small_queue.push(test[0]);
    m_small_queue.push(test[1]);
    m_small_queue.push(test[2]);
    cout << m_small_queue.top().front() << " " << m_small_queue.top().back() << endl;

    // 小顶堆，最小元素在堆顶
    auto cmp_big = [](vector<string> const &v1, vector<string> const &v2) { return v1[0] < v2[0]; };
    priority_queue<vector<string>, vector<vector<string>>, decltype(cmp_big)> m_big_queue(cmp_big);
    m_big_queue.push(test[0]);
    m_big_queue.push(test[1]);
    m_big_queue.push(test[2]);
    cout << m_big_queue.top().front() << " " << m_big_queue.top().back() << endl;
}

// 输入模板
vector<int> SplitByIntItem(const string &s, const char item){
    // item is int
    vector<int>res;
    string temp;
    stringstream ss;
    ss.str(s);
    while (true){
        if (!getline(ss, temp, item)){
            break;
        }
        res.push_back(stoi(temp));
    }
    return res;
}

// 输入模板
vector<string> SplitByStringItem(const string &s, const char item){
    // item is string
    vector<string>res;
    string temp;
    stringstream ss;
    ss.str(s);
    while (true){
        if (!getline(ss, temp, item)){
            break;
        }
        res.push_back(temp);
    }
    return res;
}

int main() {
    SortByValue();
    PriorityQueue();
}
