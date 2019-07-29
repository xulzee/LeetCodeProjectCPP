// @Time    : 2019/4/1 18:54
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>
#include <iostream>
#include <stack>

using namespace std;


static string removeNums(string str, int num) {
    int pop_num = 0;
    int now = 0;
    string result;
    if (str.empty() || str.size() == num) {
        return "0";
    }
    result = str;
    for (int i = 1; i < str.size(); i++) {
        while (int(result[now]) > int(str[i]) && now >= 0 && pop_num < num) {
            now--;
            pop_num++;
        }
        now++;
        result[now] = str[i];
    }
    string return_value;
    bool zeroFlag = false;
    for (int i = 0; i < result.size() && i < str.size() - num; i++) {
        if (result[i] != '0')
            zeroFlag = true;
        if (result[i] == '0' && !zeroFlag)
            continue;
        return_value += result[i];
    }
    if (return_value.empty()) {
        return "0";
    }
    return return_value;
}

int main() {
    string str;
    int num;
    while (cin >> str >> num) {
        cout << removeNums(str, num) << endl;
    }
    return 0;
}

//// 394
//class Solution {
//public:
//    string decodeString(string s) {
//        stack<string> chars;
//        stack<int> nums;
//        string res;
//
//        int num = 0;
//        for (char c: s) {
//
//
//            if (isdigit(c))
//                num = num * 10 + (c - '0');
//            else if (isalpha(c)) {
//                res += c;
//            } else if (c == '[') {
//                chars.push(res);
//                nums.push(num);
//                res = "";
//                num = 0;
//            } else {
//                string tmp = res;
//                for (int i = 0; i < nums.top() - 1; i++)
//                    res += tmp;
//                res = chars.top() + res;
//                chars.pop();
//                nums.pop();
//            }
//        }
//
//        return res;
//    }
//};
//
//int main() {
//    string s;
//    while (cin >> s) {
//        stack<string> stringStack;
//        stack<int> nums;
//        string res;
//
//        int num = 0;
//        for (char c: s) {
//            if (isdigit(c))
//                num = num * 10 + (c - '0');
//            else if (isalpha(c)) {
//                res += c;
//            } else if (c == '[') {
//                stringStack.push(res);
//                nums.push(num);
//                res = ""; // reset
//                num = 0;
//            } else {
//                string tmp = res;
//                for (int i = 0; i < nums.top() - 1; i++)
//                    res += tmp;
//                res = stringStack.top().append(res);
//                stringStack.pop();
//                nums.pop();
//            }
//        }
//        cout << res << endl;
//    }
//}