#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("wow.in");
long long n;
long long x;


long long blat(long long val) {
  val *= 2;
  long long x = sqrt(val);
  if(x * (x + 1) == val)
    return val;
  else {
    if(x * (x + 1) > val) {
      return (x - 1) * x;
    } else {
      return x * (x + 1);
    }
  }
}


void read() {
    in >> n;


    for(int i = 1; i <= n; i++) {
      in >> x;
      out << "Case #" << i << ": "<< blat(x) / 2 << "\n";
    }
}



int main() {
  read();
  return 0;
}
