#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");

set < pair< int,int > > S;
int n;
int x;
int pos2;
int pos1;
int val1;
int val2;

void solve() {
    set < pair < int ,int > >::iterator it;
    in >> n;
    for(int i = 1; i <= n;i++) {

        in >> x;
        S.insert(make_pair(x, i));
        if(i == 1) {
          continue;
        }

        pos1 = -1;
        pos2 = -1;
        it = S.find(make_pair(x,i));

        if(it != S.end()) {
            it++;
            val2 = it->first;
            pos2 = it->second;
            it--;

        }

        if(it != S.begin()) {
            it--;
            val1 = it->first;
            pos1 = it->second;
        }


        if(pos1 > 0 && pos2>0) {
            if(pos1 > pos2)
                cout<<val1<<" ";
            else
                cout<<val2<<" ";
            continue;
        }

        if(pos1>0)
            out<<val1<<" ";
        else
            out<<val2<<" ";
    }
}

int main() {
    solve();
    return 0;
}
