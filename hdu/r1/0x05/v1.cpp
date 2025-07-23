#include<bits/stdc++.h>
using namespace std;
#define inc(i,a,b) for(int i(a);i<=b;i++)
const int MaxN(5e5+5),MaxM(2e5+5),INF(0x3f3f3f3f);
int n,m;
vector<pair<int,int> > ed[MaxN];
struct node
{
    int u,v,c;
}origin[MaxM*2];
map<pair<int,int>,bool>vis;
map<pair<int,int>,bool>isNew;
int val[MaxN*2];
void dfs(int index,int pa,int c,set<int>& v)
{
    // if(n==9)cout<<index<<"#"<<endl;
    if((vis[{min(index,pa),max(index,pa)}]||isNew[{min(index,pa),max(index,pa)}])&&pa)return;
    vis[{min(index,pa),max(index,pa)}]=true;
    v.insert(index);
    for(auto[dp,dc]:ed[index])
    {
        if(c!=dc||vis[{min(index,dp),max(index,dp)}])continue;
        dfs(dp,index,c,v);
    }
}
int dist[MaxN*2];
void solve()
{
    vis.clear();isNew.clear();
    cin>>n>>m;
    int originN=n;
    inc(i,1,m*2)ed[i].clear(),val[i]=0;
    dist[1]=0;
    inc(i,1,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ed[a].push_back({b,c});
        ed[b].push_back({a,c});
        origin[i]={a,b,c};
    }
    inc(i,1,m)
    {   
        if(vis[{min(origin[i].u,origin[i].v),max(origin[i].u,origin[i].v)}])continue;
        set<int> p;
        dfs(origin[i].u,0,origin[i].c,p);
        n++;
        for(int tmp:p)
        {            
            isNew[{min(tmp,n),max(tmp,n)}]=true;
            ed[n].push_back({tmp,origin[i].c});
            ed[tmp].push_back({n,origin[i].c});
            val[n]=1;
        }
    }
    // cout<<n<<endl;
    // inc(i,1,n)
    // {

    //     cout<<"#"<<i<<"val: "<<val[i]<<endl;
    //     for(auto[x,y]:ed[i])if(!vis[{min(x,i),max(x,i)}])cout<<"["<<x<<"]";
    //     cout<<endl;
    // }
    priority_queue<pair<int,int> > q;
    q.push({0,1});
    inc(i,1,n)dist[i]=INF;
    dist[1]=0;
    while(!q.empty())
    {
        auto[dis,now] = q.top();
        q.pop();
        // cout<<"#"<<now<<endl;
        for(auto[p,c]:ed[now])
        {
            if(dis+val[p]>=dist[p]||vis[{min(now,p),max(now,p)}])continue;
            dist[p]=dis+val[p];
            q.push({dist[p],p});
        }
        if(dist[originN]!=INF)break;
    }
    // inc(i,1,n)cout<<dist[i]<<" ";cout<<endl;
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
1
4 3
1 2 1
2 3 3
3 4 1
*/

/*
1
8 9
1 2 1
1 3 2
3 2 3
2 6 3
2 5 1
5 4 1
5 6 3
6 7 1
6 8 2
*/