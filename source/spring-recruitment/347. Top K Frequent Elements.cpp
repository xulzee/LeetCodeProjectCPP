// @Time    : 2019/4/14 22:11
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> value;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> frequentQueue;
        for (auto &num : nums) {
            if (value.find(num) != value.end()) {
                value[num]++;
            } else {
                value[num] = 1;
            }
        }

        for (auto &it : value) {
            if (frequentQueue.size() == k) {
                if (it.second < frequentQueue.top().first) {
                    continue;
                } else {
                    frequentQueue.pop();
                }
            }
            frequentQueue.push(make_pair(it.second, it.first));
        }
        vector<int> res(k, 0);
        int index = k - 1;
        while (!frequentQueue.empty()) {
            res[index--] = frequentQueue.top().second;
            frequentQueue.pop();
        }
        return res;
    }
};

int main(){
    vector<int> test = {1,1,1,2,2,3};
    Solution().topKFrequent(test, 2);
}