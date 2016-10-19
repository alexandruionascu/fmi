#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("wow.in");

#define LE 200666
int lev[LE],father[LE];
int logp[19][LE];
vector<int> H[LE];
bool viz[LE];
int n,i;

int lca(int nod1,int nod2) {

    if  (lev[nod1]<lev[nod2]) swap(nod1,nod2);
    int i,diff=lev[nod1]-lev[nod2];

    for(i=0; (1<<i)<=diff; ++i)
        if ((1<<i)&diff)
            nod1=father[logp[i][nod1]];
    int levmin=lev[nod1]-1,step,l=0;
    if (nod1==nod2) return nod1;

   for(step=1; step<=levmin; step<<=1,++l);

    for(int pos=0; step; step>>=1,--l)
        if (pos+step<=levmin&&father[logp[l][nod1]]!=father[logp[l][nod2]]) {
            nod1=father[logp[l][nod1]];
            nod2=father[logp[l][nod2]];
            pos+=step;
        }

    return father[nod1];
}

void dfs(int nod,int level) {
    lev[nod]=level;
    viz[nod]=true;
    int N=H[nod].size();

    for(int i=0; i<N; ++i)
        if (viz[H[nod][i]]==false) {
          father[H[nod][i]] = nod;
          logp[1][H[nod][i]] = nod;
          dfs(H[nod][i],level+1);
        }

}

vector<int> getDivisors(int x) {
    vector<int> retValue;
    int i = 1;
    for(i = 1; i * i < x; i++) {
      if(x % i == 0) {
        retValue.push_back(i);
        retValue.push_back(x / i);
      }
    }

    if(i * i == x)
      retValue.push_back(i);

    return retValue;
}

long long getCost(int node1, int node2) {
  int lcaNod = lca(node1, node2);
  return lev[node1] + lev[node2] - 2 * lev[lcaNod];
}

void solve() {
  long long sum = 0;
  for(int i = 2; i <= n; i++) {
    auto divs = getDivisors(i);
    for(auto divisor : divs) {
//     out << endl << " added " << i << " " << divisor << " " << getCost(i, divisor) << endl;
      if(divisor != i)
        sum += getCost(i, divisor) + 1;

    }
  }

  out << sum;
}


#define pb push_back
int m;

int main() {
    in >> n;
    int m = n - 1;


    int x, y;
    for(i=2; i<=n; ++i) {
        in >> x; in >> y;
        H[x].pb(y);
        H[y].pb(x);
    }


    logp[1][1]=1;

    for(i=1; i<=n; ++i) logp[0][i]=i;
    dfs(1,1);

     for(i=2; (1<<i)<=n; ++i)
        for(int j=1; j<=n; ++j)
            logp[i][j]=logp[i-1][logp[1][logp[i-1][j]]];

    solve();

    return 0;
}
