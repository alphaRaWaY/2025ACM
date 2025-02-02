#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MaxN(1e5+5),mod(1e5+3);
ll dp[MaxN];
ll k,n;

ll solve(int n)
{
    if(n<0)return 0;
    else 
    {
        if(dp[n]!=0)return dp[n]%mod;
        else
        {
            ll ans(0);
            for(int i(1);i<=k;i++)
            {
                if(dp[n-i]!=0)ans+=dp[n-i];
                else ans+=solve(n-i);
            }
            return dp[n]=ans%mod;
        }
    }
}
int main()
{
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    dp[0]=1;
    cin>>k;
    for(int i(1000);i<MaxN;i+=1000)
    {
        solve(i);
    }
    for(int i(1);i<100;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    while(cin>>n)
    {
        cout<<solve(n)<<endl;
    }
    system("pause");
}