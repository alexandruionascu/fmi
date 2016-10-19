#include<bits/stdc++.h>
#define in f
#define out cout
#define double long double
#define EPS 0.0000000000001
using namespace std;

ifstream f("wow.in");
const int MAXN = 105;

int potatoes[MAXN];
int optim[MAXN];
int n, k;
double minGlobal = MAXN;
int solution[MAXN];

void read() {
    in >> n;
    in >> k;

    for(int i = 1; i <= n; i++)
      in >> potatoes[i];
}

int getMinCut(int potato, double minn) {
    double val = (double)potato / minn;
    double nearVal = nearbyint(val);
    if(val - nearVal >= -EPS && val - nearVal <= EPS) {
      return max(1, min(k, (int)nearVal));
    }
    return max(1,min(k, (int)((double)potato / minn)));
}

void solve() {

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= k; j++) {
      double diffMax = 0;
      double minn = (double)potatoes[i] / (double)j;
      optim[i] = j;
      for(int l = 1; l <= n; l++) if (i!=l) {
         optim[l] = getMinCut(potatoes[l], minn);
         double coco = (double)potatoes[l] / optim[l];
         if(coco < minn)
          diffMax = MAXN;
        else
         diffMax = max(diffMax, (double)potatoes[l] / optim[l] - minn);
      }

      if(diffMax < minGlobal) {
        minGlobal = diffMax;
        for(int l = 1; l <= n; l++)
          solution[l] = optim[l];
      }
    }
  }

  for(int i = 1; i <= n; i++)
    out << solution[i] << " ";
}

int main() {
  read();
  solve();
  return 0;
}
