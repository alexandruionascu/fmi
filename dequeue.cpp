#include<deque>
#include<fstream>
using namespace std;
#define FIN "deque.in"
#define FOUT "deque.out"
#define MAXN 5000001

ifstream f(FIN);
ofstream g(FOUT);

deque<int> d;
int v[MAXN];
int n, k;

int main()
{
    f >> n;
    f >> k;

    long long int sum = 0;

    for(int i=1; i<=n; i++)
        f >> v[i];

    for(int i=1; i<=n; i++)
    {

        while(d.size() > 0 && v[d.back()] >= v[i])
        {
            d.pop_back();
        }


        d.push_back(i);

        if(i-k == d.front())
            d.pop_front();


        if( i >= k)
            sum += v[d.front()];
    }

    g << sum;

    return 0;

}


