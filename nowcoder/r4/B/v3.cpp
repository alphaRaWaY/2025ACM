#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e6+5);
string graph[MaxN];
int n,m,k;
vector<vector<int>>dp;
vector<vector<bool>>vis;
// 多测初始化容器
void init()
{
    dp.clear();
    vis.clear();
    vis.resize(n);
    dp.resize(n);
    inc(i,0,n-1)
    {
        dp[i].resize(m);
        vis[i].resize(m);
    }
}
void solve()
{
    cin>>n>>m>>k;
    inc(i,0,n-1)cin>>graph[i];
    init();
    vis[0][0]=true;

    // 遍历起点能到的点
    inc(j,0,m-1){
        if(j){
            inc(i,0,n-1){
                if(graph[i][j]=='0'&&vis[i][j-1])
                vis[i][j]=true;
            }
        }
        inc(i,1,n-1){
            if(graph[i][j]=='0'&&vis[i-1][j])
            vis[i][j]=true;
        }
        dec(i,n-2,0){
            if(graph[i][j]=='0'&&vis[i+1][j])
            vis[i][j]=true;
        }
    }

    // 遍历每个点能到达的最远的点
    dec(j,m-1,0){
        inc(i,0,n-1)
        {
            if(graph[i][j]=='0')
            dp[i][j]=j;
        }
        if(j!=m-1){
            inc(i,0,n-1){
                if(graph[i][j]=='0')
                dp[i][j]=max(dp[i][j],dp[i][j+1]);
            }
        }
        inc(i,1,n-1){
            if(graph[i][j]=='0')
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
        dec(i,n-2,0){
            if(graph[i][j]=='0')
            dp[i][j]=max(dp[i][j],dp[i+1][j]);
        }
    }

    // inc(i,0,n-1){
    //     inc(j,0,m-1)cout<<(vis[i][j]?'o':' ');
    //     cout<<endl;
    // }
    inc(i,0,n-1)
    inc(j,0,m-1)
    {
        if(vis[i][j]&&dp[i][j]>=j+k-1&&dp[i][j]<m-1)
        {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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
6
3 5 2
00010
01110
00000
3 5 3
00010
01110
00000
3 5 2
01000
01110
00000
3 5 2
00000
01110
00000
3 5 2
01010
01110
00000
5 5 2
00000
00110
00010
01010
00010
*/