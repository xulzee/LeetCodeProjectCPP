//
// Created by xulzee on 2019/3/14.
//
#include <iostream>
#include <vector>

using namespace std;

//给定一个数组，求如果排序之后，相邻两数的最大差值，要求时
//间复杂度O(N)，且要求不能用非基于比较的排序。
class Solution {
public:
    int maxgap(vector<int> &array) {
        if (array.empty() || array.size() < 2) {
            return 0;
        }
        int array_len = static_cast<int>(array.size());
        int array_min = array[0];
        int array_max = array[0];
        for (int i = 0; i < array.size(); ++i) {
            array_max = max(array_max, array[i]);
            array_min = min(array_min, array[i]);
        }
        bool *has_num = new bool[array_len + 1];
        int *maxs = new int[array_len + 1];
        int *mins = new int[array_len + 1];
        for (int j = 0; j < array.size(); ++j) {
            int index = bucket(array[j], array_len, array_max, array_min);
            if (has_num[index]) {
                maxs[index] = max(maxs[index], array[j]);
                mins[index] = min(mins[index], array[j]);
            } else {
                maxs[index] = array[j];
                mins[index] = array[j];
            }
            has_num[index] = true;
        }
        int res = 0;
        int lastMax = maxs[0];
        for (int k = 1; k < array_len; ++k) {
            if (has_num[k]) {
                res = max(res, mins[k] - lastMax);
                lastMax = maxs[k];
            }
        }
        return res;
    }

    int bucket(int num, int len, int max, int min) {
        return int((num - min) * len / (max - min));
    }
};

int main(){
    vector<int> test = {4, 13, 23, 47, 123, 229, 231, 349, 364, 480};
    cout << Solution().maxgap(test) << endl;
}