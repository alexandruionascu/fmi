#include<stdio.h>
using namespace std;


int n;
int st[20];

int back(int k, int masca)
{
    if(k == n+1)
    {
        for(int i=1;i<=n;i++)
            printf("%d ", st[i]);
        printf("\n");
    }
    else
    {
        st[k] = 0;
        while(st[k] < n)
        {
            st[k]++;

            if((masca | (1 << st[k])) != masca)
                back(k+1, masca | (1 << st[k]));
        }

    }
}

int main()
{
    freopen("permutari.in", "r", stdin);
    freopen("permutari.out", "w", stdout);
    scanf("%d", &n);
    back(1, 0);
    return 0;
}
