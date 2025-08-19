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
mt19937_64 rng(time(0));
int getRand(int l,int r)
{
    return rng()%(r-l+1)+l;
}
/**
 * 快速幂
 */
int fast_pow(int a,int b,int p)
{
    int res(1);
    while(b)
    {
        if(b&1)res=(res*a)%p;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
/**
 * 素性测试
 */
bool millerRabin(int n)
{
    if(n<2)return 0;
    if(n%2==0)return n==2;
    static vector<int>test={2,3,5,7,11,13,17,19,23,29,31,37};
    int a=n-1;
    int b=0;
    for(;a%2==0;a/=2)b++;
    auto chk=[&](int x){
        if(n%x==0)return 1;
        int p=fast_pow(x%n,a,n);
        if(p==1)return 1;
        for(int i=0;i<b;i++){
            if(p==n-1)return 1;
            p=p*p%n;
        }
        return 0;
    };
    for(int x:test)if(!chk(x))return 0;
    return 1;
}
/**
 * Pollard Rho求非平凡因子
 */
int pr(int n)
{
    if(n == 4)return 2;
    int c(rng());
    auto f = [n, c](int x)->int{
        return ( x * x % n + c ) % n;
    };
    int cur1=f(0), cur2=f(f(0));
    while(cur1 ^ cur2)
    {
        int d=__gcd( llabs( cur2 - cur1 ), n);
        if(d > 1)return d;
        cur1=f(cur1);
        cur2=f(f(cur1));
    }
    return n;
}


void solve()
{
    int n;
    cin>>n;
    cout<<pr(n)<<endl;
}
signed main()
{
    debug0(fast_pow(2,6,200));
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}