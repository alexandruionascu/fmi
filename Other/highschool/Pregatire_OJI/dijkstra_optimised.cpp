#include<stdio.h>
#include<set>
#include<vector>
using namespace std;

#define  INF 100000
#define MAXN 50002
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"

int n,m;
vector<int> g[MAXN];
vector<int> cost[MAXN];
set< pair<int,int> > s;
int d[MAXN];

int read()
{
    freopen(FIN,"r",stdin);
    freopen(FOUT,"w",stdout);
    scanf("%d %d",&n,&m);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d", &x,&y,&z);
        g[x].push_back(y);
        cost[x].push_back(z);
    }

    return 0;
}

int solve()
{
    int x,y;
    vector<int>::iterator it;
    //init
    for(int i=2;i<=n;i++)
    {
        d[i] = INF;
    }
    //--end of init
    s.insert(make_pair(0,1));

    while(s.size() > 0)
    {
        x = (*s.begin()).first;
        y = (*s.begin()).second;
        s.erase(*s.begin());
        for(int i=0;i<g[y].size();i++)
        {
            if(d[ g[y][i] ] > x + cost[y][i])
            {
                d[ g[y][i] ] = x + cost[y][i];
                s.insert( make_pair(  d[g[y][i]] , g[y][i] ) );
            }
        }
    }
}

int write()
{
    for(int i=2;i<=n;i++)
    {
        if(d[i]!=INF)
            printf("%d ",d[i]);
        else printf("%d ",0);
    }
    return 0;
}

int main()
{
    read();
    solve();
    write();
}
