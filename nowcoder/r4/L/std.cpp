#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> ans(q);
    
    std::map<int, int> f;
    std::vector<std::vector<std::array<int, 2>>> add(n), del(n);
    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        
        int l = std::lower_bound(a.begin(), a.end(), x + 1) - a.begin();
        int r = n - y + 1;
        if (l >= r) {
            continue;
        }
        add[l].push_back({x, i});
        del[r - 1].push_back({x, i});
    }
    
    DSU dsu(q);
    std::vector<int> val(q);
    
    for (int l = 0; l < n; l++) {
        for (auto [x, i] : add[l]) 
        {
            if (f.contains(x)) 
            {
                dsu.merge(f[x], i);
            }
            else 
            {
                f[x] = i;
                val[i] = x;
            }
        }
        std::map<int, int> nf;
        for (auto [x, i] : f) {
            int y = (x + a[l] + 1) / 2;
            if (nf.contains(y)) {
                dsu.merge(nf[y], i);
            } else {
                nf[y] = i;
                val[i] = y;
            }
        }
        f = nf;
        for (auto [x, i] : del[l]) {
            ans[i] = val[dsu.find(i)] - x;
        }
    }
    
    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << "\n";
    }
    
    return 0;
}
/*
5 3
2 5 8 11 20
25 1
3 4
0 2
*/