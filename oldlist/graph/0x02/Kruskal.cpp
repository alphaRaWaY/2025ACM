//problem url:https://www.luogu.com.cn/problem/P3366
//status:AC
//date:2024/08/03
//知识点：最小生成树

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MaxN = 5000 + 5;
const int MaxM = 1e5 + 5;
int pa[MaxN];

struct Edge {
    int weight;
    int endP1;
    int endP2;
    Edge(int p1, int p2, int w) : endP1(min(p1, p2)), endP2(max(p1, p2)), weight(w) {}
    bool operator > (const Edge& e) const { return weight > e.weight; }
    void print() { cout << "[" << endP1 << "," << endP2 << "," << weight << "]"; }
};

priority_queue<Edge, vector<Edge>, greater<Edge>> q;

int fd(int a) {
    return (a == pa[a] ? a : pa[a] = fd(pa[a]));
}

int main() {
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        pa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge temp(u, v, w);
        q.push(temp);
    }

    #ifdef DEBUGedge
    while (!q.empty()) {
        Edge temp(q.top());
        q.pop();
        temp.print();
    }
    #endif

    int ans = 0, cnt = 0;
    while (cnt < n - 1 && !q.empty()) {
        Edge top(q.top());
        q.pop();
        if (fd(top.endP1) != fd(top.endP2)) {
            #ifdef DEBUGconnect
            top.print();
            #endif
            pa[fd(top.endP2)] = fd(top.endP1);
            cnt++;
            ans += top.weight;
        }
    }

    #ifdef DEBUGconnect
    cout << endl;
    #endif

    if (cnt == n - 1) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }

    return 0;
}
