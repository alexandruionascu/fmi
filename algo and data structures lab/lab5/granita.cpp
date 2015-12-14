#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#define FIN "granita.in"
#define FOUT "granita.out"
#define in f
#define out g
using namespace std;


ifstream f(FIN);
ofstream g(FOUT);

vector< pair<int, int> > borders;
int n, counter;
int minn, maxx;

int read()
{
    in >> n;

    int x, y;
    for(int i = 1; i <= n; i++)
    {
        f >> x;
        f >> y;
        borders.push_back(make_pair(x, y));
    }

    return 0;
}

int solve()
{
    sort(borders.begin(), borders.end());
    int minn = borders.begin()->first;
    int maxx = borders.begin()->second;

    for(vector< pair<int, int> >::iterator it = borders.begin(); it != borders.end(); it++)
    {
        if(it->first < minn || it->second < maxx)
        {
            counter++;
        }

        minn = min(minn, it->first);
        maxx = max(maxx, it->second);
    }

    out << counter;
    return 0;
}

int main()
{
    read();
    solve();

    return 0;
}
