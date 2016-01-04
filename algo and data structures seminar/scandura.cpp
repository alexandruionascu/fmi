#include<bits/stdc++.h>
#define MAXN 1000001
#define in f
#define out g
using namespace std;

ifstream f("scandura.in");
ofstream g("scandura.out");

int elements[2 * MAXN];
long long sums[2 * MAXN];


int n, m;
int N, S;
int headN, headS;
int endN, endS;
long long result;

void read() {
    in >> n;
    in >> m;

    N = n;
    headN = 1;
    headS = 1;

    while(m != 2 && N % (m - 1) != 1) {
        endN++;
        elements[endN] = 0;
        N++;
    }

    int x;
    for(int i = 1; i <= n; i++) {
        in >> x;
        endN++;
        elements[endN] = x;
    }

    n = N;
}

long long getMinim() {
    long long minim = 1 << 30;

    if(headN <= endN && headS <= endS) {
        if(elements[headN] <= sums[headS]) {
            headN++;
            return elements[headN - 1];
        } else {
            headS++;
            return sums[headS - 1];
        }
    } else {
        if(headN <= endN) {
            headN++;
            return elements[headN - 1];
        } else if(headS <= endS) {
            headS++;
            return sums[headS - 1];
        }
    }
}

void solve() {

    while(headN <= endN || endS - headS + 1> 1) {

        long long sum = 0;
        for(int i = 1; i <= m; i++) {
            if(headN <= endN || headS <= endS) {
                long long minn = getMinim();
                sum += minn;
            }

        }

        result += sum;

        endS++;
        sums[endS] = sum;

    }

    out << result;
}

int main() {
    read();
    solve();
    return 0;
}
