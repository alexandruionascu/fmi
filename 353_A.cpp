#include <bits/stdc++.h>
#define in cin
#define out cout
#define int64 long long
using namespace std;

ifstream f("data.in");

int64 a;
int64 b;
int64 c;

void solve() {
    in >> a;
    in >> b;
    in >> c;

    if(c == 0) {
        if(a == b)
            out<<"YES";
        else
            out<<"NO";
        return ;
    }

    if(a < 0) {
        b += -a;
        a = 0;
    }

    if(b < 0) {
        a += -b;
        b = 0;
    }

    if(a % c == b % c) {
        if(c > 0) {
            if(a <= b)
                out<<"YES";
            else
                out<<"NO";
        }
        else
        {

            if(b <= a)
                cout<<"YES";
            else
                cout<<"NO";
        }
        return;
    }
    out<<"NO";
}
int main() {
    solve();
    return 0;
}
