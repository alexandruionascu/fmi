#include<bits/stdc++.h>
#define in cin
#define out cout
#define ALPHA 26
#define MAXN 100001
#define MAXLEN 1001
using namespace std;


ifstream f("date.in");

int n;
int maxLen;
int position[MAXN];

char s[MAXN][MAXLEN];
int order[ALPHA + 1];
int length[MAXN];

vector <int> s1[ALPHA + 1];
vector <int> s2[ALPHA + 1];

bool isLetter(char c) {
    if ('a' <= c && c <= 'z')
        return true;
    if ('A' <= c && c <= 'Z')
        return true;


    return false;
}

int lowerCase(char c) {
    if ('a' <= c && c <= 'z')
        return c - 'a' + 1;

    return c - 'A' + 1;
}

bool isLower(char c) {
    if ('a' <= c && c <= 'z')
        return true;

    return false;
}



void read() {
    char c;
    for (int i = 1; i <= ALPHA; i++) {
        in >> c;
        order[i] = c - 'a' + 1;
    }

    in >> n;
    for (int i = 1; i <= n; i++) {
        position[i] = i;
        in >> s[i];
        length[i] = strlen(s[i]);
        maxLen = max(maxLen, length[i]);
    }
}



void solve() {

    int x;
    int l;
    int k;


    for (int counter = maxLen - 1; counter >= 0; counter--) {

        for (int i = 1; i <= n; i++) {
            if (isLetter(s[position[i]][counter])) {
                if (isLower(s[position[i]][counter]))
                    s1[lowerCase(s[position[i]][counter])].push_back(position[i]);
                else
                    s2[lowerCase(s[position[i]][counter])].push_back(position[i]);
            }
            else {
                s1[0].push_back(position[i]);
            }
        }

        k = 0;
        for (int i = 0; i <= ALPHA; i++) {
            l = s1[order[i]].size();
            for (int j = 0; j < l; j++)
                position[++k] = s1[order[i]][j];
            s1[order[i]].clear();
        }

        for (int i = 0; i <= ALPHA; i++) {
            l = s2[order[i]].size();
            for (int j = 0; j < l; j++)
                position[++k] = s2[order[i]][j];
            s2[order[i]].clear();
        }
    }
}

void write() {
    for (int i = 1; i <= n; i++)
        out << s[position[i]] << '\n';
}

int main() {
    read();
    solve();
    write();
    return 0;
}
