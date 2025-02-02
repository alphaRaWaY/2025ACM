#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int MaxN(5e5+5);
int n,m,k,fa[MaxN];
bool vis[MaxN];
vector<int> wait[MaxN],ed[MaxN],quiry[MaxN];
int fd(int a){return a==fa[a]?a:fa[a]=fd(fa[a]);}
map<pii,int> ans;
vector<pii> ansKey;
void dfs(int parent,int root)
{
    // cout<<root<<" ";
    vis[root]=true;
    for(auto p:quiry[root])
    {
        if(!vis[p])wait[p].push_back(root);
    }
    for(auto p:ed[root])
    {
        if(p==parent)continue;
        dfs(root,p);
    }
    for(auto p:wait[root])
    {
        // cout<<"<"<<p<<" "<<root<<">"<<endl;
        // inc(i,1,n)cout<<fa[i]<<" ";cout<<endl;
        ans[{min(p,root),max(p,root)}]=fd(p);
    }
    fa[root]=parent;
}
void solve()
{
    cin>>n>>m>>k;
    fa[0]=k;
    inc(i,1,n)fa[i]=i;
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    inc(i,1,m)
    {
        int a,b;
        cin>>a>>b;
        quiry[a].push_back(b);
        quiry[b].push_back(a);
        ans[{min(a,b),max(a,b)}]=k;
        ansKey.push_back({min(a,b),max(a,b)});
    }
    dfs(0,k);
    // cout<<endl;
    for(auto x:ansKey)
    {
        if(x.first==x.second)cout<<x.first<<endl;
        else cout<<ans[x]<<endl;
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
    system("pause");
}

/*
9 9 4
4 1
4 2
1 3
1 5
2 7
3 6
7 8
7 9

3 2
3 5
1 2
4 5
9 8
6 5
8 2
1 9
7 6
*/