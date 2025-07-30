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
const int MaxN(1e5+5);
int n;
int nums[MaxN],cnt[MaxN],ans[MaxN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    inc(j,0,30)
    {
        int a(0),b(0),c(0),d(0);
        inc(i,1,n)
        {
            if((cnt[i]&1)&&(nums[i]&1))a++;
            if((cnt[i]&1)&&!(nums[i]&1))b++;
            if(!(cnt[i]&1)&&(nums[i]&1))c++;
            if(!(cnt[i]&1)&&!(nums[i]&1))d++;
            cnt[i]+=nums[i]&1;
            nums[i]>>=1;
        }
        ans[j]=(a*b+c*d)<<j;
    }
    // debug1(ans,0,20);
    int cnt(0);
    inc(j,0,30)cnt+=ans[j];
    cout<<cnt<<endl;
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
3
5 3 9
*/