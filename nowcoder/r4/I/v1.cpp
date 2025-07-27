#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
mt19937_64 rng(time(0));
int getRng(int l,int r){return (rng()%(r-l+1)+l);}
const int MaxN(100),INF(0x3f3f3f3f3f3f3f3f);
int n,m;

int destinationX,destinationY;

int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,-1,1};
bool is_in(int x,int y){return x>=1&&x<=n&&y>=1&&y<=n;}

char g[MaxN][MaxN];
pair<int,int> from[MaxN][MaxN];
int dist[MaxN][MaxN];
vector<pair<pair<int,int>,pair<int,int>>> ans;
vector<pair<int,int>> path;
// 找最近的终点
void bfs(int x,int y)
{
    inc(i,1,n)inc(j,1,m)dist[i][j]=INF;
    dist[x][y]=0;
    from[x][y]={x,y};

    destinationX=-1;
    destinationY=-1;

    queue<pair<int,int>> q;
    q.push({x,y});


    while(!q.empty())
    {
        bool isOK(false);
        pair<int,int> top=q.front();
        q.pop();
        inc(i,1,4)
        {
            int tx=(top.first+dx[i]),ty(top.second+dy[i]);
            if(!is_in(tx,ty)||g[tx][ty]=='#')continue;
            if(dist[tx][ty]>dist[top.first][top.second]+1)
            {
                from[tx][ty]=top;
                dist[tx][ty]=dist[top.first][top.second]+1;
                q.push({tx,ty});
            }
            if(g[tx][ty]=='*')
            {
                isOK=true;
                destinationX=tx;
                destinationY=ty;
                path.clear();
                pair<int,int> now={destinationX,destinationY};
                while(dist[now.first][now.second])
                {
                    path.push_back(now);
                    now=from[now.first][now.second];
                }
                path.push_back(now);
                break;
            }
        }
        if(isOK)break;
    }
}
// 把路径添加到答案
void appendPath()
{
    // for(auto[x,y]:path)cout<<"["<<x<<","<<y<<"]";cout<<endl;
    int now(0);
    inc(i,0,path.size()-1)
    {
        if(g[path[i].first][path[i].second]!='.')
        {
            dec(j,i-1,now)
            {
                ans.push_back({path[j],path[j+1]});
            }
            now=i;
        }
    }
    g[path.back().first][path.back().second]='.';
    g[destinationX][destinationY]='!';
}
char getDirection(pair<int,int> a,pair<int,int> b)
{
    if(b.first==a.first-1)return 'U';
    if(b.first==a.first+1)return 'D';
    if(b.second==a.second-1)return 'L';
    if(b.second==a.second+1)return 'R';
    else return '!';
}
void solve()
{
    ans.clear();
    cin>>n>>m;
    inc(i,1,n)scanf("%s",g[i]+1);
    inc(i,1,n)inc(j,1,m)
    {
        if(g[i][j]=='@')
        {
            bfs(i,j);
            if(destinationX==-1)
            {
                cout<<-1<<endl;
                return;
            }
            appendPath();
        }
    }
    cout<<ans.size()<<endl;
    for(auto[y,x]:ans)
    {
        // cout<<"["<<x.first<<","<<x.second<<"] -> ["<<y.first<<","<<y.second<<"]"<<endl;
        cout<<x.first<<" "<<x.second<<" "<<getDirection(x,y)<<endl;
    }
}
signed main(){
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}
/*
3 3
@.#
#.#
#.*
*/

/*
3 3
#@#
@!*
#*
*/

/*
3
3 3
@.#
#.#
#.*
3 3
#@#
@!*
#*#
3 3
@#@
#..
**#
*/