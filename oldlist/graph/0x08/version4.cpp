//改进思路，不需要存储直径，只需要遇到直径就直接进行操作

#include<bits/stdc++.h>
const int MaxN(2e5+5);
using namespace std;
using ll = long long;
struct Edge
{
    int p;
    ll w;
};
vector<Edge> Adj[MaxN];
vector<int> tp;
ll dis[MaxN];
bool vis[MaxN];
void dfs(int root,int & p)
{
    vis[root]=true;
    bool isleaf(true);
    for(Edge temp:Adj[root])
    {
        if(!vis[temp.p])
        {
            isleaf=false;
            dis[temp.p]=dis[root]+temp.w;
            dfs(temp.p,p);
        }
    }
    if(isleaf)
    {
        if(dis[root]>dis[p])p=root;
    }
}
void dfs(int root,int & p,vector<int>& r)
{
    tp.push_back(root);
    vis[root]=true;
    bool isleaf(true);
    for(Edge temp:Adj[root])
    {
        if(!vis[temp.p])
        {
            isleaf=false;
            dis[temp.p]=dis[root]+temp.w;
            dfs(temp.p,p,r);
        }
    }
    if(isleaf)
    {
        if(dis[root]>dis[p]){p=root;r=tp;}
    }
    tp.pop_back();
}
ll doDFS(int root,int & p,vector<int>& r)
{
    p=root;
    memset(vis,false,sizeof(vis));
    memset(dis,0,sizeof(dis));
    dfs(root,p,r);
    return dis[p];
}
ll doDFS(int root,int & p)
{
    p=root;
    memset(vis,false,sizeof(vis));
    memset(dis,0,sizeof(dis));
    dfs(root,p);
    return dis[p];
}
int main()
{
    int n;
    cin>>n;
    for(int i(1);i<n;i++)
    {
        int p1,p2,w;
        cin>>p1>>p2>>w;
        Adj[p1].push_back({p2,w});
        Adj[p2].push_back({p1,w});
    }
    vector<int> dia;
    map<int,int> rs,ls;
    int p1,p2;
    doDFS(1,p1);
    ll ans1=doDFS(p1,p2,dia);//以p1为中心点更新dis数组
    for(int temp:dia){rs[temp]=dis[temp];}
    doDFS(p2,p1);//以p2为中心更新dis数组
    for(int temp:dia){ls[temp]=dis[temp];}
    //对直径上的点进行遍历
    memset(vis,false,sizeof(vis));
    int be(0),en(dia.size()-1);
    for(int i(0);i<dia.size();i++)
    {
        //把直径上一点的前后两端掐断防止访问直径上的点
        vis[dia[max(0,i-1)]]=true;
        vis[dia[min((int)dia.size()-1,i+1)]]=true;

        memset(dis,0,sizeof(dis));
        int endp=dia[i];
        dfs(dia[i],endp);
        if(dis[endp]==rs[dia[i]]){be=i;break;}
        memset(vis,false,sizeof(vis));
    }
    for(int i(0);i<dia.size();i++)
    {
        //把直径上一点的前后两端掐断防止访问直径上的点
        vis[dia[max(0,i-1)]]=true;
        vis[dia[min((int)dia.size()-1,i+1)]]=true;

        memset(dis,0,sizeof(dis));
        int endp=dia[i];
        dfs(dia[i],endp);
        if(dis[endp]==ls[dia[i]]){en=i;break;}
        memset(vis,false,sizeof(vis));
    }
    int ans2=en-be;
    cout<<ans1<<"\n"<<ans2<<endl;
    system("pause");
}