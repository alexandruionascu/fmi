#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

#define FIN "muzeu.in"
#define FOUT "muzeu.out"
#define MAXN 253

ifstream f(FIN);
ofstream g(FOUT);
queue< pair<int, int> > rooms;
int n;
int m[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main()
{
    f >> n;
    char c;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            f >> c;
            if(c == '.')
            {
                m[i][j] = -1;
            }
            else if(c == '#')
            {
                m[i][j] = -2;
            }
            else
            {
                m[i][j] = 0;
                rooms.push(make_pair(i,j));
            }
        }
    }

    //set -2 to margins
    for(int i=0; i<=n+1; i++)
        m[0][i] = -2, m[i][0] = -2, m[n+1][i] = -2, m[i][n+1] = -2;



        while(!rooms.empty())
        {
            int x = rooms.front().first;
            int y = rooms.front().second;

            rooms.pop();
            if(vis[x][y] == false)
            {
                if(m[x+1][y] != -2)
                {

                    if(m[x+1][y] == -1)
                    {
                        m[x+1][y] = m[x][y] + 1;
                    }
                    else
                    {
                        if(m[x][y] + 1 < m[x+1][y])
                            m[x+1][y] = m[x][y] + 1;

                    }

                    rooms.push(make_pair(x+1, y));
                }

                if(m[x-1][y] != -2)
                {
                    if(m[x-1][y] == -1)
                    {
                        m[x-1][y] = m[x][y] + 1;
                    }
                    else
                    {
                        if(m[x][y] + 1 < m[x-1][y])
                            m[x-1][y] = m[x][y] + 1;

                    }

                    rooms.push(make_pair(x-1, y));
                }

                if(m[x][y+1] != -2)
                {
                    if(m[x][y+1] == -1)
                    {
                        m[x][y+1] = m[x][y] + 1;
                    }
                    else
                    {
                        if(m[x][y] + 1 < m[x][y+1])
                            m[x][y+1] = m[x][y] + 1;

                    }

                    rooms.push(make_pair(x, y+1));

                }

                if(m[x][y-1] != -2)
                {

                    if(m[x][y-1] == -1)
                    {
                        m[x][y-1] = m[x][y] + 1;
                    }
                    else
                    {
                        if(m[x][y] + 1 < m[x][y-1])
                            m[x][y-1] = m[x][y] + 1;

                    }

                    rooms.push(make_pair(x, y-1));
                }
                vis[x][y] = true;

            }

        }


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            g << m[i][j] << " ";
        }

        g << '\n';
    }

}
