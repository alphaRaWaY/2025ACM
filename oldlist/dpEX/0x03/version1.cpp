#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(300),INF(0x3f3f3f3f);
int energy[MaxN*2];
int dp[MaxN][MaxN];
signed main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans(-INF);
    inc(i,1,n)
    {
        cin>>energy[i];
        energy[i+n]=energy[i];
    }
    inc(i,2,n*2-1)//右端点
    {
        dec(j,i-1,max(1ll,i-n+1))//左端点
        {
            inc(k,j,i-1)
            {
                dp[j][i]=max(dp[j][i],dp[j][k]+dp[k+1][i]+energy[j]*energy[k+1]*energy[i+1]);
                ans=max(ans,dp[j][i]);
            }
        }
    }
    cout<<ans<<endl;
    system("pause");
}