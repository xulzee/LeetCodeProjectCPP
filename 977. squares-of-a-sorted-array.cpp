//
// Created by xulzee on 2019/2/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares1(vector<int>& A) {
        for (auto i = A.begin(); i < A.end() ; ++i) {
            *i = (*i)*(*i);
        }
//        for (int j = 0; j < A.size(); ++j) {
//            for (int k = j; k < A.size(); ++k) {
//                if (A[j] > A[k]) {
//                    A[j] = A[j] ^A[k];
//                    A[k] = A[j] ^A[k];
//                    A[j] = A[j] ^A[k];
//                }
//            }
//        }
        sort(A.begin(),A.end());
        return A;
    }

    vector<int> sortedSquares(vector<int>& A) {
        int pos = 0;
        vector<int> result;
        result.clear();
        // get split position
        for (auto i = 0; i < A.size() ; ++i) {
            if (A[i] >= 0) {
                pos = i;
                break;
            }
        }
        int left = pos - 1;
        int right = pos;
        while (left >= 0 || right < A.size()) {
            if (left < 0){
                result.push_back(A[right] * A[right]);
                ++right;
            }
            else if (right >= A.size()){
                result.push_back(A[left] * A[left]);
                --left;
            }
            else if (-A[left] < A[right]) {
                result.push_back(A[left] * A[left]);
                --left;
            }
            else {
                result.push_back(A[right] * A[right]);
                ++right;
            }
        }
        return result;
    }
};

int main() {
    vector<int> A = {-1,1};
    printIntVector(Solution().sortedSquares(A));
}
