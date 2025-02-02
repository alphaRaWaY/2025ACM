#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int MAXN(2e5+5);
int n;
map<pii,int> ad;
int dis[MAXN];
vector<int> ed[MAXN];
void dfs(int a,int p,int d)
{
    dis[a]=d;
    for(int tmp:ed[a])
    {
        if(tmp==p)continue;
        dfs(tmp,a,d+1);
    }
}
void solve()
{
    ad.clear();
    cin>>n;
    inc(i,1,n)
    {
        ed[i].clear();
        dis[i]=0;
    }
    inc(i,1,n-2)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(!ad[{min(a,b),max(b,a)}])ad[{min(a,b),max(b,a)}]=i;
        else
        {
            int j(ad[{min(a,b),max(b,a)}]);
            ed[j].push_back(i);
            ed[i].push_back(j);
        }
        if(!ad[{min(a,c),max(a,c)}])ad[{min(a,c),max(a,c)}]=i;
        else
        {
            int j(ad[{min(a,c),max(a,c)}]);
            ed[j].push_back(i);
            ed[i].push_back(j);
        }
        if(!ad[{min(b,c),max(b,c)}])ad[{min(b,c),max(b,c)}]=i;
        else
        {
            int j(ad[{min(b,c),max(b,c)}]);
            ed[j].push_back(i);
            ed[i].push_back(j);
        }
    }
    dfs(1,0,0);
    int root(0);
    inc(i,1,n)
    {
        if(dis[i]>dis[root])root=i;
    }
    dfs(root,0,0);
    int ans(0);
    inc(i,1,n)
    {
        ans=max(ans,dis[i]);
    }
    cout<<ans+1<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
    system("pause");
}