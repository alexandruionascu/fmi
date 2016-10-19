#include<bits/stdc++.h>
#define IN f
#define OUT g
using namespace std;

ifstream f("darb.in");
ofstream g("darb.out");

const int MAX_SIZE = 100001;
vector<int> G[MAX_SIZE];
int n;

void read() {
  IN >> n;
  int x, y;
  for(int i = 0; i < n - 1; i++) {
      IN >> x;
      IN >> y;
      G[x].push_back(y);
      G[y].push_back(x);
  }
}

pair<int, int> getFurthest(int startVertex) {
  queue<int> q;
  bool visited[MAX_SIZE];
  int depth[MAX_SIZE];

  for(int i = 1; i <= n; i++) {
    depth[i] = 0;
  }
  for(int i = 0; i < MAX_SIZE; i++) {
    visited[i] = false;
  }

  q.push(startVertex);
  visited[startVertex] = true;

  while(q.empty() == false) {
    int vertex = q.front();
    q.pop();
    visited[vertex] = true;

    for(auto v : G[vertex]) {
        if(visited[v] == false) {
          q.push(v);
          depth[v] = depth[vertex] + 1;
          visited[v] = true;
        }
    }
  }

  int furthestVertex = startVertex;
  int maxDistance = 0;
  for(int i = 1; i <= n; i++) {
    if(depth[i] > maxDistance) {
      maxDistance = depth[i];
      furthestVertex = i;
    }
  }

  return {furthestVertex, maxDistance};
}

void solve() {
  auto maxNode = getFurthest(1);
  auto furthest = getFurthest(maxNode.first);
  OUT << furthest.second + 1;
}

int main() {
  read();
  solve();
  return 0;
}
