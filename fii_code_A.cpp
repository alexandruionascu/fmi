#include<bits/stdc++.h>
#define in f
#define out cout
using namespace std;

ifstream f("data.in");
int n;

void solve(int N, int X) {
    int aux = N;
    int digits = 0;
    while(aux > 0) {
        digits++;
        aux /= 10;
    }

    int toGive;

    if(N <= 100) {
        toGive = X;
    } else toGive = X * (digits - 1);


    out << N - toGive << " " << toGive << "\n";
}

void read() {
    in >> n;
    int x, y;
    for(int i = 1; i <= n; i++) {
        in >> x;
        in >> y;
        solve(x, y);
    }
}



int main() {
    read();
    return 0;
}
