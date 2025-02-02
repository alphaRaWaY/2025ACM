//LCA

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int MaxN(5e5+5);
int n,m,k;
int fa[MaxN];
bool vis[MaxN];
vector<int> ed[MaxN],check[MaxN];
map<pii,int> ans;
pii ansKey[MaxN];
int fd(int a)
{
    return a==fa[a]?a:fa[a]=fd(fa[a]);
}
void dfs(int parent,int root)
{
    fa[root]=root;
    vis[root]=true;
    for(int p:check[root])
    {
        if(vis[p])
        {
            ans[{min(p,root),max(p,root)}]=fd(p);
            cout<<"#"<<min(p,root)<<" "<<max(p,root)<<":"<<fd(p)<<endl;
        }
    }
    for(int p:ed[root])
    {
        if(p==parent)continue;
        dfs(root,p);
    }
    if(root!=k)fa[root]=parent;
}
void solve()
{
    cin>>n>>m>>k;
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    inc(i,1,n)
    {
        sort(ed[i].begin(),ed[i].end());
    }
    inc(i,1,m)
    {
        int a,b;
        cin>>a>>b;
        check[a].push_back(b);
        check[b].push_back(a);
        ansKey[i]={min(a,b),max(a,b)};
    }
    dfs(0,k);
    inc(i,1,m)
    {
        if(ansKey[i].first==k||ansKey[i].second==k)
        {
            cout<<k<<endl;
            continue;
        }
        if(ansKey[i].first==ansKey[i].second)
        {
            cout<<ansKey[i].first<<endl;
            continue;
        }
        cout<<ansKey[i].first<<" "<<ansKey[i].second<<":"<<endl;
        cout<<ans[ansKey[i]]<<endl;
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
5 5 4
3 1
2 4
5 1
1 4
2 4
3 2
3 5
1 2
4 5

9 9 4
3 1
2 4
5 1
1 4
3 6
7 8
7 9
2 4

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