//
// Created by liuze.xlz on 2019-08-24.
//

#include "utils.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> temp;
        vector<int> visited(nums.size(), 0);
        vector<vector<int>> res;
        dfs(nums, visited, temp, res, 0);
        return res;
    }


    void dfs(vector<int> &nums, vector<int> &visited, vector<int> &temp,vector<vector<int>> &res, int len) {
        if (len >= 2) {
            res.push_back(temp);
            return;
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (visited[j] == 0){
                visited[j] = 1;
                temp.push_back(nums[j]);
                dfs(nums, visited, temp, res, len + 1);
                temp.pop_back();
                visited[j] = 0;
            }
        }
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution().permute(nums);
}

