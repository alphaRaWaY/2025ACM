#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MaxN(1e4+5),MaxT(1e7+5);
int val[MaxN],weight[MaxN],dp[MaxT];
signed main()
{
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t>>n;
    for(int i(0);i<n;i++)
    {
        cin>>weight[i]>>val[i];
    }
    for(int i(0);i<n;i++)
    {
        for(int j(weight[i]);j<=t;j++)
        {
            dp[j]=max(dp[j],dp[j-weight[i]]+val[i]);
        }
    }
    cout<<dp[t]<<endl;
    system("pause");
}