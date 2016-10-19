#include<fstream>
#include<iostream>
#define FIN "tricky.in"
using namespace std;

ifstream f(FIN);

int solve(long long x)
{
    int power = 1;
    long long sum;

    if(x % 2 == 0)
    {
        sum = x / 2 * (x + 1);
    }
    else
    {
        sum = (x + 1) / 2 * x;
    }

    while(power  <= x)
    {
        sum -= 2 * power;
        power *= 2;
    }

    cout << sum << "\n";

    return 0;
}

int main()
{
    int t;
    cin >> t;

    long long x;
    for(int i=1; i<=t; i++)
    {
        cin >> x;
        solve(x);
    }

    return 0;
}
