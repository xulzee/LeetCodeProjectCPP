// @Time    : 2019/3/30 21:49
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(const string &s) {
        stack<char> brace;
        for (char i : s) {
            switch (i) {
                case '(':
                    brace.push(i);
                    break;
                case ')':
                    if(brace.empty() || brace.top() != '('){
                        return false;
                    }
                    brace.pop();
                    break;
                case '[':
                    brace.push(i);
                    break;
                case ']':
                    if(brace.empty() || brace.top() != '['){
                        return false;
                    }
                    brace.pop();
                    break;
                case '{':
                    brace.push(i);
                    break;
                case '}':
                    if(brace.empty() || brace.top() != '{'){
                        return false;
                    }
                    brace.pop();
                    break;
                default:
                    break;
            }
        }
        return brace.empty();
    }
};

int main(){
    string test = ")";
    Solution().isValid(test);
}
