#include<bits/stdc++.h>
#define in f
#define out cout
#define MOD 9001
#define MAXN 10001
using namespace std;

ifstream f("flori4.in");
ofstream g("flori4.out");

int n;
int result;
int dp[MAXN][MAXN];

void read() {
    in >> n;
}

void solve() {
    for(int i = 1; i <= n; i++)
        dp[1][i] = 1;

    int index, minLength, prev, prevIndex;
    prevIndex = 0;

    for(int i = 2; i <= n; i++) {
        minLength = i + i - 1;

        if(n - minLength + 1 > 0)
            prevIndex = index;

        index = n - minLength + 1;

        if(index > 0) {
            prev = prevIndex;
            for(int j = index; j > 0; j--) {
                dp[i][j] = dp[i][j + 1] + dp[i - 1][prev];
                prev--;
            }

        }

    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            result += dp[i][j] % MOD;
        }
    }

    out << result;
}

int main() {
    read();
    solve();

    return 0;
}
