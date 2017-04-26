#include <bits/stdc++.h>
#define in f
#define out cout
using namespace std;

ifstream f("data.in");
int n, p;

const int MAX_SIZE = 100 * 1000 + 10;
double a[MAX_SIZE];
double b[MAX_SIZE];

auto cmp = [](int x, int y) -> bool { return (b[x] / a[x]) > (b[y] / a[y]); };

priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

int main() {
  in >> n;
  in >> p;
  int index = 1;
  for (int i = 1; i <= n; i++) {
    in >> a[i];
    in >> b[i];
    q.push(index);
    index++;
  }

  double total = 0;
  while (true) {
    int top = q.top();
    q.pop();

    double ratio = (b[top] / a[top]);
    if (total > ratio * p) {
      break;
    }

    total += ratio;
    b[top] = p * ratio;
    q.push(top);
    cout << top;
  }
  out << total << endl;

  return 0;
}
