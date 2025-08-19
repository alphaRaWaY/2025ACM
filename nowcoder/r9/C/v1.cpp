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
bool longest[30];
int w[30],level[30],in[30];
vector<int> from[30],to[30];
int n,m;
set<int> q;
void solve()
{
    cin>>n>>m;
    inc(i,1,n)
    {
        cin>>w[i];
        from[i].clear();
        to[i].clear();
        in[i]=0;
    }
    inc(i,1,m)
    {
        int a,b;
        cin>>a>>b;
        from[a].push_back(b);
        to[b].push_back(a);
        in[b]++;
    }
    int pos(1);
    while(!q.empty())
    {
        inc(i,1,n)
        {}
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}