#include<stdio.h>
#include<vector>
#include<set>
using namespace std;

#define FIN "apm.in"
#define FOUT "apm.out"
#define MAXSIZE 200002

set< pair< int,pair<int,int> > > s;
int father[MAXSIZE];
vector<pair<int,int> > tree;
int ranc[MAXSIZE];

int n,m,nr;
int minValue;

int find(int x)
{
    if(father[x] == x)
        return x;
    else return find(father[x]);
}

void uniune(int a, int b)
{
    int aRoot = find(a);
    int bRoot = find(b);
    if(aRoot == bRoot)
        return;
    if(ranc[aRoot]<ranc[bRoot])
    {
        father[aRoot] = bRoot;
    }
    else if(ranc[aRoot]>ranc[bRoot])
        father[bRoot] = aRoot;
    else
        father[bRoot] = aRoot;
        ranc[aRoot]++;

}
int read()
{
    scanf("%d %d",&n,&m);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        s.insert(make_pair(z, make_pair(x,y)));
    }

}


int main()
{
    freopen(FIN,"r",stdin);
    freopen(FOUT,"w",stdout);
    read();

    //init
    for(int i=1;i<=n;i++)
    {
        father[i] = i;
    }
    //end of init
    int cost,x,y;
    while(nr<n-1)
    {
        cost = (*s.begin()).first;
        x = (*s.begin()).second.first;
        y = (*s.begin()).second.second;
        if(find(x) != find(y))
        {
            uniune(x,y);
            minValue += cost;
            nr++;
            tree.push_back(make_pair(x,y));
        }

        s.erase(s.begin());

    }

    //Write
    printf("%d\n%d\n",minValue,nr);
    for(int i=0;i<nr;i++)
    {
        x = tree[i].first;
        y = tree[i].second;

        printf("%d %d\n",x,y);
    }

    return 0;
}
