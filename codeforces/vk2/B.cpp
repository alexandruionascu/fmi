#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");

int main() {
  string a;
  string result;
  in >> a;

  in >> result;
  string b = "";
  for (int i = 0; i < a.size(); i++) {
    if (a[i] < result[i]) {
      out << -1;
      return 0;
    } else {
      b += result[i];
    }
  }
  out << b;

  return 0;
}
