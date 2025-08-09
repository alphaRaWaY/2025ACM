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
// 总价值
int ans(0);
int a,b,c,d;
vector<int>v[5],pv[5];
int cur[5];
void solve()
{
    ans=0;
    inc(i,0,4)cur[i]=0;
    cin>>a>>b>>c>>d;
    inc(i,1,4)
    {
        int n;
        cin>>n;
        vector<int> nv(n);
        inc(j,0,n-1)cin>>nv[j];
        v[i]=nv;
        sort(v[i].begin(),v[i].end(),greater<>());
    }
    inc(i,1,4)debug1(v[i],0,v[i].size()-1);
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
3
1 2 1 0
1 3
1 10
1 6
0
3 0 2 0
9 2 9 10 3 1 1 2 10 7
3 14 10 14
1 21
0
0 1 2 0
2 10 6
1 2
3 24 27 9
2 8 16
*/