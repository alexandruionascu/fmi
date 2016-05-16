#include<bits/stdc++.h>
#define in f
#define out g
using namespace std;

ifstream f("drepte2.in");
ofstream g("drepte2.out");

int n;

int main() {
    in >> n;
    if(n % 2 == 0)
        out << n / 2 * (n + 1) + 1;
    else out << (n + 1) / 2 * n + 1;

    return 0;
}
