#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e5+5);
int n,k,d1,d2,center;
vector<int> ed[MaxN];
int dis[MaxN],weight[MaxN];
vector<int> trace,d;
map<int,int> cnt;
void getD(int parent,int root)
{
    if(root==d2)
    {
        trace.push_back(root);
        d=trace;
    }
    if(!d.empty())return;
    trace.push_back(root);
    for(int p:ed[root])
    {
        if(p==parent)continue;
        getD(root,p);
    }
    trace.pop_back();
}
void dfs(int parent,int root)
{   
    for(int p:ed[root])
    {
        if(p==parent)continue;
        dis[p]=dis[root]+1;
        dfs(root,p);
    }
}
void getWeight(int parent,int root)
{
    if(ed[root].size()==1)return;
    int M(0);
    for(int p:ed[root])
    {
        if(p==parent)continue;
        getWeight(root,p);
        M=max(M,weight[p]);
    }
    weight[root]=M+1;
}
bool cmp(int a,int b)
{
    return a>b;
}
void solve()
{
    cin>>n>>k;
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].push_back(b);
        ed[b].push_back(a);
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
    }
    // cout<<d1<<" "<<d2<<endl;
    getD(0,d1);
    // for(int tmp:d)cout<<tmp<<" ";cout<<endl;
    center=d[d.size()/2];
    getWeight(0,center);
    // cout<<center<<endl;
    // inc(i,1,n)cout<<weight[i]<<" ";cout<<endl;
    int maxW(0);
    inc(i,1,n)
    {
        maxW=max(maxW,weight[i]);
        cnt[weight[i]]++;
    }
    int ans,tot(0);
    dec(i,maxW,0)
    {
        tot+=cnt[i];
        if(tot<=k&&tot+cnt[i-1]>k)
        {
            ans=i;
        }
    }
    cout<<ans<<endl;
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
7 1
1 2
2 3
2 4
1 5
5 6
6 7

7 4
1 2
2 3
2 4
1 5
5 6
6 7

6 3
1 2
2 3
2 4
1 5
5 6
*/
