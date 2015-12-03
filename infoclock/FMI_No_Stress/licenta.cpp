#include<iostream>
#include<fstream>
#include<set>
#include<algorithm>
#define FIN "licenta.in"
#define FOUT "licenta.out"
#define MAXN 100001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int k;
int S, T;
set< pair<int, int> > mihaela;
set< pair<int, int> > dean;

int read()
{
    f >> k;
    f >> S;

    int x, y;
    for(int i = 1; i <= S; i++)
    {
        f >> x;
        f >> y;
        mihaela.insert(make_pair(x, y));
    }

    f >> T;
    for(int i = 1; i <= T; i++)
    {
        f >> x;
        f >> y;
        dean.insert(make_pair(x, y));
    }

    return 0;
}

int solve()
{
    while(!dean.empty() && !mihaela.empty())
    {
        pair<int, int> d = *(dean.begin());
        pair<int, int> m = *(mihaela.begin());

        //cout <<"dean: "<<dean.begin()->first << " " << dean.begin()->second<<endl;
        //cout <<"mihaela: "<<mihaela.begin()->first << " "<<mihaela.begin()->second<<endl;
        int rangeA = max(d.first, m.first);
        int rangeB = min(d.second, m.second);
        //cout << rangeA << " "<<rangeB <<endl;
        int r = rangeB - rangeA;
       // cout << r << endl;
        if(r >= k)
        {
            g << rangeA << " " << rangeA  + k << endl;
            return 0;
        }
        else
        {
            if(d.second < m.second)
            {
                //cout <<"deleted "<< dean.begin()->first << " "<<dean.begin()->second<<endl;
                dean.erase(dean.begin());
            }
            else
            {
                //cout <<"deleted "<< mihaela.begin()->first << " "<<mihaela.begin()->second<<endl;
                mihaela.erase(mihaela.begin());
            }
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
