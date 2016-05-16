#include<bits/stdc++.h>
#define in f
#define out cout
using namespace std;


ifstream f("data.in");

int n;

vector<vector<int>> m;
void read() {
    in >> n;

    int x;
    for(int i = 1; i <= n; i++) {
        vector<int> row;
        for(int j = 1; j <= n; j++) {
            in >> x;
            row.push_back(x);
        }

        m.push_back(row);
    }
}

vector<int> getColumn(vector<vector<int>> matrix, int c) {
    vector<int> column;

    for(int i = matrix.size() - 1; i >= 0; i--) {
        column.push_back(matrix[i][c]);
    }

    return column;
}

vector<vector<int>> rotateMatrix(vector<vector<int>> matrix) {
    vector<vector<int>> result;

    for(int i = 0; i < matrix.size(); i++) {
        result.push_back(getColumn(matrix, i));
    }

    return result;
}


void solve() {
    vector  <vector<vector<int>> > matrixes;

    matrixes.push_back(m);

    for(int i = 1; i <= 3; i++) {
        m = rotateMatrix(m);
        matrixes.push_back(m);
    }


    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m.size(); j++) {

            bool exists = false;

            for(int k = 0; k < matrixes.size(); k++) {
                if(matrixes[k][i][j] == 1) {
                    exists = true;
                }
            }

            if(exists == true) {
                out << 1 << " ";
            } else out << 0 << " ";
        }

        out << "\n";
    }



}

int main() {
    read();
    solve();
    return 0;
}
