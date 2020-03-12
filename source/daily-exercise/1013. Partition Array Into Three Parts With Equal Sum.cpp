//
// Created by xulzee on 2020/3/11.
//

#include "utils.h"

using namespace std;

//{0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1}

class Solution {
public:
    bool canThreePartsEqualSum(vector<int> &A) {
        int sum = 0;
        for (const auto &a : A) {
            sum += a;
        }

        int target;
        if (sum % 3 != 0) {
            return false;
        } else {
            target = sum / 3;
        }

        int count = 0;
        int i = 0;
        sum = 0;
        for (i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum == target) {
                sum = 0;
                ++count;
                if (count == 2) {
                    ++i;
                    break;
                }
            }

        }

        if (i == A.size()) {
            return false;
        }

        while (i < A.size()) {
            sum += A[i];
            ++i;
        }

        return sum == target;
    }
};

int main() {
    vector<int> A = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    cout << Solution().canThreePartsEqualSum(A) << endl;
}