#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5),INF(1e18);
int n;
int nums[MAXN];
int cal(int a)
{
    return a*(a+1)/2;
}
int ans(0);
map<int,int> l;
void solve()
{
    cin>>n;
    inc(i,1,n)
    {
        int tmp;
        cin>>tmp;
        int length = i-l[tmp]-1;
        ans+=cal(length);
        l[tmp]=i;
    }
    for(auto[x,y]:l)
    {
        int length=n-y;
        ans+=cal(length);
    }
    cout<<cal(n)*l.size()-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}