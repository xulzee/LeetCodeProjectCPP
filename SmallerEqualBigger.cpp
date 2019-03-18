//
// Created by xulzee on 2019/3/17.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// 链表的荷兰国旗问题，要求保证稳定性，时间复杂度O(n), 空间复杂度O(1)
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* SmallEqualBigger(ListNode *head, int target) {
        ListNode *small_head = nullptr;
        ListNode *small_tail = nullptr;
        ListNode *equal_head = nullptr;
        ListNode *equal_tail = nullptr;
        ListNode *big_head = nullptr;
        ListNode *big_tail = nullptr;
        ListNode *next = nullptr; // save next node;
        while (head != nullptr) {
            next = head->next;
            head->next = nullptr;
            if (head->val == target) {
                if (equal_head == nullptr) {
                    equal_head = head;
                    equal_tail = head;
                } else {
                    equal_tail->next = head;
                    equal_tail = head;
                }
            } else if (head->val < target) {
                if (small_head == nullptr) {
                    small_head = head;
                    small_tail = head;
                } else {
                    small_tail->next = head;
                    small_tail = head;
                }
            } else {
                if (big_head == nullptr) {
                    big_head = head;
                    big_tail = head;
                } else {
                    big_tail->next = head;
                    big_tail = head;
                }
            }
            head = next;
        }
        if (small_tail != nullptr) { // connect small and equal
            small_tail->next = equal_head;
            equal_tail = equal_head == nullptr ? small_tail : equal_tail;
        }
        if (equal_tail != nullptr) { // connect all
            equal_tail->next = big_head;
        }
        if (small_head != nullptr) {
            return small_head;
        } else if (equal_head != nullptr) {
            return equal_head;
        } else {
            return big_head;
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(vector<int> l) {
    // Generate list from the input
    vector<int> list = l;

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    vector<int> A = {8, 7, 6, 5, 4, 3, 2, 1};
    ListNode *head = stringToListNode(A);

    head = Solution().SmallEqualBigger(head, 9);

//    string out = boolToString(ret);
//    cout << out << endl;
    return 0;
}