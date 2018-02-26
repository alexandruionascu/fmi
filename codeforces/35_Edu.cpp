#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");

bool canX(int x, int a, int b, int n) {
  bool a_taken, b_taken;
  a_taken = false;
  b_taken = false;
  for (int i = 1; i <= n; i++) {
    if (a >= x) {
      a -= x;
      a_taken = true;
    } else if (b >= x) {
      b -= x;
      b_taken = true;
    } else {
      return false;
    }
  }

  if (a_taken == true && b_taken == true)
    return true;

  return false;
}

int main() {
    int n;
    int a, b;
    in >> n;
    in >> a;
    in >> b;
    int maxx = 0;
    for (int i = 1; i <= 210; i++) {
      if (canX(i, a, b, n)) {
        maxx = max(maxx, i);
      }
    }

    cout << maxx;

    return 0;
}
