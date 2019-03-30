// @Time    : 2019/3/30 17:01
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(const string &s) {
        int res = 0;
        for (auto i = s.begin(); i != s.end() ; ++i) {
            if((i + 1) != s.end() && hash[*(i + 1)] > hash[*i]){
                res += hash[*(i + 1)] - hash[*i];
                i++;
            } else{
                res += hash[*i];
            }
        }
        return res;
    }

private:
    unordered_map<char, int> hash = {{'I', 1},
                                     {'V', 5},
                                     {'X', 10},
                                     {'L', 50},
                                     {'C', 100},
                                     {'D', 500},
                                     {'M', 1000}};
};

int main(){
    string test = "IV";
    cout << Solution().romanToInt(test) << endl;
}