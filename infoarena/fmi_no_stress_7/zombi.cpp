// MLC
#include <bits/stdc++.h>
#define in f
#define out cout
#define int64 long long
using namespace std;

ifstream f("data.in");
ofstream g("shield.out");

int const MAX_SIZE = 100005;
int n;
int l;
unordered_map<int, vector<int>> zombies;
multiset<int> to_catch;

int main() {
  in >> n;
  in >> l;
  int x, y;
  int currentPos = 1;
  int currentTime = 1;
  for (int i = 1; i <= n; i++) {
    in >> x;
    in >> y;
    if (zombies[x].size() == 0)
      to_catch.insert(x);
    zombies[x].push_back(y);
  }

  for (auto level : to_catch) {
    int64 mean = 0;
    for (auto zombie : zombies[level]) {
      mean += zombie;
    }

    mean /= zombies[level].size();
    int64 target = mean - (l / 2);

    if (target > currentPos) {
      for (int i = 1; i <= target - currentPos; i++) {
        out << "R";
      }
    } else {
      for (int i = 1; i <= currentPos - target - 1; i++) {
        out << "L";
      }
    }

    int elapsed = abs(currentTime - target) - 1;
    for (int i = 1; i <= level - currentTime - elapsed - 1; i++) {
      out << "S";
    }

    out << endl;
    out << "FROM " << currentPos << " TO " << target << endl;
    out << "NEXT LEVEL " << endl;
    currentTime = level;
    currentPos = target;
  }
}
