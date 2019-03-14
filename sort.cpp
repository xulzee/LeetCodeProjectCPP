//
// Created by xulzee on 2019/3/11.
//
#include <iostream>
#include <vector>
#include "utils.h"

#define random(x) (rand() % x)

using namespace std;


class Solution {
public:
    void swap(vector<int> &array, int i, int j) {
        if (i == j)
            return;
        array[i] = array[i] ^ array[j];
        array[j] = array[i] ^ array[j];
        array[i] = array[i] ^ array[j];
    }

    void bubblesort(vector<int> &array) {
        if (array.empty()) {
            return;
        }
        for (int i = 0; i < array.size(); ++i) {
            for (int j = static_cast<int>(array.size() - 1); j > i; --j) {
                if (array[j] < array[j - 1]) {
                    swap(array, j, j - 1);
                }
            }
        }
    }

    void insertsort(vector<int> &array) {
        for (int i = 1; i < array.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (array[j] > array[j + 1]) {
                    swap(array, j, j + 1);
                } else{
                    break;
                }
            }
        }
    }

    void selectsort(vector<int> &array) {
        if (array.empty()) {
            return;
        }
        for (int i = 0; i < array.size(); ++i) {
            int min = i;
            for (int j = i; j < array.size(); ++j) {
                if (array[j] < array[min]) {
                    min = j;
                }
            }
            if (i != min) {
                swap(array, i, min);
            }
        }
    }

    void merge(vector<int> &array, int L, int R, int mid) {
        vector<int> temp(R - L + 1, 0);
        int p_l = L;
        int p_r = mid + 1;
        int i = 0;
        while (p_l <= mid && p_r <= R) {
            if (array[p_l] <= array[p_r]) {
                temp[i++] = array[p_l++];
            } else {
                temp[i++] = array[p_r++];
            }
        }

        while (p_l <= mid) {
            temp[i++] = array[p_l++];
        }

        while (p_r <= R) {
            temp[i++] = array[p_r++];
        }

        for (int j = 0; j < R - L + 1; ++j) {
            array[L + j] = temp[j];
        }
    }

    void mergesort(vector<int> &array, int L, int R) {
        if (L == R) {
            return;
        }
        int mid = L + ((R - L) >> 1);
        mergesort(array, L, mid);
        mergesort(array, mid + 1, R);
        merge(array, L, R, mid);
    }

    int smallsummerge(vector<int> &array, int L, int R, int mid) {
        vector<int> temp(R - L + 1, 0);
        int p_l = L;
        int p_r = mid + 1;
        int res = 0;
        int i = 0;
        while (p_l <= mid && p_r <= R) {
            if (array[p_l] < array[p_r]) {
                res += array[p_l] * (R - p_r + 1);
                temp[i++] = array[p_l++];
            } else {
                temp[i++] = array[p_r++];
            }
        }
        while (p_l <= mid) {
            temp[i++] = array[p_l++];
        }
        while (p_r <= R) {
            temp[i++] = array[p_r++];
        }
        return res;
    }

    int smallsum(vector<int> &array, int L, int R) {
        if (L == R) {
            return 0;
        }
        int mid = L + ((R - L) >> 1);
        return smallsum(array, L, mid) + smallsum(array, mid + 1, R) + smallsummerge(array, L, R, mid);
    }

    void quicksort(vector<int> &array) {
        if (array.empty() || array.size() < 2) {
            return;
        }
        quicksortprocess(array, 0, static_cast<int>(array.size() - 1));
    }

    void quicksortprocess(vector<int> &array, int L, int R) {
        if (L < R) {
            vector<int> res;
            res = quicksortpartition(array, L, R);
            quicksortprocess(array, L, res[0] - 1);
            quicksortprocess(array, res[0] + 1, R);
        }
    }

    vector<int> quicksortpartition(vector<int> &array, int L, int R) {
        vector<int> res = {0, 0};
        int less = L - 1;
        int more = R;
        while (L < more) {
            if (array[L] < array[R]) {
                swap(array, L, less + 1);
                less++;
                L++;
            } else if (array[L] > array[R]) {
                swap(array, L, more - 1);
                more--;
            } else {
                L++;
            }
        }
        swap(array, more, R);
        res[0] = less + 1;
        res[1] = more;
        return res;
    }

    void heapsort(vector<int> &array) {
        if (array.empty() || array.size() < 2) {
            return;
        }
        for (int i = 0; i < array.size(); ++i) {
            heapinsert(array, i);
        }
        int size = static_cast<int>(array.size() - 1);
        swap(array, 0, size);
        while (size > 0) {
            heapify(array, size, 0);
            --size;
            swap(array, 0, size);
        }
    }

    void heapinsert(vector<int> &array, int index) {
        // parent_inde = (index - 1) / 2
        while (array[(index - 1) / 2] < array[index]) {
            swap(array, index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }

    void heapify(vector<int> &array, int size, int index) {
        int left = index * 2 + 1;
        int largest = 0;
        while (left < size) {
            if (left + 1 < size) {
                largest = array[left] > array[left + 1] ? left : left + 1;
            } else {
                largest = left;
            }
            largest = array[index] > array[largest] ? index : largest;
            if (largest == index) {
                break;
            }
            swap(array, index, largest);
            index = largest;
            left = index * 2 + 1;
        }
    }

};


int main() {
    vector<int> test = {40, 37, 90, 69, 91, 67, 78, 18, 15, 42, 88, 10, 76, 85, 97, 57, 60, 7, 99, 19};
    int a = 10;
//    int a = Solution().smallsum(test, 0, 4);
//    int mid = 0 + (4 - 0) >> 1;
//    Solution().merge(test, 0, 4, mid);
//    printIntVector(test);
    Solution().insertsort(test);
    printIntVector(test);
}

