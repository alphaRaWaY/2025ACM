#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int nums[MAXN],rr[MAXN],ll[MAXN];
int n;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<> >q;
bool vis[MAXN];
void solve()
{
    int ans(0);
    cin>>n;
    inc(i,1,n)vis[i]=false;
    inc(i,1,n)
    {
        cin>>nums[i];
        ans+=nums[i];
        rr[i]=i+1;
        ll[i]=i-1;
    }
    inc(i,1,n-1)q.push({nums[i]+nums[i+1],i});
    int cnt(0);
    while(cnt<n-1)
    {
        auto[val,pos] = q.top();
        int l=pos,r=rr[pos];
        q.pop();
        val=nums[l]+nums[r];
        if(vis[l]||vis[r]||r>=n||l<=0)continue;
        if(val>=0)break;
        vis[l]=vis[r]=true;
        // cout<<l<<"-"<<r<<":"<<val<<endl;
        ans-=val;
        rr[ll[l]]=rr[r];
        ll[rr[r]]=ll[l];
        // cout<<nums[ll[l]]<<"+"<<nums[rr[r]]<<"at"<<ll[l]<<endl;
        q.push({nums[ll[l]]+nums[rr[r]],ll[l]});
        cnt+=2;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    while(_--)solve();
}
/*
20
-14 74 -48 38 -51 43 5 37 -39 -29 80 -44 -55 59 17 89 -37 -68 38 -16
*/