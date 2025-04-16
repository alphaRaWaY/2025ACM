#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5),INF(1e18);
int n;
int nums[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    sort(nums+1,nums+1+n);
    
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}