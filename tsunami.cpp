#include<fstream>
#include<iostream>
#include<queue>
#define FIN "tsunami.in"
#define FOUT "tsunami.out"
#define MAXN 1004
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int n, m, h;
int A[MAXN][MAXN];
queue< pair<int, int> > t;
bool viz[MAXN][MAXN];
int victims;

bool valid(int i, int j)
{
    if(A[i+1][j] > 0 || A[i-1][j] > 0 || A[i][j+1] > 0 || A[i][j-1] > 0)
        return true;
    else return false;
}

int read()
{
    f >> n;
    f >> m;
    f >> h;


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            f >> A[i][j];
        }
    }


    return 0;
}


int solve()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(A[i][j] == 0 && (i == 1 || j == 1 || i == n || j == m))
            {
                t.push(make_pair(i, j));
            }

        }
    }

    for(int i=0; i<=n+1; i++)
        A[i][0] = MAXN, A[i][m+1] = MAXN;

    for(int i=0; i<=m+1; i++)
        A[0][i] = MAXN, A[n+1][i] = MAXN;

    while(!t.empty())
    {
        int i = t.front().first;
        int j = t.front().second;

        t.pop();

        if(viz[i][j] == false)
        {
            if(A[i][j] > 0)
            {
                victims++;
            }


            if(A[i+1][j] < h)
            {
                t.push(make_pair(i+1, j));
            }
            else if(A[i-1][j] < h)
            {
                t.push(make_pair(i-1, j));
            }
            else if(A[i][j+1] < h)
            {
                t.push(make_pair(i, j+1));
            }
            else if(A[i][j-1] < h)
            {
                t.push(make_pair(i, j-1));
            }

        }

        viz[i][j] = true;



    }
    return 0;
}

int write()
{
    g << victims;
    return 0;
}

int main()
{
    read();
    solve();
    write();

    return 0;
}
