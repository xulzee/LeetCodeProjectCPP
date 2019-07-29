// @Time    : 2019/4/21 19:06
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

//#include <iostream>
//#include <unordered_map>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    int lightHeight = 0;
//    int carNum = 0;
//    cin >> carNum >> lightHeight;
//    unordered_map<int, int> line;
//    vector<int> car(carNum + 1, 0);
//    for (int i = 1; i <= carNum; ++i) {
//        cin >> car[i];
//    }
//    for (int j = 1; j <= carNum; ++j) { // y = k * x  + lightHeight
//        float k = static_cast<float>(car[j] - lightHeight) / static_cast<float>(j);
//        int res = 0;
//        for (int i = j - 1; i > 0; --i) {
//            if (k * i + lightHeight <= car[i]) {
//                res = i;
//                break;
//            }
//        }
//        cout << res << endl;
//    }
//}


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int times = 0;
    cin >> times;
    for (int i = 0; i < times; ++i) {
        int k = 0;
        int len = 0;
        cin >> k;
        cin >> len;
        vector<int> nums(len, 0);
        for (int j = 0; j < len; ++j) {
            cin >> nums[j];
        }
        int pos = 0;
        while (k > 0 && pos < len) {
            pair<int, int> swapNum(nums[pos], pos); // max - index
            for (int j = pos + 1; j <= k + pos && j < len; ++j) {
                if (nums[j] > swapNum.first) {
                    swapNum.first = nums[j];
                    swapNum.second = j;
                }
            }
            if (swapNum.first != nums[pos]) {
                k -= (swapNum.second - pos);
                nums.erase(nums.begin() + swapNum.second);
                nums.insert(nums.begin() + pos, swapNum.first);
            }
            pos++;
        }
        if (k > 0 && k % 2 != 0) {
            int temp = nums.back();
            nums[len - 1] = nums[len - 2];
            nums[len - 2] = temp;
        }
        for (int l = 0; l < nums.size() - 1; ++l) {
            cout << nums[l] << " ";
        }
        cout << nums.back() << endl;
    }
}






