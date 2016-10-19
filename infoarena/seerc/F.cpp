#include<bits/stdc++.h>
#define in cin
#define out cout
#define int64 unsigned long long
using namespace std;

ifstream f("wow.in");
int64 n;
int64 m[11][11];
vector<int64> numbers;

int64 countDigits(int64 x) {
  int result = 0;
  while(x > 0) {
    x /= 10;
    result++;
  }

  return result;
}

int64 power(int64 k) {
    int64 result = 1;
    for(int i = 1; i <= k; i++) {
        result = (result * 10) % 7;
    }

    return result;
}

void read() {
  in >> n;

  int x;
  for(int i = 1; i <= n; i++) {
    in >> x;
    numbers.push_back(x);
    int64 digits = countDigits(x);
    m[digits][x % 7]++;
  }

}

void solve() {
  int64 result = 0;

  for(int k = 0; k < n; k++) {
   for(int i = 1; i <= 10; i++) {
      int64 x = numbers[k];
      int64 digits = countDigits(x);
      m[digits][x % 7]--;
      int64 number = (int64)numbers[k] * (int64)power(i);
      int64 mod = (7 - (number % 7)) % 7;
      result += m[i][mod];
      m[digits][x % 7]++;
    }
  }

  out << result;
}

int main() {
  read();
  solve();
  return 0;
}
