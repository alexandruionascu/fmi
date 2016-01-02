#include<bits/stdc++.h>
#define in f
#define out g
#define MAXN 1000001
#define INF 1 << 30
using namespace std;

ifstream f("slidingwindow.in");
ofstream g("slidingwindow.out");

int v[MAXN];
int n, k;
multiset<int> s;
int minim = INF;

int main() {
    in >> n;
    in >> k;

    for(int i = 1; i <= n; i++) {
        in >> v[i];

        s.insert(v[i]);

        multiset<int>::iterator it = s.find(v[i]);
        multiset<int>::iterator lower = --s.find(v[i]);
        multiset<int>::iterator upper = ++s.find(v[i]);

        if(upper != s.end()) {
            if(*upper - *it < minim)
                minim = *upper - *it;
        }

        if(it != s.begin()) {
            if(*it - *lower < minim)
                minim = *it - *lower;
        }

        if(i >= k)
            s.erase(v[i - k + 1]);
    }

    out << minim;

    return 0;
}
