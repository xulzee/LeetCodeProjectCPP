// @Time    : 2019/3/4 11:55
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include "utils.h"

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {  //递归反转链表
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *t = NULL;
        t = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return t;

    }

    bool isPalindrome1(ListNode *head) {
        if (head == NULL or head->next == NULL) {
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL and fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast->next != NULL) {
            slow = slow->next;
        }

        slow = reverseList(slow);

        while (slow != NULL) {
            if (head->val != slow->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }

    bool isPalindrome(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        bool res = true;
        //找到链表中间节点
        ListNode *n1 = head;
        ListNode *n2 = head;
        while (n2->next != nullptr && n2->next->next != nullptr) {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        // n2 表示下一半的前一个
        // 反转 n2 ~ end
        n2 = n1->next; // 中间节点的下一个
        ListNode *n3;// 保存下一个节点
        n1->next = nullptr; // mid -> nullptr
        while (n2 != nullptr) {
            n3 = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
        }
        // n2 -> end node
        n3 = n1; // save last node
        n2 = head;
        // check Palindrome
        while (n1 != nullptr && n2 != nullptr) {
            if (n1->val != n2->val) {
                res = false;
                break;
            }
            n1 = n1->next; // left to mid
            n2 = n2->next; // right to mid
        }
        n1 = n3->next;
        n3->next = nullptr;
        while (n1 != nullptr) {
            n2 = n1->next; // save next node
            n1->next = n3;
            n3 = n1;
            n1 = n2;
        }
        return res;
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
    vector<int> A = {1, 2, 3, 2, 1};
    ListNode *head = stringToListNode(A);

    bool ret = Solution().isPalindrome(head);

    string out = boolToString(ret);
    cout << out << endl;
    return 0;
}
