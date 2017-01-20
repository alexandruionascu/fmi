#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");
int n, k;
int north;

vector<pair<int, int>> contests;

long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
void read() {
  in >> n;
  int x, y;
  for (int i = 1; i <= n; i++) {
    in >> x;
    in >> y;
    contests.push_back({x, y});
  }
}

void solve() {
  long long maxRating = 0;
  for (int i = 0; i <= 2500; i++) {
    long long rating = i;
    bool possible = true;
    for (auto contest : contests) {
      if (contest.second == 1 && rating < 1900) {
        possible = false;
      }
      if (contest.second == 2 && rating >= 1900) {
        possible = false;
      }
      rating += contest.first;
    }

    if (possible) {
      maxRating = max(maxRating, i);
    }
  }

  if (maxRating == 0) {
    out << "Impossible";
  } else if (maxRating == 2500) {
    out << "Infinity";
  } else {
    for (auto contest : contests) {
      maxRating += contest.first;
    }
    out << maxRating;
  }
}
int main() {
  read();
  solve();
  return 0;
}
