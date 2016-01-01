#include<bits/stdc++.h>
#define FIN "per.in"
#define FOUT "per.out"
#define in f
#define out cout
#define BASE 127
#define MAXN 6001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int n, k;
string text;
int counter;
int h[MAXN];

void read() {
    in >> n;
    in >> k;
    in >> text;
}

void solve() {

    int currentHash = 0;

    for(int i = 1; i <= n / k; i++) {
        currentHash = h[i - 1] * BASE + text[i - 1];
        h[i] = currentHash;

        for(int j = i; j <= n; j++) {



        }
    }
}

int main() {
    read();
    solve();
    return 0;
}
