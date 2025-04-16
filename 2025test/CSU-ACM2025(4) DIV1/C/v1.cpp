#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5),INF(1e18);
int n,q;
bool w[MAXN],h[MAXN];
void solve()
{
    cin>>n>>q;
    int ans(n*n);
    int cw(0ll),ch(0ll);
    while(q--)
    {
        int type,pos;
        cin>>type>>pos;
        if(type==1)
        {
            int res(0);
            if(pos!=1)res+=(w[pos]^w[pos-1])?-1:1;
            if(pos!=n)res+=(w[pos]^w[pos+1])?-1:1;
            ans-=res*(n-ch);
            cw+=res;
            w[pos]=!w[pos];
        }
        else
        {
            int res(0);
            if(pos!=1)res+=(h[pos]^h[pos-1])?-1:1;
            if(pos!=n)res+=(h[pos]^h[pos+1])?-1:1;
            ans-=res*(n-cw);
            ch+=res;
            h[pos]=!h[pos];
        }
        cout<<ans<<endl;
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
100
3 3
1 2
2 3
1 2

*/