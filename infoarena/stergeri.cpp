#include<fstream>
#define MAXN 100001
using namespace std;

ifstream f("stergeri.in");
ofstream g("stergeri.out");

long long n, m, k;
long long o[MAXN][2];

int main()
{
    f >> n;
    f >> m;
    f >> k;

    for(int i=1; i<=m; i++)
    {
        f >> o[i][0];
        f >> o[i][1];
    }

    for(int i=m; i>=1; i--)
    {
        if(o[i][0] <= k)
            k += o[i][1] - o[i][0] + 1;
    }

    g << k;
    return 0;
}
