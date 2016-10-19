#include<fstream>
#include<algorithm>
#define MAXN 100001
using namespace std;
 
 
ifstream f("cocochanel.in");
ofstream g("cocochanel.out");
 
int n,m;
int cocks[MAXN];
int chicks[MAXN];
 
int main()
{
    f >> n;
    f >> m;
 
    for(int i=1; i<=n; i++)
    {
        f >> cocks[i];
    }
 
    for(int i=1; i<=m; i++)
    {
        f >> chicks[i];
    }
 
    sort(chicks + 1, chicks + m + 1);
 
    for(int i=1; i<=n; i++)
    {
        int counter = 0;
        int *it = lower_bound(chicks + 1, chicks + m + 1, cocks[i]);
 
        while(it != (chicks + m + 1))
        {
            counter++;
            cocks[i] *= 2;
            it = lower_bound(it+1, chicks + m + 1, cocks[i]);
        }
 
        g << counter << '\n';
    }
 
    return 0;
}
