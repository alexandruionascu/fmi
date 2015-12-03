#include<iostream>
#include<fstream>
using namespace std;

#define FIN "kfib.in"
#define FOUT "kfib.out"
#define MOD  666013

ifstream f(FIN);
ofstream g(FOUT);

int n;
long long C[2][2] = {0, 1, 1, 1};
long long M[2][2] = {1, 0, 0, 1};

int multiply(long long A[2][2], long long B[2][2])
{
    long long x = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    long long y = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    long long z = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    long long t = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = t;
}

int fib(int x, long long A[2][2])
{
    if(x == 1)
    {
        multiply(A, C);
    }
    else if(x % 2 == 0)
    {
        fib(x / 2, A);
        multiply(A, A);

    }
    else
    {
        fib(x  / 2, A);
        multiply(A, A);
        multiply(A, C);
    }

}



int main()
{
    f >> n;
    fib(n-1 , M);
    g << M[1][1];
    return 0;
}
