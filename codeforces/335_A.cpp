#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int mapp(char c) {
    if(c == 'U') return 0;
    if(c == 'R') return 1;
    if(c == 'D') return 2;
    if(c == 'L') return 3;
}

char moves[500000];
int Viz[1000][1000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
    #endif

    int maxx, maxy, x, y;

    cin>>maxx>>maxy>>x>>y;
    cin>>moves;

    int total = x*y;

    for(int i=0; moves[i]; i++) {
        if(Viz[x][y])
            cout<<0<<'\n';
        else {
            cout<<1<<'\n';
            Viz[x][y] = 1;
            total--;
        }

        int curmove = mapp(moves[i]);

        x += dx[curmove];
        y += dy[curmove];

        if(x <= 0) x++; if(x > maxx) x--;
        if(y <= 0) y++; if(y > maxy) y--;
    }

    cout<<total;



}
