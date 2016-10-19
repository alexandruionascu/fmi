#include <fstream>
#include <iostream>
#include <algorithm>
#define FIN "queries.in"
#define MAXN 200002
using namespace std;

ifstream f(FIN);

int n, m;
long long a[MAXN];
long long b[MAXN];

int read()
{
    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

int search(int value)
{
    int left = 1;
    int right = n;
    int mid;
    int position = 0;

    while (left  <= right)
    {
        mid = (left + right) / 2;

        if (value >= a[mid])
        {
            position = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    return position;
}

int solve()
{
    sort(a + 1, a + n + 1);

    int x;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        cout << search(x) << " ";
    }

    return 0;
}

int main()
{
    read();
    solve();

    return 0;
}
