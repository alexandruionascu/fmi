#include <fstream>
#include <iostream>
#include <cstring>
#define FIN "palindrome.in"
#define ASCII 26
#define MAXN 200002
using namespace std;

ifstream f(FIN);


int n;
char str[MAXN];

int counter[ASCII];

int read()
{
    cin >> str;
    n = strlen(str);

    for (int i = 0; i < n; i++)
        counter[str[i] -'a']++;

    return 0;
}

int solve()
{
    int j = ASCII - 1;

    for (int i = 0; i < j; i++)
    {
        if (counter[i] % 2 == 0) continue;

        while(j > i && counter[j] % 2 == 0)
        {
            j--;
        }

        counter[i]++;
        counter[j]--;
    }

    int mid = -1;

    for (int i = 0; i < ASCII; i++)
    {
        if (counter[i] % 2 == 1)
        {
            mid = i;
        }

    }

    char a;
    int l;

    for (int i = 0; i < ASCII; i++)
    {
        if (mid == i) continue;
        a = i + 'a';
        l = counter[i] / 2;

        for (int j = 0; j < l; j++)
        {
            cout << a;
        }
    }

    if (mid != -1)
    {
        l = counter[mid];
        a = mid + 'a';
        for (int j = 0; j < l; j++)
         cout << a;
    }

    for (int i = ASCII - 1; i >= 0; i--)
    {
        if (mid == i) continue;

        a = i + 'a';
        l = counter[i] / 2;

        for (int j = 0; j < l; j++)
            cout << a;
    }

    cout << "\n";

    return 0;
}

int main()
{
    read();
    solve();

    return 0;
}
