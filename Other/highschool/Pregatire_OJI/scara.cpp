#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 122
#define INF 1000000
#define FIN "scara.in"
#define FOUT "scara.out"

ifstream f(FIN);
ofstream g(FOUT);

vector<int> G[MAXN];
int cost[MAXN];
bool rez[MAXN];
int d[MAXN];


int n,k,j; //numarul de trepte,
           //numarul de sticle de ape,
           // numarul de sticle de energizant

int citire()
{
    int x,y;
    f>>n;
    int i;
    G[0].push_back(1);
    for(int q=0;q<=n+1;q++)
            cost[q] = INF;

    cost[1] = 0;
    for(i=1;i<=n;i++)
    {
        G[i].push_back(i+1);
    }
    f>>k;
    //citesc apa si adaug muchiile corespunzatoare
    for(i=1;i<=k;i++)
    {
        f>>x;
        f>>y;
        for(int t=y;t>0;t--)
        {
            if(x+t <= n+1)
            {
                G[x].push_back(x+t);
            }

        }
    }
    //citesc energizantele si adaug muchiile corespunzatoare
    f>>j;
    for(int i=1;i<=j;i++)
    {
        f>>x;
        f>>y;
        for(int t=2*y;t>0;t--)
        {
            if(x+t <= n+1)
            {
              G[x].push_back(x+t);
            }

        }

    }

    return 0;
}

int solve(int nod)
{
    rez[nod] = 1;
    for(int i=nod; i<=n+1;i++)
    {
        //pentru fiecare nod
        for(vector<int>::iterator it=G[i].begin();it!=G[i].end();it++)
        {
            if(rez[*it]!=1)
            {
                if(cost[*it]>cost[i] + 1)
                    cost[*it]=cost[i] + 1;
            }
        }

        rez[i] = 1;

    }

}

int afisare()
{
    for(int i=1;i<=n+1;i++)
    {
        cout<<i<<": ";
        for(vector<int>::iterator it = G[i].begin();it!=G[i].end();++it)
        {
            cout<<*it<<" ";
        }

        cout<<endl;
    }

    return 0;
}

int main()
{
    citire();
    solve(1);
    cout<<cost[n+1]+1;


    return 0;
}
