#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

#define LOCAL
#ifdef LOCAL
#define debug0(x) cout<<"[DEBUG] "<<#x<<"="<<x<<endl
#define debug1(c,l,r) cout<<"[DEBUG] "<<#c<<" : ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr)cout<<"[DEBUG]"<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
ostream& operator<< (ostream& o,const pair<int,int>& a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
#else
#define debug0(x)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif
const int MaxN(5e3+5),MOD(998244353);
int fast_pow(int a,int b)
{
    int ans(1);
    while(b)
    {
        if(b&1)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

int n;
vector<int> ed[MaxN];
/**
 * i：第i个点
 * j：剩下j个点的方案数
 * k：当前结点是否被删除（0为所有方案数,1为被删）
 */
array<array<array<int,2>,MaxN>,MaxN> dp;
array<int,MaxN>sz;
void getSz(int index,int pa)
{
    sz[index] = 1;
    for(int tmp : ed[index])
    {
        if(tmp == pa)continue;
        getSz( tmp , index );
        sz[index] += sz[tmp];
    }
}
void dfs(int index,int pa)
{
    // 初始dp[i][j][0]只保存不删除当前结点的方案数
    // 当前结点被删除
    dp[index][0][1] = 1;
    // 当前结点不被删除
    dp[index][1][0] = 1;
    for(int tmp:ed[index])
    {
        array<array<int,2>,MaxN> ndp;
        if(tmp == pa)continue;
        dfs(tmp,index);
        inc(i,0,sz[index])inc(j,0,sz[index])
        {
            if(j+i>sz[index]) continue;
            ndp[i+j][1] = dp[index][i][1] * dp[tmp][j][0] % MOD;
            ndp[i+1][0] = dp[index][i][0] * dp[tmp][j][1] % MOD;
        }
        dp[index] = ndp;
    }
    inc(i,0,sz[index]) dp[index][i][0] = ( dp[index][i][0] + dp[index][i][1] ) % MOD;

}
void solve()
{
    cin>>n;
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    getSz(1,0);
    int x(0),y(0);
    inc(i,1,sz[1])x=(x+(dp[1][i][0]*i)%MOD)%MOD;
    inc(i,1,sz[1])y=(y+dp[1][i][0])%MOD;

    cout<<x*fast_pow(y,MOD-2)%MOD<<endl;
    // debug1(sz,1,n);
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}

/*
3
1 2
2 3
*/