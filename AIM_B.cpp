#include<bits/stdc++.h>
#define in cin
#define out cout
#define MAXN 27
using namespace std;

ifstream f("date.in");
int n;
int v[MAXN];
long long result;

void read() {
    in >> n;
    for(int i = 1; i <= n; i++) {
        in >> v[i];
    }
}

void solve() {
    sort(v + 1, v + 1 + n);
    result += v[n];
    for(int i = n-1; i >= 1; i--) {

        if(v[i] == v[i+1]) {
            v[i]--;
        } else {
            if(v[i] > v[i+1]) {
                v[i] = min(v[i], v[i+1]) - 1;
            }

        }

        if(v[i] > 0)
            result += v[i];

    }

    out << result;

}

int main() {
    read();
    solve();
    return 0;
}

