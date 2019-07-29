// @Time    : 2019/3/10 19:52
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion
#include <stack>
using namespace std;




class A {
public:
    int x;
    int y;

    A() {
        x = 10;
        y = 20;
    }
};

class B {
public:
    int a;
    int b;

    B() {
        a = 30;
        b = 40;
    }
};

class C : public B {
public:
    int p;
    int q;
    A *a;
    C(){
        p = 200;
        q = 1000;
    }

};

int main(){
    auto c = new C();
    stack<int> data;
}