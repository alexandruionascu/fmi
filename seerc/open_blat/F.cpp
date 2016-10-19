#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("wow.in");

long long x;

string optim(long long x) {
  if(x == 0) {
    return "";
  }
  if(x == 1) {
    return "1";
  } else if(x % 2 == 0) {
      string s1 = optim(x / 2);

      if(s1.size() + 2 < x) {
        return "[" + s1 + "]";
      } else {
        string ret = "";
        for(int i = 1; i <= x; i++)
          ret += "1";
        return ret;
      }
  } else {
    string s1 = optim(x / 2);

    if(s1.size() + 3 < x) {
      return "[" + s1 + "]1";
    } else {
      string ret = "";
      for(int i = 1; i <= x; i++)
        ret += "1";
      return ret;
    }
  }

}

int main() {
  in >> x;
  out << optim(x);
  return 0;
}
