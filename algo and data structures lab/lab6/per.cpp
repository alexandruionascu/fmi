#include<bits/stdc++.h>
#define BASE 127
#define in f
#define out cout
#define int64 unsigned long long
#define MAXN 6001
using namespace std;

ifstream f("per.in");
ofstream g("per.out");

int n, k;
string s;
int64 h[MAXN];
int l[MAXN];
int counter;

void read() {
    in >> n;
    in >> k;
    in >> s;
}

void solve() {

    int64 baseNumber = 1;
    int64 currentHash = 0;
    for(int length = 1; length <= n / k; length++) {
        currentHash = currentHash * BASE + s[length - 1];

        l[length - 1] = 1;
        h[length - 1] = currentHash;
        int64 auxHash = currentHash;

        for(int i = length; i < n; i++) {
            auxHash = (auxHash - s[i - length] * baseNumber) * BASE + s[i];
            h[i] = auxHash;
            l[i] = 1;

            if(h[i] == h[i - length]) {
                l[i] += l[i - length];
            }

            if(l[i] >= k)
                counter++;
        }

        baseNumber *= BASE;

    }

    out << counter;
}


int main() {
    read();
    solve();
    return 0;
}
