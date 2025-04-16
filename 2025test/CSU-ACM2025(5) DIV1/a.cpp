#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5),INF(1e18);
int n,q;
int pos[MAXN],nums[MAXN];
int getLIndex(int a)
{
    return lower_bound(pos,pos+1+n,a)-pos;
}
int getRIndex(int a)
{
    return upper_bound(pos,pos+1+n,a)-pos-1;
}
void solve()
{
    pos[0]=-INF;
    cin>>n;
    pos[n+1]=INF;
    inc(i,1,n)cin>>pos[i];
    inc(i,1,n)cin>>nums[i];
    partial_sum(nums,nums+1+n,nums);
    cin>>q;
    while(q--)
    {
        int L,R;
        cin>>L>>R;
        L=getLIndex(L);
        R=getRIndex(R);
        // cout<<L<<"-"<<R<<endl;
        cout<<(R>=L)*(nums[R]-nums[L-1])<<endl;
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
4
1 3 5 7
1 2 3 4
4
1 1
2 6
0 10
2 2
*/