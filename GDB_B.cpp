#include<bits/stdc++.h>
#define FIN "date.in"
#define in cin
#define out cout

using namespace std;

ifstream f(FIN);
long long a, b;

void read() {
    in >> a;
    in >> b;
}

void solve() {
    int n = 0;
    int counter = 0;


    for(int i = 0; i <= 60; i++) {
        long long x = 0;
        for(int j = 1; j <= i; j++) {
            x = x | 1;
            x <<= 1;
        }

        while(x <= b) {
            x <<= 1;
            x = x | 1;

            if(x >= a && x <= b) {
                if((x & (x - 1)) && x != 1)
                    counter++;
            }
        }
    }

    out << counter;
}

int main() {
    read();
    solve();
    return 0;
}
