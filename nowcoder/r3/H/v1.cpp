#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e6+5);
int fa[35][MaxN],depth[MaxN];
bool vis[MaxN];
int n,k;
int getDepth(int i){
    if(i==0)return 0;
    if(depth[i])return depth[i];
    else return getDepth(fa[0][i])+1;
    // return depth[i]?depth[i]:(depth[i]=getDepth(fa[0][i])+1);
}
void solve(){
    cin>>n>>k;
    inc(i,2,n)cin>>fa[0][i];    
    inc(d,1,20)inc(i,1,n)
    {
        fa[d][i]=fa[d-1][fa[d-1][i]];
    }
    vis[0]=vis[1]=true;
    int ans(-1);
    while(k--)
    {
        int u,l,r;
        cin>>u>>l>>r;
        if(ans!=-1)continue;
        // 之前能够抵达
        if(vis[u])
        {
            ans=l;
            continue;
        }
        // 连通块拓展节点
        int node=u;
        dec(i,20,0)if(!vis[fa[i][node]])node=fa[i][node];
        node=fa[0][node];

        // cerr<<node<<endl;
        int dist = getDepth(u)-getDepth(node)-(r-l+1);
        // 连通块能够拓展到对应位置
        if(dist<=0)
        {
            ans=l+(getDepth(u)-getDepth(node)-1);
            continue;
        }
        // 拓展终点
        int endPoint(u);
        // 扩展连通块
        dec(i,20,0)if(getDepth(fa[i][endPoint])-getDepth(node)>r-l+1)endPoint=fa[i][endPoint];
        while(endPoint!=node)
        {
            endPoint=fa[0][endPoint];
            vis[endPoint]=true;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}