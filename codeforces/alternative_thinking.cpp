#include<iostream>
#include<fstream>
#define FIN "alternative.in"
#define in f
#define MAXN 100001
using namespace std;

ifstream f(FIN);


char v[MAXN];
int n;
int maxx = 1;

int read()
{
    in >> n;
    in >> v[1];

    for(int i = 2; i <= n; i++)
    {
        f >> v[i];
        if(v[i] != v[i-1])
            maxx++;
    }

    return 0;
}

int count(int a, int b)
{
    int counter = 1;
    for(int i = 2; i <= n; i++)
    {
        if(i == a || i == b)
        {
            if(v[i] == v[i-1])
                counter++;
        }
        else
        {
            if(v[i] != v[i-1])
                counter++;
        }
    }

    return counter;
}


int solve()
{
    int right = n;
    int left = 1;
    int mid;

    while(left < right)
    {
        int mid = (right + left) / 2;
        int c1 = count(1, mid);
        int c2 = count(mid, n);
        int c3 = count(mid, mid);

        //cout << mid << " ";

        cout << left << " "<<right << endl;;

        if(c1 > maxx)
        {
            right = mid;
        }
        else if(c2 > maxx)
        {
            left = mid;
        }
        else if(c3 > maxx)
        {
            cout << c3;
            return 0;
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
