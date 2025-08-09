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
int n,a,b,c;
array<int,4>f;
int g,h;
const int U=(1<<30)-1;
int get() {
    int ng,nh;
    ng=f[0]^((f[0]*(1<<16))&U);
    nh=ng^(ng>>5);
    f[3]=nh^((nh<<1)&U)^f[1]^f[2];

    g=ng;
    h=nh;
    inc(j,0,2)f[j]=f[j+1];
    return f[3];
}
void solve()
{
    cin>>n>>a>>b>>c;
    f[0]=a&U;
    f[1]=b&U;
    f[2]=c&U;
    int ans = 0;
    inc(i,0,n-1)
    {
        int f = get();
        if (f % (n - i)) ans = !ans;
    }
    cout << ans;
    inc (i, 1, n - 1) {
        int l = get()%n, r = get()%n, d = get()%n + 1;
        if (l > r) swap(l, r);
        if ((d * (r - l)) & 1) ans = !ans;
        cout << ans;
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
5
3 0 0 0
3 0 0 1
3 0 1 0
3 6 7 8
10 123 456 789
*/