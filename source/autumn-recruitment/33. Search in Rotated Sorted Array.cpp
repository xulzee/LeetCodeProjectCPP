//
// Created by liuze.xlz on 2019-08-27.
//

#include "utils.h"

class Solution {
public:
    int FindRotateIndex(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        if (nums[left] < nums[right]) {
            return 0;
        }
        while (left <= right) {
            int mid = left + (right - left >> 1);
            if (nums[mid] > nums[mid + 1]) {
                return mid + 1;
            } else {
                if (nums[left] > nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return 0;
    }

    int BinarySearch(vector<int> &nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left >> 1);
            if (nums[mid] == target) {
                return mid;
            } else {
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        if (nums.size() == 1) {
            return nums.front() == target ? 0 : -1;
        }

        int rotate_index = FindRotateIndex(nums);
        if (rotate_index == 0) {
            return BinarySearch(nums, target, 0, nums.size() - 1);
        } else {
            if (nums[rotate_index] <= target && nums.back() >= target) {
                return BinarySearch(nums, target, rotate_index, nums.size() - 1);
            } else {
                return BinarySearch(nums, target, 0, rotate_index);
            }
        }
    }
};

int main() {
    vector<int> nums = {5, 1, 3};
    cout << Solution().search(nums, 0) << endl;
    cout << Solution().search(nums, 5) << endl;
    cout << Solution().search(nums, 6) << endl;
    cout << Solution().search(nums, 7) << endl;
    cout << Solution().search(nums, 0) << endl;
    cout << Solution().search(nums, 1) << endl;
    cout << Solution().search(nums, 2) << endl;
    cout << Solution().search(nums, 8) << endl;
}