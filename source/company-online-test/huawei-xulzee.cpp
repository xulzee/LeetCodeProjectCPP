//
// Created by xulzee on 2019/9/4.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

string CheckJson(vector<string> &s) {
    string res;
    vector<int> nums = {0, 0, 0, 0, 0};
    vector<int> count = {0, 0};
    for (auto &line : s) {
        for (auto &item : line) {
            if (item == '"') {
                ++nums[3];
            } else if (item == '{') {
                ++nums[2];
            } else if (item == '}') {
                --nums[2];
            } else if (item == '[') {
                ++nums[1];
            } else if (item == ']') {
                --nums[1];
            }
        }
    }
    if (nums[1] != 0) {
        res += '1';
    }
    if (nums[2] != 0) {
        res += '2';
    }
    if (nums[3] % 2 != 0) {
        res += '3';
    }
    if (res.empty()) {
        res += '0';
    }
    return res;
}

int main() {
    vector<string> lines;
    while (true) {
        string line;
        getline(cin, line);
        if (line.empty()) {
            break;
        }
        lines.push_back(line);
    }
    string res = CheckJson(lines);
    cout << res << endl;
}

vector<string> SplitByStringItem(const string &s, const char item) {
    // item is string
    vector<string> res;
    string temp;
    stringstream ss;
    ss.str(s);
    while (true) {
        if (!getline(ss, temp, item)) {
            break;
        }
        res.push_back(temp);
    }
    return res;
}

inline void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

inline void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

inline bool isVar(string &input) {
    for (auto &c : input) {
        if (c >= '0' && c <= '9') {
            return false;
        }
    }
    return true;
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main2() {
    string s;
    int n;
    string input;
    getline(cin, input);
    n = stoi(input);
    unordered_map<string, string> name_value;
    while (n > 0) {
        string line;
        getline(cin, line);

        trimLeftTrailingSpaces(line);
        trimRightTrailingSpaces(line);
        vector<string> output = SplitByStringItem(line, '=');

        if (output.size() < 2) {
            continue;
        }

        string left = output.front();
        trimLeftTrailingSpaces(left);
        trimRightTrailingSpaces(left);
        string right = output.back();

        vector<string> nums = SplitByStringItem(right, '+');
        int res = 0;
        bool isValied = true;
        for (auto &num : nums) {
            trimLeftTrailingSpaces(num);
            trimRightTrailingSpaces(num);
            if (isVar(num)) {
                if (name_value.find(num) == name_value.end()) {
                    name_value[left] = "*";
                    isValied = false;
                    break;
                } else {
                    res += stoi(name_value[num]);
                }
            } else {
                res += stoi(num);
            }
        }
        if (isValied) {
            name_value[left] = to_string(res);
        }

        if (n == 1) {
            if (name_value[left] == "*") {
                cout << "NA" << endl;
            } else {
                cout << name_value[left] << endl;
            }
        }
        --n;
    }
}
//5
//   xx= 2
//yy = 5
//   zz = xx
// cd= xx+ yy + zz

int main1() {
    int n;
    cin >> n;
    int res = INT32_MAX;
    bool flag = false;
    for (int i = 0; i <= n / 9; ++i) {
        for (int j = 0; j <= n / 4; ++j) {
            if (i * 9 + j * 4 == n) {
                flag = true;
                res = min(res, i + j);
            }
        }
    }
    if (!flag) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
