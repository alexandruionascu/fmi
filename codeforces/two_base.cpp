#include<iostream>
#include<fstream>
#define FIN "twobase.in"
using namespace std;

ifstream f(FIN);

int main()
{
    long long A = 0;
    long long B = 0;

    int n, base;
    int x;

    cin >> n;
    cin >> base;

    for(int i=1; i <= n; i++)
    {
        cin >> x;
        A = A * base + x;
    }

    cin >> n;
    cin >> base;

    for(int i=1; i <= n; i++)
    {
        cin >> x;
        B = B * base + x;
    }

    if(A == B)
        cout << "=\n";
    else if(A > B)
        cout << ">\n";
    else cout <<"<\n";

    return 0;
}
