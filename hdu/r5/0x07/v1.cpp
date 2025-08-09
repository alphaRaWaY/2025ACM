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
const int MaxN(5e3+5),MOD(1e9+7);
int fast_pow(int a,int b,int p)
{
    int ans(1);
    while(b > 0)
    {
		if(b & 1)
        {
			ans *= a;
            ans %= p;
    	}
		
        a *= a;
        a %= p;
		b >>= 1;
	}
    return ans;
}
int n,k;
int inv(int a){return fast_pow(a,MOD-2,MOD);}
void solve()
{
    cin>>n>>k;
    cout<<k*inv(n-k+1)%MOD<<endl;
}
signed main()
{
    // inc(i,1,10)cout<<i*inv(i)%MOD<<endl;
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
5
3 2
10 7
1000 278
1000000 114514
1000000000 20250406

1
750000007
15214385
93181493
131113678
*/