//倍增法

/*
对于每一种查询，令层最深的结点为a
所有节点分为两类：
（1）S1：a的祖宗    
（2）S2：非a的祖宗  
令S2中层最深的点为b
如果该查询结果为YES，则S2中的结点一定满足：
（1）为b的祖宗
（2）与S1中的所有点LCA相同（只需要通过S1中最深和最浅的两个点判断）
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
using pii = pair<int,int>;
const int MAXN(2e5+5),MAXLG(40);
int n,q;
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
map<pii,int> vis;
int getLCA(int a,int b)
{
    if(vis[{min(a,b),max(a,b)}])return vis[{min(a,b),max(a,b)}];
    else return vis[{min(a,b),max(a,b)}]=LCA(a,b);
}
void solve()
{
    vis.clear();
    cin>>n;
    inc(i,1,n)ed[i].clear();
    inc(i,1,n-1)
    {
        int a,b;
        cin>>a>>b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dfs(1,0,1);
    cin>>q;
    while(q--)
    {
        int sz;
        cin>>sz;
        vector<pii> s;
        inc(i,1,sz)
        {
            int a;
            cin>>a;
            s.push_back({depth[a],a});
        }
        sort(s.begin(),s.end(),greater<>());
        vector<int> branch1,branch2;
        for(auto[d,p]:s)
        {
            int tmp=getLCA(p,s.front().second);
            if(tmp!=p)branch2.push_back(p);
            else branch1.push_back(p);
        } 
        bool isOK(true);
        for(int p:branch2)
        {
            int tmp1=getLCA(p,branch1.front());
            int tmp2=getLCA(p,branch1.back());
            int tmp3=getLCA(p,branch2.front());
            if(tmp1!=tmp2||tmp3!=p)
            {
                isOK=false;
                break;
            }
        }
        if(isOK)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
signed main()
{
    getlog(MAXN-5);
    // dec(i,10,3)cout<<i<<" ";cout<<endl;
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
    system("pause");    
}