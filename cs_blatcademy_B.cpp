#include<bits/stdc++.h>
#define in cin
#define out cout
#define MAXN 100001
using namespace std;

ifstream f("date.in");
int n;
pair<int, int> v[MAXN];
int counter;
set<int> s;

void read() {
    in >> n;

    int x;
    for(int i = 1; i <= n; i++) {
        in >> x;
        v[i] = make_pair(x, i);

        s.insert(i);
    }
}

void solve() {

    sort(v + 1, v + n + 1);
    for(int i = 1; i <= n; i++) {
        s.erase(s.find(v[i].second));
        if(*s.begin() > i)
            counter++;
    }

    counter++;

    out << counter;

}

int main() {
    read();
    solve();
    return 0;
}
