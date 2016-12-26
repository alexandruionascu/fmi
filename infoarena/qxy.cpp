#include<bits/stdc++.h>
#define in f
#define out g
using namespace std;

int n, q;
const int MAX_SIZE = 1e4 + 5;
const int MAX_VAL = 1005;
short int v[MAX_SIZE];
short int m[MAX_SIZE][MAX_VAL];
short int M[MAX_SIZE][MAX_VAL];


ifstream f("qxy.in");
ofstream g("qxy.out");

void read() {
  in >> n;
  int x;
  for(int i = 1; i <= n; i++) {
    in >> v[i];
  }

}

void solve() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= MAX_VAL; j++) {
      if(v[i] < j) {
        m[i][j] = m[i - 1][j] + 1;
        M[i][j] = M[i - 1][j];
      }
      if(v[i] > j) {
        m[i][j] = m[i - 1][j];
        M[i][j] = M[i - 1][j] + 1;
      }

      if(v[i] == j) {
        m[i][j] = m[i - 1][j] + 1;
        M[i][j] = M[i - 1][j] + 1;
      }
    }
  }

  in >> q;
  int l, r, x, y;
  for(int i = 1; i <= q; i++) {
    in >> l; in >> r;
    in >> x; in >> y;

    out << min(M[r][x] - M[l - 1][x], m[r][y] - m[l - 1][y]) << "\n";
  }
}


int main() {
  read();
  solve();
  return 0;
}
