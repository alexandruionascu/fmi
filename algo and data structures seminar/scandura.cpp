#include<bits/stdc++.h>
#define in f
#define out g
using namespace std;

ifstream f("scandura.in");
ofstream g("scandura.out");

queue<long long> s;
queue<long long> sums;
int n, m;
long long result;

void read() {
    in >> n;
    in >> m;

    int rest = (n - 1) % (m - 1);

    for(int i = 1; i <= rest; i++) {
        s.push(0);
    }

    int x;
    for(int i = 1; i <= n; i++) {
        in >> x;
        s.push(x);
    }

}

void solve() {


    while(!s.empty()) {

        long long sum = 0;
        for(int i = 1; i <= m; i++) {
            if(!s.empty() && !sums.empty()) {
                if(s.front() > sums.front()) {
                    sum += sums.front();
                    sums.pop();
                } else {
                    sum += s.front();
                    s.pop();
                }
            } else {
                if(!s.empty()) {
                    sum += s.front();
                    s.pop();
                } else if(!sums.empty()) {
                    sum += sums.front();
                    sums.pop();
                }
            }

        }

        result += sum;

        sums.push(sum);
    }

    out << result;
}

int main() {
    read();
    solve();
    return 0;
}
