#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

// #define LOCAL
#ifdef LOCAL
#define debug0(x) cout<<"[DEBUG] "<<#x<<"="<<x<<endl
#define debug1(c,l,r) cout<<"[DEBUG] "<<#c<<" : ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr)cout<<"[DEBUG]"<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
ostream& operator<< (ostream& o,const pair<int,int>& a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
#else
#define debug0(x)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif

const int INF(0x3f3f3f3f);
int n,m;
vector<vector<int>>g,dist;
vector<vector<bool>> vis;
int tx[4]={0,0,1,-1};
int ty[4]={1,-1,0,0};
bool is_in(int x,int y)
{
    return x>=0&&x<=n-1&&y>=0&&y<=m-1;
}
void cal()
{
    queue<pair<int,int>> q;
    inc(i,0,n-1)inc(j,0,m-1){
        if(g[i][j])
        {
            dist[i][j]=0;
            vis[i][j]=true;
            q.push({i,j});
        }
    }
    while(!q.empty())
    {
        auto [x,y]=q.front();
        // debug0(q.front());
        q.pop();
        inc(j,0,3)
        {
            int xx=x+tx[j];
            int yy=y+ty[j];
            if(!is_in(xx,yy)||vis[xx][yy])continue;
            q.push({xx,yy});
            vis[xx][yy]=true;
            dist[xx][yy]=dist[x][y]+1;
        }
    }
    debug2(dist,0,0,n-1,m-1);
}
void solve()
{
    cin>>n>>m;
    bool flag(false);
    inc(i,1,n)
    {
        vector<int> newD,newG;
        vector<bool> newV;
        inc(j,1,m)
        {
            int tmp;
            cin>>tmp;
            flag|=tmp;
            newG.push_back(tmp);
            newD.push_back(INF);
            newV.push_back(false);
        }
        g.push_back(newG);
        dist.push_back(newD);
        vis.push_back(newV);
    }

    // if(!flag)
    if(false)
    {
        g[n/2][m/2]=1;
        cal();
        int Md(0);
        inc(i,0,n-1)inc(j,0,m-1)Md=max(Md,dist[i][j]);
        cout<<Md<<endl;
        return;
    }

    debug2(g,0,0,n-1,m-1);
    cal();
    // debug2(dist,0,0,n-1,m-1);

    int l(-1),r(2e5+5);
    while(r-l>1)
    {
        int mid(((r-l)>>1)+l);
        int a(INF),b(-INF),c(INF),d(-INF);
        inc(i,0,n-1)inc(j,0,m-1)
        {
            if(dist[i][j]>mid)
            {
                a=min(i+j,a);
                b=max(i+j,b);
                c=min(j-i,c);
                d=max(j-i,d);
            }
            // debug0(mid);
            // debug0(b-a+1);
            // debug0(d-c+1);
        }
        if(2*mid+1>=b-a+1&&2*mid+1>=d-c+1&&(2*mid>b-a||2*mid>d-c)||(a+b)/2%2==(c+d)/2%2)r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--){
        solve();
    }
}
/*

5 6
0 0 0 0 0 0 
0 0 0 0 0 1
0 0 0 0 0 0
0 0 1 0 0 0
1 0 0 0 0 1

3 3
1 0 0 
0 0 0
0 0 0
*/
