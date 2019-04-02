//
// Created by xulzee on 2019/1/22.
//

#include <vector>
#include <queue>
#include <iostream>


class RecentCounter {
public:
    RecentCounter() = default;

    int ping(int t) {
        q.push(t);
        while(not q.empty() and q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }

private:
    std::queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    std::cout << "Expected result is " << "[1, 2, 3, 3] " << std::endl;
    RecentCounter* obj = new RecentCounter();
    std::cout << "Our Solution result is [ " << obj->ping(1) << ", " << obj->ping(100) <<", " << obj->ping(3001)
            <<", " << obj->ping(3002) << "]" << std::endl;
}