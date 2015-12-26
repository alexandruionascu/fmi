#include<iostream>
#include<fstream>
#include<algorithm>
#include<string.h>
#include<vector>
#define FIN "date.in"
#define in cin
#define out cout

using namespace std;

ifstream f(FIN);
int n;
int p, q;
string word;

int read()
{
    in >> n;
    in >> p;
    in >> q;

    in >> word;

    return 0;
}

int solve(vector<int> v, int n)
{
    if(n == 0)
    {
        out << v.size() << "\n";
        int k = 0;
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 1; j <= v[i]; j++)
            {
                cout << word[k];
                k++;
            }

            out << "\n";
        }

        return 1;
    }
    else if(n > 0)
    {
        vector<int> v2 = v;

        v.push_back(p);
        int r1 = solve(v, n - p);
        if(r1 == 1)
        {
            return 1;
        }

        v2.push_back(q);
        int r2 = solve(v2, n - q);
        if(r2 == 1)
        {
            return 1;
        }
    }

}

int main()
{
    read();
    vector<int> v;
    int r = solve(v, n);

    if(r != 1)
    {
        out << -1;
    }


    return 0;
}
