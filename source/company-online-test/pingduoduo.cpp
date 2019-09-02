//
// Created by xulzee on 2019/9/1.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

// 题目一描述：
// 读入一个数列和N值，返回按优先级排序的N个数，满足：1.偶数优先级大于奇数；2.同为偶数或同为奇数时，数值大的优先级高；
// 输入：1,2,3,4,5;5
// 输出：4,2,5,3,1
class Topic1 {
    void GetPriorityNNums() {
        vector<int> nums;
        string input;
        cin >> input;

        vector<string> split_result = SplitByStringItem(input, ';');
        nums = SplitByIntItem(split_result[0], ',');
        int n = stoi(split_result[1]);

        vector<int> odd;
        vector<int> even;
        sort(nums.begin(), nums.end(), [](int &num1, int &num2) { return num1 >= num2; });
        for (auto &num : nums) {
            if (num % 2 == 0) {
                even.push_back(num);
            } else {
                odd.push_back(num);
            }
        }

        int flag = n;
        auto iter_odd = odd.begin();
        auto iter_even = even.begin();
        while (n > 0) {
            if (n != flag) {
                cout << ",";
            }
            if (iter_even != even.end()) {
                cout << *iter_even;
                --n;
                ++iter_even;
                continue;
            }
            if (iter_odd != odd.end()) {
                cout << *iter_odd;
                --n;
                ++iter_odd;
            }
        }
        cout << endl;
    }
};

// 题目二描述：
// 扑克游戏，每一局A抽N张牌，自左到右依次排在桌面上；B也抽取M张牌(8>=N>=M>=1)，自左到右依次排在桌面上，A需要经过N个回合，使手中扑克牌
// 组成一个新的扑克牌序列，每个回合有三种策略：
// d 丢弃最左边牌
// l 将最左边牌取出，放到新序列的最左边
// r 将最左边牌取出，放到新序列的最右边
// 最后A希望N个回合之后，新的扑克牌序列跟B的完全一样，输出按字典序排序的所有方法；
// 输入：
// s 作为局数，接下来每两行都是AB各自抽取到的牌
// 输出：
// 每一局以{开始，}结束，中间输出所有方法，每一个回合策略的结尾输出一个空格；
class Topic2 {
public:
    void dfs(string cur, string path, int left, int right) {
        if (left > right + 1) {
            return;
        } else {
            if (cur == target && left == right + 1) {
                res.push_back(path);
            } else {
                dfs(cur, path + "d", left + 1, right);
                dfs(s[left] + cur, path + "l", left + 1, right);
                dfs(cur + s[left], path + "r", left + 1, right);
            }
        }
    }

    void main() {
        int n;
        cin >> n;
        while (n > 0) {
            cin >> s >> target;
            res.clear();
            dfs("", "", 0, s.size() - 1);
            sort(res.begin(), res.end());
            cout << "{";
            for (const auto &method : res) {
                for (const auto &item : method) {
                    cout << item << " ";
                }
                cout << endl;
            }
            cout << "}";
        }
    }

private:
    vector<string> res;
    string target;
    string s;
};

// 题目三描述：
// n个骰子，每个骰子的结果x(2 <= xi <= 50)，所有骰子的结果的最大值作为最终结果，求最终结果的期望，保留两位小数；
// 输入：
// 2
// 2 2
// 输出
// 1.75
#include <iomanip>
class Topic3 {
public:
    void main() {
        int n;
        cin >> n;
        vector<int> p(n, 0);
        int target = 0;
        double sum = 1;
        for (int &i : p) {
            cin >> i;
            sum *= i;
            target = max(target, i);
        }
        sort(p.begin(), p.end());

        vector<double> res(target, 1);
        for (int i = 1; i <= target; ++i) {
            double different = 1;
            for (int &j : p) {
                res[i - 1] *= i > j ? j : i;
                different *= i > j ? j : i - 1;
            }
            res[i - 1] -= different;
        }

        double ret = 0;
        for (int i = 0; i < res.size(); ++i) {
            ret += static_cast<double>(i + 1) * res[i] / sum;
        }

        cout << fixed << setprecision(2) << ret << endl;
    }
};

#include <queue>
int main(){
    int m, n, k;
    cin >> n >> m >> k;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    priority_queue<int> nums;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            nums.push(i * j);
        }
    }

    while (k > 0){
        nums.pop();
        --k;
    }

    cout << nums.top() << endl;
}