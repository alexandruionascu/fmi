#include<bits/stdc++.h>
<<<<<<< HEAD
#define BASE 127
#define in f
#define out g
#define int64 unsigned long long
=======
#define FIN "per.in"
#define FOUT "per.out"
#define in f
#define out cout
#define BASE 127
>>>>>>> d57abe25561e9c5e1567e9c98595c422b7f7a14d
#define MAXN 6001
using namespace std;

ifstream f("per.in");
ofstream g("per.out");

int n, k;
<<<<<<< HEAD
string s;
int64 h[MAXN];
int l[MAXN];
int counter;

void read() {
    in >> n;
    in >> k;
    in >> s;
}

void solve() {

    int64 baseNumber = 1;
    int64 currentHash = 0;
    for(int length = 1; length <= n / k; length++) {
        currentHash = currentHash * BASE + s[length - 1];

        l[length - 1] = 1;
        h[length - 1] = currentHash;
        int64 auxHash = currentHash;

        for(int i = length; i < n; i++) {
            auxHash = (auxHash - s[i - length] * baseNumber) * BASE + s[i];
            h[i] = auxHash;
            l[i] = 1;

            if(h[i] == h[i - length]) {
                l[i] += l[i - length];
            }

            if(l[i] >= k)
                counter++;
        }

        baseNumber *= BASE;

    }

    out << counter;
}

int main()
{
    read();
    solve();
    return 0;
=======
string text;
int counter;
int h[MAXN];

void read() {
    in >> n;
    in >> k;
    in >> text;
}

void solve() {

    int currentHash = 0;

    for(int i = 1; i <= n / k; i++) {
        currentHash = h[i - 1] * BASE + text[i - 1];
        h[i] = currentHash;

        for(int j = i; j <= n; j++) {



        }
    }
>>>>>>> d57abe25561e9c5e1567e9c98595c422b7f7a14d
}

int main() {
    read();
    solve();
    return 0;
}
