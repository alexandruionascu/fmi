#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#define FIN "date.in"
#define in f
#define out cout

using namespace std;

ifstream f(FIN);
vector<pair<int, int> > v;
int n, k;

int read()
{
    in >> n;
    in >> k;

    int x, y;
    for(int i = 1; i <= n; i++)
    {
        in >> x;
        in >> y;

        v.push_back(make_pair(x, y));
    }
    return 0;
}

int solve()
{
    sort(v.begin(), v.end());
    vector< pair< pair<int, int>, int > >  s;

    for(int i = 0; i < v.size(); i++)
    {
        if(s.empty())
        {
            s.push_back(v[i], 1);
        }
        else
        {
            pair< pair<int, int>, int> last = s.back();
        }
    }


    return 0;
}

int main()
{
    read();
    solve();

    return 0;
}
