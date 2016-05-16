#include <bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");

char a[3][3], a2[3][3];
char b[3][3];

pair <int, int> x;

void citeste() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            in >> a[i][j];
            a2[i][j] = a[i][j];
            if (a[i][j] == 'X') x = make_pair(i, j);
        }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            in >> b[i][j];
}

bool e_egal(char a[3][3], char b[3][3]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (a[i][j] != b[i][j]) return false;
    return true;
}

bool roteste_stanga(int i, int j) {
    int i_next, j_next;
    while(1) {
        if (i == 0) {
            if (j == 1) {
                i_next = 1;
                j_next = 1;
            }
            else {
                i_next = 0;
                j_next = 1;
            }
        }
        else {
            if (j == 1) {
                i_next = 1;
                j_next = 0;
            }
            else {
                i_next = 0;
                j_next = 0;
            }
        }

        swap(a[i][j], a[i_next][j_next]);
        i = i_next;
        j = j_next;

        if (e_egal(a, b)) return true;
        if (e_egal(a, a2)) return false;
    }

    return false;
}

bool roteste_dreapta(int i, int j) {
    int i_next, j_next;
    while(1) {
        if (i == 0) {
            if (j == 1) {
                i_next = 0;
                j_next = 0;
            }
            else {
                i_next = 1;
                j_next = 0;
            }
        }
        else {
            if (j == 1) {
                i_next = 0;
                j_next = 1;
            }
            else {
                i_next = 1;
                j_next = 1;
            }
        }

        swap(a[i][j], a[i_next][j_next]);
        i = i_next;
        j = j_next;

        if (e_egal(a, b)) return true;
        if (e_egal(a, a2)) return false;
    }

    return false;
}


int main() {
    citeste();
    if (e_egal(a, b)) {
        cout << "YES\n";
        return 0;
    }
    if (roteste_stanga(x.first, x.second)) {
        cout << "YES\n";
        return 0;
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = a2[i][j];

    if (roteste_dreapta(x.first, x.second)) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}
