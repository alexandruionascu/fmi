#include<bits/stdc++.h>
#define in f
#define out cout
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

    out << row << endl;
    vector<int> ones;

    for(int i = 0; i < row.size(); i++) {
        if(row[order[i + 1]] == '0')
            zeroes.push_back(order[i + 1]);
        else ones.push_back(order[i + 1]);
    }


    int index = 1;
    for(auto it : zeroes) {
        order[index] = it;
        index++;
    }



    for(auto it : ones) {
        order[index] = it;
        index++;
    }


    for(int i = 1; i <= n; i++)
        out << order[i] << " ";
    out << "\n";

}

void write() {
    for(int i = 1; i <= n; i++)
        out << order[i] << " ";
}

int main() {
    read();
    write();
    return 0;
}
