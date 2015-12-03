#include<iostream>
#include<fstream>
#define FIN "buget.in"
#define FOUT "buget.out"
#define MAXN 100001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);
int v[MAXN];
int n;
long long b;

int read()
{
    f >> n;
    f >> b;

    for(int i = 1; i <= n; i++)
        f >> v[i];

    return 0;
}

bool check(long long money)
{
    long long sum = 0;

    for(int i = 0; i <= n; i++)
    {
        if(v[i] <= money)
            sum += v[i];
        else sum += money;

        if(sum > b)
            return false;
    }

    return true;
}

int solve()
{
    long long left = 1;
    long long right = b;

    while(right - left > 1)
    {
        long long mid = (left + right) / 2;

        if(check(mid) == true)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    if(check(right))
        g << right;
    else g << left;

    return 0;
}

int main()
{
    read();
    solve();

    return 0;
}
