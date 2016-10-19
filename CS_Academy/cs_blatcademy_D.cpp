#include<bits/stdc++.h>
#define in cin
#define out cout
#define MAXN 100002
using namespace std;

ifstream f("date.in");

int a[MAXN];
int b[MAXN];

vector<pair<int, int> > swaps;

int n, k, m;
int first, target;

void read() {
    in >> n;
    in >> m;
    in >> k;

    a[0] = 1;


    int x, y;
    swaps.push_back(make_pair(1, 1));
    for(int i = 1; i <= m; i++) {
        in >> x;
        in >> y;
        swaps.push_back(make_pair(x, y));

        if(a[i - 1] == x) {
            a[i] = y;
        } else if(a[i - 1] == y) {
            a[i] = x;
        } else a[i] = a[i - 1];
    }

}

void solve() {
    b[m + 1] = k;

    for(int i = m; i >= 1; i--) {
        if(swaps[i].first == b[i + 1]) {
            b[i] = swaps[i].second;
        } else if(swaps[i].second == b[i + 1]) {
            b[i] = swaps[i].first;
        } else b[i] = b[i + 1];

    }

    if(b[2] == 1) {
        out << 1;
        return;
    }

    for(int i = 1; i < m; i++) {
        if(a[i] == b[i + 2]) {
            out << i + 1;
            return;
        }
    }
}

int main() {
    read();
    solve();
    return 0;
}
