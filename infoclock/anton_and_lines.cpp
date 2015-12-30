#include<bits/stdc++.h>
#define FIN "lines.in"
#define in cin
#define out cout
using namespace std;

ifstream f(FIN);

vector<pair<long long, long long> >points;
vector<pair<long long, long long> >lines;
long long x1, x2;
int n;

bool comparator(pair<long long, long long> p1, pair<long long, long long> p2)
{
    if(p1.first < p2.first)
        return true;
    else if(p1. first == p2.first)
        return p1.second < p2.second;
    else return false;
}

void read() {
    in >> n;
    in >> x1;
    in >> x2;

    long long p1, p2;
    for(int i = 0; i < n; i++)
    {
        in >> p1; in >> p2;
        points.push_back(make_pair(p1, p2));
        lines.push_back(make_pair(x1 * p1 + p2, x2 * p1 + p2));
    }
}

void solve() {

    sort(lines.begin(), lines.end(), comparator);

    long long lowerBound = lines[0].second;

    for(int i = 0; i < lines.size(); i++)
    {
        if(lines[i].second < lowerBound)
        {
            out << "YES";
            return;
        }

        lowerBound = lines[i].second;
    }

    out << "NO";
}

int main()
{
    read();
    solve();

    return 0;
}
