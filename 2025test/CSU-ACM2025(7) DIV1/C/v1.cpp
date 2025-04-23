#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e5+5),MAXK(2e5+5),INF(0x3f3f3f3f);
int n;
int nums[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    int ans(0ll);
    inc(i,1,n)
    {
        if(nums[i]==nums[i-1])continue;
        if(nums[i]>nums[i-1])ans+=(nums[i]-nums[i-1])*(n-nums[i]+1);
        else ans+=(nums[i-1]-nums[i])*nums[i];
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}