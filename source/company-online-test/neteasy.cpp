// @Time    : 2019/3/9 9:35
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

//#include <iostream>
//#include <stdio.h>
//#include <string>
//
//using namespace std;
//
//int main() {
//    int N;
//    cin >> N;
//    string str[10];
//    int x[10];
//    int y[10];
//    for (int k = 0; k <N ; ++k) {
//        cin >> x[k] >> y[k];
//        cin >> str[k];
//    }
//    for (int i = 0; i < N; ++i) {
//        bool impossible = false;
//        int line_num = 0;
//        int count = 0;
//        for (int j = 0; j < str[i].length(); ++j) {
//            if (str[i][j] == '\n'){
//                count = 0;
//                ++line_num;
//            }
//
//            if (str[i][j] != ',' && str[i][j] != '.' && str[i][j] != '!' && str[i][j] != '?'){
//                count += x[i];
//            } else{
//                if (x[i] == y[i]){
//                    cout << "impossible" << endl;
//                    impossible = true;
//                    break;
//                }
//                if (count == 0){
//                    count += 2*x[i];
//                } else{
//                    count += x[i];
//                }
//            }
//
//            if (count >= y[i]){
//                count -= y[i];
//                line_num++;
//            }
//
//        }
//        if (count > 0){
//            line_num++;
//            count = 0;
//        }
//        if (!impossible){
//            cout << line_num << endl;
//        }
//        line_num = 0;
//        count = 0;
//    }
//    return 1;
//}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;
int main()
{
    int n, k;
    int i, j;
    char temp;
    char a[1000][1000];
    char t[1000];
    int p = 0;

    string line;
    while (getline(cin, line)) {
        vector<int> nums;
        stringstream ss;
        ss.str(line);
        string item;
        char split_item = ',';
        while (getline(ss, item, split_item)) {
            nums.push_back(stoi(item));
        }
        k = nums[1];
        n = nums[0];
        for (i = 1; i <= n; i++)
        {
            to_string(i, a[p]);
            p++;
        }
        for (i = 0; i < p - 1; i++)
        {
            for (j = 0; j < p - 1 - i; j++)
                if (strcmp(a[j], a[j + 1]) > 0)
                {
                    strcpy(t, a[j]);
                    strcpy(a[j], a[j + 1]);
                    strcpy(a[j + 1], t);

                }
        }
        cout << a[k - 1] << endl;
    }
    return 0;
}