#include<fstream>
#include<iostream>
using namespace std;

#define MAXN 100001
#define MOD 9917
ifstream f("inv.in");
ofstream g("inv.out");

int v[MAXN];
int aux[MAXN];
int n;
int inv;

int merge(int a, int n, int b)
{
    int indexA = a;
    int indexB = n + 1;
    int indexC = 1;

    while(indexA <= n && indexB <= b)
    {
        if(v[indexA] <= v[indexB])
        {
            aux[indexC] = v[indexA];
            indexA++;
            indexC++;
        }
        else
        {
            aux[indexC] = v[indexB];
            indexC++;
            indexB++;
            inv++;
            inv %= MOD;
        }
    }

    while(indexA <= n)
    {
        aux[indexC] = v[indexA];
        indexA++;
        indexC++;
        inv++;
        inv %= MOD;
    }

    while(indexB <= b)
    {
        aux[indexC] = v[indexB];
        indexB++;
        indexC++;
    }
    indexC = 1;
    for(int i=a; i <= b; i++)
    {
        v[i] = aux[indexC];
        indexC++;
    }

    return 0;
}

int sort(int a, int b)
{


    if(b > a)
    {
        int mid = (a + b) / 2;
        sort(a, mid);
        sort(mid+1, b);
        merge(a, mid, b);
    }
}

int main()
{
    f >> n;
    for(int i=1; i<=n; i++)
        f >> v[i];

    sort(1, n);
    g << inv;

    return 0;
}
