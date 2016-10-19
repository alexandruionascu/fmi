#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("date.in");
double L, d, v1, v2;

void read() {
    in >> d;
    in >> L;
    in >> v1;
    in >> v2;
}

void solve() {
    printf("%f", (L - d) / (v1 + v2));
}

int main() {
    read();
    solve();
    return 0;
}
