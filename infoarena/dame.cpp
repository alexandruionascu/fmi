#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("damesah.in");

const int MAX_SIZE = 30;
int d1[MAX_SIZE];
int d2[MAX_SIZE];
int p[MAX_SIZE];
int viz[MAX_SIZE];

int n;

int main() {
  in >> n;
  srand(0);
  double start = clock();
  while (true) {
    memset(d1, 0, sizeof d1);
    memset(d2, 0, sizeof d2);
    memset(viz, 0, sizeof viz);
    for (int i = 1; i <= n; i++) {
      int x = 1 + rand() % n;

      if (viz[x] == 0) {
        if (d1[x + i] == 0) {
          if (d2[x - i + n] == 0) {
            if (i == n) {
              p[i] = x;
              for (int i = 1; i <= n; i++) {
                out << p[i] << " ";
              }
              out << endl;
              //  out << (clock() - start);
              //    return 0;
            } else {
              viz[x] = 1;
              d1[x + i] = 1;
              d2[x - i + n] = 1;
              p[i] = x;
            }
          } else {
            break;
          }
        } else {
          break;
        }
      } else {
        break;
      }
    }
  }

  return 0;
}
