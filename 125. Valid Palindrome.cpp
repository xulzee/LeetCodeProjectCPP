// @Time    : 2019/3/31 16:23
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size();
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            } else if (!isalnum(s[right])) {
                right--;
            } else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }

private:
    char tolower(char c) {
        if (c >= '0' and c <= '9'){
            return c;
        }
        if (c >= 'a' and c <= 'z'){
            return c;
        }

        if (c >= 'A' and c <= 'Z'){
            c += 'a' - 'A';
            return c;
        }
    }
};

int main() {
    string test = "A man, a plan, a canal: Panama";
    Solution().isPalindrome(test);
}
