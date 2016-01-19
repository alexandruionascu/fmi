#include<bits/stdc++.h>
#define in f
#define out cout
#define int64 unsigned long long
using namespace std;


ifstream f("date.in");
int64 l, r, k;

void read() {
    in >> l;
    in >> r;
    in >> k;

}

void solve() {
    bool exists = false;

    int64 pow = 1;

    while(pow <= r) {
        if(pow <= r && pow >= l) {
            out << pow << " ";
            exists = true;
        }

        pow *= k;
    }

    if(exists == false) {
        out << -1;
    }
}

int main() {
    read();
    solve();
    return 0;
}
