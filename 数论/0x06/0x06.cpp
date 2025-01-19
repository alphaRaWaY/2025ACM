// Problem: P5656 【模板】二元一次不定方程 (exgcd)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5656
// Memory Limit: 16 MB
// Time Limit: 500000 ms
// 扩展欧几里得算法
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i, a, b) for (int i(a); i <= b; i++)
#define dec(i, a, b) for (int i(a); i >= b; i--)
#define ALL(x) x.begin(), x.end()
const int INF(0x3f3f3f3f);
string int128ToString(__int128 x) {
  if (x == 0) return "0";
  string result;
  bool is = x < 0;
  if (is) x = -x;
  while (x > 0) {
    result.push_back('0' + (x % 10));
    x /= 10;
  }
  if (is) result.push_back('-');
  reverse(result.begin(), result.end());
  return result;
}
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f * x;
}
void exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  int tx, ty;
  exgcd(b, a % b, tx, ty);
  x = ty;
  y = tx - (a / b) * ty;
  return;
}
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int g = __gcd(a, b);
  if (c % g) {
    cout << -1 << endl;
    return;
  }
  int x, y;
  exgcd(a, b, x, y);
  int ta(a), tb(b);
  b /= g;
  a /= g;
  x = x * c / g;
  y = y * c / g;
  x %= b;
  y %= a;
  if (x <= 0) x += b;
  if (y <= 0) y += a;
  if (ta * x >= c || tb * y >= c)
    cout << x << " " << y << endl;
  else {
    cout << (((c - ta * x) / tb) - (y)) / a + 1 << " " << x << " " << y << " "
         << (c - tb * y) / ta << " " << (c - ta * x) / tb << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) solve();
}