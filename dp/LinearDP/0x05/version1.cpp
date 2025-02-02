#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(105),INF(0x3f3f3f3f);
int n,m;
int nums[MAXN][MAXN];
int dp[MAXN];
void solve()
{
    cin>>n>>m;
    inc(i,1,n)
    {
        inc(j,1,m)
        {
            cin>>nums[i][j];
        }
    }
    // inc(i,1,n)
    // {
    //     inc(j,1,m)
    //     {
    //         cout<<nums[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    memset(dp,0,sizeof(dp));
    inc(i,1,n)
    {
        dec(j,m,1)
        {
            dp[i]=max(dp[j-1]+nums[i][j],dp[j]);
        }
    }
    cout<<dp[m]<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
    system("pause");
}

/*
3 5
7 23 -5 -24 16
5 21 -4 10 23
-21 5 -4 -20 20
*/