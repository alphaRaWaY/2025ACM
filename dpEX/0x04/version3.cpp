//纯dfs

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define ALL(x) x.begin(),x.end()
const int MaxN(1e4+5),MaxM(1e3+5),INF(0x3f3f3f3f);
int n,m,k;
int x[MaxN],y[MaxN],a[MaxN],b[MaxN];
map<int,bool> ps;
int dp[MaxN][MaxM];
void debug()
{
    dec(j,m,0)
    {
        inc(i,0,n)
        {
            if(dp[i][j]>=INF)cout<<"* ";
            else cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
void solve()
{
   memset(dp,INF,sizeof(dp));
   cin>>n>>m>>k;
   inc(i,0,n-1)cin>>x[i]>>y[i];
   inc(i,1,k)
   {
        int pos,aa,bb;
        cin>>pos>>aa>>bb;
        ps[pos]=true;
        a[pos]=aa;b[pos]=bb;
   }
   inc(i,1,n)dp[0][i]=0;
   inc(i,1,n)
   {
        inc(j,1,m-1)
        {
            if(j>=1+x[i-1])
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-x[i-1]]+1);
                dp[i][j]=min(dp[i][j],dp[i][j-x[i-1]]+1);
            }    
        }
        inc(j,1,m-1)if(j<=m-y[i-1])dp[i][j]=min(dp[i][j],dp[i-1][j+y[i-1]]);
        inc(j,1,m)
        {
            dp[i][m]=min(dp[i][m],dp[i-1][j]+(m-j-1)/x[i-1]+1);
        }
        if(ps[i])
        {
            inc(j,1,a[i])dp[i][j]=INF;
            inc(j,b[i],m)dp[i][j]=INF;
            bool isOK(false);
            inc(j,1,m)
            {
                if(dp[i][j]<INF)
                {
                    isOK=true;
                    break;
                }
            }
            if(!isOK)
            {
                int ans(0);
                inc(j,0,i)
                {
                	if(ps[j])ans++;
                }
                cout<<0<<endl<<ans<<endl;
                //debug();
                return;
            }
        }
   }
   //debug();
   int ans(INF);
   inc(i,1,m)
   {
        ans=min(ans,dp[n][i]);
   }
   cout<<1<<endl<<ans<<endl;
}
signed main()
{
    //ios::sync_with_stdio(false);
    int _;
    //cin>>_;
    _=1;
    while(_--)solve();
    //system("pause");
}