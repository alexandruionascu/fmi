#include<bits/stdc++.h>
#define in cin
#define out cout
#define MAXN 20001
#define int64 long
using namespace std;

ifstream f("data.in");

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

    if(length % 2 == 0)
      return length / 2;
    return length;
}

void solve() {
    int64 order = 1;
    int aux[120];
    for(int i = 1; i <= n; i++)
      aux[i] = 0;
    for(int i = 1; i <= n; i++)
      aux[p[i]]++;
    for(int i = 1; i <= n; i++)
      if(aux[i] != 1) {
        out << -1;
        return;
      }
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
