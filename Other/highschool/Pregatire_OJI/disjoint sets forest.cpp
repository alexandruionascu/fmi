#include<stdio.h>
#include<string.h>
using namespace std;

#define FIN "disjoint.in"
#define FOUT "disjoint.out"
#define MAXSIZE 100002

int n,m;
int father[MAXSIZE];
int ranc[MAXSIZE];

int find(int x)
{
    if(father[x] == x)
    {
        return x;
    }
    else
    {
        return find(father[x]);
    }
}

void uniune(int a, int b)
{
    int rootX = find(a);
    int rootY = find(b);

    if(rootX == rootY)
        return;
    if(ranc[rootX] > ranc[rootY])
        father[rootY] = rootX;
    else if(ranc[rootX] < ranc[rootY])
        father[rootX] = rootY;
    else
    father[rootX] = rootY;
    ranc[rootY]++;

}

int main()
{
    //INIT: set each element to point to itself
    freopen(FIN, "r",stdin);
    freopen(FOUT,"w",stdout);
    scanf("%d %d", &n,&m);

    for(int i=1;i<=n;i++)
    {
        father[i] = i;
    }
    int x,y,z;

    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d", &x,&y,&z);
        switch(x)
        {
        case 1:
            uniune(y,z);
            break;
        case 2:
            if(find(y) == find(z))
            {
                printf("DA\n");
            }
            else printf("NU\n");
            break;
        }
    }

    return 0;
}
