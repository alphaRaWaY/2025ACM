#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define pb emplace_back
#define INF 0x7f7f7f7f
#define MAXN 300005
#define MAXM 1000005
using namespace std;
using ll = long long;

int n, m;

struct Edge{
    int u, v, w;
    Edge(int _u, int _v, int _w) {u = _u; v = _v; w = _w;}
};
vector< Edge > E;

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

vector< int > ET[MAXN * 2];
int f[MAXN * 2];

int fa[MAXN * 2], tot, val[MAXN];
int find(int x) {
    if (!fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void join(int x, int y, int w) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        fa[fx] = fa[fy] = ++tot;
        f[fx] = f[fy] = tot;
        ET[tot].pb(fx);
        ET[tot].pb(fy);
        val[tot] = w;
    }
}

int dis[MAXN][2];
bool vis[MAXN * 2];

int L, id;
void dfs(int u) {
    vis[u] = true;
    if (u <= n) dis[u][id] = val[L];
    for (auto v : ET[u])
        if (!vis[v])
            dfs(v);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E.pb(u, v, w);
    }
    sort(E.begin(), E.end(), cmp);
    tot = n;
    for (auto [u, v, w] : E) {
        join(u, v, w);
        if (tot == n * 2 - 1) break;
    }
    
    id = 0;
    for (int u = 1; u; u = f[u]) {
        L = u;
        dfs(u);
    }
    memset(vis, 0, 2 * n * sizeof(int));
    id = 1;
    for (int u = n; u; u = f[u]) {
        L = u;
        dfs(u);
    }
    
    int ans = INF;
    for (auto [u, v, w] : E) {
        for (int i = 0; i < 2; i++) {
            int d1 = dis[u][i], d2 = dis[v][1 - i];
            if (d1 <= w && d2 <= w) {
                ans = min(ans, w + max(d1, d2));
            }
        }
    }
    
    cout << ans;
    return 0;
}