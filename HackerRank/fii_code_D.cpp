#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");

unsigned long long result;
int n;

void solve() {
    in >> n;
    int current = 0;
    int x;
    for(int i = 1; i <= n; i++) {
        in >> x;

        if(x > current) {
            result += x - current;
        }

        current = x;
    }

    out << result;
}

int main() {
    solve();
    return 0;
}
