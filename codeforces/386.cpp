#include<bits/stdc++.h>
#define in f
#define out cout
using namespace std;

ifstream f("data.in");

int n, m;

vector<int> v;

void read() {
  int x;
  in >> n;
  in >> m;

  for(int i = 1; i <= n; i++) {
    in >> x;
    v.push_back(x);
  }

}

void solve() {
  sort(v.begin(), v.end());
  int start = 1;
  vector<pair<int, int>> ranges;

  for(auto x : v) {
    out << x << " ";
    if(x <= m) {
      if(start < x ) {
        ranges.push_back({start, x});
      }

      start = x + 1;
    }

  }




  for(auto r : ranges) {
    out << r.first << " " << r.second << endl;
  }

}

int main() {
  read();
  solve();
  return 0;
}
