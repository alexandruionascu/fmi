#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("wow.in");
int x;
const int MAXN =  10001;
bool prime[MAXN + 20];
int powers[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void sieve() {
  for(int i = 1; i <= MAXN; i++)
      prime[i] = true;

      for(int i = 2; i <= MAXN; i++) {
          if(prime[i] == true) {
              for(int j = i + i; j <= MAXN; j += i) {
                  prime[j] = false;
              }
          }
      }

      prime[1] = false;
}

int countDigits(int x) {
  return (int)log10(x) + 1;
}

int getSubNumber(int left, int right, int x) {
  return (x / powers[right]) % powers[countDigits(x) - left - right];
}

bool isUltraPrime(int x) {
  int digits = countDigits(x);

  for(int i = 0; i < digits; i++) {
    for(int j = 0; j < digits; j++) {
      if(i + j < digits) {
        int subNumber = getSubNumber(i, j, x);
        if(prime[subNumber] == false) {
          return false;
        }
      }
    }
  }

  return true;
}




int main() {
    sieve();
    in >> x;

    int counter = 0;


   for(int i = 2; i <= MAXN; i++) {
      if(isUltraPrime(i) == true)
        counter++;

      if(counter == x) {
        out << i;
        return 0;
      }
    }

    out << -1;

}
