#include<bits/stdc++.h>
#define in cin
#define out cout
#define int64 long long
using namespace std;

ifstream f("date.in");
priority_queue<int64> s;
int n;
int64 sum;

void read() {
    in >> n;
    int64 x;
    for(int i = 1; i <= n; i++) {
        in >> x;
        if(x >= 0) {
            sum += x;
        } else {
            s.push(x);
        }
    }
}

void solve() {
    if(s.size() % 2 == 1)
        s.pop();
    while(s.size() > 1) {

        sum += s.top();
        s.pop();
        s.pop();
    }

    out << sum;
}

int main() {
    read();
    solve();
    return 0;
}
