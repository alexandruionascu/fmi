#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;


ifstream f("date.in");

long double n, x, y;
long double minn = 3000000000;
long double maxx = 0;


void read() {
    in >> n;
    in >> x;
    in >> y;

    long double a, b;
    for(int i = 1; i <= n; i++) {
        in >> a;
        in >> b;

        long double xDist = x - a;
        xDist *= xDist;

        long double yDist = y - b;
        yDist *= yDist;

        long double dist = xDist + yDist;


        if(dist < minn) {
            minn = dist;
        }

        if(maxx < dist) {
            maxx = dist;
        }

    }

    printf("%.8Lf", (long double)atan((long double)1) * (long double)4 * (maxx - minn)) ;
}

void solve() {

}

int main() {
    read();
    solve();
    return 0;
}
