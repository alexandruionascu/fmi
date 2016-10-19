#include<iostream>
#include<fstream>
#include<math.h>
#define FIN "swimming.in"
using namespace std;

ifstream f(FIN);


int main()
{
    int n;
    int x, y;
    cin >> n;
    cin >> x;
    cin >> y;

    int maxX = x;
    int maxY = y;
    int minX = x;
    int minY = y;

    for(int i=2; i<=n; i++)
    {
        cin >> x;
        cin >> y;

        minX = min(x, minX);
        minY = min(y, minY);

        maxX = max(x, maxX);
        maxY = max(y, maxY);

    }

    long long surface = abs(maxX - minX) * abs(maxY - minY);

    if(surface)
        cout << surface;
    else cout << -1;

    return 0;
}

