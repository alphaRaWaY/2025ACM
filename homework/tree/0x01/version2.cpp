#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int MaxN(2e5+5);
int n,d1,d2,ans;
vector<pii> ed[MaxN];
vector<int> d,trace;
int ls[MaxN],rs[MaxN],dis[MaxN],maxD[MaxN];
bool isD[MaxN];
void getDis(int pos,int parent,int root,int target)
{
    maxD[target]=max(maxD[target],pos);
    for(auto[w,p]:ed[root])
    {
        if(p==parent||isD[p])continue;
        getDis(pos+w,root,p,target);
    }
}
void dfs(int parent,int root)
{
    for(auto[w,p]:ed[root])
    {
        if(p==parent)continue;
        dis[p]=dis[root]+w;
        dfs(root,p);
    }
}
void getD(int parent,int root)
{
    if(root==d2)d=trace;
    if(!d.empty())return;
    for(auto[w,p]:ed[root])
    {
        if(p==parent)continue;
        trace.push_back(p);
        getD(root,p);
        trace.pop_back();
    }
}
void solve()
{
    cin>>n;
    inc(i,1,n-1)
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
    inc(i,1,n)ls[i]=dis[i];
    maxDis=0;
    inc(i,1,n)
    {
        ans=max(ans,dis[i]);
        if(dis[i]>maxDis)
        {
            maxDis=dis[i];
            d2=i;
        }
    }
    dis[d2]=0;
    dfs(0,d2);
    inc(i,1,n)rs[i]=dis[i];
    trace.push_back(d1);
    getD(0,d1);
    for(auto tmp:d)isD[tmp]=true;
    for(int tmp:d)
    {
        getDis(0,0,tmp,tmp);
    }
    // for(int tmp:d)cout<<tmp<<" ";cout<<endl;
    // for(int tmp:d)cout<<maxD[tmp]<<" ";cout<<endl;
    // for(int tmp:d)cout<<ls[tmp]<<" ";cout<<endl;
    // for(int tmp:d)cout<<rs[tmp]<<" ";cout<<endl;
    int j,k;
    inc(i,0,d.size()-1)
    {
        if(rs[d[i]]==maxD[d[i]])
        {
            j=i;
            break;
        }
    }
    dec(i,d.size()-1,0)
    {
        if(ls[d[i]]==maxD[d[i]])
        {
            k=i;
            break;
        }
    }
    cout<<ans<<endl;
    cout<<j-k<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
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