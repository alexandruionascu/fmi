#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#define base 127
#define MOD1 100007
#define MOD2 100021
#define FIN "strmatch.in"
#define FOUT "strmatch.out"
using namespace std;


ifstream f(FIN);
ofstream g(FOUT);

string pattern;
string text;

vector<int> matches;


int rollingHash(string s, int mod)
{
    int h = 0;
    for(int i = 0; i < s.size(); i++)
    {
        h = (h * base) % mod;
        h = (h + s[i]) % mod;
    }

    return h;
}

int main()
{
    f >> pattern;
    f >> text;

    int hashA = 0;
    int hashB = 0;
    int patternHashA = rollingHash(pattern, MOD1);
    int patternHashB = rollingHash(pattern, MOD2);

    int B1 = 1;
    int B2 = 1;
    for(int i = 1; i < pattern.size(); i++)
    {
        B1 = (B1 * base) % MOD1, B2 = (B2 * base) % MOD2;
    }

    for(int i = 0; i < pattern.size() - 1; i++)
    {
        hashA = (hashA * base) % MOD1 + text[i] % MOD1;
        hashB = (hashB * base) % MOD2 + text[i] % MOD2;
    }

    for(int i = pattern.size() - 1; i < text.size(); i++)
    {
        hashA = (hashA * base) % MOD1 + text[i] % MOD1;
        hashB = (hashB * base) % MOD2 + text[i] % MOD2;

        if(hashA == patternHashA && hashB == patternHashB)
        {
            matches.push_back(i - pattern.size() + 1);
        }

        hashA = (hashA - ((text[i - pattern.size() + 1] * B1) % MOD1) + MOD1) % MOD1;
        hashB = (hashB - ((text[i - pattern.size() + 1] * B2) % MOD2) + MOD2) % MOD2;

    }

    g << matches.size() << "\n";
    for(int i = 0; i < matches.size(); i++)
    {
        g << matches[i] << " ";
        if(i + 1 == 1000)
            return 0;
    }

    return 0;

}
