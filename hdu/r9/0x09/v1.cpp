#include<bits/stdc++.h>
using namespace std;
#define int __int128
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
#else
#define debug0(x)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif
int qmul(int a,int b,int mod)
{
    int c=(double)a/mod*b;
    int res=(unsigned int)a*b-(unsigned int)c*mod;
    return (res+mod)%mod;
}
int qpow(int a,int n,int mod)
{
    int res=1;
    while(n)
    {
        if(n&1) res=qmul(res,a,mod);
        a=qmul(a,a,mod);
        n>>=1;
    }
    return res;
}
const int mod = 998244353;
// 输出int128板子
string int128ToString(__int128 x) {
    if (x == 0) return "0";
    string result;
    bool is = x < 0;
    if (is) x = -x;
    while (x > 0) {
        result.push_back('0' + (x % 10));
        x /= 10;
    }
    if (is) result.push_back('-');
    reverse(result.begin(), result.end());
    return result;
}
int cal(int p)
{
    p--;
    switch (p%4)
    {
    case 0:
        return p;
    case 1:
        return 1;
    case 2:
        return p+1;
    case 3:
        return 0;
    default:
        break;
    }
    return 0;
}
vector<int> inv;//逆元数组
void initInv(int n,int mod)
{
    inv.assign(n+5,0);
    inv[1]=1;
    inc(i,2,n)
    {
        inv[i]=((mod-mod/i)*inv[mod%i])%mod;
    }
}
void solve()
{   
    long long tmp;
    cin>>tmp;
    int p = tmp;
    int k=(p-1)/119+1;
    // cout<<k<<endl;
    if(p<3000)
    {
        initInv(p,p);
        __int128 res(0);
        inc(i,1,p-1)
        {
            // cout<<int128ToString((__int128)(inv[i]+(1ll<<k))*(i+(1ll<<(2*k))))<<endl;
            res=res^((__int128)(inv[i]+(1ll<<k))*(__int128)(i+(1ll<<(2*k))));
        }
        cout<<int128ToString(res%mod)<<endl;
    }
    else
    {
        cout<<int128ToString(
            // (((p-1)&1)
            (long long)((1^((__int128)(p-1)*(p-1)))%mod
            +qpow(2,3*k,mod)*((p-1)&1)%mod
            +qpow(2,2*k,mod)*cal(p)%mod
            +qpow(2,k,mod)*cal(p)%mod)%mod
        )
        <<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    long long _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
5
3019
154534172
3023
480445179
3037
790978979
3041
118645777
3049
770468175
*/