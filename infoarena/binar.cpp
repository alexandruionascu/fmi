#include<bits/stdc++.h>
#define in f
#define out g
#define FIN "binar.in"
#define FOUT "binar.out"
#define MAXN 2001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);
int n, m;
int order[MAXN];
char v[MAXN];
vector<string> rows;

void solve(string row);

void read() {

    in >> m;
    in >> n;

    for(int i = 1; i <= n; i++)
        order[i] = i;

    string row;
    for(int i = 1; i <= m; i++) {
        f >> row;
        rows.push_back(row);
    }

    for(int i = rows.size() - 1; i >= 0; i--)
        solve(rows[i]);
}

void solve(string row) {

    vector<int> zeroes;
    vector<int> ones;

    for(int i = 1 ; i <= n; i++) {
        v[i] = row[order[i] - 1];
    }

    for(int i = 1; i <= n; i++) {
        if(v[i] == '0') {
            zeroes.push_back(order[i]);
        } else ones.push_back(order[i]);
    }

    int index = 1;
    for(int i = 0; i < zeroes.size(); i++) {
        order[index] = zeroes[i];
        index++;
    }

    for(int i = 0; i < ones.size(); i++) {
        order[index] = ones[i];
        index++;
    }


}


void write() {
    for(int i = 1; i <= n; i++) {
        out << order[i] << " ";
    }
}

int main() {
    read();
    write();
    return 0;
}
