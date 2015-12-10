#include<iostream>
#include<fstream>
#include<cstdlib>
#define FIN "sdo.in"
#define FOUT "sdo.out"
#define MAXN 3000001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int n, k, v[MAXN];

int solve(int left, int right, int k)
{
    if(left == right)
        return v[left];

    int random = rand() % (right - left) + left + 1;
    int pivot = v[random];

    int i = left;
    int j = right;

    while(i <= j)
    {
        while(v[i] < pivot)
        {
            i++;
        }

        while(v[j] > pivot)
        {
            j--;
        }

        if(i <= j)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    int pos = j - left + 1;

    if(pos >= k)
    {
        return solve(left, j, k);
    }
    else
    {
        return solve(j + 1, right, k - pos);
    }

    return 0;

}

int main()
{
    f >> n;
    f >> k;

    for(int i = 1; i <= n; i++)
        f >> v[i];

    g << solve(1, n, k);

    return 0;
}
