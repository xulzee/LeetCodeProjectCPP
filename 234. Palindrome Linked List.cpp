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

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *t = NULL;
        t = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return t;

    }

    bool isPalindrome(ListNode *head) {
        if (head == NULL or head->next == NULL){
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

ListNode* stringToListNode(vector<int> l) {
    // Generate list from the input
    vector<int> list = l;

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
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
    vector<int> A = {1,0,1};
    ListNode* head = stringToListNode(A);

    bool ret = Solution().isPalindrome(head);

    string out = boolToString(ret);
    cout << out << endl;
    return 0;
}
