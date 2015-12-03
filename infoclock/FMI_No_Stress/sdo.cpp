#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define FIN "sdo.in"
#define FOUT "sdo.out"
#define MAXN 3000001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int v[MAXN];
int n, k;

int swap(int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;

    return 0;
}

int quick(int left, int right)
{
    srand(time(NULL));

    int pivot = rand() % right + left;
    pivot = v[7];

    while(left < right)
    {
        while(v[left] < pivot)
        {
            left++;
        }


        while(v[right] > pivot)
        {
            right--;
        }

        cout << left << " "<<right << endl;
        if(left <= right)
        {
            swap(left, right);
        }
    }

    for(int i=1; i<=n; i++)
        cout << v[i] << " ";
}

int main()
{
    f >> n;
    f >> k;

    for(int i=1; i<=n; i++)
    {
        f >> v[i];
    }

    int c = 4;
    int b=  pow(10,c);
    cout << b;

//   quick(1, n);
   return 0;

}
