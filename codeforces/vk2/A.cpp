#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");

string change(string s, int i) {
  if (s[i] == 'V') {
    s[i] = 'K';
  } else {
    s[i] = 'V';
  }

  return s;
}

int count(string s) {
  int no = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == 'K' && s[i - 1] == 'V') {
      no++;
    }
  }

  return no;
}

int main() {
  string s;
  in >> s;
  int best = count(s);
  for (int i = 0; i < s.size(); i++) {
    best = max(best, count(change(s, i)));
  }

  out << best;
  return 0;
}
