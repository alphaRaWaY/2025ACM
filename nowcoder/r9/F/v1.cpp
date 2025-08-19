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
void solve() {
    int sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
    cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;
    cout<<max(llabs(tx1+tx2-sx1-sx2),llabs(ty1+ty2-sy1-sy2))<<endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
7
0 0 0 1 0 0 0 1
0 0 1 0 0 0 0 1
0 0 0 1 1 1 0 1
0 0 0 1 1 1 1 0
0 0 0 1 0 0 -1 0
0 0 1 0 0 1 -1 1
0 0 -1 0 40 50 40 51
*/