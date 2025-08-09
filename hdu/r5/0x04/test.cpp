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

const int MAXN(1e5+5);
int fac[MAXN],ver[MAXN];//存储阶乘,逆元
void prepare(int p)
{
    fac[0]=fac[1]=1;
    ver[1]=1;
    inc(i,2,MAXN)
    {
        fac[i]=(fac[i-1]*i)%p;
        ver[i]=((p-p/i)*ver[p%i])%p;
    }
}
int c(int m,int n,int p)
{
    return (fac[m]*ver[fac[n]]*ver[fac[m-n]])%p;
}
int lucas(int m,int n,int p)
{
    if(p==1)return 0;
    if(!n)return 1;
    return (c(m%p,n%p,p)*lucas(m/p,n/p,p))%p;
}
const int MaxN(1e5+5),MOD(1e9+7);
int pp[MaxN];
vector<int> primes;
void getPrimes()
{
    int MaxA=MaxN-3;
    pp[1]=1;
    // cout<<"ciallo world!"<<endl;
    inc(i,2,MaxA-5)
    {
        if(!pp[i]){
            primes.push_back(i);
            pp[i]=i;
        }
        for(int tmp:primes)
        {
            if(tmp*i>=MaxA)break;
            pp[tmp*i]=tmp;
            if(i%tmp==0)break;
        }
        // cout<<i<<endl;
    }
}


//下m+n,上n
int n,m;
int q[MaxN],k[MaxN];
void solve()
{
    // int n,m,p;
    // cin>>n>>m>>p;
    // cout<<endl;
    // cout<<lucas(m+n,n,p)<<endl;
    cin>>n>>m;
    inc(i,1,n)cin>>q[i];
    inc(i,1,m)cin>>k[i];
    cout<<(fac[n]*m)%MOD<<endl;
}
void test()
{
    debug0(lucas(5,3,MOD));
    debug0(fac[5]);
}
signed main()
{
    // 准备组合数
    prepare(MOD);
    // 准备质数
    // getPrimes();
    // 测试
    // test();
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