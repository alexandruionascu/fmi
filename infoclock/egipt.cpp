#include<iostream>
#include<fstream>
#include<vector>
#define FIN "egipt.in"
#define FOUT "egipt.out"
#define MAXN 10001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int n, v[MAXN];
int m[4];
vector< pair<int, int> > sol;

int swap(int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;

    sol.push_back(make_pair(i, j));

    return 0;
}

int solve()
{
    for(int i=1; i<=m[1]; i++)
    {
        if(v[i] == 2)
        {
            int index2 = m[1] + 1;

            while(v[index2] != 1)
            {
                if(index2 > n)
                {
                    break;
                }
                index2++;
            }

            swap(i, index2);
        }
        else if(v[i] == 3)
        {
            int index3 = m[1] + m[2] + 1;

            while(v[index3] != 1)
            {
                if(index3 > n)
                {
                    index3 = m[1] + 1;
                }

                index3++;
            }

            swap(i, index3);
        }
    }

    for(int i=m[1] + 1; i <= m[1] + m[2]; i++)
    {
        if(v[i] != 2)
        {
            int index3 = m[1] + m[2] + 1;
            while(v[index3]  != 2)
            {
                index3++;
            }

            swap(i, index3);
        }
    }


    return 0;
}

int write()
{
    g << sol.size() << "\n";
    for(vector< pair<int, int> >::iterator it = sol.begin(); it != sol.end(); it++)
    {
        g << it->first << " " << it->second << "\n";
    }
    return 0;
}

int main()
{
    f >> n;
    for(int i=1; i<=n; i++)
    {
        f >> v[i];
        m[v[i]]++;
    }

    solve();
    write();
    return 0;
}
