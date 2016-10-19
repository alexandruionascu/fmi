#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("date.in");

int x;

void read() {
    in >> x;
}

void solve() {
    int rest = x % 5;
    int res = x / 5;

    if(rest > 0) {
        out << res + 1;
    } else if(x <= 5) {
        out << 1;
    } else out << res;

}

int main() {
    read();
    solve();

    return 0;
}

