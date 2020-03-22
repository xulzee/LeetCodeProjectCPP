//
// Created by xulzee on 2020/3/20.
//

#include "utils.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> arr_queue;
        for (auto &num : arr) {
            arr_queue.push(num);
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr_queue.top());
            arr_queue.pop();
        }
        return res;
    }
};

int main() {
    vector<int> arr = {3, 2, 1};
    int k = 2;
    printIntVector(Solution().getLeastNumbers(arr, k));
}