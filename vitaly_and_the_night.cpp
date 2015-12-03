#include<iostream>
#include<fstream>
#define FIN "vitaly.in"
using namespace std;

ifstream f(FIN);

int n, m;

int main()
{
    int x;
    int y;
    int people = 0;
    int sum = 0;
    cin >> n;
    cin >> m;
    for(int i=1; i <= n; i++)
    {

        for(int j=1; j <= m; j++)
        {
            cin >> x;
            cin >> y;
            if(x + y > 0)
                people++;
        }
    }

    cout << people;
    return 0;
}
