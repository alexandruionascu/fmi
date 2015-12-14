#include<fstream>
#include<deque>
using namespace std;

#define FIN "vila2.in"
#define FOUT "vila2.out"
#define MAXN 100001

ifstream f(FIN);
ofstream g(FOUT);

deque<int> d1;
deque<int> d2;

int n, k;
int v[MAXN];
int maxx;

int main()
{
    f >> n;
    f >> k;

    for(int i=1; i<=n; i++)
    {
        f >> v[i];
    }

    for(int i=1; i<=n; i++)
    {
        while(d1.size() > 0 && v[d1.back()] >= v[i])
        {
            d1.pop_back();
        }

        while(d2.size() > 0 && v[d2.back()] <= v[i])
        {
            d2.pop_back();
        }

        d1.push_back(i);
        d2.push_back(i);

        if(i - k - 1 == d1.front())
            d1.pop_front();

        if(i - k - 1 == d2.front())
            d2.pop_front();

        if(v[d2.front()] - v[d1.front()] > maxx)
            maxx = v[d2.front()] - v[d1.front()];

    }

    g << maxx;

    return 0;
}
