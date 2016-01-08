#include<stdio.h>
#include<vector>
 
#define FIN "hashuri.in"
#define FOUT "hashuri.out"
#define MOD 666013
using namespace std;
 
vector<int> h[MOD];
int n;
 
vector<int>::iterator hash_find(int x)
{
    int list = x % MOD;
    vector<int>::iterator it;
    for(it=h[list].begin();it!=h[list].end();it++)
    {
        if(*it == x)
        {
            return it;
        }
    }
 
    return h[list].end();
}
 
void hash_insert(int x)
{
    int list = x % MOD;
 
    if(hash_find(x) == h[list].end())
        h[list].push_back(x);
 
}
 
void hash_erase(int x)
{
    int list = x % MOD;
    vector<int>::iterator it = hash_find(x);
     if(it != h[list].end())
        h[list].erase(it);
 
}
 
int main()
{
    int x,y;
    freopen(FIN,"r",stdin);
    freopen(FOUT,"w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        switch(x)
        {
            case 1:
                hash_insert(y);
                break;
            case 2:
                hash_erase(y);
                break;
            case 3:
                printf("%d\n",(hash_find(y)!=h[y%MOD].end()));
                break;
        }
    }
 
    return 0;
}