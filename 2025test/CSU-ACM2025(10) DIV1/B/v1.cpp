#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
vector<vector<int> >nums;
const int MAXN(1e5+5);
int cnt[MAXN];
int n,m;
void solve()
{
    cin>>n>>m;
    nums.resize(n+1);
    for(vector<int>& v:nums)v.resize(m+1);
    inc(i,1,n)inc(j,1,m)cin>>nums[i][j];
    // inc(i,1,n)
    // {
    //     inc(j,1,m)cout<<nums[i][j]<<" ";
    //     cout<<endl;
    // }
    int top(nums[1][1]);
    cnt[1]++;
    while(true)
    {
        cnt[top]++;
        inc(i,1,n)cout<<cnt[i]<<" ";cout<<endl;
        cout<<"#"<<top<<endl;
        // cout<<top<<endl;
        if(cnt[top]>=m)break;
        top=nums[top][cnt[top]+1];
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
