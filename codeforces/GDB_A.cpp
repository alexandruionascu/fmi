#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("date.in");

int x;
string s;

int main() {

    in >> x;
    string tmp;
    in >> tmp;
    in >> s;

    if (s == "month") {

        if (x == 30) {
            out << 11 << '\n';
            return 0;
        }
        if (x < 30) {
            out << 12 << '\n';
            return 0;
        }
        out << 7 << '\n';
        return 0;
    }


    if (x == 6 || x == 5) {
        out << 53 << '\n';
        return 0;
    }

    out << 52 << '\n';
    return 0;
}
