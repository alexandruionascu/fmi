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
const int NMAX = 2002;
const int MAX =  10005;
int freq[MAX], cnt[MAX], a[NMAX], v[NMAX*NMAX];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("date.in","r",stdin);
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(false);
    cin.tie(TATA);
    int n;
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
    sort(a+1,a+n+1);
    FOR(i,1,n)
        FOR(j,i+1,n)
            cnt[a[j]-a[i]]++;
    ROF(i,5000,1)
        freq[i] = freq[i+1]+cnt[i];
    long long ans = 0;
    FOR(i,1,5000)
        FOR(j,1,5000)
        {
            if(i+j > 5000)
                continue;
            ans += 1LL*cnt[i]*cnt[j]*freq[i+j+1];
        }
    double c = n*(n-1)/2.0;
    cout<<setprecision(7)<<fixed;
    cout<<1.0*ans/(1.0*c*c*c)<<"\n";
    return 0;
}
