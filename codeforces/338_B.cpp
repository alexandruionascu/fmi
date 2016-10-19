#include<bits/stdc++.h>
#define MAXN 100001
#define in cin
#define out cout
#define int64 long long
using namespace std;

ifstream f("date.in");

vector<int> g[MAXN];
int n, m;
int64 maximum = 0;
bool visited[MAXN];
int d[MAXN];


void read() {
    in >> n;
    in >> m;

    int x, y;
    for(int i = 1; i <= m; i++) {
        in >> x;
        in >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
}


void solve() {
    d[1] = 1;

    for(int i = 2; i <= n; i++) {
        int maxLen = 1;
        for(auto it : g[i]) {
            if(it < i) {
                maxLen = max(d[it] + 1, maxLen);
            }
        }

        d[i] = maxLen;

        if(maxLen * g[i].size() > maximum)
            maximum = maxLen * g[i].size();
    }

    out << maximum;
}

int main() {
    read();
    solve();
    return 0;
}
