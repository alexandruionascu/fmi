#include <bits/stdc++.h>
#define in f
#define out g
using namespace std;

ifstream f("dragoni.in");
ofstream g("dragoni.out");

int operation, n, m;
const int MAX_SIZE = 1000;
const int INF = 2e9 + 10;
int max_dist[MAX_SIZE];
int max_travel[MAX_SIZE];
bool visited[MAX_SIZE];
int dist[MAX_SIZE];
vector<pair<int, int>> G[MAX_SIZE];

void read() {
  in >> n;
  in >> m;

  for (int i = 1; i <= n; i++)
    in >> max_dist[i];
  int x, y, z;

  for (int i = 1; i <= m; i++) {
    in >> x;
    in >> y;
    in >> z;
    G[x].push_back({y, z});
    G[y].push_back({x, z});
  }
}

void solve1() {
  queue<int> Q;
  Q.push(1);
  visited[1] = true;

  while (!Q.empty()) {
    int current = Q.front();
    Q.pop();

    for (auto adj : G[current]) {
      if (!visited[adj.first] && adj.second <= max_dist[1]) {
        Q.push(adj.first);
        visited[adj.first] = true;
      }
    }
  }

  int maxx = 0;
  for (int i = 1; i <= n; i++)
    if (visited[i])
      maxx = max(maxx, max_dist[i]);
  out << maxx;
}

void dijkstra(int vertex, int dragon_capacity) {
  auto cmp = [](pair<int, int> a, pair<int, int> b) -> bool {
    return a.second > b.second;
  };

  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> Q(cmp);
  for (int i = 1; i <= n; i++)
    dist[i] = INF, visited[i] = false;
  dist[vertex] = 0;
  visited[vertex] = true;
  Q.push({vertex, 0});
  while (!Q.empty()) {
    pair<int, int> current = Q.top();
    Q.pop();
    for (auto adj : G[current.first]) {
      if (!visited[adj.first] && adj.second <= dragon_capacity &&
          dist[current.first] + adj.second < dist[adj.first]) {
        dist[adj.first] = dist[current.first] + adj.second;
        Q.push({adj.first, dist[adj.first]});
        visited[current.first] = true;
      }
    }
  }
}

void solve2() {
  int first_dist[MAX_SIZE];
  dijkstra(1, max_dist[1]);
  for (int i = 1; i <= n; i++)
    first_dist[i] = dist[i];
  int minn = INF;
  for (int i = 1; i <= n; i++) {
    dijkstra(i, max_dist[i]);
    if (first_dist[i] != INF && dist[n] != INF)
      minn = min(minn, first_dist[i] + dist[n]);
  }

  out << minn;
}
int main() {
  in >> operation;
  read();
  if (operation == 1) {
    solve1();
  } else {
    solve2();
  }

  return 0;
}
