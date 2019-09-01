// @Time    : 2019/4/15 10:32
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    int calculate(const string &s) {
        stack<int> res;
        stringstream ss('+' + s);
        char op;
        int num;
        while (ss >> op >> num){
            if (op == '+'){
                res.push(num);
            }
            if (op == '-'){
                res.push(-num);
            }
            if (op == '*'){
                int ans = res.top() * num;
                res.pop();
                res.push(ans);
            }
            if (op == '/'){
                int ans = res.top() / num;
                res.pop();
                res.push(ans);
            }
        }

        int ans = 0;
        while (!res.empty()){
            ans += res.top();
            res.pop();
        }
        return ans;
    }
};