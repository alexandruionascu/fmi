#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#define FIN "zeul.in"
#define FOUT "zeul.out"
#define MAXN 100001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int n, m;
int degree[MAXN];
pair<int, int> G[MAXN];
vector< pair<int, int> > sol;

int read()
{
    f >> n;
    f >> m;

    int a, b;
    for(int i = 1; i <= m; i++)
    {
        f >> a;
        f >> b;

        degree[a]--;
        degree[b]++;

    }


    for(int i = 1; i <= n; i++)
        G[i] = make_pair(degree[i], i);

    return 0;
}

int solve()
{
    sort(G + 1, G + n + 1);
    int front = 1;
    int back = n;    ;
    while(G[front].first != 0)
    {

        int k = min(-G[front].first, G[back].first);
        for(int i = 1; i <= k; i++)
            sol.push_back(make_pair(G[front].second, G[back].second));


        G[front].first += k;
        G[back].first -= k;

        if(G[front].first == 0)
            front++;
        if(G[back].first == 0)
            back--;

    }
    g << sol.size() << "\n";
    for(int i = 0; i < sol.size(); i ++)
        g << sol[i].second << " " << sol[i].first << "\n";

    return 0;
}

int main()
{
    read();
    solve();
    return 0;
}

