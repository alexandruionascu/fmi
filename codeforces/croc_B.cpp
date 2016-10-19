#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");
int n, k;
unsigned long long result;

const int MAXN = 100000 + 10;

int v[MAXN];

void read() {
    in >> n;
    in >> k;
}

void solve() {
    if(n == 1) {
        out << 0;
        return ;
    }

    int aux = k;
    int length = n - 1;
    int toAdd = 0;
    int l = 1;
    int r = n;
    int steps = 0;

    while(k > 0 && l < r) {
        result += length;
        result += toAdd;
        k--;
        length--;
        toAdd++;
        l++;
        r--;

        steps++;
    }

    if(l < r)
        result += ((n - 2 * steps) * aux);
    else if(l == r)
        result += aux;

    out << result;
}

int main() {
    read();
    solve();
    return 0;
}
