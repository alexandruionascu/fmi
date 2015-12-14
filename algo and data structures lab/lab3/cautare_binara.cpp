#include<iostream>
#include<fstream>
#define MAXN 100001
using namespace std;
 
ifstream f("cautbin.in");
ofstream g("cautbin.out");
int n, m;
int v[MAXN];
int max_step;
 
int caut0(int value)
{
    int i = 1;
    int step = max_step;
    for(i=1; step != 0; step >>= 1)
    {
        if((i + step) <= n && v[i + step] <= value)
            i += step;
    }
 
    if(v[i] != value)
        g << -1 << '\n';
    else
        g << i << '\n';
    return 0;
}
 
int caut1(int value)
{
    int i = 1;
    int step = max_step;
    for(i=1; step != 0; step >>= 1)
    {
        if((i + step) <= n && v[i + step] <= value)
            i += step;
    }
 
    g << i << '\n';
    return 0;
}
 
int caut2(int value)
{
    int i = n;
    int step = max_step;
    for(i=n; step != 0; step >>= 1)
    {
        if((i - step) > 0 && v[i - step] >= value)
            i -= step;
    }
 
    g << i << '\n';
    return 0;
 
}
 
int main()
{
    f >> n;
 
    for(max_step = 1; max_step < n; max_step <<= 1);
 
    for(int i=1; i<=n; i++)
        f >> v[i];
    f >> m;
    int x, y;
    for(int i=1; i<=m; i++)
    {
        f >> x;
        f >> y;
 
        switch(x)
        {
            case 0:
                caut0(y);
                break;
            case 1:
                caut1(y);
                break;
            case 2:
                caut2(y);
                break;
        }
    }
 
    return 0;
 
}