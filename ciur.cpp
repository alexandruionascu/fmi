#include<stdio.h>
#define FIN "ciur.in"
#define FOUT "ciur.out"
#define MAXN 2000002
using namespace std;


bool prim[MAXN];

int main()
{
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    int n;
    scanf("%d", &n);

    int counter = 0;
    for(int i=3; i<=n; i += 2)
    {
        prim[i+1] = 1;

        if(prim[i] == 0)
        {
            counter++;
            for(int j = i * i; j <= n; j += i)
            {
                prim[i] = 1;
            }
        }

    }

    printf("%d", counter);

    return 0;

}
