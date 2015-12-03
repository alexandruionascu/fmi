#include<iostream>
#include<fstream>
#include<vector>
#define MAXN 4003
#define FIN "dentist.in"
using namespace std;

ifstream f(FIN);

long long n, m[MAXN][4];
long long hall[MAXN];
long long office[MAXN];

vector<long long > solution;
vector< pair<long long, long long> > v;
long long kids;

int run(long long i);
int check();


int run(long long k)
{
    for(long long i=k+1; i < v.size(); i++)
    {
        v[i].second -= hall[v[k].first];
    }

    v.erase(v.begin() + k);

    check();
}
int check()
{
    for(long long i=0; i < v.size(); i++)
    {
        if( v[i].second < 0)
            run(i);
    }
}
int read()
{
    cin >> n;
    long long o, h, c;
    for(long long i=1; i<=n; i++)
    {
        cin >> o;
        cin >> h;
        cin >> c;

        office[i] = o;
        hall[i] = h;
        v.push_back(make_pair(i, c));
    }

    return 0;
}

int solve()
{
    while(!v.empty())
    {

       /* for(vector< pair<long, long> >::iterator it = v.begin(); it!= v.end(); it++)
            cout << it->second << " ";
        cout << endl;*/

        if(v.begin()->second >= 0)
        {
            solution.push_back(v.begin()->first);
            long long shock = office[v.begin()->first];
            v.erase(v.begin());
            for(vector< pair <long long, long long> >::iterator it = v.begin(); it != v.end(); it++)
            {
                if(shock == 0)
                    break;
                (*it).second -= shock;
                shock--;
            }

            kids++;
            check();
        }
        else
        {
            run(0);
        }


    }

    return 0;
}

int write()
{
    cout << kids << '\n';
    for(vector< long long >::iterator it = solution.begin(); it != solution.end(); it++)
        cout << *it << " ";
    return 0;
}

int main()
{
    read();
    solve();
    write();

    return 0;
}
