#include<iostream>
#include<fstream>
#define FIN "array.in"
#define MAXN 200001
using namespace std;

ifstream f(FIN);

int main()
{
    long long aux = 0;
    long long value = 0;

    int n;
    cin >> n;
    int add = 0;
    int sub = 0;


    for(int i=1; i<=n; i++)
    {
        cin >> value;

        if(value > aux)
        {
            add += value - aux;
        }

        if(value < aux)
        {
            sub += aux - value;
        }

        aux = value;
    }

    cout << add + sub;
    return 0;
}
