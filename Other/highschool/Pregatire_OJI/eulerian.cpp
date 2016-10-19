#include<stdio.h>
#include<vector>
using namespace std;

#define MAXSIZE 100002
#define FIN "ciclueuler.in"
#define FOUT "ciclueuler.out"

int n,m;
vector<int> g[MAXSIZE];
vector<int> chain;

int read()
{
    scanf("%d %d",&n,&m);
    int x,y;

    for(int i=1;i<=m;i++)
    {
        scanf("%d %d", &x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

int euler(int nod)
{
    while(g[nod].size()>0) //atata timp cat nodul are vecini
    {
        int w = g[nod].front();
        //---------------------sterg muchia nod w-----------
        g[nod].erase(g[nod].begin());
        for(vector<int>::iterator it = g[w].begin();it!=g[w].end();it++)
        {
            if(*it == nod)
            {
                g[w].erase(it);
                break;
            }
        }
        //------------------------------------------------------
        euler(w);
    }
    chain.push_back(nod);

}

int write()
{
    for(int i=0;i<m;i++)
    {
        printf("%d ",chain[i]);
    }
}

int main()
{
    freopen(FIN,"r",stdin);
    freopen(FOUT,"w",stdout);
    read();
    euler(1);
    write();

    return 0;
}
