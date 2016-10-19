#include <bits/stdc++.h>
#define in cin
#define out cout
#define int64 long long
using namespace std;

ifstream f("data.in");
const int MAXN = 20;

int a, b, c ,d;
int r[MAXN];
int sum[MAXN];
int n;

void read() {
    in >> n;
    in >> a;
    in >> b;
    in >> c;
    in >> d;
}

void solve() {
    int64 result = 0;

    for(int i = 1; i <= n; i++) {
        sum[1] = i + a + b;
        sum[2] = i + a + c;
        sum[3] = i + b + d;
        sum[4] = i + c +d;
        int maxx = sum[1];

        for(int j=1; j <= 4; j++)
            if(sum[j] >= maxx)
                maxx = sum[j];

        bool possible = true;
        maxx++;

        int minn = 1<<27;

        for(int j = 1; j <= 4;j++)
        {
            int r = maxx - sum[j];
            minn = min(minn, n - r + 1);
            if(r > n) {
                possible = false;
            }
        }
        if(possible) {
            result += minn;
        }

    }

    out<<result;
}
int main() {

    read();
    solve();

    return 0;
}
