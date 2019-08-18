//
// Created by liuze.xlz on 2019-08-18.
//
#include "utils.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int nums1_len = nums1.size();
        int nums2_len = nums2.size();
        if (nums1_len > nums2_len) { // ensure nums1.size <= nums2.size
            swap(nums1, nums2);
            swap(nums1_len, nums2_len);
        }
        int i = 0, j = 0;
        int i_min = 0, i_max = nums1_len;
        while (i_min <= i_max) {
            i = (i_min + i_max) >> 1;
            j = ((nums1_len + nums2_len + 1) >> 1) - i;
            if (j > 0 && i < i_max && nums2[j - 1] > nums1[i]) {
                i_min = i + 1; // i is too small
            } else if (i > i_min && j < nums2_len && nums1[i - 1] > nums2[j]) {
                i_max = i - 1; // i is too big
            } else { // i is perfect
                int left_max = 0;
                if (i == 0) {
                    left_max = nums2[j - 1];
                } else if (j == 0) {
                    left_max = nums1[i - 1];
                } else {
                    left_max = max(nums1[i - 1], nums2[j - 1]);
                }
                if ((nums1_len + nums2_len) % 2 == 1) {
                    return left_max;
                }

                int right_min = 0;
                if (i == nums1_len) {
                    right_min = nums2[j];
                } else if (j == nums2_len) {
                    right_min = nums1[i];
                } else {
                    right_min = min(nums1[i], nums2[j]);
                }

                return (left_max + right_min) / 2.0;
            }
        }
        return 0.0;
    }
};
