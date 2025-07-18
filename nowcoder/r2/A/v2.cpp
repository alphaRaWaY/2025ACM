#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(5e5+5),MOD(998244353);
int n;
int nums[MaxN],cnt1;
int dp[MaxN][2];
int fast_pow(int a,int b)
{
    int base(a),res(1);
    while(b)
    {
        if(b&1)res=(base*res)%MOD;
        b>>=1;
        base=(base*base)%MOD;
    }
    return res;
}
int mod_mul(int a,int b)
{
    return ((a%MOD)*(b%MOD))%MOD;
}

int getPower(vector<int> segment)
{
    if(segment.empty())return 0;
    int now1(0),s(0);
    for(int tmp:segment)if(tmp==-1)now1++;
    return mod_mul(s,fast_pow(2ll,cnt1-now1));
}
void solve()
{
    cin>>n;
    cnt1=0;
    inc(i,1,n){
        cin>>nums[i];
        if(nums[i]==-1)cnt1++;
    }
    if(nums[1]!=1)dp[1][0]=0;
    if(nums[1]!=0)dp[1][1]=1;
    inc(i,2,n)
    {
        if(nums[i]==1){
            dp[i][0]=0;
            dp[i][1]=(dp[i-1][0]+1+dp[i-1][1])%MOD;
        }
        else if(nums[i]==0){
            dp[i][1]=0;
            dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
        }
        else{
            dp[i][1]=(dp[i-1][0]+1+dp[i-1][1])%MOD;
            dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
        }
    }
    inc(i,1,n)cout<<dp[i][1]<<" ";cout<<endl;
    inc(i,1,n)cout<<dp[i][0]<<" ";cout<<endl;
    cout<<(dp[n][1]+dp[n][0])%MOD<<endl;
}
signed main()
{
    // cout<<fast_pow(3,5)<<endl;
    ios::sync_with_stdio(false);
    int _=1;
    cin>>_;
    while(_--)solve();
}
/*
3
3
1 0 1
3
0 0 0
3
1 -1 1
*/