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
const int MOD(1e9+7),MaxN(5e5+5),MaxM(1e6+5);
int n,m,k;
struct node{
    int u,v,w;
}eds[MaxM];
vector<node> ed[MaxN];
void solve()
{
    cin>>n>>m>>k;
    inc(i,1,m)
    {
        cin>>eds[i].u>>eds[i].v>>eds[i].w;
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
/*
5
3 2 2
1 2 1
2 3 2

3 3 5
1 2 3
2 3 4
1 3 5

2 1 3
1 2 3

6 6 5
1 2 3
1 3 1
2 4 2
3 5 2
2 6 4
5 6 5

2 0 25

*/