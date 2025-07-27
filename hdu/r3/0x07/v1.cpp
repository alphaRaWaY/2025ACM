#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(2e5+5),INF(0x3f3f3f3f3f);
int n;
pair<int,int> nums[MaxN];
void solve()
{
    int l(-INF),r(INF);
    cin>>n;
    inc(i,1,n)
    {
        cin>>nums[i].first>>nums[i].second;
    }
    sort(nums+1,nums+1+n);
    set<int> ans;
    inc(i,1,n)
    {
        if(!(nums[i].first>l&&nums[i].first<=r))ans.insert(nums[i].first);
        if(!(nums[i].second>l&&nums[i].second<=r))ans.insert(nums[i].second);
    }
    cout<<ans.size()+1<<endl;
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
7
1
1 6
4
0 12
4 13
6 13
12 13
0
3
-1 1
0 1
0 2
2
0 1
0 1
4
2 3
5 8
1 4
6 7
4
2 3
4 8
1 5
6 7
*/