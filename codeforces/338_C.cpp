#include<bits/stdc++.h>
#define MAXN 200001
#define in cin
#define out cout
#define int64 unsigned long long
#define MOD 1000000007
using namespace std;

ifstream f("date.in");

int n, divMin, divMax;
int p[MAXN];
int divisors[MAXN];

void read() {
    in >> n;
    in >> divMin;
    divMax = divMin;

    p[divMin]++;
    divisors[1] = divMin;


    int x;
    for (int i = 2; i <= n; i++) {
        in >> x;
        divMin = min(divMin, x);
        divMax = max(divMax, x);
        p[x]++;

        divisors[i] = x;

    }
}

int64 nr_divizori() {

}

int64 power(int64 x, int p) {
    if (p == 0)
        return 1;
    int64 aux = power(x, p / 2);
    aux = (aux * aux) % MOD;
    if (p % 2 == 0)
        return aux;
    return (aux * x) % MOD;
}

void solve() {

    int64 noDivisors = 1;

    for (int i = divMin; i <= divMax; i++) {
        noDivisors = noDivisors * (p[i] + 1);
    }


    int64 result = 1;

    if (noDivisors % 2 == 1) {

        for (int i = 1; i <= n; i++) {
            p[divisors[i]]--;

            if (p[divisors[i]] % 2) {
                result = (result * power(divisors[i], noDivisors)) % MOD;
            }
        }

        out << result;
        return;
    }

    noDivisors /= 2;
    for (int i = 1; i <= n; i++) {
        result = result * power(divisors[i], noDivisors) % MOD;
    }

   out << result;
}

int main() {
    read();
    solve();
    return 0;
}
