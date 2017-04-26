// MLC
#include <bits/stdc++.h>
#define in f
#define out g
#define int64 long long
using namespace std;

ifstream f("blaturi.in");
ofstream g("blaturi.out");

int const MAX_SIZE = 100005;
int n;
vector<pair<int>> gagici;
int t;
int64 partial[MAX_SIZE];

int main() {
  in >> n;
  in >> t;
  int x, y;
  for (int i = 1; i <= n; i++) {
    in >> x;
    in >> y;
    gagici.push_back({x, y});
  }

  sort(gagici.begin(), gagici.end(), [](pair<int, int> a, pair<int, int> b) {
    return (a.first / a.second) < (b.first / b.second);
  });
}
