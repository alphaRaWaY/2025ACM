// 关键：k此升级可以全部花在任何一条公路上
// 并且每一次查询一定是选择一条路径，再在这条路径上选择升级效果最好的一条升级
// 所以一次肯定只升级一条边
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

const int MaxN(2e5+5),MaxM(6e5+5),INF(0x3f3f3f3f3f3f);
int n,m;
int dist1[MaxN],dist2[MaxN];
struct node
{
    int u,v,t,w;
    int y(){
        return dist1[u]+dist2[v]+t;
    }
    int x(){
        return -w;
    }
}road[MaxM];
vector<int> ed1[MaxN],ed2[MaxN];
bool vis[MaxN];
// 凸包
struct Hell{
    vector<pair<int,int>>nodes,ss;
    pair<int,int> getVector(pair<int,int> a,pair<int,int> b)
    {
        return make_pair(b.first-a.first,b.second-a.second);
    }
    int cross(pair<int,int> a,pair<int,int> b,pair<int,int> c)
    {
        pair<int,int>x(getVector(a,b)),y(getVector(b,c));
        return x.first*y.second-x.second*y.first;
    }
    Hell()
    {
        inc(i,1,m)nodes.push_back(make_pair(road[i].x(),road[i].y()));
        sort(nodes.begin(),nodes.end());
        ss.push_back(nodes[0]);
        inc(i,1,nodes.size()-1)
        {
            while(ss.size()>1&&cross(ss[ss.size()-2],ss[ss.size()-1],nodes[i])<0)ss.pop_back();
            ss.push_back(nodes[i]);
        }
    }
    void debug(){
        for(auto[x,y]:ss)
        {
            cout<<"["<<x<<" "<<y<<"]";
        }
        cout<<endl;
    }
    int query(int k)
    {
        int l(0),r(ss.size()-1);
        
        auto cal = [k](pair<int,int> tmp)->int{
            return tmp.first*k+tmp.second;
        };

        while(r-l>1)
        {
            int mid(((r-l)>>1)+l);
            if(cal(ss[mid])>cal(ss[mid+1]))l=mid;
            else r=mid;    
        }

        return min(cal(ss[l]),cal(ss[r]));
    }
};
void solve()
{
    cin>>n>>m;
    // 初始化容器
    inc(i,1,n)ed1[i].clear();
    inc(i,1,n)ed2[i].clear();
    // 输入
    inc(i,1,m)
    {
        cin>>road[i].u>>road[i].v>>road[i].t>>road[i].w;
        ed1[road[i].u].push_back(i);
        ed2[road[i].v].push_back(i);
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
    // 到起点的最短路
    inc(i,2,n)dist1[i]=INF;dist1[1]=0;
    inc(i,1,n)vis[i]=false;
    q.push({0,1});
    while(!q.empty())
    {
        auto [dis,index]=q.top();
        q.pop();
        if(vis[index])continue;
        vis[index]=true;
        for(int tmp:ed1[index])
        {
            auto[u,v,t,w]=road[tmp];
            if(dist1[v]>dist1[index]+t)
            {
                dist1[v]=dist1[index]+t;
                q.push({dist1[v],v});
            }
        }
    }
    // 到终点的最短路
    inc(i,1,n-1)dist2[i]=INF;dist2[n]=0;
    inc(i,1,n)vis[i]=false;
    q.push({0,n});
    while(!q.empty())
    {
        auto [dis,index]=q.top();
        q.pop();
        if(vis[index])continue;
        vis[index]=true;
        for(int tmp:ed2[index])
        {
            auto[u,v,t,w]=road[tmp];
            if(dist2[u]>dist2[index]+t)
            {
                dist2[u]=dist2[index]+t;
                q.push({dist2[u],u});
            }
        }
    }
    // inc(i,1,n)cout<<dist1[i]<<" ";cout<<endl;
    // inc(i,1,n)cout<<dist2[i]<<" ";cout<<endl;
    
    Hell ans;
    // ans.debug();
    int query;
    cin>>query;
    while(query--)
    {
        int k;
        cin>>k;
        cout<<ans.query(k)<<endl;
    }
}   
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
2

4 4
1 2 15 1
1 3 20 2
2 4 10 1
3 4 10 1
2
9
1

9 12
1 2 1 1
1 3 2 1
1 5 2 3
1 8 2 1
2 6 5 6
3 4 4 1 
4 6 3 3
5 6 9 7 
6 7 6 6
6 8 7 4
8 9 2 1
7 9 5 4
0
*/