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
int a,b;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("date.in","r",stdin);
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(false);
    cin.tie(TATA);
    cin >> a >> b;
    int l = 0,r = 1<<30,mid,ans;
    while(l<=r)
    {
        mid = (l+r)/2;
        int nr3 = mid/3-mid/6;
        int nr2 = mid/2-mid/6;
        int nr6 = mid/6;
        if(nr3<b)
            nr6 -= b-nr3;
        if(nr2<a)
            nr6 -= a-nr2;
        if(nr6>=0)
        {
            ans= mid;
            r = mid-1;
        }
        else
            l = mid +1;
    }

    cout<<ans<<"\n";
    return 0;
}
