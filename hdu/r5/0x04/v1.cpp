//Lucas求组合数
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


const int MaxN(1e5+5),MOD(1e9+7);
int k[MaxN],q[MaxN],fac[MaxN];
int n,m;
void solve()
{
    cin>>n>>m;
    inc(i,1,n)cin>>q[i];
    inc(i,1,m)cin>>k[i];
    int ans(1);
    inc(i,1,m)ans=(ans*fac[n])%MOD;
    cout<<ans<<endl;
}
void init()
{
    fac[1]=1;
    inc(i,2,MaxN-3)fac[i]=(fac[i-1]*i)%MOD;
}
signed main()
{
    init();
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
}
/*
3
2 1
1 0
3
2 1
1 0
3
1 1
0
1
*/