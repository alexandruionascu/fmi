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
bool s[MAXN];


int quick(int left, int right)
{
    int pivot = v[rand() % (right - left) + left + 1];
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
            swap(v[left], v[right]);
            i++;
            j--;
        }
    }

    return left - i + 1;
}

int solve(int left, int right)
{
    int pivot = (rand() % right - left) + left + 1;

    if(left <= right)
    {
        cout << pivot <<endl;
        int r = quick(left, right);

        if(r == k)
        {
            cout << v[k] << endl;
            return 0;
        }
        else if(r < k)
        {
            solve(left, k - 1);
        }
        else
        {
            solve(k+1, right);
        }
    }
}

int main()
{
    f >> n;
    f >> k;


    for(int i=1; i<=n; i++)
        f >> v[i];

    solve(1, n);

    for(int i=1; i<=n;i++)
  //      cout << v[i] << " ";

    return 0;
}
