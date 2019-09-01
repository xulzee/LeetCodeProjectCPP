// @Time    : 2019/4/18 18:16
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
        vector<int> out;
        dfs(nums, visited, out);
        return res;
    }

    void dfs(vector<int> &arr,vector<int> &visited, vector<int> &out){
        if (out.size() == arr.size()){
            res.push_back(out);
            return;
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (visited[i] == 1){
                continue;
            }
            visited[i] = 1;
            out.push_back(arr[i]);
            dfs(arr, visited, out);
            out.pop_back();
            visited[i] = 0;
        }
    }
};


int main(){
    vector<int> test = {5,7,9};
    Solution().permute(test);
}
