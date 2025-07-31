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
const int MaxN(5e5+5),MOD(998244353);
int n,m;
int inv[MaxN];
int nums1[MaxN],nums2[MaxN];
void solve()
{
    cin>>n>>m;
    int ans(1);

    nums1[1]=n*(n-1)%MOD;
    nums2[1]=m%MOD;
    inc(i,2,m)
    {
        nums1[i]=((n-1)*n%MOD+MOD-i+1)%MOD*inv[i]%MOD*nums1[i-1]%MOD;
        nums2[i]=(m-i+1)*inv[i]%MOD*nums2[i-1]%MOD;
    }
    inc(i,1,m)
    {
        ans=(ans+nums1[i]*nums2[i]%MOD)%MOD;
    }
    cout<<ans<<endl;
}
void init()
{
    inv[1]=1;
    inc(i,2,MaxN-3)
    {
        inv[i]=((MOD-MOD/i)*inv[MOD%i])%MOD;
    }
}
signed main()
{
    init();
    // inc(i,1,10)cout<<inv[i]*i%MOD<<" ";cout<<endl;
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}