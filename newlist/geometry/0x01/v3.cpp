// https://www.luogu.com.cn/problem/P1652

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define debug1(c,l,r) inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr) inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
const int MaxN(55);
int n;
int x[MaxN],y[MaxN],r[MaxN];
int ans[MaxN][2];
void solve()
{
    int n;
    cin>>n;
    inc(i,1,n)cin>>x[i];
    inc(i,1,n)cin>>y[i];
    inc(i,1,n)cin>>r[i];
    inc(j,0,1)
    {   
        int a,b;
        cin>>a>>b;
        inc(i,1,n)
        {
            ans[i][j]=((x[i]-a)*(x[i]-a)+(y[i]-b)*(y[i]-b)<r[i]*r[i]);
        }
    }
    int cnt(0);
    inc(i,1,n)cnt+=ans[i][0]^ans[i][1];
    cout<<cnt<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    while(_--)solve();
}