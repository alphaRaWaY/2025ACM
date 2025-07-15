#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(2e5+5);
int n;
int nums[MAXN];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<> > q;
int rr[MAXN],ll[MAXN];
bool vis[MAXN];
int rm(int l,int r)
{
    rr[ll[l]]=rr[r];
    ll[rr[r]]=ll[l];
    vis[l]=vis[r]=true;
    return nums[l]+nums[r];
}
void solve()
{
    cin>>n;
    inc(i,1,n)cin>>nums[i];
    int ans(0);
    inc(i,1,n)
    {
        ans+=nums[i];
        rr[i]=i+1;
        ll[i]=i-1;
        if(i<n)q.push(make_pair(nums[i]+nums[i+1],make_pair(i,i+1)));
    }
    while(!q.empty())
    {
        auto top = q.top();
        q.pop();
        int l(top.second.first),r(top.second.second),sum(top.first);
        if(rr[l]!=r||ll[r]!=l||vis[l]||vis[r]||l<=0||r>n)continue;
        if(sum>=0)break;
        ans-=sum;
        // cout<<l<<"-"<<r<<":"<<sum<<endl;
        rm(l,r);
        int newL=ll[l],newR=rr[r];
        if(newL>=1&&newR<=n)q.push(make_pair(nums[newL]+nums[newR],make_pair(newL,newR)));
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