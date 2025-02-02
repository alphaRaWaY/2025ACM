//倍增法
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(5e5+5),MAXLG(40);
int n,q,r;
vector<int> ed[MAXN];
int depth[MAXN];
int fa[MAXN][30];
int lg[MAXN];
/**
 * lg:存储log(i)向下取整的值
 */
void getlog(int n)
{
    n=n-5;
    lg[1]=0;
    inc(i,2,n)
    {
        lg[i]=lg[i-1];
        if(2<<lg[i-1]==i)lg[i]++;
    }
}
void dfs(int i,int pa,int d)
{
    fa[i][0]=pa;
    depth[i]=d;
    inc(j,1,lg[d]+1)
    {
        fa[i][j]=fa[fa[i][j-1]][j-1];
    }
    for(int tmp:ed[i])
    {
        if(tmp==pa)continue;
        dfs(tmp,i,d+1);
    }
}
int LCA(int x, int y) {
	if(depth[x]<depth[y])swap(x,y);
	while(depth[x]>depth[y])x=fa[x][lg[depth[x]-depth[y]]];
	if(x==y)return x;
    dec(k,lg[depth[x]],0)if(fa[x][k]!=fa[y][k])x=fa[x][k],y=fa[y][k];
	return fa[x][0];
}
void solve()
{
    cin>>n>>q>>r;
    inc(i,1,n)ed[i].clear();
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dfs(r,0,1);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
}
signed main()
{
    getlog(MAXN-5);
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
    system("pause");    
}