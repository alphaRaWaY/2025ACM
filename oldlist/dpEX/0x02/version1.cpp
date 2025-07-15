#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e6+5),mod(998244353);
int f[MaxN],dp[MaxN];
signed main()
{
    ios::sync_with_stdio(false);
    inc(i,1,MaxN-5)
    {
        for(int j(i);j<=MaxN-5;j+=i)
        {
            f[j]++;
        }
    }
    int n;
    while(cin>>n)
    {
        inc(i,1,n)dp[i]=f[i];
        inc(i,2,n)
        {
            dp[i]=(dp[i-1]*2+dp[i])%mod;
        }
        cout<<(mod+dp[n]-dp[n-1])%mod<<endl;
    }
    system("pause");
}