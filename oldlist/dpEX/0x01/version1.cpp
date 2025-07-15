#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(100);
int dp[2*MaxN][MaxN][MaxN],luv[MaxN][MaxN];
signed main()
{
    ios::sync_with_stdio(false);
    int m,n;
    cin>>m>>n;
    inc(i,1,m)inc(j,1,n)cin>>luv[i][j];
    inc(i,1,m+n)
    inc(x,1,m)
    inc(y,1,m)
    {
        if(x==y)continue;
        dp[i][x][y]=max(max(dp[i-1][x-1][y-1],dp[i-1][x][y]),max(dp[i-1][x][y-1],dp[i-1][x-1][y]));
        dp[i][x][y]+=luv[x][i-x]+luv[y][i-y];
    }
    int ans(0);
    ans=max(dp[m+n-1][m][m-1],dp[m+n-1][m-1][m]);
    cout<<ans<<endl;
    system("pause");
}