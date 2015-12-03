#include<iostream>
#include<fstream>
using namespace std;

#define MAXN 2001

ifstream f("binar.in");
ofstream g("binar.out");

int merge(int collumn, int a, int n, int b)
{
    int indexA = a;
    int indexB = n + 1;
    int indexC = 1;

    while(indexA <= n && indexB <= b)
    {
        if(m[indexA][collumn] <= m[indexB][collumn])
        {
            aux[indexC] = indexA;
            indexA++;
            indexC++;
        }
        else
        {
            aux[indexC] = indexB;
            indexC++;
            indexB++;

        }
    }

    while(indexA <= n)
    {
        aux[indexC] = indexA;
        indexA++;
        indexC++;
    }

    while(indexB <= b)
    {
        aux[indexC] = indexB;
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

int sort(int collumn, int a, int b)
{


    if(b > a)
    {
        int mid = (a + b) / 2;
        sort(a, mid);
        sort(mid+1, b);
        merge(a, mid, b);
    }
}

int a[MAXN][MAXN];
int n. m;

int main()
{
    f >> n;
    f >> m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            f >> m[i][j];
        }
    }

    for(int i=1; i<=n; i++)
        sort(i, 1, m);
}
