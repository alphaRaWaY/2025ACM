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
const int MOD(998244353);
int n,k;
pair<int,int> e[20],ne[20];
int q[15];
pair<int,int> mull(pair<int,int> e1,pair<int,int> e2)
{
    return {e1.first*e2.first%MOD,e1.second*e2.second%MOD};
}
void solve()
{
    cin>>n>>k;
    inc(i,1,k)
    {
        cin>>q[i];
        e[q[i]]={q[i],1};
    }
    inc(i,1,n)
    {
        inc(j,1,k)
        {
            inc(_,0,15)
            {}
        }
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
2 2
848507702
10000 9
463950893


39/20
3714/77271
*/