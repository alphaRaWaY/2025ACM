
//尝试缩减两端集合，但是会漏可能
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF(0x3f3f3f3f);
const int MaxN(2e5+5);
map<pair<int,int> , int>usd;
struct Edge
{
    int p;
    ll w;
    bool operator < (const Edge & a) const {return w<a.w;}
};
vector<Edge> Adj[MaxN];
ll dis[MaxN];
bool vis[MaxN];
stack<int> pa;
void dfs(int root,int & p,set<stack<int> >& t)
{
    if(t.size()>3)return;
    pa.push(root);
    bool isroot(true);
    for(Edge temp:Adj[root])
    {
        if(!vis[temp.p])
        {
            isroot=false; 
            vis[temp.p]=true;
            dis[temp.p]=dis[root]+temp.w;
            dfs(temp.p,p,t);
        }
    }
    if(isroot)
    {
        if(dis[root]>dis[p]){p=root;t.clear();t.insert(pa);}
        if(dis[root]==dis[p]){t.insert(pa);}
    }
    pa.pop();
}
void dfs(int root,int & p)
{
    bool isroot(true);
    for(Edge temp:Adj[root])
    {
        if(!vis[temp.p])
        {
            isroot=false; 
            vis[temp.p]=true;
            dis[temp.p]=dis[root]+temp.w;
            dfs(temp.p,p);
        }
    }
    if(isroot)
    {
        if(dis[root]>dis[p])p=root;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i(1);i<n;i++)
    {
        int p1,p2;
        ll w;
        cin>>p1>>p2>>w;
        Adj[p1].push_back({p2,w});
        Adj[p2].push_back({p1,w});
    }
    int p1(1),p2;
    memset(dis,0,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[1]=0;
    vis[1]=true;
    dfs(1,p1);

    set<stack<int> > t1;
    memset(dis,0,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[p1]=0;
    vis[p1]=true;
    dfs(p1,p2,t1);
    ll ans1(dis[p2]);

    set<stack<int> > t2;
    memset(dis,0,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[p2]=0;
    vis[p2]=true;
    dfs(p2,p1,t2);
    set<stack<int> > t3;
    for(stack<int> temp:t2)
    {
        stack<int> in;
        while(!temp.empty()){in.push(temp.top());temp.pop();}
        t3.insert(in);
    }
    /*
    for(stack<int> temp:t1)
    {
        while(!temp.empty())
        {
            int top(temp.top());temp.pop();
            cout<<top<<" ";
        }
        cout<<endl;
    }
    */
    //cout<<"===================================="<<endl;
    /*
    for(stack<int> temp:t3)
    {
        while(!temp.empty())
        {
            int top(temp.top());temp.pop();
            cout<<top<<" ";
        }
        cout<<endl;
    }
    */
    //cout<<"===================================="<<endl;
    vector<stack<int> > t4;
    set_union(t1.begin(),t1.end(),t3.begin(),t3.end(),back_inserter(t4));
    int ans2(0);
    for(stack<int> temp:t4)
    {
        int pt(temp.top());temp.pop();
        while(!temp.empty())
        {
            int top(temp.top());temp.pop();
            usd[make_pair(pt,top)]++;
            pt=top;
        }
    }
    //cout<<"===================================="<<endl;
    for(auto [x,y]:usd)
    {
        /*
        cout<<"[{"<<x.first<<","<<x.second<<"}"<<y<<"]";
        */
        if(y==t4.size())
            ans2++;
    }
    cout<<ans1<<"\n"<<ans2<<endl;
    system("pause");
}