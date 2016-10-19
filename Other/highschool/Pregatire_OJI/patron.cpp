#include<iostream>
#include<fstream>
using namespace std;

#define FIN "patron.in"
#define NMAX 204

ifstream f(FIN);
int n,L;
int g[NMAX];
int Nr[NMAX];
int Uz[NMAX][NMAX];
int Optim[NMAX];
int sol;
int V[NMAX];
int citire()
{
    f>>L;

    int i = 0;
    while(!f.eof())
    {
        f>>g[i];
        i++;
    }

    n=i-1;

    return 0;
}

int rezolva()
{
    Optim[0] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j = L-g[i];j>=0;--j)
        {
            if(Optim[j+g[i]]<Optim[j] + 1)
            {
                Optim[j+g[i]] = Optim[j] + 1;
                if(Optim[j+g[i]] > sol)
                {
                    sol = Optim[j+g[i]];
                }


            }
        }
    }


    return 0;
}

int afisare()
{
    cout<<sol<<endl;
}


int main()
{
    citire();
    rezolva();
    afisare();
    for(int i=1;i<=n;i++)
        cout<<V[i]<<" ";

    return 0;
}
