//Lucas求组合数
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
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
//下m+n,上n
void solve()
{
    int n,m,p;
    cin>>n>>m>>p;
    prepare(p);
    // cout<<endl;
    cout<<lucas(m+n,n,p)<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
}

/*
2
1 2 5
2 1 5
*/

/*
5
4 5 29 
1 4 23
7 1 31
4 5 19
8 7 53
*/