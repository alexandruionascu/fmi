#include<bits/stdc++.h>
#define in f
#define out g
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int m[100][100];
int n, k;

void read() {
    in >> n;
    in >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            in >> m[i][j];
        }
    }

}

void printCycle(int i, int j) {
    if(m[i][j] != 0) {
        out << j << " ";
        int aux = m[i][j];
        m[i][j] = 0;
        printCycle(i, aux);
    } else out << ")";
}



void solve() {
    for(int i = 1; i <= n; i++) {
        out << "Permutarea " << i << "\n";
        for(int j = 1; j <= k; j++) {
            out << m[i][j] << " ";
        }

        out << "\nProdusul in ciclii disjuncti: \n";
        for(int j = 1; j <= k; j++) {
            if(m[i][j] != 0) {
                out << "( " << j << " ";
                int aux = m[i][j];
                m[i][j] = 0;
                printCycle(i, aux);
                out << " ";
            }
        }

        out << "\n \n";
    }
}

int main() {
    read();
    solve();
    return 0;
}
