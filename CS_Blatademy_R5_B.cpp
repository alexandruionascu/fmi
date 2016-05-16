#include<bits/stdc++.h>
#define in f
#define out cout
#define INF 100000000000
using namespace std;

const int MAXN =  100100;
vector<int> G[MAXN];
int n, m;

ifstream f("data.in");

int a, b, s;


void read() {
    in >> n;
    in >> m;
    in >> s;
    in >> a;
    in >> b;

    int x, y;
    for(int i = 1; i <= m; i++) {
        in >> x;
        in >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void solve() {
    queue<int> Q;
    unordered_map<int, int> depth;
    unordered_map<int, bool> visited;

    for(int i = 1; i <= n; i++) {
        depth[i] = 0;
        visited[i] = false;
    }

    Q.push(s);


    bool stop = false;
    int maxDepth = INF;
    visited[s] = true;

    while(Q.empty() == false && stop == false ) {
        int current = Q.front();
        Q.pop();

        out << current << endl;
        if(depth[current] > maxDepth) {
            stop = true;
        }

        for(int i = 0; i < G[current].size(); i++) {
            if(visited[G[current][i]] == false) {
                Q.push(G[current][i]);
                visited[G[current][i]] = true;
                depth[G[current][i]] = depth[current] + 1;

                if(G[current][i] == a || G[current][i] == b) {
                    maxDepth = depth[current];
                }

            }
        }
    }

    out << maxDepth;

}

int main() {
    read();
    solve();
    return 0;
}
