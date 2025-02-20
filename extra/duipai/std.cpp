#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e5+5),INF(0x3f3f3f3f);
int n;
int nums[MAXN],dp[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i],dp[i]=INF;
    dp[1]=nums[1];
    inc(i,2,n)
    {
        int pos=upper_bound(dp+1,dp+1+n,nums[i])-dp;
        dp[pos]=nums[i];
    }
    int pos=lower_bound(dp+1,dp+1+n,INF)-dp-1;
    cout<<pos<<endl;
    // inc(i,1,pos)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
2
9
1 4 2 3 2 2 5 8 7
4
1 2 3 4
*/