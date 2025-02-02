//problem url:https://www.luogu.com.cn/problem/B3647
//status:AC
//date:2024/08/04
//知识点：floyd算法求多元最短路径（不保存路径只保存距离）


#include<bits/stdc++.h>
using namespace std;
const int MaxN(100+5);
const int MaxM(4500+5);
int dis [MaxN][MaxN];
const int INF (0x3f3f3f3f);
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(dis,INF,sizeof(dis));
        for(int i(1);i<=n;i++){dis[i][i]=0;}
        for(int i(0);i<m;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            dis[a][b]=min(dis[a][b],w);
            dis[b][a]=min(dis[b][a],w);
        }
        for(int i(1);i<=n;i++)
        for(int j(1);j<=n;j++)
        for(int k(1);k<=n;k++)
        {
            dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
        }
        for(int i(1);i<=n;i++)
        {
            for(int j(1);j<=n;j++)
            {
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}