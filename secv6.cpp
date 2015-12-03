#include<iostream>
#include<fstream>
#include<stack>
#include<algorithm>
#define FIN "secv6.in"
#define FOUT "secv6.out"
#define N 8192
#define MAXSIZE 16000001
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

long long n;
int x[N + 1];
int a[MAXSIZE];
int counter;
stack<int> st;


int main()
{
    f >> n;

    int m = n < N ? n : N;
    for(long long i = 0; i < m; i++)
    {
        f >> x[i];
    }

    for(long long i = 0; i < n; i++)
    {
        a[i] = i + (x[i / N] ^ x[i % N]);
    }


    for(long long i = 0; i < n; i++)
    {
        while(!st.empty() && st.top() < a[i])
            st.pop(), counter++;

        if(!st.empty())
            counter++;

        if(st.empty() || st.top() != a[i])
            st.push(a[i]);
    }

    g << counter;

    return 0;

}
