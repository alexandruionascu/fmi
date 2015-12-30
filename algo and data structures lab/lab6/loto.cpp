#include<bits/stdc++.h>
#define FIN "loto.in"
#define FOUT "loto.out"
#define in f
#define out g
#define MAXN 101
using namespace std;

typedef struct Sum {
    int a;
    int b;
    int c;
    int value;
};

ifstream f(FIN);
ofstream g(FOUT);

int n, s;
Sum sums[MAXN * MAXN * MAXN];
int v[MAXN];
int length;


void read() {
    in >> n;
    in >> s;

    for(int i = 1; i <= n; i++)
        in >> v[i];
}

void write(Sum x, Sum y) {
    out << x.a << " " << x.b << " " << x.c << " ";
    out << y.a << " " << y.b << " " << y.c << " ";
}

void solve() {
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            for(int k = j; k <= n; k++) {
                Sum aux;
                aux.value = v[i] + v[j] + v[k];
                aux.a = v[i];
                aux.b = v[j];
                aux.c = v[k];

                length++;
                sums[length] = aux;
            }
        }
    }

    sort(sums + 1, sums + length, [](Sum a, Sum b) {
        return a.value < b.value;
    });

    int left = 1;
    int right = length;

    while(left < right) {
        int target = s - sums[left].value;

        while(sums[right].value > target)
            right--;

        if(left > right) {
            out << -1;
            return;
        }

        if(sums[right].value == target) {
            write(sums[left], sums[right]);
            return;
        }

        left++;
    }

    out << -1;
}

int main() {
    read();
    solve();
    return 0;
}




