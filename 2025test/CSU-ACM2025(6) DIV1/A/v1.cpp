#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(3e5+5),INF(0x3f3f3f3f);
int n;
int a[MAXN],b[MAXN],nums[MAXN],dp[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>a[i];
    inc(i,1,n)cin>>b[i];
    inc(i,1,n)nums[a[i]]=b[i];
    // inc(i,1,n)cout<<nums[i]<<" ";cout<<endl;
    inc(i,1,n)dp[i]=INF;
    dp[1]=nums[1];
    inc(i,2,n)
    {
        int pos(lower_bound(dp+1,dp+1+n,nums[i])-dp);
        dp[pos]=nums[i];
    }
    int ans(0);
    inc(i,1,n)if(dp[i]!=INF)ans++;else break;
    cout<<ans+n<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}