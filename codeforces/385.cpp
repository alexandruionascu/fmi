#include<bits/stdc++.h>
#define in f
#define out cout
using namespace std;


ifstream f("data.in");

const int MAX_SIZE = 700;
char p[MAX_SIZE][MAX_SIZE];

int main() {
    int n, m;
    in >> n;
    in >> m;

    char c;
    bool fixed = false;

    for(int i = 1; i <= n; i++) {
        string s;
        in >> s;

        for(int j = 0; j < s.size(); j++) {
            p[i][j + 1] = s[j];
        }
    }



    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            int lengthX = 0;
            int lengthY = 0;

            int x = i;
            int y = j;

            if(p[i][j] == 'B') {
                continue;
            }


            if(fixed == true) {
                if(p[i][j] == 'X') {
                    out << "NO";
                    return 0;
                }
            }



            while(p[i][y] == 'X') {
                lengthX++;
                y++;
            }

            while(p[x][j] == 'X') {
                lengthY++;
                x++;
            }



            for(int k = 0; k < lengthX; k++) {
                for(int l = 0; l < lengthY; l++) {
                    if(p[i + k][j + l] == '.') {
                        out << "NO";
                        return 0;
                    } else if(p[i + k][j + k] == 'X') {
                        p[i + k][j + l] = 'B';
                        fixed = true;
                    }


                }


            }
        }
    }

        for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            out << p[i][j] << " ";
        }

        out << endl;
    }



    out << "YES";
}
