// @Time    : 2019/3/30 15:55
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    explicit Solution(vector<int> nums) {
        ori = nums;
        res = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int pos = 0;
        for (int i = 0; i < res.size(); ++i) {
            pos = i + rand() % (res.size() - i);
            swap(ori, i, pos);
        }
        return res;
    }
private:
    vector<int> ori;
    vector<int> res;
    void swap(vector<int> &nums, int i, int j){
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }
};