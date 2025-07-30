#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

// #define LOCAL
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

/*-------------------------------------------------*/

int mod_mul(int a,int b){return (a%MOD*(b%MOD))%MOD;}
int mod_add(int a,int b){return (a+b)%MOD;}
int mod_sub(int a,int b){return ((a-b)%MOD+MOD)%MOD;}

int n,m,k;
const int MOD(998244353),MaxN(2e5+5);
pair<int,int> road[MaxN*2];
vector<int> ed[MaxN];
void solve()
{
    cin>>n>>m>>k;
    inc(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        road[i]={u,v};
        road[i+n-1]={v,u};
        ed[u].push_back(i);
        ed[v].push_back(i+n-1);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
}
/*

5 6
0 0 0 0 0 0 
0 0 0 0 0 1
0 0 0 0 0 0
0 0 1 0 0 0
1 0 0 0 0 1

3 3
1 0 0 
0 0 0
0 0 0
*/
