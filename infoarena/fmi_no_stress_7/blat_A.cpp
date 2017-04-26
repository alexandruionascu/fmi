// MLC
#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("dicsi.in");
ofstream g("dicsi.out");

int const MAX_SIZE = 200005;

int n;
int c[MAX_SIZE];

int main() {
  in >> n;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      c[j]++;
    }
  }
  int maxx = 0;
  for (int i = 1; i <= n; i++)
    maxx = max(maxx, c[i]);
  c[1] = maxx + 1;
  out << maxx + 1 << "\n";
  for (int i = 1; i <= n; i++)
    out << c[i] << " ";
  return 0;
}
