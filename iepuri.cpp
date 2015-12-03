#include<iostream>
#include<fstream>
#define MOD 666013
#define FIN "iepuri.in"
#define FOUT "iepuri.out"
#define MAXN 4
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

long long t, x, y, z, a, b, c, n;
long long C[4][4];
long long P[4][4];
long long A[4][4];

int printM()
{
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << "\n";
    }
    cout << "\n";
}


int multiply(long long A[][MAXN], int x, int y, long long B[][MAXN], int z, int t)
{
    long long aux[x+1][t+1];
    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=y; j++)
        {
            long long sum = 0;
            for(int k = 1; k <= y; k++)
            {
                sum = ( sum + (A[i][k] * B[k][j]) % MOD) % MOD;
            }

            aux[i][j] = sum;
        }
    }

    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=t; j++)
        {
            A[i][j] = aux[i][j];
        }
    }

    return 0;
}

int pow(long long M[][MAXN], int n)
{
    if(n == 1)
    {
        multiply(M, 3, 3, C, 3, 3);
        return 0;
    }
    else if(n % 2 == 0)
    {
        pow(M, n / 2);
        multiply(M, 3, 3, M, 3, 3);
    }
    else
    {

        pow(M, n / 2);
        multiply(M, 3, 3, M, 3, 3);
        multiply(M, 3, 3, C, 3, 3);

    }
}

int solve()
{
    //init
    for(int i=1; i <= 3; i++)
    {
        for(int j=1; j <= 3; j++)
        {
            if(i == j)
            {
                A[i][j] = 1;
            }
            else
            {
                A[i][j] = 0;
            }
        }
    }

    C[1][1] = 0, C[1][2] = 1, C[1][3] = 0;
    C[2][1] = 0, C[2][2] = 0, C[2][3] = 1;
    C[3][1] = c, C[3][2] = b, C[3][3] = a;
    P[1][1] = x; P[2][1] = y; P[3][1] = z;

    pow(A, n);

    multiply(A, 3, 3, P, 1, 3);

    g << A[1][1] << "\n";

    return 0;


}




int main()
{
    f >> t;
    for(int i=1; i<=t; i++)
    {
        f >> x; f >> y; f >> z;
        f >> a; f >> b; f >> c;
        f >> n;
        solve();
    }
    return 0;
}
