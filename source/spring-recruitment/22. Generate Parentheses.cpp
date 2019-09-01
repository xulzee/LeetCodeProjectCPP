//
// Created by liuze.xlz on 2019-08-28.
//
#include "utils.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        nums = {n, n};
        vector<char> items = {'(', ')'};
        string temp;
        backtrack(items, temp);
        return res;
    }

    void backtrack(vector<char> &items, string &temp) {
        if (nums[0] == 0 && nums[1] == 0) {
            res.push_back(temp);
        }
        for (int i = 0; i < items.size(); ++i) {
            if (nums[i] >= 0) {
                if (i == 0 && nums[1] == 0) {
                    continue;
                }
                if (i == 1 && nums[0] >= nums[1]) {
                    continue;
                }
                --nums[i];
                temp.push_back(items[i]);
                backtrack(items, temp);
                temp.pop_back();
                ++nums[i];
            }
        }
    }

private:
    vector<int> nums = {0, 0};
    vector<string> res;
};

int main() {
    vector<string> res;
    res = Solution().generateParenthesis(3);
    for (auto &item : res) {
        cout << item << endl;
    }
    struct SqliteEntry {
        SqliteEntry(std::string uid, std::string data, std::string time_stamp)
                : uid(uid), data(data), time_stamp(time_stamp) {}

        std::string uid;
        std::string data;
        std::string time_stamp;
    };
    vector<SqliteEntry> tasks;
    SqliteEntry entry("", "", "");
}
