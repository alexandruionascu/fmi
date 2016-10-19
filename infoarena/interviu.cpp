#include<bits/stdc++.h>
using namespace std;


class A {

  public:
     void f() {
       cout << "Hello from A \n";
     }
};

class B : virtual public  A {

};

class C : virtual public A {

};

class D :  public B,  public C {

};

int main() {
    D d;
    d.f();

    return 0;
}
