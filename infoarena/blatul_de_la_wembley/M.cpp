#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("wow.in");

int t;
set<int> chairs[1005];
int n, m;
int broken;


void solve() {
  int sum1 = 0;
  int sum2 = 0;
  for(int i = 0; i < n; i++) {
    for(auto it = chairs[i].begin(); next(it, 1) != chairs[i].end(); it++) {
      int l = *next(it, 1) - *it - 1;
      if(l == 1) {
        sum1++;
        sum2++;
        continue;
      }


      if(l % 2 == 0) {
        sum1 += (l / 2);
        sum2 += (l / 2);
      } else {
        sum1 += (l / 2 + 1);
        sum2 += (l / 2);
      }
    }

  }
  out << sum1 << " " << sum2 << "\n";

}

void read() {
    in >> t;

    for(int i = 1; i <= t; i++) {
      in >> n;
      in >> m;
      in >> broken;
      int x, y;
      out << "Case #" << i << ": ";
      for(int j = 1; j <= broken; j++) {
        in >> x; in >> y;
        chairs[x].insert(y);
      }

      for(int i = 0; i < n; i++) {
        chairs[i].insert(-1);
        chairs[i].insert(m);
      }

      solve();
      for(int i = 0; i < n; i++) {
        chairs[i].clear();
      }


    }
}

int main() {
  read();
  return 0;
}
