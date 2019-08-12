//
// Created by liuze.xlz on 2019-08-12.
//

#include "utils.h"

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            if (iter != s.end() && char_map[*iter] < char_map[*(iter + 1)]) {
                res -= char_map[*iter];
            } else {
                res += char_map[*iter];
            }
        }
        return res;
    }

private:
    unordered_map<char, int> char_map = {{'I', 1},
                                         {'V', 5},
                                         {'X', 10},
                                         {'L', 50},
                                         {'C', 100},
                                         {'D', 500},
                                         {'M', 1000}};
};

int main() {
    cout << Solution().romanToInt("MCMXCIV") << endl;
}
