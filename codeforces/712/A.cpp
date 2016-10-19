#include<bits/stdc++.h>
#define IN cin
#define OUT cout
using namespace std;

ifstream f("data.in");

struct Taxi {
  long double x;
  long double y;
  long double speed;
};

long double x;
long double y;

int n;
vector<Taxi> taxies;

void read() {
  IN >> x;
  IN >> y;
  IN >> n;

  for(int i = 1; i <= n; i++) {
    Taxi taxi;
    IN >> taxi.x;
    IN >> taxi.y;
    IN >> taxi.speed;
    taxies.push_back(taxi);
  }
}

long double getDistance(long double a, long double b) {
  return sqrt( (a - x) * (a - x) + (b - y) * (b - y));
}

void solve() {
  long double result = 1 << 30;

  for(auto taxi : taxies) {
    result = min(result, getDistance(taxi.x, taxi.y) / taxi.speed);
  }

  OUT << setprecision(8) << result;

}

int main() {
  read();
  solve();
  return 0;
}
