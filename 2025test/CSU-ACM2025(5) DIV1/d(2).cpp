#include <bits/stdc++.h>  
using namespace std;  
#define int long long  

const int MAXN = 105, INF = 1e18;  
int n, m;  
vector<int> ed[MAXN];  
vector<int> ans[MAXN];  
bool vis[MAXN], tracked[MAXN];  
int fa[MAXN];  

int fd(int a) {  
    if (a == fa[a]) return a;  
    return fa[a] = fd(fa[a]); // Path compression  
}  

void getDis(int index, vector<int>& trace, vector<int>& newans) {  
    stack<int> stk;  
    stk.push(index);  
    vis[index] = true;  
    trace.push_back(index);  

    while (!stk.empty()) {  
        int curr = stk.top();  
        bool found = false;  
        for (int next : ed[curr]) {  
            if (!vis[next]) {  
                vis[next] = true;  
                trace.push_back(next);  
                stk.push(next);  
                found = true;  
                break; // Go deeper  
            }  
        }  
        if (!found) {  
            // Leaf node or backtracking  
            if (trace.size() > newans.size()) {  
                newans = trace;  
            }  
            stk.pop();  
            vis[curr] = false;  
            trace.pop_back();  
        }  
    }  
}  

void solve() {  
    cin >> n >> m;  
    // Initialize Union-Find  
    iota(fa + 1, fa + m + 1, 1); // Fill 1 to m with consecutive values  
    
    int a, b;  
    while (cin >> a >> b) {  
        if (a == -1 && b == -1) break;  
        ed[a].push_back(b);  
        ed[b].push_back(a);  
        fa[fd(a)] = fd(b); // Union operation  
    }  
    
    for (int i = 1; i <= m; ++i) {  
        vector<int> newans;  
        vector<int> trace;  
        getDis(i, trace, newans);  
        if (newans.size() > ans[fd(i)].size()) {  
            ans[fd(i)] = newans;  
        }  
    }  

    int tot = 0;  
    for (int i = 1; i <= m; ++i) {  
        if (fd(i) == i) {  
            tot += ans[i].size() - (ans[i].size() & 1);  
        }  
    }  
    cout << tot / 2 << endl;  

    for (int i = 1; i <= m; ++i) {  
        if (fd(i) == i) {  
            for (size_t j = 0; j < ans[i].size(); j += 2) {  
                if (j + 1 < ans[i].size()) {  
                    cout << ans[i][j] << " " << ans[i][j + 1] << endl;  
                }  
            }  
        }  
    }  
}  

signed main() {  
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  // Fast I/O  
    int _;  
    cin >> _;  
    while (_--) solve();  
}  