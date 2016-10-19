#include<bits/stdc++.h>
#define in cin
#define out cout
using namespace std;

ifstream f("data.in");

const int MAXSIZE = 100100;

int dp[MAXSIZE];

string marcel;
string correct;
int n;

void read() {
    in >> n;
    in >> marcel;
    in >> correct;
}

void solve() {

    int max_so_far = 0;
    int max_ending_here = 0;
    int points = 0;

    if(marcel == correct) {
        out << n - 1;
        return;
    }
    for(int i = 0; i < marcel.size(); i++) {
        int value;

        if(marcel[i] == correct[i])
            value = -1, points++;
        else value = 1;

        max_ending_here += value;

        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }

    out << max_so_far + points;

}

int main() {
    read();
    solve();
    return 0;
}
