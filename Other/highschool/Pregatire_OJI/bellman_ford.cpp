#include<stdio.h>
#include<set>
using namespace std;

#define FIN "bellmanford.in"
#define FOUT "bellmanford.out"
#define MAXSIZE 50002
#define INF 200000

set< pair<int, pair<int,int> > > s;
int n,m;
int d[MAXSIZE];

int read()
{
    scanf("%d %d",&n,&m);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        s.insert(make_pair(z,make_pair(x,y)));
    }

    return 0;

}

int init()
{
    for(int i=2;i<=n;i++)
        d[i] = INF;
    return 0;
}

int solve()
{
    set<pair<int,pair<int,int> > >::iterator it;
    int cost,x,y;
    for(int i=1;i<n;i++)
    {
         for( it = s.begin();it!=s.end();it++)
        {
            cost = (*it).first;
            x = (*it).second.first;
            y = (*it).second.second;

            if(d[x] + cost < d[y])
                d[y] = d[x] + cost;

        }
    }


    return 0;
}

int write()
{
    int cost,x,y;

    for(set<pair<int,pair<int,int> > >::iterator it = s.begin();it!=s.end();it++)
    {
        cost = (*it).first;
        x = (*it).second.first;
        y = (*it).second.second;

        if(d[x] + cost < d[y])
        {
            printf("Ciclu negativ!");
            return 0;
        }
    }

    for(int i=2;i<=n;i++)
    {
        printf("%d ",d[i]);
    }
    return 0;
}

int main()
{
    freopen(FIN,"r",stdin);
    freopen(FOUT,"w",stdout);

    read();
    init();
    solve();
    write();



    return 0;
}
