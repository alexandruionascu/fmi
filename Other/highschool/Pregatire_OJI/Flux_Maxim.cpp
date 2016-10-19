#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define MAXSIZE 1002
#define FIN "maxflow.in"
#define FOUT "maxflow.out"

int n,m;
vector<int> graph[MAXSIZE]; //graful
int c[MAXSIZE][MAXSIZE]; //cantitatea
int maxFlow;
int father[MAXSIZE];

int read()
{
    freopen(FIN,"r",stdin);
    freopen(FOUT,"w",stdout);

    scanf("%d %d", &n,&m);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d", &x,&y,&z);
        graph[x].push_back(y);
        c[x][y] = z;
    }

    return 0;
}

int BFS()
{
    queue<int> q;
    memset(father,0,sizeof(father));
    vector<int>::iterator it;
    father[1] = -1;
    q.push(1);
    while(!q.empty())
    {
        int nod = q.front();
        if(nod == n)
        {
            return 1;
        }
        q.pop();
        for(it = graph[nod].begin();it!=graph[nod].end();it++)
        {
            if(father[*it] == 0 && c[nod][*it]>0)
            {
                q.push(*it);
                father[*it] = nod;
            }
        }
    }
    return 0;
}

int solve()
{
    while(BFS() == 1)
    {
        //get min value
        int minn = c[father[n]][n];
        for(int i=n;i!=1;i=father[i])
        {
            if(minn > c[father[i]][i])
                minn = c[father[i]][i];
        }

        for(int i=n;i!=1;i=father[i])
        {
            c[father[i]][i] -=minn;
        }
        maxFlow +=minn;
    }

    return 0;
}

int write()
{
    printf("%d",maxFlow);
    return 0;
}

int main()
{
    read();
    solve();
    write();

    return 0;
}
