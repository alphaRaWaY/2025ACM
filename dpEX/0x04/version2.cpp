//纯dfs

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define ALL(x) x.begin(),x.end()
const int MaxN(1e4+5),MaxM(1e3+5),INF(0x3f3f3f3f);
int n,m,k;
int x[MaxN],y[MaxN],a[MaxN],b[MaxN];
map<int,bool> ps;
int dp[MaxN][MaxM*2];
void solve()
{
    memset(dp,INF,sizeof(dp));
    cin>>n>>m>>k;
    inc(i,0,n-1)
    {
        a[i]=1;
        b[i]=m;
        cin>>x[i]>>y[i];
    }
    a[n]=0,b[n]=m+1;
    inc(i,1,k)
    {
        int aa,bb,pos;
        ps[pos]=1;
        cin>>pos>>aa>>bb;
        a[pos]=aa;b[pos]=bb;
    }
    int index(0);
    inc(i,1,n)dp[0][i]=0;
    inc(i,1,n)
    {
        inc(j,1,m)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][max(0ll,j-x[i-1])]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j+y[i-1]]);
            dp[i][j]=min(dp[i][j],dp[i][max(0ll,j-x[i-1])]+1);
            inc(k,max(m-x[i-1],0ll),m)
            {
                dp[i][m]=min(dp[i][m],dp[i-1][k]+1);
            }
            inc(k,1,a[i])dp[i][k]=INF;
            inc(k,b[i],m)dp[i][k]=INF;
        }
    }
    int ans(INF);
    inc(i,1,m)ans=min(ans,dp[n][i]);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    //cin>>_;
    _=1;
    while(_--)solve();
}