#include<iostream>
#include<fstream>
#define in cin
#define out cout
#define FIN "date.in"
#include<string.h>
#include<deque>
using namespace std;

ifstream f(FIN);

string a, b;
deque<bool> d;

int sum;
int total;

int main()
{

    in >> a;
    in >> b;


    for(int i = 0; i < a.size(); i++)
    {
        if(b[i] == '1')
        {
            d.push_back(1);
        }
        else
        {
            d.push_back(0);
        }
    }

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
        {
            sum++;
        }
    }

    total += sum;

    for(int i = a.size(); i < b.size(); i++)
    {
        bool oldBack = d.back();
        bool oldFront = d.front();

        if(b[i] == '1')
        {
            d.push_back(1);
        }
        else
        {
            d.push_back(0);
        }

        d.pop_front();

        if(d.back() != oldBack)
        {
            sum++;
        }

        if(oldFront == d.front())
        {
            sum--;
        }

        total += sum;
    }

    out << total;
    return 0;
}
