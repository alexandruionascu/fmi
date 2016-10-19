#include<bits/stdc++.h>
#define in cin
#define out cout
#define PI 3.14159265
using namespace std;

ifstream f("data.in");

int n;
double result;

void solve() {
    in >> n;
    int currentX = 0;
    int currentY = 0;

    int x, y;
    for(int i = 1; i <= n; i++) {
        in >> x;
        in >> y;

        double r = atan2(y - currentY, x - currentX) * 180 / PI;

        double p = r * (double)100 / (double)90;
        double d = sqrt((x - currentX) * ( x - currentX) + (y - currentY) * (y - currentY));


        result += d * (1 + p / 100);



        currentX = x;
        currentY = y;

    }

    printf("%.7f\n", result);
}

int main() {
    solve();
    return 0;
}
