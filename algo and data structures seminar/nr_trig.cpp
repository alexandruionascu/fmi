#include<iostream>
#include<fstream>
#include<algorithm>
#define FIN "nrtri.in"
#define FOUT "nrtri.out"
#define MAXN 801
using namespace std;


ifstream f(FIN);
ofstream g(FOUT);

int v[MAXN];
int n;
int counter;


int read()
{
    f >> n;

    for(int i=1; i<=n; i++)
        f >> v[i];

    return 0;
}

int solve()
{
    sort(v + 1, v + n + 1);

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<= n; j++)
        {
            for(int k=j+1; k <= n; k++)
            {
                if(v[i] + v[j] >= v[k])
                    counter++;
                else break;
            }
        }
    }

    return 0;

}

int write()
{
    g << counter;
    return 0;
}



int main()
{
    read();
    solve();
    write();

    return 0;
}
