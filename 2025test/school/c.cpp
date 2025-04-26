#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n;
int nums[MAXN];
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    inc(i,1,n)
    {
        cout<<nums[i]*i-nums[i-1]*(i-1)<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
    // system("pause");
}
/*

*/