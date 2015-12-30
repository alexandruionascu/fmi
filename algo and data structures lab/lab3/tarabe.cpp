#include<bits/stdc++.h>
#define MAXN 200001
#define FIN "tarabe.in"
#define FOUT "tarabe.out"
#define in f
#define out g
using namespace std;


ifstream f(FIN);
ofstream g(FOUT);

int n, k;
int a[MAXN], b[MAXN];
long long lower;
long long upper;


void read() {
    in >> n;
    in >> k;

    for(int i = 1; i <= n; i++) {
        in >> b[i];
        in >> a[i];

        long long value = ((long long)a[i] + (long long)b[i]) * (long long) k;

        if(value > upper)
            upper = value;
    }
}

long long getProducts(long long maxPrice) {
    long long products = 0;

    for(int i = 1; i <= n; i++) {
        if(a[i] <= maxPrice) {
            products = products + ((maxPrice - a[i]) / b[i]) + 1;
        }
    }

    return products;
}

long long getCost(long long maxPrice) {

    long long products = 0;
    long long number = 0;
    long long sum = 0;

    for(int i = 1; i <= n; i++) {
        if(a[i] <= maxPrice) {
            number = ((maxPrice - a[i]) / b[i]) + 1;
            sum += number * a[i] + (
            number * (number - 1)) / 2 * b[i];
            products += number;
        }

    }

    sum -= maxPrice * (products - k);
    return sum;
}

void solve() {
    lower = 1;
    long long mid;

    while(upper - lower > 1) {

        mid = (lower + upper) / 2;

        if(getProducts(mid) < k) {
            lower = mid;
        } else upper = mid;
    }

    out << getCost(mid);
}

int main() {
    read();
    solve();
    return 0;
}

