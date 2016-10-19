#include<iostream>
#include<fstream>
#include<strings.h>
#define FIN "strings.in"
using namespace std;

ifstream f(FIN);

int m;
int l;
int r;
int k;

string word;

int query()
{
    string sub = word.substr(l-1, r-l+1);
    for(int i=0; i < sub.size(); i++)
    {
        int position =  k % sub.size();
        word[l - 1 + ((i + position) % sub.size())] = sub[i];
    }

    return 0;
}

int main()
{

    cin >> word;
    cin >> m;

    for(int i=1; i<=m; i++)
    {
        cin >> l;
        cin >> r;
        cin >> k;
        query();
    }

    cout << word;
    return 0;
}
