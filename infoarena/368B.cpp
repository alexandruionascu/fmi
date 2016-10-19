#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");
const int MAXN = 100005;
const int INF = 1 << 30;

vector< pair<int, int> > graph[MAXN];
int n, m, k;
unordered_set<int> storages;

void read() {
  in >> n;
  in >> m;
  in >> k;

  int x, y, z;
  for(int i = 1; i <= m; i++) {
    in >> x; in >> y; in >> z;
    graph[x].push_back({y, z});
    graph[y].push_back({x, z});
  }

  for(int i = 1; i <= k; i++) {
    in >> x;
    storages.insert(x);
  }
}

void solve() {
  int minn = INF;
  //for each vertex
  for(int i = 1; i <= n; i++) {
    //if the vertex does not have a storage
    if(storages.find(i) == storages.end()) {
      for(auto adj : graph[i]) {
        //if the vertex is a storage
        if(storages.find(adj.first) != storages.end())
          minn = min(minn, adj.second);
      }
    }
  }

  if(minn == INF)
    out << -1;
  else
    out << minn;
}

int main() {
  read();
  solve();
  return 0;
}
