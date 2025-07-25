#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
int n,m,k;
vector<vector<int>> graph;
int tx[4]={0,-1,0,1};
int ty[4]={0,0,1,0};
map<pair<int,int>,bool>can_from,can_get,vis;
map<pair<int,int>,int>depth;
vector<pair<int,int>>ed;
bool is_in(int x,int y){
    return (x>=1&&x<=n&&y>=1&&y<=m);
}
bool is_back(int from,int to){
    return (from==3&&to==1)||(from==1&&to==3);
}
// 判断是否可以从起点抵达
void fromBegin(int x,int y,int dir){
    // cout<<"#"<<x<<" "<<y<<endl;
    can_from[{x,y}]=true;
    inc(i,1,3)
    {
        if(is_back(dir,i))continue;
        int dx=x+tx[i];
        int dy=y+ty[i];
        if(!is_in(dx,dy)||graph[dx][dy]||can_from[{dx,dy}])continue;
        fromBegin(dx,dy,i);
    }
}
// 判断是否可以抵达终点
void getEnd(int x,int y,int dir){
    // cout<<"#"<<x<<" "<<y<<endl;
    can_get[{x,y}]=true;
    inc(i,1,3)
    {
        if(is_back(dir,i))continue;
        int dx=x-tx[i];
        int dy=y-ty[i];
        if(!is_in(dx,dy)||graph[dx][dy]||can_get[{dx,dy}])continue;
        getEnd(dx,dy,i);
    }
}
// 判断边缘是否会陷入陷阱
bool check(int x,int y,int dir,int originY){
    depth[{x,y}]=max(y,depth[{x,y}]);
    if(depth[{x,y}]-originY>=k){
        return true;
    }
    if(vis[{x,y}])return false;
    vis[{x,y}]=true;
    bool ans(false);
    inc(i,1,3)
    {
        if(is_back(dir,i))continue;
        int dx=x+tx[i];
        int dy=y+ty[i];
        if(!is_in(dx,dy)||graph[dx][dy])continue; 
        if(!can_get[{dx,dy}]&&can_from[{dx,dy}]){
            ans|=check(dx,dy,i,originY);
            depth[{x,y}]=max(depth[{x,y}],depth[{dx,dy}]);
        }
    }
    return ans;
}
// 多测初始化容器
void init()
{
    can_from.clear();
    can_get.clear();
    ed.clear();
    depth.clear();
    vis.clear();
}
void solve(){
    cin>>n>>m>>k;
    graph.resize(n+1);
    inc(i,1,n)graph[i].resize(m+1);
    inc(i,1,n)inc(j,1,m){
        char tmp;
        cin>>tmp;
        graph[i][j]=tmp=='1';
    }
    init();
    fromBegin(1,1,0);
    getEnd(1,m,0);
    // cout<<"=============="<<endl;
    // inc(i,1,n)
    // {
    //     inc(j,1,m)
    //     {
    //         if(graph[i][j])cout<<1;
    //         else if(can_from[{i,j}])cout<<'o';
    //         else cout<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"=============="<<endl;
    // inc(i,1,n)
    // {
    //     inc(j,1,m)
    //     {
    //         if(graph[i][j])cout<<1;
    //         else if(can_get[{i,j}])cout<<'o';
    //         else cout<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // 记录边缘的点
    inc(j,1,m)
    inc(i,1,n)
    {
        if(!can_from[{i,j}])continue;
        inc(dir,1,3){
            int dx=i+tx[dir];
            int dy=j+ty[dir];
            if(can_from[{dx,dy}]&&!can_get[{dx,dy}]){
                ed.push_back({i,j});
                break;
            }
        }
    }
    for(auto[x,y]:ed)
    {
        bool res = check(x,y,0,y);
        if(res){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
1
3 5 2
00010
01110
00000
*/

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

/*
4
9 10 4
0000000000
0011111110
0010000000
0010111110
0010000010
0011000010
0000000010
0011111110
0000000000
13 12 4
000000000000
000000011100
000000010100
000000010100
000000010100
000000010010
000000010100
000000010100
000000010100
000000010100
000000010100
011110010110
000000000110
3 14 5
00000000000000
00111101111000
00100000001000
10 10 1
0000000000
0111111110
0000000010
0000000010
0000000010
0000000010
0000000010
0000000010
0111111110
0000000000
*/