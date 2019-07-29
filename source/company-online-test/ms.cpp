//
// Created by xulzee on 2019/4/3.
//
#include <vector>
#include <iostream>

using namespace std;

int process(vector<vector<bool> > &arr, int cur, int end, int step) {
    if (step == 0) {
        if (cur == end) {
            return 1;
        } else {
            return 0;
        }
    }
    int ret = 0;
    for (int i = 1; i < arr[0].size(); ++i) {
        if (arr[cur][i] && cur != i) {
            ret += process(arr, i, end, step - 1);
        }
    }
    return ret;
}

int dynamicProcess(vector<vector<bool> > &arr, int cur, int end, int step) {
    vector<vector<int> > dp(arr[0].size(), vector<int>(step + 1, 0));
    for (int j = 0; j <= step; ++j) { // step
        for (int i = 1; i <= cur; ++i) { // cur
            if (j == 0) {
                if (i == end) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            } else {
                int ret = 0;
                for (int k = 1; k < arr[0].size(); ++k) {
                    if (arr[i][k] && i != k) {
                        ret += dp[k][j - 1];
                    }
                }
                dp[i][j] = ret;
            }
        }
    }
    return 1;
}


int maxCircles(int input1, int input2, int input3) {
    vector<vector<bool> > arr(input1 + 1, vector<bool>(input1 + 1, false));
    for (int i = 1; i <= input1; ++i) {
        for (int j = 1; j <= input1; ++j) {
            if (j % i == 0 || i % j == 0) {
                arr[i][j] = true;
            }
        }
    }
//    dynamicProcess(arr, input2, input2, input3);
    cout << process(arr, input2, input2, input3) << endl;
    int res = 0;
    for (int k = 2; k < input3; ++k) {
        res += dynamicProcess(arr, input2, input2, k);
    };
    return res;
}


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(vector<int> s) {
    vector<int> rev = s;
    reverse(rev.begin(), rev.end());
    int len = s.size();
    vector<vector<int>> dp(len + 1, vector<int>(len + 1));
    for (int i = 1; i <= len; ++i)
        for (int j = 1; j <= len; ++j) {
            if (s[i - 1] == rev[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
            }
        }
    return len - dp[len][len] + 1;
}


int process(vector<int> arr, int i, int j) {
    if (i == j) {
        return 1;
    }
    int min_point = LCS(vector<int>(arr.begin() + i, arr.begin() + j + 1));
    for (int k = i; k <= j; ++k) {
        min_point = min(min_point, process(arr, i, k) + process(arr, k + 1, j));
    }
}


int points(int input1, vector<int> input2) {
    vector<int> arr(input1, 0);
    for (int i = 0; i < input1; ++i) {
        arr[i] = input2[i];
    }
    vector<vector<int>> dp(input1 + 1, vector<int>(input1 + 1, 0));
    for (int i = input1; i >= 0; --i) {
        for (int j = 0; j < input1; ++j) {
            if (j >= i) {
                if (i == j) {
                    dp[i][j] = 1;
                } else {
                    int min_point = LCS(vector<int>(arr.begin() + i, arr.begin() + j + 1));
                    for (int k = i; k < j; ++k) {
                        min_point = min(min_point, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = min_point;
                }
            }
        }
    }
    return dp[0][input1-1];
}

int main() {
    vector<int> arr = {1, 4, 1, 3, 5};
    cout << points(5, arr) << endl;
}


//#include <map>
//
//
//int findPosition(int input1, int input2, vector<vector<int> > &input3) {
//    map<int, int> posMap;
//    for (int i = 1; i <= input1; ++i) {
//        posMap[i] = i;
//    }
//    int head = 1;
//    int res = 0;
//    for (int j = 0; j < input2; ++j) {
//        int E = input3[j][0];
//        int X = input3[j][1];
//        if (E == 1) {
//            posMap[head] = -1;
//            head++;
//        } else if (E == 2) {
//            posMap[X] = -1;
//        } else if (E == 3) {
//            int cnt = 1;
//            for (map<int, int>::iterator i = posMap.begin(); i != posMap.end(); ++i) {
//                if ((*i).first == X) {
//                    res += cnt;
//                    break;
//                }
//                if ((*i).second != -1) {
//                    cnt++;
//                }
//            }
//        }
//    }
//    return res;
//}
//
//#include <queue>
//#include <math.h>
//#include <set>
//
//class Node;
//
//class Edge;
//
//class Edge {
//public:
//    int weight;
//    Node *from;
//    Node *to;
//
//    Edge(int w, Node *f, Node *t) {
//        weight = w;
//        from = f;
//        to = t;
//    }
//};
//
//class Node {
//public:
//    bool isFlower;
//    int value;
//    int in; // 入度
//    int out; // 出度
//    vector<Node *> nexts;
//    vector<Edge *> edges;
//
//    explicit Node(int n) {
//        value = n;
//        in = 0;
//        out = 0;
//    }
//
//};

//class Graph {
//public:
//    map<int, Node *> nodes;
//    set<Edge *> edges;
//};
//
//int
//honey(int input1, int input2, vector<vector<int>> input3, vector<vector<int>> input4, vector<int> input5, int input6) {
//    float maxDistance = input6;
//    vector<vector<float> > flower2combdistance(input1, vector<float>(input2, 0));
//    int firstFlow = 0;
//    float firstFlowDistance = 0x7fffffff;
//    set<int> usedFlower;
//    int res = 0;
//    for (int k = 0; k < input1; ++k) {
//        float temp = sqrt(pow((input5[0] - input3[k][0]), 2) + pow((input5[1] - input3[k][1]), 2));
//        if (temp < firstFlowDistance) {
//            firstFlowDistance = temp;
//            firstFlow = k;
//        }
//    }
//
////    vector<priority_queue<int> ,vector<int >, > flower2combdistanceQueue;
//    vector<priority_queue<int> > comb2flowerdistanceQueue;
//    for (int i = 0; i < input1; ++i) { // flower
//        int flower_x = input3[i][0];
//        int flower_y = input3[i][1];
//        for (int j = 0; j < input2; ++j) { //comb
//            int comb_x = input4[i][0];
//            int comb_y = input4[i][1];
//            float dis = sqrt(pow((comb_x - flower_x), 2) + pow((comb_y - flower_y), 2));
//            flower2combdistance[i][j] = dis;
//            flower2combdistance[j][i] = dis;
//        }
//    }
//
//    if (maxDistance > firstFlowDistance) {
//        usedFlower.insert(firstFlow);
//        maxDistance -= firstFlowDistance;
//    }
//
//    int cur = firstFlow;
//    bool flag = true; // true : flower -> comb  false : comb -> flower
//    while (maxDistance > 0) {
//        float minDistance = 0x7fffffff;
//        if (flag) {
//            usedFlower.insert(cur);
//            for (int i = 0; i < input2; ++i) { // find comb
//                if (flower2combdistance[cur][i] < minDistance) {
//                    minDistance = flower2combdistance[cur][i];
//                    cur = i;
//                }
//            }
//            if (minDistance > maxDistance) {
//                break;
//            } else {
//                maxDistance -= minDistance;
//                res++;
//            }
//            flag = false;
//        } else {
//            for (int i = 0; i < input1; ++i) {// find flower
//                if (flower2combdistance[i][cur] < minDistance && usedFlower.find(i) == usedFlower.end()) {
//                    minDistance = flower2combdistance[i][cur];
//                    cur = i;
//                }
//            }
//            if (minDistance > maxDistance) {
//                break;
//            } else {
//                maxDistance -= minDistance;
//            }
//            flag = true;
//        }
//    }
//
//
//}
//
//int main() {
//    vector<vector<int>> input3 = {{3, 3},
//                                  {4, 6}};
//    vector<vector<int>> input4 = {{5, 5},
//                                  {6, 1}};
//    vector<int> input5 = {5, 5};
//    honey(2, 2, input3, input4, input5, 13);
//}