#include<bits/stdc++.h>
#define IN cin
#define OUT cout
using namespace std;

ifstream f("data.in");
int n;
vector<int> v;

void read() {
  IN >> n;
  int x;
  for(int i = 1; i <= n; i++) {
    IN >> x;
    v.push_back(x);
  }

}

int binarySearch(int money) {
  int low = -1;
  int high = v.size();
  int mid;

  while(high - low > 1) {
    mid = (high + low) / 2;

    if(v[mid] > money) {
      high = mid;
    } else {
      low = mid;
    }
  }


  if(v[mid] <= money) {
    return mid + 1;
  } else {
    return mid;
  }




  return mid;
}

void solve() {
  sort(v.begin(), v.end());
  int money;
  int q;
  IN >> q;
  for(int i = 1; i <= q; i++) {
    IN >> money;
    OUT << binarySearch(money) << endl;
  }

}

int main() {
  read();
  solve();
  return 0;
}
