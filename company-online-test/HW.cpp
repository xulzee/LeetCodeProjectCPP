// @Time    : 2019/4/10 19:04
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion


#include <vector>
#include <iostream>

using namespace std;

int uniquePaths(vector<vector<int>> &memorySearch, vector<vector<int>> &arr, int curRow, int curColumn, int endRow,
                int endColumn) {
    if (curRow == endRow && curColumn == endColumn) {
        return 1;
    }
    int ret = 0;
    int curHeight = arr[curRow][curColumn];
    arr[curRow][curColumn] = -1; // marked in use
    if (curRow + 1 < arr.size() && arr[curRow + 1][curColumn] > curHeight && arr[curRow + 1][curColumn] != -1) {
        if (memorySearch[curRow + 1][curColumn] == -1) {
            ret += uniquePaths(memorySearch, arr, curRow + 1, curColumn, endRow, endColumn) % 1000000000;
        } else {
            ret += memorySearch[curRow + 1][curColumn] % 1000000000;
        }
    }
    if (curRow - 1 >= 0 && arr[curRow - 1][curColumn] > curHeight && arr[curRow - 1][curColumn] != -1) {
        if (memorySearch[curRow - 1][curColumn] == -1) {
            ret += uniquePaths(memorySearch, arr, curRow - 1, curColumn, endRow, endColumn) % 1000000000;
        } else {
            ret += memorySearch[curRow - 1][curColumn] % 1000000000;
        }
    }
    if (curColumn + 1 < arr[0].size() && arr[curRow][curColumn + 1] > curHeight && arr[curRow][curColumn + 1] != -1) {
        if (memorySearch[curRow][curColumn + 1] == -1) {
            ret += uniquePaths(memorySearch, arr, curRow, curColumn + 1, endRow, endColumn) % 1000000000;
        } else {
            ret += memorySearch[curRow][curColumn + 1] % 1000000000;
        }
    }
    if (curColumn - 1 >= 0 && arr[curRow][curColumn - 1] > curHeight && arr[curRow][curColumn - 1] != -1) {
        if (memorySearch[curRow][curColumn - 1] == -1) {
            ret += uniquePaths(memorySearch, arr, curRow, curColumn - 1, endRow, endColumn) % 1000000000;
        } else {
            ret += memorySearch[curRow][curColumn - 1] % 1000000000;
        }
    }
    arr[curRow][curColumn] = curHeight; // no longer in use
    memorySearch[curRow][curColumn] = ret;
    return ret % 1000000000;
}

int main() {
    int row;
    int column;
    cin >> row >> column;
    vector<vector<int>> input(row, vector<int>(column, 0));
    int temp;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cin >> temp;
            input[i][j] = temp;
        }
    }
    int start_x, start_y;
    int end_x, end_y;
    cin >> start_x >> start_y;
    cin >> end_x >> end_y;
    vector<vector<int>> memorySearch(row, vector<int>(column, -1));
    cout << uniquePaths(memorySearch, input, start_x, start_y, end_x, end_y) << endl;
    return 0;
}


//#include <string>
//#include <stack>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//string unZipString(string s) {
//    stack<string> chars;
//    stack<int> nums;
//    string res;
//    int num = 0;
//
//    for (char c: s) {
//        if (isdigit(c))
//            num = num * 10 + (c - '0');
//        else if (isalpha(c)) {
//            res += c;
//        } else if (c == '[' || c == '{' || c == '(') {
//            chars.push(res);
//            nums.push(num);
//            res = "";
//            num = 0;
//        } else {
//            string tmp = res;
//            for (int i = 0; i < nums.top() - 1; i++)
//                res += tmp;
//            res = chars.top() + res;
//            chars.pop();
//            nums.pop();
//        }
//    }
//
//    return res;
//}
//
//int main() {
//    string input;
//    cin >> input;
//    string res = unZipString(input);
//    reverse(res.begin(), res.end());
//    cout << res << endl;
//}