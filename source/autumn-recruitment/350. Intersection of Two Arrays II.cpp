//
// Created by liuze.xlz on 2019-07-30.
//
#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> intersect1(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        unordered_map<int, int> num_map;
        for (const auto &num : nums1) {
            if (num_map.find(num) != num_map.end()) {
                ++num_map[num];
            } else {
                num_map[num] = 1;
            }
        }

        for (const auto &num : nums2) {
            if (num_map.find(num) != num_map.end() && num_map[num] > 0) {
                res.push_back(num);
                --num_map[num];
            }
        }

        return res;
    }

    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            } else if(nums1[i] < nums2[j]){
                ++i;
            } else{
                ++j;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    printIntVector(Solution().intersect(nums1, nums2));
}
