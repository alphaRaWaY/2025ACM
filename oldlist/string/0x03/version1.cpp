// Problem: P3538 [POI2012] OKR-A Horrible Poem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3538
// Memory Limit: 128 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define f first
#define s second
#define inc(i, a, b) for (int i(a); i <= b; i++)
#define dec(i, a, b) for (int i(a); i >= b; i--)
#define ALL(x) x.begin(), x.end()
const int INF(0x3f3f3f3f), mod1(137), mod2(149);
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
const int MaxN(5e5 + 5), mod(1e9 + 7);
string s;
int n, q;
vector<int> primes;
int minP[MaxN], Pow[MaxN], ha[MaxN];  // 最小质因数
bool vis[MaxN];
// 线性筛质数
void getP() {
  inc(i, 2, n) {
    if (!vis[i]) {
      vis[i] = true;
      minP[i] = i;
      primes.push_back(i);
    }
    for (int tmp : primes) {
      if (tmp * i > n) break;
      vis[tmp * i] = true;
      minP[tmp * i] = tmp;
      if (i % tmp == 0) break;
    }
  }
}
int getH(int l, int r) { return (mod+(ha[r] - ha[l - 1]) * Pow[r-l+1])%mod; }
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> s >> q;
  s = " " + s;
  getP();
  inc(i, 1, n) { ha[i] = (ha[i - 1] * mod1 + s[i]) % mod; }
  Pow[0] = 1;
  inc(i, 1, n) { Pow[i] = (Pow[i - 1] * mod1) % mod; }
  cout<<ha[3]<<" "<<ha[4]<<" "<<ha[5]<<endl;
  cout<<Pow[2]<<" "<<Pow[3]<<endl;
  cout<<getH(3,4)<<" "<<getH(6,7)<<endl;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int len = (r - l + 1), ans = len;
    while (len > 1) {
      int temp = ans / minP[len];
      if (getH(l, r - temp) == getH(l + temp, r)) {
        ans = temp;
      }
      len /= minP[len];
    }
    cout << ans << endl;
  }
}