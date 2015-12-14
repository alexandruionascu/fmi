#include<iostream>
#include<fstream>
#include<queue>
#define MAXN 1002
#define FIN "tsunami.in"
#define FOUT "tsunami.out"
#define in f
#define out g
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int n, m, h, counter;
int a[MAXN][MAXN];
queue< pair<int,int> > q;
bool visited[MAXN][MAXN];


int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, -1, 0, 1};

bool check(int i, int j)
{
    if(i < 1 || j < 1 || i > n || j > m)
        return false;

    if(visited[i][j] == true)
    {
        return false;
    }
    else
    {
        if(a[i][j] > 0)
        {
            if(a[i][j] < h)
                return true;
            else return false;
        }

        return true;
    }
}
int read()
{
    in >> n;
    in >> m;
    in >> h;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f >> a[i][j];

            if(a[i][j] == 0)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    return 0;
}

int solve()
{
    while(q.empty() == false)
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        visited[x][y] = true;

        if(a[x][y] != 0)
        {
            counter++;
        }


        for(int i = 0; i < 4; i++)
        {
            if(check(x + dirX[i], y + dirY[i]) == true)
            {
                q.push(make_pair(x + dirX[i], y + dirY[i]));
                visited[x + dirX[i]][y + dirY[i]] = true;
            }
        }
    }

    out << counter;
    return 0;
}

int main()
{
    read();
    solve();
    return 0;
}
