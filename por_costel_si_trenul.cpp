#include<iostream>
#include<fstream>
#define MAXN 100001
#define FIN "trenul.in"
#define FOUT "trenul.out"
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int v[MAXN];
int n, m;

int q[4];

int read()
{
    f >> n;
    f >> m;
    for(int i = 1; i <= m; i++)
    {
        f >> v[i];
        q[v[i]]++;
    }

    return 0;
}

int solve()
{
    int index2 = 1;
    int index3 = n - 3 * q[3] + 1;
    int index1 = 2 * q[2] + 1;

    for(int i = 1; i <=m; i++)
    {
        switch(v[i])
        {
            case 1:
                g << index1 <<"\n";
                index1++;
                break;

            case 2:
                g << index2 <<" "<<index2 + 1 << "\n";
                index2 += 2;
                break;
            case 3:
                g << index3 << " "<<index3 + 1 << " "<<index3 + 2 <<"\n";
                index3 += 3;
                break;
        }
    }
    return 0;
}

int main()
{
    read();
    solve();

    return 0;
}
