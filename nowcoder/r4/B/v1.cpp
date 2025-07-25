// Problem: Blind Alley
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108301/B
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<cstdio>
#include<cstring>
#include<algorithm>
#define ri int
using namespace std;
typedef long long ll;
const int N=2e6+10,INF=1e9+7;
char s[N];
bool v1[N],v2[N],vis[N];
int T,n,m,k,st[N],f[N];
inline int get(int i,int j){return (i-1)*m+j;}
int dx1[3]={0,-1,1}; int dx2[3]={0,-1,1};
int dy1[3]={1,0,0};  int dy2[3]={-1,0,0};

void dfs1(int x,int y)
{
	v1[get(x,y)]=true;
	for(ri i=0;i<=2;i++)
	{
		int nx=x+dx1[i],ny=y+dy1[i];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(st[get(nx,ny)]!=1&&v1[get(nx,ny)]==false) dfs1(nx,ny);
	}
}

void dfs2(int x,int y)
{
	v2[get(x,y)]=true;
	for(ri i=0;i<=2;i++)
	{
		int nx=x+dx2[i],ny=y+dy2[i];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(st[get(nx,ny)]!=1&&v2[get(nx,ny)]==false) dfs2(nx,ny);
	}
}

int dfs3(int x,int y,int from)
{
	if(vis[get(x,y)]) return f[get(x,y)];
	vis[get(x,y)]=true;
	int res=0,nfrom;
	for(ri i=0;i<=2;i++)
	{
		int nx=x+dx2[i],ny=y+dy2[i];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(nx==x-1) nfrom=-1;
		if(nx==x+1) nfrom=1;
		if((nfrom==1&&from==-1)||(nfrom==-1&&from==1)) continue;
		if(st[get(nx,ny)]!=1 && v1[get(nx,ny)])
		{
			if(ny==y-1) res=max(res,dfs3(nx,ny,0)+1);
			else res=max(res,dfs3(nx,ny,nfrom));
		}
	}
	if(v2[get(x,y)]) f[get(x,y)]=max(0,f[get(x,y)]);
	f[get(x,y)]=max(f[get(x,y)],res);
	return f[get(x,y)];
}

/*
inline int dfs3(int x,int y,int from)
{
    if(x<1||x>n||y<1||y>m) return -m;
    if(f[get(x,y)][from]!=-m) return f[get(x,y)][from];
    int res=-m;
    if(from==0)
    {
    	int res=-m;
    	if(st[get(x+1,y)]==0) res=max(res,dfs3(x+1,y,0));
    	if(st[get(x,y-1)]==0) res=max(res,dfs3(x,y-1,0)+1);
    	if(st[get(x,y-1)]==0) res=max(res,dfs3(x,y-1,1)+1);
    }
    else
    {
    	int res=-m;
    	if(st[get(x-1,y)]==0) res=max(res,dfs3(x-1,y,1));
    	if(st[get(x,y-1)]==0) res=max(res,dfs3(x,y-1,0)+1);
    	if(st[get(x,y-1)]==0) res=max(res,dfs3(x,y-1,1)+1);
    	//f[x][y][from]=max(dfs(x - 1, y, 1), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + 1;
    }
    return f[get(x,y)][from]=res;
}
*/
void solve()
{
	scanf("%d %d %d",&n,&m,&k);
	for(ri i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(ri j=1;j<=m;j++) st[get(i,j)]=s[j]-'0'; 
	}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			v1[get(i,j)]=v2[get(i,j)]=false;
	dfs1(1,1),dfs2(1,m);
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			f[get(i,j)]=-m,vis[get(i,j)]=false;
	for(ri j=m;j>=1;j--)
		for(ri i=n;i>=1;i--)	
			if(v1[get(i,j)]==true&&v2[get(i,j)]==false)
			{
				int t=dfs3(i,j,0);
				//printf("%d %d:%d\n",i,j,t);
				if(t>=k){printf("Yes\n");return;}
			}
	printf("No\n");
}
int main()
{
	scanf("%d",&T);
	while(T--) solve();
	return 0;
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

/*
1
2 3 1
01
11
11
*/