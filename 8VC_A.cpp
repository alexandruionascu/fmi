#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("date.in");
int n;
string text;
int r, l, up, down;
int result;


void read() {
    in >> n;
    in >> text;
}

void solve() {

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int x = 0;
            int y = 0;
            for(int k = i; k <= j; k++) {
                if(text[k] =='U')
                    x++;
                if(text[k] == 'D')
                    x--;
                if(text[k] == 'L')
                    y--;
                if(text[k] == 'R')
                    y++;

            }


        if(x == 0 && y == 0){
            result++;
            for(int k = i; k <= j; k++)
                out<<text[k];
            out<<"\n";
            out<<i<<" "<<j<<"\n";
        }
        }
    }

    out << result;
}

int main() {
    read();
    solve();
    return 0;
}
