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
int weight[13][40];
int day[20]={
    0,
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31,
};
void solve()
{
    memset(weight,0,sizeof(weight));
    int k,n,m;
    cin>>k>>n>>m;
    int now((n-2025+(n-2025)/4+3)%7);
    inc(i,n,m)
    {
        inc(j,1,12)
        {
            inc(x,1,day[j]+(j==2&&i%4==0))
            {
                if(now%7!=0&&now%7!=6)weight[j][x]++;
                now=(now+1)%7;
            }
        }
    }
    vector<int> ans;
    inc(j,1,12)
    {
        // inc(x,1,day[j]+(j==2))cout<<weight[j][x]<<" ";
        inc(x,1,day[j]+(j==2))ans.push_back(weight[j][x]);
        // cout<<endl;
    }
    sort(ans.begin(),ans.end());
    int out(0);
    inc(i,0,k-1)out+=ans[i];
    cout<<out<<endl;
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
4
1 2025 2075
2 2025 2075
50 2025 2025
366 2045 2050
*/