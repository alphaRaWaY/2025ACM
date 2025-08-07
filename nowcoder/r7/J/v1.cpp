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
#define ll int
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
const int MM(1e7+5);
vector<int>primes;
int pp[MM];
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
ll qmul(ll a,ll b,ll mod)//快速乘
{
    ll c=(long double)a/mod*b;
    ll res=(unsigned ll)a*b-(unsigned ll)c*mod;
    return (res+mod)%mod;
}
ll qpow(ll a,ll n,ll mod)//快速幂
{
    ll res=1;
    while(n)
    {
        if(n&1) res=qmul(res,a,mod);
        a=qmul(a,a,mod);
        n>>=1;
    }
    return res;
}
bool millerRabin(ll n)//Miller Rabin Test
{
    if(n<3||n%2==0) return n==2;//特判
    ll u=n-1,t=0;
    while(u%2==0) u/=2,++t;
    ll ud[]={2,325,9375,28178,450775,9780504,1795265022};
    for(ll a:ud)
    {
        ll v=qpow(a,u,n);
        if(v==1||v==n-1||v==0) continue;
        for(int j=1;j<=t;j++)
        {
            v=qmul(v,v,n);
            if(v==n-1&&j!=t){v=1;break;}//出现一个n-1，后面都是1，直接跳出
            if(v==1) return 0;//这里代表前面没有出现n-1这个解，二次检验失败
        }
        if(v!=1) return 0;//Fermat检验
    }
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
        cout<<n<<endl;
        int d=__gcd( llabs( cur2 - cur1 ), n);
        if(d > 1)return d;
        cur1=f(cur1);
        cur2=f(f(cur1));
    }
    return n;
}

int f(int t,int c,int x){return (t*t%x+c)%x;};
ll Pollard_Rho(ll x) {
  ll t = 0;
  ll c = rand() % (x - 1) + 1;
  ll s = t;
  int step = 0, goal = 1;
  ll val = 1;
  for (goal = 1;; goal <<= 1, s = t, val = 1) {
    for (step = 1; step <= goal; ++step) {
      t = f(t, c, x);
      val = val * abs(t - s) % x;
      // 如果 val 为 0，退出重新分解
      if (!val) return x;
      if (step % 127 == 0) {
        ll d = gcd(val, x);
        if (d > 1) return d;
      }
    }
    ll d = gcd(val, x);
    if (d > 1) return d;
  }
}

void getPrime()
{
    int n=MM-5;
    inc(i,2,n)
    {
        if(!pp[i])primes.push_back(i);
        for(int tmp:primes)
        {
            if(tmp*i>n)break;
            pp[tmp*i]=tmp;
            if(i%tmp==0)break;
        }
    }
}
void getPrimeFac(int a,map<int,int>& cnt)
{
    while(pp[a])
    {
        // debug0(a);
        cnt[pp[a]]++;
        a/=pp[a];        
    }
    cnt[a]++;
}
void dfs(int a,map<int,int>& cnt)
{
    if(millerRabin(a))
    {
        cnt[a]++;
        return;
    }
    if(a<=1e7)
    {
        getPrimeFac(a,cnt);
        return;
    }
    int tmp=Pollard_Rho(a);
    dfs(a/tmp,cnt);
    dfs(tmp,cnt);
}
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int>fa,fc;
    map<int,int>ca,cc;
    dfs(a,ca);
    dfs(c,cc);


    // for(auto[x,y]:ca)cout<<x<<" ";cout<<endl;
    // for(auto[x,y]:ca)cout<<y<<" ";cout<<endl;
    // for(auto[x,y]:cc)cout<<x<<" ";cout<<endl;
    // for(auto[x,y]:cc)cout<<y<<" ";cout<<endl;


    for(auto[x,y]:ca)fa.push_back(x);
    for(auto[x,y]:cc)fc.push_back(x);
    int i(0),j(0);
    int ans(1);
    while(i<fa.size()&&j<fc.size())
    {
        if(fa[i]==fc[j])
        {
            ans=qmul(ans,qpow(fa[i],min(ca[fa[i]]*b,cc[fc[j]]*d),MOD),MOD);
            i++;
            j++;
        }
        else if(fa[i]<fc[j])i++;
        else j++;
    }
    cout<<ans<<endl;
}
void test()
{
    inc(i,1,100)
    {        
        int tmp=getRand(1e17,1e18);
        debug0(tmp);
        map<int,int> cnt;
        dfs(tmp,cnt);
        for(auto[x,y]:cnt)cout<<x<<" ";cout<<endl;
        for(auto[x,y]:cnt)cout<<y<<" ";cout<<endl;
    }
}
signed main()
{
    getPrime();
    test();
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
5
2 3 3 2
4 2 8 1
6 2 9 1
7 1 11 1
10000000000000 1 10000000000000 1

*/