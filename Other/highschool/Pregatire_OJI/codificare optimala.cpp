#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

#define FIN "text.txt"
#define FOUT "text.out"
#define MAXN 102

ifstream f(FIN);
ofstream g(FOUT);

int l[MAXN][MAXN];
char T [] = { 'a', 'a','a', 'c', 'a', 'a','a', 'c', 'b', 'b', 'd', 'e', 'f','d', 'e', 'f'};
int n = 16;

int nrCifre(int x)
{
    int nr = 0;
    while(x>0)
    {
        x = x/10;
        nr++;
    }

    return nr;
}

int seRepeta(int i,int j,int k)
{
    char s[MAXN];
    char s1[MAXN];

    strncpy(s, T+i, k);
    s[k] = NULL;
    s1[k] = NULL;

    for(int h=i+k; h<=j; h+=k)
    {
        strncpy(s1, T+h, k);
        if(strcmp(s,s1) != 0)
        {
            return 0;
        }
    }
    return 1;
}

int solve()
{
    for(int i=0;i<n;i++)
    {
        l[i][i] = 2;
    }
    for(int d=2;d<=n;d++)
    {
        for(int i = 0; i<=n-d;i++)
        {
            int j = i+d-1;
            //cazul I
            l[i][j] = d+1;
            l[j][i] = 0;

            //cazul II
            for(int k=i;k<j;k++)
            {
                if(l[i][k] + l[k+1][j] < l[i][j])
                {
                    l[i][j] = l[i][k] + l[k+1][j];
                    l[j][i] = k;
                }
            }

            //cazul III
            for(int k=1;k<=d/2;k++)
            {
                if(d % k == 0)
                {
                    if(seRepeta(i,j,k) == 1)
                    {
                        l[i][j] = nrCifre(d/k) + k;
                        l[j][i] = -k;
                        break;
                    }
                }
            }
        }
    }

    return 0;

}

int afiseaza(int i, int j)
{
    if(i == j)
    {
        cout<<T[i]<<1;
    }
    else
    {
        int k = l[j][i];
        char s[MAXN];
        if(k == 0)
        {
            strncpy(s,T+i,j-i+1);
            s[j-i+1] = NULL;
            cout<<s<<1;
        }
        else
        {
            if(k>0)
            {
                afiseaza(i,k);
                afiseaza(k+1,j);
            }
            else
            {
                strncpy(s,T+i,-k);
                s[-k] = NULL;
                cout<<s<<(j-i+1)/(-k);
            }

        }
    }

    return 0;
}

int write()
{
    for(int i=0;i<n;i++)
    {
        cout<<T[i];
    }

    return 0;
}

int writeL()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<l[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}
int main()
{
    solve();
    afiseaza(0,n-1);

    return 0;
}
