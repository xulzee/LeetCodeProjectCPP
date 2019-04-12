// @Time    : 2019/4/11 17:36
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return head == nullptr ? nullptr : mergeSort(head);
    }

    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *dummyNode = new ListNode(0);
        ListNode *res = dummyNode;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                dummyNode->next = left;
                dummyNode = dummyNode->next;
                left = left->next;
            } else {
                dummyNode->next = right;
                dummyNode = dummyNode->next;
                right = right->next;
            }
        }
        if (left != nullptr){
            dummyNode->next = left;
        }
        if (right != nullptr){
            dummyNode->next = right;
        }
        return res->next;
    }

    ListNode *mergeSort(ListNode *head) { // sort nodes
        if (head->next == nullptr) {
            return head;
        }
        ListNode *pre = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        ListNode *left = mergeSort(head);
        ListNode *right = mergeSort(slow);
        return merge(left, right);
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

ListNode *stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

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

string listNodeToString(ListNode *node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode *head = stringToListNode(line);

        ListNode *ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}