#include<bits/stdc++.h>
#define in f
#define out g
#define MAXN 20001
#define int64 long long
using namespace std;

ifstream f("perm2.in");
ofstream g("perm2.out");

int p[MAXN];
int n;
bool visited[MAXN];


void read() {
    in >> n;
    for(int i = 1; i <= n; i++) {
        in >> p[i];
    }

}

int gcd(int a, int b) {
    if(b != 0) {
        return gcd(b, a % b);
    }

    return a;
}

int lcm(int a, int b) {
    int64 product = a * b;
    return product / gcd(a, b);
}

int getCycleLength(int i) {

    visited[i] = true;
    int index = p[i];
    visited[index] = true;
    int length = 1;

    while(index != i) {
        index = p[index];
        visited[index]++;
        length++;
    }

    return length;
}

void solve() {
    int64 order = 1;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == false) {
            int length = getCycleLength(i);
            order = lcm(order, length);
        }
    }

    out << order;

}

int main() {
    read();
    solve();
    return 0;
}
