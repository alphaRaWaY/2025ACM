#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

#define LOCAL
#ifdef LOCAL
#define debug0(x) cout<<"[DEBUG] "<<#x<<"="<<x<<endl
#define debug1(c,l,r) cout<<"[DEBUG] "<<#c<<" : ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr)cout<<"[DEBUG]"<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
#else
#define debug0(x)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif

const int N = 5e5+5 , M = 3e6 + 10; //点数和边数

int n, ans(0), outDegree[N], a[N], u[M], v[M];

vector<int> g[N], g2[N]; //vector存图

//cnt记录访问次序，stk是栈，top栈顶，instk是否在栈里，belong属于哪个强连通分量
int dfn[N], low[N], cnt = 0, stk[N], top=0, instk[N], belong[N];

// 判断是不是环
bool isSCC[N];
int sz[N];

int in[N]; //in入度，dp动态规划，ans答案
void tarjan(int u) { //tarjan算法
    dfn[u] = low[u] = ++cnt, stk[++top] = u, instk[u] = 1;
    for(auto i : g[u]) { //遍历下一个点
        if(!dfn[i]) { //没有访问过
            tarjan(i); //去递归它
            low[u] = min(low[u], low[i]); //更新low值
        }
        else if(instk[i]) //访问过且在栈中
            low[u] = min(low[u], dfn[i]); //更新low值
    }
    if(dfn[u] == low[u]) { //找到一个SCC
        do {
            instk[stk[top]] = 0; //出栈
            belong[stk[top]] = u; //这个结点属于u代表的SCC
            if(stk[top] != u) a[u] += a[stk[top]]; //缩点累加权值
        }while(stk[top--] != u); //循环直到栈顶是自己
    }
}
struct status{
    int index;
    bool power;
    bool visSCC;
};
void topo() { //拓扑排序
    queue<status> q;
    for(int i = 1; i <= n; i++) {
        if(i == belong[i] && !in[i]) { //找到一个入度为零的点且代表SCC
            q.push({i,a[i]>0,isSCC[i]}); //入队
        }
    }
    while(!q.empty()) {
        auto s = q.front(); q.pop(); //类似广搜
        if(s.visSCC&&s.power)ans+=sz[s.index]+1;
        for(auto i : g2[s.index]) { //枚举下一个点
            a[i]=s.power||a[i];
            isSCC[i]=s.visSCC||isSCC[i];
            // dp[i] = max(dp[i], dp[s] + a[i]); //状态转移       
            if(--in[i] == 0) q.push({i,s.power||a[i],s.visSCC||isSCC[i]}); //入度为零就入队
        }
    }
}
void init()
{
    ans=cnt=top=0;
    inc(i,1,n)
    {
        g[i].clear();
        g2[i].clear();
        outDegree[i]=a[i]=u[i]=v[i]=sz[i]=in[i]=dfn[i]=low[i]=stk[i]=instk[i]=belong[i]=0;
        isSCC[i]=false;
    }
}
void solve() {
    cin >> n ;
    init();
    inc(i,1,n)cin >> a[i];
    inc(i,1,n)cin>>outDegree[i];
    int edCnt(0);
    inc(i,1,n)
    {
        inc(j,1,outDegree[i])
        {
            edCnt++;
            int tmp;        
            cin>>tmp;
            u[edCnt]=i;
            v[edCnt]=tmp;
            g[i].push_back(tmp);
        }
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i); //tarjan
    for(int i = 1; i <= edCnt; i++) { //缩点
        int x = belong[u[i]], y = belong[v[i]];
        if(x != y) { //边的两个顶点不同才被放进新图中
            g2[x].push_back(y);
            in[y]++; //统计入度
        }
    }
    
    // 给每一个缩过的环打上标签
    inc(i,1,n)
    {
        if(belong[i]!=i)
            a[belong[i]]+=a[i],
            isSCC[belong[i]]=true,
            sz[belong[i]]++;
    }
    topo(); //拓扑排序
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    long long _;
    _=1;
    cin>>_;
    while(_--)solve();
}