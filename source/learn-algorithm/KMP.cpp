// @Time    : 2019/4/8 16:20
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> getNext(const string &s) {
    if (s.size() <= 1) {
        return {-1};
    }
    vector<int> next(s.size(), -1);
    int i = 1; // cur
    int j = -1; // pre
    while (i < s.size()) {
        if (j == -1 || s[i - 1] == s[j]) {
            next[i++] = j + 1;
            j++; // next[i -1]
        } else {
            j = next[j];
        }
    }
    return next;
}

int getIndexOf(const string &s, const string &t) {
    if (s.empty() || t.empty() || s.size() < t.size()) {
        return -1;
    }
    vector<int> next = getNext(t);
    int i = 0;
    int j = 0;
    while (i < s.size() && j < int(t.size())) {
        if (j == -1 || s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == t.size()) {
        return i - j;
    } else {
        return -1;
    }
}


class Test {
    int a;
};

typedef struct _data {
    int id;
    char name[6];
    long long time;
    char add[4];
} data;

#include <queue>

class Solution {
public:
    void swap(vector<int> &arr, int i, int j) {
        if (i == j) {
            return;
        }
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }

    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto num:nums) {
            if (q.size() == k) {
                if (num <= q.top()) {
                    continue;
                }
                q.pop();
            }
            q.push(num);
        }
        return q.top();
    }

    int _findKthLargest(vector<int> &nums, int k) {
        vector<int> ret;
        k = nums.size() - k;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            ret = partition(nums, left, right);
            if (k < ret[0]) {
                right = ret[0] - 1;
            } else if (k > ret[1]) {
                left = ret[1] + 1;
            } else {
                return nums[k];
            }
        }
        return nums[k];
    }

    vector<int> partition(vector<int> &arr, int left, int right) {
        int less = left - 1;
        int more = right;
        while (left < more) {
            if (arr[left] < arr[right]) {
                swap(arr, left, less + 1);
                ++left;
                ++less;
            } else if (arr[left] == arr[right]) {
                ++left;
            } else {
                swap(arr, left, more - 1);
                --more;
            }
        }
        swap(arr, left, right);
        return {less + 1, left};
    }
};

int main() {
    vector<int> test = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    auto ans = Solution()._findKthLargest(test, 4);
    cout << ans << endl;



//    auto x = sizeof(data);
//    char arr[] = {'a', 'b','\0', 'c','d'};
//    auto y = sizeof(arr );
//    string s = "123qweabababab123";
//    string a = "a";
//    auto z = a.substr(0, 1);
//    string test = "abcaabc";
//    auto ret = getIndexOf(s, test);
//    char c[4][8] = {{"ab"},
//                    {"bc"},
//                    {"cd"}};

}



