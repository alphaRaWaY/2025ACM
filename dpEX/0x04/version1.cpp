//纯dfs

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e4+5),INF(0x3f3f3f3f);
int n,m,k;
int x[MaxN],y[MaxN];
map<int,int> dp[MaxN];
struct ppp
{
    int a,b,pos;
    bool operator > (const ppp& p )const 
    {
        return pos>p.pos;
    }
};
priority_queue<ppp,vector<ppp>,greater<ppp> > ps;
void solve()
{
    cin>>n>>m>>k;
    inc(i,0,n-1)cin>>x[i]>>y[i];
    inc(i,1,k)
    {
        ppp temp;
        cin>>temp.pos>>temp.a>>temp.b;
        ps.push(temp);
    }
    inc(i,1,n)
    {
        dp[0][i]=0;
    }
    inc(i,0,n-1)
    {
        if(dp[i].empty())
        {
            cout<<0<<endl<<k-ps.size()-1<<endl;
            return;
        }
        if(!ps.empty()&&i+1==ps.top().pos)
        {
            auto[a,b,reject] = ps.top();ps.pop();
            for(auto[h,dis]:dp[i])
            {
                if(h-y[i]>a&&h-y[i]<b)
                {
                    dp[i+1][h-y[i]]=dp[i+1][h-y[i]]?min(dp[i+1][h-y[i]],dis):dis;
                }
                for(int j(1);h+j*x[i]<b;j++)
                {
                    if(h+j*x[i]<=a)continue;
                    dp[i+1][h+j*x[i]]=dp[i+1][h+j*x[i]]?min(dp[i+1][h+j*x[i]],dis+j):dis+j;
                }
            }
        }
        else
        {
            for(auto[h,dis]:dp[i])
            {
                if(h-y[i]>0)
                {
                    dp[i+1][h-y[i]]=dp[i+1][h-y[i]]?min(dp[i+1][h-y[i]],dis):dis;
                }
                for(int j(1);h+j*x[i]<=m+x[i];j++)
                {
                    dp[i+1][min(h+j*x[i],m)]=dp[i+1][min(h+j*x[i],m)]?min(dp[i+1][min(h+j*x[i],m)],dis+j):dis+j;
                }
            }
        }
    }
    int ans(INF);
    for(auto[h,dis]:dp[n])
    {
        ans=min(ans,dis);
    }
    cout<<1<<endl<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    //cin>>_;
    _=1;
    while(_--)solve();
}