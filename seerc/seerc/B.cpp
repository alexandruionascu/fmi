#include <bits/stdc++.h>
using namespace std;
#define LE 100666
#define f cin

ifstream f("wow.in");

bool viz[LE],on_path[LE];
vector<int> H[LE];
int okz;

void dfs(int nod)
{
    viz[nod]=true;
    on_path[nod]=true;

    for(auto it: H[nod])
        if (!viz[it]){
            dfs(it);
        }
        else{
            if (on_path[it]){
               okz=2;
            }
        }
    on_path[nod]=false;
}

int main()
{
    int n,m;
    f>>n>>m;

    for(int i=1; i<=m; ++i)
    {
        int xx,yy;
        f>>xx>>yy;
        H[xx].push_back(yy);
    }

    for(int i=1;i<=n;++i)
        if (viz[i]==false){
           dfs(i);
        }

    if (okz==2){
        cout<<0;
        return 0;
    }

    if (m){
        cout<<1;
        return 0;
    }

    cout<<2<<'\n';


    return 0;
}
