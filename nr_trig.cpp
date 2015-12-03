#include<iostream>
#include<fstream>
#include<algorithm>
#define FIN "nrtri.in"
#define FOUT "nrtri.out"
#define MAXN 801
using namespace std;


ifstream f(FIN);
ofstream g(FOUT);

int v[MAXN];
int n;



bool isTriangle(int a, int b, int c)
{
    if( a + b >= c &&  a + c >= b && b + c >= a)
        return true;
    else return false;
}

int searchRight(int a, int b, int left, int right)
{
    int step = 1;
    int i = left;

    for(step = 1; step < n; step <<= 1);

    for(i=left; step != 0; step >>= 1 )
    {
        if( (i+step) <= right && a + b >= v[i+step] )
            i += step;
    }

    return i;
}


int searchLeft(int a, int b, int left, int right)
{
    int step = 1;
    int i = right;

    for(step = 1; step < n; step <<= 1);

    for(i=right; step != 0; step >>= 1 )
    {
        if( (i-step) > left && a + b >= v[i-step] )
            i -= step;
    }

    return i;
}



int main()
{
    f >> n;
    int counter = 0;
    for(int i=1; i<=n; i++)
        f >> v[i];

    sort(v + 1, v + n + 1);

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<= n; j++)
        {
           int right = searchRight(v[i], v[j], j, n);
           int left = searchLeft(v[i], v[j], j, n);

           if(left > j && left <= right )
           {
               counter += right - left + 1;

               //cout << v[i] << " " << v[j] << " " << v[left] << " "<<v[right] << endl;
           }
        }
    }

    cout << counter ;

    g << counter;

    return 0;

}
