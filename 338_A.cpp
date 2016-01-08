#include<bits/stdc++.h>
#define in cin
#define out cout
#define MAXN 101

using namespace std;

ifstream f("date.in");

bool turned[MAXN];
int n, m;

void read() {
    in >> n;
    in >> m;

    int k;
    for(int i = 1; i <= n; i++) {
        in >> k;
        int x;
        for(int i = 1; i <= k; i++) {
            in >> x;
            turned[x] = true;
        }
    }
}

void solve() {
    for(int i = 1; i <= m; i++) {
        if(turned[i] == false) {
            out << "NO";
            return;
        }
    }

    out << "YES";
}

int main() {
    read();
    solve();
    return 0;
}
