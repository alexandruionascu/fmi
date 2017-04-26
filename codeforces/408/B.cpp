#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");

int n, m, k;
int is_hole[1000 * 1000 + 10];

int main() {
  int x, y;
  in >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    in >> x;
    is_hole[x]++;
  }

  int position = 1;

  if (is_hole[position] > 0) {
    out << 1;
    return 0;
  }

  for (int i = 1; i <= k; i++) {
    in >> x;
    in >> y;

    if (position == x) {
      position = y;
    } else {
      if (position == y) {
        position = x;
      }
    }

    if (is_hole[position] > 0) {
      out << position;
      return 0;
    }
  }
  out << position;

  return 0;
}
