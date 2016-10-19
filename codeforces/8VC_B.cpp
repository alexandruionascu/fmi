#include <bits/stdc++.h>
#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(a,b,c) for(int a=(b);a<=(c);++a)
#define ROF(a,b,c) for(int a=(b);a>=(c);--a)
#define dbg(x) cout<<#x<<" = "<<(x)<<"\n";
#define pii pair<int,int>
#define pil pair< pair< int, int> , ind >
#define mp make_pair
#define pb push_back
#define fi first.first
#define se first.second
#define ind second
#define ll long long
#define TATA NULL
using namespace std;
const int NMAX = 100002;
const int MAX = 200;
int freq[4];
char text[202];
int dp[MAX+1][MAX+1][MAX+1];
int n;
inline bool Can(const int x,const int y,const int z)
{
    if(x > MAX || y > MAX || z > MAX)
        return 0;
    if(dp[x][y][z]!=-1)
        return dp[x][y][z];
    if(x==freq[1] && y==freq[2] && z==freq[3])
        return 1;
    bool ans = 0;
    if(x>0)
        ans |= Can(x+1,y,z) | Can(x-1,y+1,z+1);
    if(y>0)
        ans |= Can(x,y+1,z) | Can(x+1,y-1,z+1);
    if(z>0)
        ans |= Can(x,y,z+1) | Can(x+1,y+1,z-1);

    dp[x][y][z] = ans;
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("date.in","r",stdin);
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(false);
    cin.tie(TATA);
    cin >> n;
    cin >> (text+1);
    FOR(i,1,n)
    {
        if(text[i]=='R')
            freq[1]++;
        if(text[i]=='G')
            freq[2]++;
        if(text[i]=='B')
            freq[3]++;
    }
    FOR(i,0,MAX)
        FOR(j,0,MAX)
            FOR(k,0,MAX)
                dp[i][j][k] = -1;
    if(Can(0,0,1))
        cout<<"B";
    if(Can(1,0,0))
        cout<<"R";
    if(Can(0,1,0))
        cout<<"G";

    return 0;
}
