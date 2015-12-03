#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#define FIN "lines.in"
using namespace std;

ifstream f(FIN);

vector<pair<long long, long long> >points;
vector<pair<long long, long long> >lines;
long long x1, x2;
int n;

bool comparator(pair<long long, long long> p1, pair<long long, long long> p2)
{
    if(p1.first <= p2.first)
        return true;
    else return false;
}

int read()
{
    f >> n;
    f >> x1;
    f >> x2;

    long long p1, p2;
    for(int i = 0; i < n; i++)
    {
        f >> p1; f >> p2;
        points.push_back(make_pair(p1, p2));
        lines.push_back(make_pair(x1 * p1 + p2, x2 * p1 + p2));
    }

    return 0;
}

int solve()
{

    sort(lines.begin(), lines.end(), comparator);
    for(int i = 0; i < lines.size(); i++)
        cout << lines[i].first << " "<<lines[i].second << endl;
    for(int i = 1; i < lines.size(); i++)
    {
        if(lines[i].second < lines[i-1].second && lines[i].first != lines[i-1].first)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}

int main()
{
    read();
    solve();

    return 0;
}
