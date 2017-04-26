#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");

int n, m, k;

int main() {
  int v[500];
  in >> n;
  in >> m;
  in >> k;

  for (int i = 1; i <= n; i++) {
    in >> v[i];
  }

  int depth = 1;
  while (true) {
    if (m + depth <= n) {
      if (v[m + depth] > 0 && v[m + depth] <= k) {
        out << depth * 10;
        break;
      }
    }
    if (m - depth > 0) {
      if (v[m - depth] > 0 && v[m - depth] <= k) {
        out << depth * 10;
        break;
      }
    }

    depth++;
  }

  return 0;
}
