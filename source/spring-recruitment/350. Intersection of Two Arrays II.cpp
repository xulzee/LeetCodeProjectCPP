//
// Created by xulzee on 2019/2/26.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        vector<int> result;
        for (auto i = nums1.begin(); i < nums1.end(); ++i) {
            if (record.find(*i) != record.end()) {
                record[*i] += 1;
            } else {
                record[*i] = 1;
            }
        }

        for (auto j = nums2.begin(); j < nums2.end(); ++j) {
            if (record.find(*j) != record.end() && record[*j] > 0) {
                result.push_back(*j);
                --record[*j];
            }
        }

        return result;
    }
};

int main() {
    vector<int> A = {4,9,5};
    vector<int> B = {9,4,9,8,4};
    printIntVector(Solution().intersect(A, B));
}