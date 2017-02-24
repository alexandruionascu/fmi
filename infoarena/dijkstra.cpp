#include <bits/stdc++.h>
using namespace std;

const int INF = 5e4 + 10;
const int MAX_SIZE = 2e5 + 10;
auto cmp = [](pair<int, int> a, pair<int, int> b) -> bool {
  return a.second > b.second;
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> Q(cmp);
vector<pair<int, int>> G[MAX_SIZE];
int n, m;
int dist[MAX_SIZE];
bool visited[MAX_SIZE];

void read() {
  scanf("%d %d", &n, &m);
  int x, y, z;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &x, &y, &z);
    G[x].push_back({y, z});
  }
}

void dijkstra(int vertex) {
  for (int i = 1; i <= n; i++)
    dist[i] = INF;
  dist[vertex] = 0;
  visited[vertex] = true;
  Q.push({vertex, 0});
  while (!Q.empty()) {
    pair<int, int> current = Q.top();
    Q.pop();
    for (auto adj : G[current.first]) {
      if (!visited[adj.first] &&
          dist[current.first] + adj.second < dist[adj.first]) {
        dist[adj.first] = dist[current.first] + adj.second;
        Q.push({adj.first, dist[adj.first]});
        visited[current.first] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (i != vertex) {
      if (dist[i] == INF)
        printf("0 ");
      else
        printf("%d ", dist[i]);
    }
  }
}

int main() {
  freopen("dijkstra.in", "r", stdin);
  freopen("dijkstra.out", "w", stdout);
  read();
  dijkstra(1);
  return 0;
}
