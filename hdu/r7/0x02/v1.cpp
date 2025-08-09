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
const int MaxN(1e6+5);
int n;
int s[MaxN],q[MaxN],r[MaxN];
void solve()
{
    cin>>n;
    inc(i,1,n)
    {
        cin>>q[i]>>r[i]>>s[i];
    }
    sort(s+1,s+1+n);
    sort(q+1,q+1+n);
    sort(r+1,r+1+n);

    int pos(0);
    inc(i,1,n-1)
    {
        if(
            s[i]+q[i]+r[i]<=0
            &&s[i+1]+q[i+1]+r[i+1]>=0
        ){
            pos=i;
            break;
        }
    }
    int remain(-(s[pos]+q[pos]+r[pos]));
    int s0=s[pos],q0=q[pos],r0=r[pos];
    debug0(remain);

    int tmp=min(remain,q[pos+1]-q[pos]);
    remain-=tmp;
    q0+=tmp;
    debug0(tmp);
    
    tmp=min(remain,r[pos+1]-r[pos]);
    remain-=tmp;
    r0+=tmp;
    debug0(tmp);
    
    tmp=min(remain,s[pos+1]-s[pos]);
    remain-=tmp;
    s0+=tmp;
    debug0(tmp);
    
    debug0(q0);
    debug0(r0);
    debug0(s0);

    int ans(0);
    inc(i,1,n)
    {
        ans+=llabs(r[i]-r0)+llabs(q[i]-q0)+llabs(s[i]-s0);
    }
    cout<<ans/2<<endl;
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
1
4
1 3 -4
0 0 0
2 -1 -1
3 0 -3
*/