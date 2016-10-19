#include<bits/stdc++.h>
#define in f
#define out cout
using namespace std;

ifstream f("wow.in");
char M[105][105];

int main() {
  int n;
  in >> n;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      M[i][j] = '#';

  for(int i = 1; i <= n; i++) {
    string row;
    in >> row;

    for(int j = 0; j < row.size(); j++) {
      if(row[j] != '.' && row[j] != '#') {
        M[i][j + 1] = row[j];
        M[j + 1][i] = row[j];
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      out << M[i][j];
    }

    out << "\n";
  }

  return 0;
}
