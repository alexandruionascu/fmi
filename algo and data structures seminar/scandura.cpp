#include<bits/stdc++.h>
<<<<<<< HEAD
=======
#define MAXN 1000001
>>>>>>> 9579a4323b7fc0ef4be8da38a070fd4572e98b81
#define in f
#define out g
using namespace std;

ifstream f("scandura.in");
ofstream g("scandura.out");

<<<<<<< HEAD
queue<long long> s;
queue<long long> sums;
int n, m;
=======
int elements[2 * MAXN];
long long sums[2 * MAXN];


int n, m;
int N, S;
int headN, headS;
int endN, endS;
>>>>>>> 9579a4323b7fc0ef4be8da38a070fd4572e98b81
long long result;

void read() {
    in >> n;
    in >> m;

<<<<<<< HEAD
    int rest = (n - 1) % (m - 1);

    for(int i = 1; i <= rest; i++) {
        s.push(0);
=======
    N = n;
    headN = 1;
    headS = 1;

    while(m != 2 && N % (m - 1) != 1) {
        endN++;
        elements[endN] = 0;
        N++;
>>>>>>> 9579a4323b7fc0ef4be8da38a070fd4572e98b81
    }

    int x;
    for(int i = 1; i <= n; i++) {
        in >> x;
<<<<<<< HEAD
        s.push(x);
    }

}

void solve() {


    while(!s.empty()) {

        long long sum = 0;
        for(int i = 1; i <= m; i++) {
            if(!s.empty() && !sums.empty()) {
                if(s.front() > sums.front()) {
                    sum += sums.front();
                    sums.pop();
                } else {
                    sum += s.front();
                    s.pop();
                }
            } else {
                if(!s.empty()) {
                    sum += s.front();
                    s.pop();
                } else if(!sums.empty()) {
                    sum += sums.front();
                    sums.pop();
                }
=======
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
>>>>>>> 9579a4323b7fc0ef4be8da38a070fd4572e98b81
            }

        }

        result += sum;

<<<<<<< HEAD
        sums.push(sum);
=======
        endS++;
        sums[endS] = sum;

>>>>>>> 9579a4323b7fc0ef4be8da38a070fd4572e98b81
    }

    out << result;
}

int main() {
    read();
    solve();
    return 0;
}
