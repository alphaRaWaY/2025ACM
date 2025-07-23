#include<bits/stdc++.h>
using namespace std;
#define inc(i,a,b) for(int i(a);i<=b;i++)
const int MaxN(5e5+5),MaxM(2e5+5),INF(0x3f3f3f3f);
int n,m;
vector<int> ed[MaxN];
vector<int> newEd[MaxN];
struct node
{
    int u,v,c;
    bool operator< (const node& n) const {
        if(c==n.c)
        {
            if(u==n.u)return v<n.v;
            else return u<n.u;
        }
        return c<n.c;
    }
}origin[MaxM*2];

bool vis[MaxM*2];
int val[MaxN*2];
void dfs(int index,int pa,int c,vector<int>& v)
{
    if((vis[pa])&&pa)return;
    vis[pa]=true;
    v.push_back(index);
    for(int i:ed[index])
    {
    	int dc = origin[i].c, dp = (index==origin[i].u)?origin[i].v:origin[i].u;
        if(c!=dc||vis[i])continue;
        dfs(dp,i,c,v);
    }
}
int dist[MaxN*2];
bool vvis[MaxN*2];
void solve()
{
    cin>>n>>m;
    for (int i = 1; i <= m; i++) vis[i] = false;
    int originN=n;
    inc(i,1,m+n)newEd[i].clear(),ed[i].clear(),val[i]=0,dist[i]=INF;
    dist[1]=0;
    inc(i,1,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        origin[i]={a,b,c};
    }
    sort(origin+1,origin+1+m);
    inc(i,1,m)
    {
        auto[a,b,c] = origin[i];
        ed[a].push_back(i);
        ed[b].push_back(i);    
    }
    inc(i,1,m)
    {   
        if(vis[i])continue;
        vector<int> p;
        dfs(origin[i].u,0,origin[i].c,p);
        n++;
        for(int tmp:p)
        {            
            newEd[n].push_back(tmp);
            newEd[tmp].push_back(n);
            val[n]=1;
        }
    }
    priority_queue<pair<int,int> > q;
    q.push({0,1});
    inc(i,1,n+m)vvis[i]=false;
    while(!q.empty())
    {
        auto[dis,now] = q.top();
        q.pop();
        if(vvis[now])continue;
        else vvis[now]=true;
        for(auto p:newEd[now])
        {
            if(dis+val[p]>=dist[p])continue;
            dist[p]=dis+val[p];
            q.push({dist[p],p});
        }
        if(dist[originN]!=INF)break;
    }
    cout<<dist[originN]<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
}

/*
2
4 3
1 2 1
2 3 3
3 4 1
8 10
1 2 1
1 3 2
3 2 3
2 4 1
2 6 3
2 5 1
5 4 1
5 6 3
6 7 1
6 8 2
*/

