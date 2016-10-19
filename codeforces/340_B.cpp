#include <bits/stdc++.h>
#define in cin
#define out cout
#define MAXN 102
using namespace std;

ifstream f("date.in");

int n;
int total = 0;
int nuts;
int v[MAXN];

void read() {
    in >> n;
    int x;
    for(int i = 1; i <= n; i++) {
        in >> v[i];
        if(v[i] == 1) {
            nuts++;
        }
    }
}



void solve() {
    if(nuts == 1) {
        out << 1;
    } else {
        for(int i = 1; i <= n; i++) {
        int l = i - 1;
        int r = i + 1;

        if(l >= 1) {
            while(v[l] != 1) {
                total++;
                l--;
                if(l < 1) {
                    break;
                }
            }
        }

        if(r <= n) {
            while(v[r] != 1) {
                total++;
                r++;
                if(r > n) {
                    break;
                }
            }

        }
    }

    out << total;

    }

}

int main() {
    read();
    solve();

    return 0;
}
