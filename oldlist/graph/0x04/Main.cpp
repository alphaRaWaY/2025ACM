#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MaxN = 1e5 + 5;
const int INF = 1e9 + 5;

struct Edge {
    int p;
    ll w;
    bool operator < (const Edge& e) const { return w < e.w; }
};

vector<Edge> Adj[MaxN];
ll dis[MaxN];
bool vis[MaxN];

struct cmp {
    bool operator () (const int t1, const int t2) const { return dis[t1] > dis[t2]; }
};

int main() {
    //ios::sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        Adj[u].push_back({ v, w });
    }

    #ifdef DEBUGadj
    for (int i = 1; i <= n; i++) {
        cout << "#" << i << ":" << endl;
        for (Edge temp : Adj[i]) {
            cout << "[" << temp.p << "," << temp.w << "]";
        }
        cout << endl;
    }
    #endif

    fill(dis, dis + MaxN, INF);
    dis[s] = 0;

    priority_queue<int, vector<int>, cmp> q;
    q.push(s);

    while (!q.empty()) {
        int top = q.top();
        q.pop();
        if (!vis[top]) {
            cout<<top<<endl;
            vis[top] = true;
            for (Edge temp : Adj[top]) {
                if (dis[temp.p] > dis[top] + temp.w) {
                    dis[temp.p] = dis[top] + temp.w;
                    q.push(temp.p);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) {
            cout << "INF ";
        } else {
            cout << dis[i] << " ";
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
