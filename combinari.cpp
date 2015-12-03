#include<stdio.h>
using namespace std;


int n, p;
int st[20];

int back(int k, int masca)
{
    if(k == p+1)
    {
        for(int i=1;i<= p;i++)
            printf("%d ", st[i]);
        printf("\n");
    }
    else
    {
        if(k > 1)
            st[k] = st[k-1];
        else st[k] = 0;

        while(st[k]  < n)
        {
            st[k]++;

            if((masca | (1 << st[k])) != masca)
                back(k+1, masca | (1 << st[k]));
        }

    }
}

int main()
{
    freopen("combinari.in", "r", stdin);
    freopen("combinari.out", "w", stdout);
    scanf("%d %d", &n, &p);
    back(1, 0);
    return 0;
}
