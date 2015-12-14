#include<iostream>
#include<fstream>
#include<string.h>
#define FIN "per.in"
#define FOUT "per.out"
#define base 127
#define MOD 100007
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int n, k;
string s;

int rollingHash(string str)
{
    int h = 0;
    for(int i = 0; i < s.size(); i++)
    {
        h = (h * base) % MOD;
        h = (h + str[i]) % MOD;
    }

    return h;
}

int main()
{
    f >> n;
    f >> k;
    f >> s;

    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < n - k; j++)
        {
            string sub = s.substr(j, k);
            int hash = rollingHash(sub);
        }
    }
}
