#include<iostream>
#include<fstream>
#include<math.h>
#define MAXN 100001
#define MOD 1000000007
#define FIN "pasha.in"
using namespace std;

ifstream f(FIN);

long long a[MAXN];
long long b[MAXN];
int n, k;
long long res = 1;

int d(long long a, long long b)
{
    return a / b + ( a % b != 0);
}

int main()
{
    cin >> n;
    cin >> k;

    for(int i=1; i <= n/k; i++)
    {
        cin >> a[i];
    }

    for(int i=1; i <= n/k; i++)
    {
        cin >> b[i];
    }


    long long p = 1;
    for(int i=1; i <= k; i++)
        p *= 10;

    for(int i=1; i <= n/k; i++)
    {
        long long number = d(p, a[i])  - d((b[i] + 1) * p / 10, a[i]) + d(b[i] * p / 10, a[i]);
        res = (res * number) % MOD;
    }

    cout << res;
    return 0;
}
