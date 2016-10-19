#include<bits/stdc++.h>
#define in cin
#define out cout
#define MAXN 100001
#define MAXM 100005
#define INF 1 << 30
using namespace std;

ifstream f("date.in");

int n, m;
pair <int, int> platforms[MAXN];
int balls[MAXM];
vector < pair <int, pair <int, int> > > intervals;

void read() {
    in >> n;
    in >> m;
    for (int i = 1; i <= n; i++)
        in >> platforms[i].first, in >> platforms[i].second;

    for (int i = 1; i <= m; i++)
        in >> balls[i];
}

int getInterval(int length) {
    int m = 0;
    int sol = -1;
    int l = 0;
    int r = intervals.size() - 1;

    while (l <= r) {
        m = (l + r) / 2;
        if (intervals[m].first < length) {
            l = m + 1;
        }
        else {
            r = m - 1;
            sol = m;
        }
    }

    return sol;
}

void solve() {
    pair < int, pair <int, int> > p;

    balls[++m] = INF;
    balls[++m] = -INF;

    sort(balls + 1, balls + m + 1);

    for (int i = 2; i <= m; i++) {
        p.first = abs(balls[i] - balls[i - 1]);
        p.second.first = balls[i - 1];
        p.second.second = balls[i];
        intervals.push_back(p);
    }

    sort(intervals.begin(), intervals.end());
    int first;
    pair <int, int> interval, platform;
    long long cost = 0, current;
    m = intervals.size();

    for (int i = 1; i <= n; i++) {
        platform = platforms[i];
        first = getInterval(platform.second - platform.first);

        current = INF;
        for (int j = first; j < m; j++) {
            interval = intervals[j].second;
            if (interval.second <= platform.second) {
                current = min(1LL * platform.second - interval.second, current);
            }
            else {
                current = min(1LL * interval.first - platform.first, current);
            }
        }
        cost = cost + current;
    }

    cout << cost;
}

int main() {
    read();
    solve();
    return 0;
}
