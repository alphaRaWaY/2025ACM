// Problem: P4503 [CTSC2014] 企鹅 QQ
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4503
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 可以不取模就不取模
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i, a, b) for (int i(a); i <= b; i++)
#define dec(i, a, b) for (int i(a); i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define f first
#define s second
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
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
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
const int base1(149), base2(137), mod(1e9 + 7), MaxN(3e4 + 5), MaxL(205);
int ha1[MaxN][MaxL], ha2[MaxN][MaxL], tmp[MaxN];
signed main() {
  ios::sync_with_stdio(false);
  int n, l, p, ans(0);
  cin >> n >> l >> p;
  inc(i, 1, n) {
    string s;
    cin >> s;
    s = "#" + s;
    inc(j, 1, l) ha1[i][j] = ha1[i][j - 1] * base1 + s[j];
    dec(j, l, 1) ha2[i][j] = ha2[i][j + 1] * base2 + s[j];
  }
  inc(i, 1, l) {
    inc(j, 1, n) tmp[j] = ha1[j][i - 1] * 233 + ha2[j][i + 1] * 213;
    sort(tmp + 1, tmp + 1 + n);
    int cnt(1);
    inc(j, 2, n) {
      if (tmp[j] == tmp[j - 1]) {
        ans += cnt;
        cnt++;
      } else {
        cnt = 1;
      }
    }
  }
  cout << ans << endl;
}