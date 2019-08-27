//
// Created by liuze.xlz on 2019-08-27.
//
#include "utils.h"


class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2) {
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        });

        auto cmp = [](vector<int> const &v1, vector<int> const &v2) { return v1[1] > v2[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> rooms_queue(cmp);

        for (const auto &interval : intervals) {
            if (rooms_queue.empty() || interval[0] <= rooms_queue.top()[1]) {
                rooms_queue.push(interval);
            } else{
                rooms_queue.pop();
                rooms_queue.push(interval);
            }
        }

        return rooms_queue.size();
    }
};

int main() {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << Solution().minMeetingRooms(intervals) << endl;
}

