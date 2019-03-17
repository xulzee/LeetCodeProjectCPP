// @Time    : 2019/3/16 22:15
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <vector>

using namespace std;

// 打印两个有序数组的公共部分
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<int> printCommonPart(ListNode *head1, ListNode *head2) {
        vector<int> res;
        ListNode *L1 = head1;
        ListNode *L2 = head2;
        while (L1 != nullptr && L2 != nullptr) {
            if (L1->val < L2->val) {
                L1 = L1->next;
            } else if (L1->val > L2->val) {
                L2 = L2->next;
            } else{
                res.push_back(L1->val);
                L1 = L1->next;
                L2 = L2->next;
            }
        }
        return res;
    }
};