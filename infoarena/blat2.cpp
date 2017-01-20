#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;

ifstream in("zimeria.in");
ofstream out("zimeria.out");

const int ORDER_LENGTH = 12;
const int LENGTH = 5;
const int base = 27;
const int nMax = 400005;

int blat[2000];

int p, n;
char order[ORDER_LENGTH];
char cuvant[LENGTH + 1];

char complexity['z' + 1];
char charName[30];
int blat2[2000];
void rez1() {
  unordered_set<unsigned long long> ap;
  unsigned long long Hash;
  int rasp = 0;
  for (int i = 1; i <= n; ++i) {
    in >> cuvant;
    assert(strlen(cuvant) == 5);
    Hash = 0;
    for (int j = 0; j < LENGTH; ++j)
      Hash = Hash * base + cuvant[j];
    if (ap.find(Hash) == ap.end()) {
      ap.insert(Hash);
      rasp++;
    }
  }
  out << rasp;
}

int main() {
  in >> p >> n;
  in >> order;
  if (p == 1)
    rez1();
  return 0;
}
