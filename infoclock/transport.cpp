#include<iostream>
#include<fstream>
#define FIN "transport.in"
#define FOUT "transport.out"
#define MAXN 16001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int n, k;
int v[MAXN];

bool possible(int x)
{
    int vol = 0;
    int trans = 1;
    bool ok = true;
    for(int i=1; i<=n; i++)
    {

        if(v[i] > x)
        {
            ok = false;
            break;
        }

        if(vol + v[i] <= x)
        {
            vol += v[i];
        }
        else
        {
            trans++;
            vol = v[i];
        }

        if(trans > k )
        {
            ok = false;
            break;
        }
    }

    return ok;
}

int main()
{
    f >> n;
    f >> k;
    int sum = 0;

    for(int i=1; i<=n; i++)
    {
        f >> v[i];
        sum += v[i];
    }

    int right = sum;
    int left = 0;

    while(right - left > 1)
    {

        int mid = (right + left) / 2;
        if(possible(mid))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }

    }

    if(possible(left))
        g << left;
    else g << right;

    return 0;

}
