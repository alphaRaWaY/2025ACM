//problem url:https://www.luogu.com.cn/problem/P5318
//status:AC
//date:2024/08/03
//知识点：深度优先搜索和广度优先搜索


#include<bits/stdc++.h>
#define DEBUGdfs    //输出深搜的结果
#define DEBUGbfs    //输出广搜的结果
using namespace std;
const int MaxN(1e5+5);
vector<int> Adj[MaxN];
bool vis[MaxN];
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    vis[root]=true;
    cout<<root<<" ";
    while(!q.empty())
    {
        int size(q.size());
        for(int i(0);i<size;i++)
        {
            int top(q.front());
            q.pop();
            for(int temp:Adj[top])
            {
                if(!vis[temp])
                {
                    vis[temp]=true;
                    q.push(temp);
                    cout<<temp<<" ";
                }
            }
        }
    }
}
void dfs(int root)
{
    vis[root]=true;
    cout<<root<<" ";
    for(int temp:Adj[root])
    {
        if(!vis[temp])
        {
            dfs(temp);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i(0);i<m;i++)
    {
        int f,c;
        cin>>f>>c;
        Adj[f].push_back(c);
    }
    for(int i(1);i<=n;i++)
    {
        sort(Adj[i].begin(),Adj[i].end());
    }
    #ifdef DEBUGdfs
    memset(vis,false,sizeof(vis));
    dfs(1);
    cout<<endl;
    #endif
    #ifdef DEBUGbfs
    memset(vis,false,sizeof(vis));
    bfs(1);
    cout<<endl;
    #endif
    system("pause");
    return 0;
}