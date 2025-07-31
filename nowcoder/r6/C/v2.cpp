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

const int MaxN(5e5+5),MOD(998244353);
int t[MaxN][4],dt[MaxN][4];
void solve()
{
    int n;
    cin>>n;
    cout<<t[n][3]<<endl;
}
void test()
{
    // debug2(t,1,0,30,3);
}
void init()
{
    int n=MaxN-3;
    t[1][0]=t[0][0]=1;
    inc(i,2,n)t[i][0]=(t[i-1][0]*i)%MOD;
    inc(i,1,3)t[1][i]=1;
    // inc(i,2,n)
    // {
    //     t[i][1]=dt[i-1][1]+(i-1)*t[i-1][1];
    //     t[i][2]=dt[i-1][2]+(i-1)*t[i-1][2];
    //     t[i][3]=dt[i-1][3]+(i-1)*t[i-1][3];

    //     dt[i][1]=t[i][1]+t[i][0];
    //     dt[i][2]=t[i][2]+2*t[i][1]+t[i][0];
    //     dt[i][3]=t[i][3]+3*t[i][2]+3*t[i][1]+t[i][0];
    // }
    inc(i,2,n)
    {
        t[i][1] = (( t[i-1][1] + t[i-1][0] ) % MOD + (i-1) * t[i-1][1]%MOD)%MOD;
        t[i][2] = (( t[i-1][2] + 2*t[i-1][1] % MOD + t[i-1][0]%MOD ) % MOD + (i-1)*t[i-1][2]%MOD)%MOD;
        t[i][3] = (( t[i-1][3] + 3*t[i-1][2] % MOD + 3*t[i-1][1]%MOD + t[i-1][0]%MOD )%MOD + (i-1)*t[i-1][3]%MOD)%MOD;
    }
}
signed main()
{
    init();
    test();
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
2
3
3741
*/
/*
1        tot=1
1 1      tot=9
2 3 1    tot=53
6 11 6 1         tot=320
24 50 35 10 1    tot=2134
120 274 225 85 15 1      tot=15918
720 1764 1624 735 175 21 1       tot=132474
5040 13068 13132 6769 1960 322 28 1      tot=1222032
40320 109584 118124 67284 22449 4536 546 36 1    tot=12404856
362880 1026576 1172700 723680 269325 63273 9450 870 45 1         tot=137607096
*/