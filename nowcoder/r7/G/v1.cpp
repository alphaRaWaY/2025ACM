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
const int MM(1e7+5);
vector<int>primes;
int pp[MM];
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
        debug0(a);
        cnt[pp[a]]++;
        a/=pp[a];        
    }
    cnt[a]++;
}
int getPrimeFac(int a)
{
    int tmp(0);
    while(pp[a])
    {
        tmp++;
        a/=pp[a];        
    }
    tmp++;
    return tmp;
}
vector<int> good;
void solve()
{
    int n;
    cin>>n;
    inc(i,0,n/2-1)cout<<good[i]<<" ";cout<<endl;
}
void test()
{
    int tmp;
    while(cin>>tmp)
    {        
        cout<<getPrimeFac(tmp)<<endl;
    }
}
void init()
{
    int cur(2);
    while(good.size()<5e5)
    {
        if(getPrimeFac(cur)&1)good.push_back(cur);
        cur++;
    }
}
signed main()
{
    getPrime();
    // test();
    init();
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}