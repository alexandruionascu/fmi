#include<iostream>
#include<fstream>
#include<string.h>
#define MAXN 102
#define FIN "2char.in"
using namespace std;

ifstream f(FIN);

int n;
string words[MAXN];


int check(string word, int a, int b)
{
    for(int i = 0; i < word.size(); i++)
        if(!(word[i] == char(a) || word[i] == char(b)))
            return 0;

    return word.size();
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> words[i];
    }
    int maxx = 0;
    for(int i = (int)'a' ; i <= int('z'); i++)
    {
        for(int j = (int)'a' ; j <= int('z'); j++)
        {
            int sum = 0;
            for(int k = 1; k <= n; k++)
            {
                sum += check(words[k], i, j);
            }

            if(maxx < sum)
                maxx = sum;
        }
    }

    cout << maxx;
    return 0;
}
