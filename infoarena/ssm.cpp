#include<bits/stdc++.h>
#define in f
#define out g
using namespace std;

ifstream f("ssm.in");
ofstream g("ssm.out");

int main() {
  vector<int> nums;
  int n;
  in >> n;
  for(int i = 0; i < n; i++) {
    int x;
    in >> x;
    nums.push_back(x);
  }
  int maxx = nums[0];
  int prev = nums[0];

  int start = 1;
  int fin = 0;

  for(int i = 1; i < nums.size(); i++) {
      prev = max(prev + nums[i], nums[i]);
      if(prev < 0) {
        start = i + 1;
      }
      if(prev > maxx) {
        fin = i;
      }
      maxx = max(maxx, prev);




  }

  out << maxx <<" "<< ++start << " " << ++fin;
  return 0;


}
