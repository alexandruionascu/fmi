#include<fstream>
#include<iostream>
using namespace std;
#define FIN "lgput.in"
#define FOUT "lgput.out"
#define MOD 1999999973

ifstream f(FIN);
ofstream g(FOUT);


long long pow(long long x, long long n)
{

    if(n == 0)
    {
        return 1;
    }
    else if(n == 1)
    {
        return x;
    }
    else if(n % 2 == 0)
    {
        return pow((x * x) % MOD, n / 2) % MOD;
    }
    else
    {
        return (x * pow((x * x) % MOD, n / 2)) % MOD;
    }

}


long long n, p;

int main()
{
    f >> n;
    f >> p;
    g << pow(n, p);
    return 0;

}
