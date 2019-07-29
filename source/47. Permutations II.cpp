// @Time    : 2019/4/19 23:22
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> visited;
    vector<int> out;
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.empty()){
            return {};
        }
        visited = vector<int>(nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(nums);
        return res;
    }

    void dfs(vector<int> &arr) {
        if (out.size() == arr.size()) {
            res.push_back(out);
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (visited[i] == 0) {
                if (i != 0 && arr[i] == arr[i - 1] && visited[i - 1] == 0) {
                    continue;
                }
                visited[i] = 1;
                out.push_back(arr[i]);
                dfs(arr);
                out.pop_back();
                visited[i] = 0;
            }
        }
    }
};

int main() {
    vector<int> test = {3, 3, 1, 1};
    Solution().permuteUnique(test);
}
