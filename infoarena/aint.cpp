#include<bits/stdc++.h>
#define in f
#define out g
using namespace std;

ifstream f("arbint.in");
ofstream g("arbint.out");

const int MAXN = 2e6 + 100;
int v[MAXN], n, t;
int tree[MAXN];

void read() {
  in >> n;
  in >> t;
  for(int i = 1; i <= n; i++)
    in >> v[i];
}

void buildTree(int node, int left, int right) {
  if(left == right) {
    tree[node] = v[left];
  } else {
    int mid = (left + right) / 2;
    buildTree(2 * node, left, mid);
    buildTree(2 * node + 1, mid + 1, right);
    tree[node] =  max(tree[2 * node], tree[2 * node + 1]);
  }
}

int query(int node, pair<int, int> treeRange, pair<int, int> range) {
  if(treeRange.first == range.first && range.second == treeRange.second) {
    return tree[node];
  } else {
    int mid = (treeRange.first + treeRange.second) / 2;
    if(range.second <= mid)
      return query(2 * node, {treeRange.first, mid}, range);
    if(range.first > mid)
      return query(2 * node + 1, {mid + 1, treeRange.second}, range);

    int left = query(2 * node, {treeRange.first, mid}, {range.first, mid});
    int right = query(2 * node + 1, {mid + 1, treeRange.second}, {mid + 1, range.second});

    return max(left, right);
  }
}

void update(int node, pair<int, int> range, int index, int value) {
    if(range.first == range.second) {
      tree[node] = value;
    } else {
      int mid = (range.first + range.second) / 2;
      if(index <= mid)
        update(2 * node, {range.first, mid}, index, value);
      if(index > mid)
        update(2 * node + 1, {mid + 1, range.second}, index, value);

      tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

void solve() {

  buildTree(1, 1, n);

  int x, y, z;
  for(int i = 1; i <= t; i++) {
    in >> x;
    in >> y;
    in >> z;

    if(x == 0) {
      out << query(1, {1, n}, {y, z}) << "\n";
    } else {
      update(1, {1, n}, y, z);
    }
  }
}

int main() {
  read();
  solve();
  return 0;
}
