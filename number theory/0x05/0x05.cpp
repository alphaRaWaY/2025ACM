// Problem: P2197 【模板】Nim 游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2197
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//博弈论：必胜的条件一定是下一步能使对方必输，根据最终失败条件找出最终状态的特征，然后根据最终状态的二项性判断初始状态。
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i, a, b) for (int i(a); i <= b; i++)
#define dec(i, a, b) for (int i(a); i >= b; i--)
const int MaxN(1e4 + 5);
int nums[MaxN];
void solve() {
  int n;
  cin >> n;
  inc(i, 1, n) cin >> nums[i];
  inc(i, 2, n) { nums[1] ^= nums[i]; }
  if (nums[1])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) solve();
}