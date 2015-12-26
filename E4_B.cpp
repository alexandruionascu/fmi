#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdlib.h>
#define MAXN 200001
#define FIN "date.in"
#define in cin
#define out cout

using namespace std;

ifstream f(FIN);
int v[MAXN];
int c[MAXN];
int n;

int read()
{
    in >> n;
    int x;
    for(int i = 1; i <= n; i++)
    {
        in >> x;
        v[x] = i;

    }

    return 0;
}

int solve()
{
    long long time = 0;

    for(int i = 2; i <= n; i++)
    {
        time += abs(v[i] - v[i-1]);
    }

    out << time;
    return 0;
}

int main()
{
    read();
    solve();

    return 0;
}
