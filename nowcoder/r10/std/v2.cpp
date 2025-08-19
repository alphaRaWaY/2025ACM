#include<iostream>
#include<vector>

#define endl '\n'
#define MAXN 1000005
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int a[MAXN];

int main() {
    // freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (gcd(n, m) != 1) {
        cout << "NO";
        return 0;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            a[x * m + y] = (i - 1) * m + j;
            int dy = j;
            if (j & 1) dy = -dy;
            y = (y + dy + m) % m;
        }
        a[x * m + y] = i * m;
        int dx = (i * m) % n;
        if (i & 1) dx = -dx;
        x = (x + dx + n) % n;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i * m + j] << ' ';
        cout << endl;
    }
    return 0;
}