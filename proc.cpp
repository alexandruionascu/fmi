#include<iostream>
#include<fstream>
#define FIN "proc.in"
#define FOUT "proc.out"
using namespace std;

ifstream f(FIN);
ofstream g(FOUT);

int n, k, p;

bool possible(unsigned int x)
{
    unsigned int cores = 1;
    unsigned int time = 0;
    int t1 = k;
    int t2 = n - k;

    for(int i=1; i<=p; i++)
    {

        while(time + i * 2 <= x && t2)
        {
            time += i * 2;
            t2--;
        }

        while(time + i <= x && t1)
        {
            time += i;
            t1--;
        }

        cores++;
        time = 0;

        if(t1 == 0 && t2 == 0)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    f >> n;
    f >> k;
    f >> p;


    unsigned int left = 0;
    unsigned int right = 2 * n;

    int step, i;
    for(step = 1; step < right; step <<= 1);

    for(i = 2 * n; step != 0; step >>= 1)
    {
        if((i - step) > 0 && possible(i - step))
            i -= step;
    }

    g << i;


    return 0;

}
