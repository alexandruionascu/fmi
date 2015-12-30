#include<bits/stdc++.h>
#define in cin
#define out cout
#define HMAX 501
#define WMAX 501
using namespace std;

ifstream f("date.in");


int n, m;
int vertical[HMAX][WMAX];
int horizontal[HMAX][WMAX];
char v[HMAX][WMAX];

void read() {
    in >> n;
    in >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            in >> v[i][j];

}

void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            vertical[i][j] = vertical[i - 1][j] + vertical[i][j - 1] - vertical[i - 1][j - 1];
            horizontal[i][j] = horizontal[i - 1][j] + horizontal[i][j - 1] - horizontal[i - 1][j - 1];

            if (v[i][j] == '.' && v[i - 1][j] == '.')
                vertical[i][j]++;
            if (v[i][j] == '.' && v[i][j - 1] == '.')
                horizontal[i][j]++;
        }
}

void write(int v[HMAX][WMAX]) {

    cout << '\n';
    for (int i = 1; i <= n; i++, cout << "\n")
        for (int j = 1; j <= m; j++) cout << v[i][j] << " ";
    cout << '\n';

}


void solve() {
    int q, a, b, c, d;
    in >> q;
    for (int i = 1; i <= q; i++) {
        in >> a;
        in >> b;
        in >> c;
        in >> d;

        out << vertical[c][d] + vertical[a - 1][b - 1] - vertical[a - 1][d] - vertical[c][b - 1] - (vertical[a][d] - vertical[a][b - 1] - vertical[a - 1][d] + vertical[a - 1][b - 1]) + horizontal[c][d] + horizontal[a - 1][b - 1] - horizontal[a - 1][d] - horizontal[c][b - 1] - (horizontal[c][b] - horizontal[a - 1][b] - horizontal[c][b - 1] + horizontal[a - 1][b - 1]) << "\n";
    }
}

int main() {
    read();
    init();
    solve();
}
