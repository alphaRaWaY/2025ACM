#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int MaxN(2e5+5);
int n,m,d1,d2;
vector<pii> ed[MaxN];
int dis[MaxN],rDis[MaxN],lDis[MaxN];
void dfs(int parent,int root)
{
    for(auto[w,p]:ed[root])
    {
        if(p==parent)continue;
        dis[p]=dis[root]+w;
        dfs(root,p);
    }
}
void solve()
{
    cin>>n>>m;
    inc(i,1,m)
    {
        int a,b,w;
        cin>>a>>b>>w;
        ed[a].push_back({w,b});
        ed[b].push_back({w,a});
    }
    dis[1]=0;
    dfs(0,1);
    int maxDis(0);
    inc(i,1,n)
    {
        if(dis[i]>maxDis)
        {
            maxDis=dis[i];
            d1=i;
        }
    }
    dis[d1]=0;
    dfs(0,d1);
    maxDis=0;
    inc(i,1,n)
    {
        if(dis[i]>maxDis)
        {
            maxDis=dis[i];
            d2=i;
        }
        lDis[i]=dis[i];
    }
    dis[d2]=0;
    dfs(0,d2);
    inc(i,1,n)rDis[i]=dis[i];
    inc(i,1,n)dis[i]=min(rDis[i],lDis[i]);
    int ans(0);
    // inc(i,1,n)cout<<dis[i]<<" ";cout<<endl;
    inc(i,1,n)ans=max(ans,dis[i]);
    cout<<maxDis+ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
    // system("pause");
}
/*
4 3
1 2 1
2 3 1
3 4 1

6 5
1 3 1000
1 4 10
2 4 100
4 5 50
4 6 100
*/