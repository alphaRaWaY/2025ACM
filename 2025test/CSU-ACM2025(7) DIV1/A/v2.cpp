#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(1e6+5),MAXM(2e3+5),INF(0x3f3f3f3f);
int n,m;
int nums[MAXN];
int cnt[MAXM];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<> >q;
void solve()
{
    cin>>n>>m;
    inc(i,1,n)cin>>nums[i];
    pair<int,int> ans(make_pair(0,INF));
    int left(1);
    int vis(0);
    inc(i,1,n)
    {
        if(!cnt[nums[i]])vis++;
        cnt[nums[i]]++;
        while(cnt[nums[left]]>1)
        {
            cnt[nums[left]]--;
            left++;
        }
        if(vis==m)
        {
            // cout<<left<<" "<<i<<endl;
            if(ans.second-ans.first>i-left)ans=make_pair(left,i);
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}