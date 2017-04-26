#include <bits/stdc++.h>
#define in f
#define out cout
using namespace std;

ifstream f("data.in");

const int MAX_SIZE = 3 * 100 * 100 + 10;
const int MINUS_INF = -1 * (1 << 30);
const int INF = 1 << 30;
vector<int> G[MAX_SIZE];
int n;
int strength[MAX_SIZE];
int neighbours_count[MAX_SIZE];
int neighbours[MAX_SIZE];
bool is_hacked[MAX_SIZE];

int min_strength = MINUS_INF;

int count_neighbours(int vertex) {
  set<int> neighbours;
  for (auto neighbour : G[vertex]) {
    if (is_hacked[neighbour] == false)
      neighbours.insert(neighbour);
    for (auto semineighbour : G[neighbour]) {
      if (is_hacked[semineighbour] == false)
        neighbours.insert(semineighbour);
    }
  }

  return neighbours.size();
}

void hack(int vertex) {
  is_hacked[vertex] = true;
  set<int> neighbours;
  for (auto neighbour : G[vertex]) {
    if (is_hacked[neighbour] == false)
      neighbours.insert(neighbour);
    for (auto semineighbour : G[neighbour]) {
      if (is_hacked[semineighbour] == false)
        neighbours.insert(semineighbour);
    }
  }

  for (auto semineighbour : neighbours) {
    strength[semineighbour]++;
  }

  min_strength = max(min_strength, strength[vertex]);
}

void dfs(int vertex) {
  out << "HACK " << vertex << endl;
  hack(vertex);
  int min_count = INF;
  int to_visit;
  for (auto neighbour : G[vertex]) {
    if (is_hacked[neighbour] == false) {
      min_count = min(neighbours_count[neighbour], min_count);
      to_visit = neighbour;
    }
  }

  if (min_count != INF)
    dfs(to_visit);
}

int main() {
  in >> n;

  for (int i = 1; i <= n; i++) {
    in >> strength[i];
  }

  int x, y;
  for (int i = 1; i < n; i++) {
    in >> x;
    in >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  for (int i = 1; i <= n; i++) {
    neighbours_count[i] = count_neighbours(i);
    cout << i << " -> " << neighbours_count[i] << endl;
  }

  int minn_vertex = 1;
  for (int i = 2; i <= n; i++) {
    if (neighbours_count[i] < neighbours_count[minn_vertex]) {
      minn_vertex = i;
    } else if (neighbours_count[i] == neighbours_count[minn_vertex]) {
      if (strength[i] > strength[minn_vertex]) {
        minn_vertex = i;
      }
    }
  }
  cout << minn_vertex << endl;
  dfs(minn_vertex);
  out << min_strength;
  return 0;
}
