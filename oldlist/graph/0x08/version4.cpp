//�Ľ�˼·������Ҫ�洢ֱ����ֻ��Ҫ����ֱ����ֱ�ӽ��в���

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
    ll ans1=doDFS(p1,p2,dia);//��p1Ϊ���ĵ����dis����
    for(int temp:dia){rs[temp]=dis[temp];}
    doDFS(p2,p1);//��p2Ϊ���ĸ���dis����
    for(int temp:dia){ls[temp]=dis[temp];}
    //��ֱ���ϵĵ���б���
    memset(vis,false,sizeof(vis));
    int be(0),en(dia.size()-1);
    for(int i(0);i<dia.size();i++)
    {
        //��ֱ����һ���ǰ���������Ϸ�ֹ����ֱ���ϵĵ�
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
        //��ֱ����һ���ǰ���������Ϸ�ֹ����ֱ���ϵĵ�
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