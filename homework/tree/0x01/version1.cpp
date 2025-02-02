#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
#define pii pair<int,int>
const int MaxN(2e5+5);
int n,d1,d2,ans;
vector<pii> ed[MaxN];
vector<int> d,trace[MaxN];
bool isD[MaxN];
int dis[MaxN],maxDis[MaxN],ls[MaxN],rs[MaxN];
void printTrace()
{
    inc(i,1,n)
    {
        for(int tmp:trace[i])cout<<tmp<<" ";cout<<endl;
    }
}
void dfs(int parent,int root)
{
    for(auto[w,p]:ed[root])
    {
        if(p==parent)continue;
        dis[p]=dis[root]+w;
        trace[p]=trace[root];
        trace[p].push_back(p);
        dfs(root,p);
    }
}
void reAnchor(int root)
{
    trace[root]={root};
    dis[root]=0;
    dfs(0,root);
}
int getMaxDis()
{
    int end;
    int tmp(0);
    inc(i,1,n)
    {
        if(dis[i]>tmp)
        {
            tmp=dis[i];
            end=i;
        }
    }
    return end;
}
int getMaxDisOnD()
{
    int end;
    int tmp(0);
    inc(i,1,n)
    {
        bool isOK(true);
        for(int tmp:trace[i])
        {
            if(isD[i])
            {
                isOK=false;
                break;
            }
        }
        if(!isOK)continue;
        if(dis[i]>tmp)
        {
            tmp=dis[i];
            end=i;
        }
    }
    return end;
}
void solve()
{
    memset(maxDis,0,sizeof(maxDis));
    memset(isD,false,sizeof(isD));
    memset(dis,0,sizeof(dis));
    cin>>n;
    inc(i,0,n)ed[i].clear();
    inc(i,1,n-1)
    {
        int a,b,w;
        cin>>a>>b>>w;
        ed[a].push_back({w,b});
        ed[b].push_back({w,a});
    }
    reAnchor(1);
    d1=getMaxDis();
    reAnchor(d1);
    d2=getMaxDis();
    ans=dis[d2];
    d=trace[d2];
    for(int tmp:d)isD[tmp]=true;
    inc(i,1,n)ls[i]=dis[i];
    reAnchor(d2);
    inc(i,1,n)rs[i]=dis[i];
    for(int tmp:d)
    {
        reAnchor(tmp);
        int end=getMaxDisOnD();
        maxDis[tmp]=dis[end];
    }
    for(int tmp:d)cout<<tmp<<" ";cout<<endl;
    for(int tmp:d)cout<<maxDis[tmp]<<" ";cout<<endl;
    for(int tmp:d)cout<<ls[tmp]<<" ";cout<<endl;
    for(int tmp:d)cout<<rs[tmp]<<" ";cout<<endl;
    // int j,k;
    // inc(i,0,d.size()-1)if(maxDis[d[i]]==ls[d[i]]){j=i;break;}
    // dec(i,d.size()-1,0)if(maxDis[d[i]]==rs[d[i]]){k=i;break;}
    // cout<<ans<<endl;
    // cout<<j-k+1<<endl;
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
6
3 1 1000
1 4 10
4 2 100
4 5 50
4 6 100
*/