#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");
const int MAXN = 5010;
const int INF = 1 << 30;
bool visited[MAXN];
int depth[MAXN], cost[MAXN], father[MAXN];
int n, m, t;
vector< pair<int, int> > graph[MAXN];

void read() {
  in >> n;
  in >> m;
  in >> t;

  int x, y, z;
  for(int i = 1; i <= m; i++) {
    in >> x;
    in >> y;
    in >> z;

    graph[x].push_back({y, z});
  }
}

void solve() {
  for(int i = 2; i < MAXN; i++)
    cost[i] = INF;

  queue<int> q;
  q.push(1);
  cost[1] = 0;

  while(q.empty() == false) {
    int node = q.front();
    q.pop();
    visited[node] = true;

    for(auto adj : graph[node]) {
      if(cost[node] + adj.second < cost[adj.first]) {
        cost[adj.first] = cost[node] + adj.second;
      }


      if(depth[node] + 1 > depth[adj.first] && cost[node] + adj.second <= t) {
        //out << "increase depth " << node << " -> " << adj.first << endl;
        depth[adj.first] = depth[node] + 1;
        father[adj.first] = node;
      }

      if(visited[adj.first] == false && cost[adj.first] <= t) {
        q.push(adj.first);
        visited[adj.first] = true;
        father[adj.first] = node;
      }
    }
  }

  vector<int> solution;

  int currentNode = n;

  while(currentNode != 0) {
    solution.push_back(currentNode);
    currentNode = father[currentNode];
  }

  out << solution.size() << "\n";
  for(int i = solution.size() - 1; i >= 0; i--) {
    out << solution[i] << " ";
  }


}

int main() {
  read();
  solve();
  return 0;
}
